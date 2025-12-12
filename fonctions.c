// fonctions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" // Assurez-vous que votre fichier d'en-tête est bien nommé "types.h"

// Définition des variables globales (déclarées "extern" dans types.h)
Trajet trajets[MAX_LIGNES];
int nombreTrajets = 0;

// --- Fonctions Utilitaires (Parsing CSV) ---

int extraireEntier(const char *chaine, int *index, char delim) {
    int resultat = 0;
    int debut = *index;

    while (chaine[*index] != '\0' && chaine[*index] != delim) {
        if (chaine[*index] >= '0' && chaine[*index] <= '9') {
            resultat = resultat * 10 + (chaine[*index] - '0');
        }
        (*index)++;
    }

    if (chaine[*index] == delim) {
        (*index)++;
    }

    if (*index - 1 == debut && delim != '\0') {
         // Valeur manquante ou vide, renvoie 0
    }

    return resultat;
}

float extraireFlottant(const char *chaine, int *index, char delim) {
    float resultat = 0.0;
    float decimal = 0.1;
    int apresPoint = 0;
    int debut = *index;

    while (chaine[*index] != '\0' && chaine[*index] != delim) {
        if (chaine[*index] >= '0' && chaine[*index] <= '9') {
            if (!apresPoint) {
                resultat = resultat * 10.0 + (chaine[*index] - '0');
            } else {
                resultat = resultat + (chaine[*index] - '0') * decimal;
                decimal /= 10.0;
            }
        } else if (chaine[*index] == '.') {
            apresPoint = 1;
        }
        (*index)++;
    }

    if (chaine[*index] == delim) {
        (*index)++;
    }

    if (*index - 1 == debut && delim != '\0') {
         return 0.0; // Prix manquant
    }

    return resultat;
}

void extraireChaine(const char *chaine, int *index, char delim, char *destination) {
    int i = 0;
    int debut = *index;

    while (chaine[*index] != '\0' && chaine[*index] != delim && i < TAILLE_CHAINE - 1) {
        destination[i++] = chaine[*index];
        (*index)++;
    }
    destination[i] = '\0';

    if (chaine[*index] == delim) {
        (*index)++;
    }

    if (*index - 1 == debut && delim != '\0') {
        strcpy(destination, "Inconnu"); // Nom manquant
    }
}

// --- Fonction de Chargement ---

int chargerTrajets(const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        // En mode production/final, on affiche seulement un message sans perror sur stderr
        // printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return 0;
    }

    char ligne[TAILLE_LIGNE];
    nombreTrajets = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL && nombreTrajets < MAX_LIGNES) {
        ligne[strcspn(ligne, "\r\n")] = '\0';

        Trajet *t = &trajets[nombreTrajets];
        int index = 0;
        int val;

        // 1. numBus
        t->numBus = extraireEntier(ligne, &index, ',');
        // 2. villeDepart
        extraireChaine(ligne, &index, ',', t->villeDepart);
        // 3. villeArrivee
        extraireChaine(ligne, &index, ',', t->villeArrivee);
        
        // 4. dateDepart (JJ/MM/AAAA)
        t->dateDepart.jour = extraireEntier(ligne, &index, '/');
        t->dateDepart.mois = extraireEntier(ligne, &index, '/');
        t->dateDepart.annee = extraireEntier(ligne, &index, ',');

        // 5. horaireDepart (HHMM)
        val = extraireEntier(ligne, &index, ',');
        t->horaireDepart.heure = val / 100;
        t->horaireDepart.minute = val % 100;
        
        // 6. horaireArrivee (HHMM - Peut être absent)
        int debut_horaire_arrivee = index;
        while (ligne[index] != '\0' && ligne[index] != ',') { index++; }
        
        if (index > debut_horaire_arrivee) {
            index = debut_horaire_arrivee;
            val = extraireEntier(ligne, &index, ',');
            t->horaireArrivee.heure = val / 100;
            t->horaireArrivee.minute = val % 100;
        } else {
            t->horaireArrivee.heure = -1; // Sentinelle
            t->horaireArrivee.minute = -1; 
            if (ligne[index] == ',') index++;
        }

        // 7. Liste des passagers (id:nom:prixBillet, ...)
        t->nombrePassagers = 0;
        while (ligne[index] != '\0' && t->nombrePassagers < MAX_PASSAGERS) {
            Passager *p = &t->passagers[t->nombrePassagers];
            
            // id
            p->id = extraireEntier(ligne, &index, ':');

            // nom (peut être manquant, délimité par :)
            int debut_nom = index;
            while (ligne[index] != '\0' && ligne[index] != ':' && ligne[index] != ',') { index++; }

            if (index > debut_nom && ligne[index] == ':') {
                index = debut_nom;
                extraireChaine(ligne, &index, ':', p->nom_prenom);
            } else {
                 strcpy(p->nom_prenom, "Inconnu:Prix Manquant"); // Sentinelle temporaire
                 if (ligne[index] == ':') index++;
            }

            // prixBillet (peut être manquant, délimité par , ou \0)
            int debut_prix = index;
            while (ligne[index] != '\0' && ligne[index] != ',') { index++; }

            if (index > debut_prix) {
                index = debut_prix;
                p->prixBillet = extraireFlottant(ligne, &index, ',');
            } else {
                p->prixBillet = 0.0;
                if (ligne[index] == ',') index++;
            }
            
            // Correction finale du cas de nom manquant
            if(strcmp(p->nom_prenom, "Inconnu:Prix Manquant") == 0) {
                 p->prixBillet = 0.0;
                 strcpy(p->nom_prenom, "Inconnu");
            }
            
            t->nombrePassagers++;
            
            if (ligne[index] == '\0') break;
        }

        nombreTrajets++;
    }

    fclose(fichier);
    return nombreTrajets;
}

// --- Fonctionnalité 1 & 3: Affichage simple du Trajet (tableau ASCII) ---

void afficherTrajetSimple(const Trajet *t) {
    char horaire_arr_str[10];
    if (t->horaireArrivee.heure != -1) {
        sprintf(horaire_arr_str, "%02d:%02d", t->horaireArrivee.heure, t->horaireArrivee.minute);
    } else {
        strcpy(horaire_arr_str, "N/A");
    }

    printf("| %-3d | %-14s | %-14s | %02d/%02d/%04d | %02d:%02d | %-11s |\n", 
           t->numBus, 
           t->villeDepart, 
           t->villeArrivee, 
           t->dateDepart.jour, 
           t->dateDepart.mois, 
           t->dateDepart.annee, 
           t->horaireDepart.heure, 
           t->horaireDepart.minute,
           horaire_arr_str);
}


void afficherTousTrajets() {
    printf("\n=== 1. Affichage de tous les trajets prévus (%d) ===\n", nombreTrajets);
    if (nombreTrajets == 0) {
        printf("Aucun trajet n'a été chargé.\n");
        return;
    }
    
    printf("+-----+----------------+----------------+-------------+---------+-------------+\n");
    printf("| Bus | Ville Départ   | Ville Arrivée  | Date Départ | H. Dép. | H. Arr.     |\n");
    printf("+-----+----------------+----------------+-------------+---------+-------------+\n");

    for (int i = 0; i < nombreTrajets; i++) {
        afficherTrajetSimple(&trajets[i]);
    }
    printf("+-----+----------------+----------------+-------------+---------+-------------+\n");
}


// --- Fonctionnalité 2: Affichage complet du trajet par numéro de bus (tableau ASCII strict) ---

void afficherTrajetParBus(int numBusRecherche) {
    printf("\n=== 2. Informations du trajet pour le Bus n°%d ===\n", numBusRecherche);
    int trouve = 0;
    
    for (int i = 0; i < nombreTrajets; i++) {
        if (trajets[i].numBus == numBusRecherche) {
            Trajet *t = &trajets[i];
            
            char horaire_arr_str[10];
            if (t->horaireArrivee.heure != -1) {
                sprintf(horaire_arr_str, "%02d:%02d", t->horaireArrivee.heure, t->horaireArrivee.minute);
            } else {
                strcpy(horaire_arr_str, "N/A");
            }
            
            // Partie 1: Informations de base du trajet (strictement les infos demandées)
            printf("\n--- Détails du Trajet (Bus %d) ---\n", t->numBus);
            printf("+----------------+----------------+----------------+----------------+\n");
            printf("| VILLE DEPART   | VILLE ARRIVEE  | DATE DEPART    | HEURE DEPART   |\n");
            printf("+----------------+----------------+----------------+----------------+\n");
            printf("| %-14s | %-14s | %02d/%02d/%04d | %02d:%02d       |\n", 
                   t->villeDepart, 
                   t->villeArrivee, 
                   t->dateDepart.jour, 
                   t->dateDepart.mois, 
                   t->dateDepart.annee,
                   t->horaireDepart.heure,
                   t->horaireDepart.minute);
            printf("+----------------+----------------+----------------+----------------+\n");

            printf("| HEURE ARRIVEE  | Nombre Passagers |\n");
            printf("+----------------+------------------+\n");
            printf("| %-14s | %-16d |\n",
                   horaire_arr_str,
                   t->nombrePassagers);
            printf("+----------------+------------------+\n");


            // Partie 2: Liste des passagers (tableau ASCII strict)
            printf("\n--- Liste des Passagers ---\n");
            printf("+------+----------------------------------+-----------------+\n");
            printf("| ID   | Nom du Passager                  |  Billet (euros) |\n");
            printf("+------+----------------------------------+-----------------+\n");
            
            if (t->nombrePassagers == 0) {
                 printf("| Aucune réservation enregistrée.                                  |\n");
            }

            for (int j = 0; j < t->nombrePassagers; j++) {
                Passager *p = &t->passagers[j];
                char nom_display[TAILLE_CHAINE];
                
                if (strcmp(p->nom_prenom, "Inconnu") == 0) {
                    strcpy(nom_display, "Nom manquant");
                } else {
                    strncpy(nom_display, p->nom_prenom, TAILLE_CHAINE - 1);
                    nom_display[TAILLE_CHAINE - 1] = '\0';
                }

                printf("| %-4d | %-32s | %-15.2f |\n", 
                       p->id, 
                       nom_display,
                       p->prixBillet);
            }
            printf("+------+----------------------------------+-----------------+\n");

            trouve = 1;
            break; 
        }
    }
    if (!trouve) {
        printf("Aucun trajet trouvé pour le Bus n°%d.\n", numBusRecherche);
    }
}


// --- Fonctionnalité 3: Affichage des trajets triés ---

int comparerTrajets(const Trajet *t1, const Trajet *t2) {
    // 1. Tri par ville de départ (alphabétique)
    int cmp_ville = strcmp(t1->villeDepart, t2->villeDepart);
    if (cmp_ville != 0) {
        return cmp_ville;
    }

    // 2. Tri par date de départ (chronologique)
    if (t1->dateDepart.annee != t2->dateDepart.annee) {
        return t1->dateDepart.annee - t2->dateDepart.annee;
    }
    if (t1->dateDepart.mois != t2->dateDepart.mois) {
        return t1->dateDepart.mois - t2->dateDepart.mois;
    }
    if (t1->dateDepart.jour != t2->dateDepart.jour) {
        return t1->dateDepart.jour - t2->dateDepart.jour;
    }
    
    // Heure (pour stabilité si tout est identique)
    int h1 = t1->horaireDepart.heure * 100 + t1->horaireDepart.minute;
    int h2 = t2->horaireDepart.heure * 100 + t2->horaireDepart.minute;
    return h1 - h2;
}

void afficherTrajetsTries() {
    printf("\n=== 3. Affichage des trajets triés (Ville Départ / Date Départ) ===\n");
    if (nombreTrajets == 0) {
        printf("Aucun trajet n'a été chargé.\n");
        return;
    }

    // Créer une copie du tableau de trajets pour le tri (Tri à Bulles)
    Trajet trajetsTries[MAX_LIGNES];
    for(int i = 0; i < nombreTrajets; i++) {
        trajetsTries[i] = trajets[i];
    }
    
    // Tri à bulles
    for (int i = 0; i < nombreTrajets - 1; i++) {
        for (int j = 0; j < nombreTrajets - 1 - i; j++) {
            if (comparerTrajets(&trajetsTries[j], &trajetsTries[j + 1]) > 0) {
                Trajet temp = trajetsTries[j];
                trajetsTries[j] = trajetsTries[j + 1];
                trajetsTries[j + 1] = temp;
            }
        }
    }

    // Affichage des résultats triés (réutilise l'affichage simple)
    printf("+-----+----------------+----------------+-------------+---------+-------------+\n");
    printf("| Bus | Ville Départ   | Ville Arrivée  | Date Départ | H. Dép. | H. Arr.     |\n");
    printf("+-----+----------------+----------------+-------------+---------+-------------+\n");
    for (int i = 0; i < nombreTrajets; i++) {
        afficherTrajetSimple(&trajetsTries[i]);
    }
    printf("+-----+----------------+----------------+-------------+---------+-------------+\n");
}