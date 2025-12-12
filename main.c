#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" // Changé 'type.h' en 'types.h' pour la cohérence

// Définition du nom de fichier pour le chargement initial
#define NOM_FICHIER "trajets_bus.csv" 

// Fonction pour la lecture sécurisée d'un entier
int lireEntier() {
    int val;
    // On s'assure de consommer toute la ligne d'entrée après le nombre
    if (scanf("%d", &val) != 1) {
        // Vider le buffer d'entrée en cas d'échec de lecture (caractère non numérique)
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return -1; // Indiquer une erreur
    }
    return val;
}


//====[BILAL]====//
int main() {
    int choix = 0;
    int num_bus_recherche;
    
    // --- ÉTAPE 1: CHARGEMENT DU FICHIER ---
    
    printf("Tentative de chargement du fichier: %s\n", NOM_FICHIER);
    
    if (chargerTrajets(NOM_FICHIER) == 0) {
        printf("Erreur critique: Aucune donnée de trajet chargée. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    printf("\n--- %d trajets chargés avec succès. ---\n\n", nombreTrajets);
    
    // --- ÉTAPE 2: MENU INTERACTIF ---
    
    while (choix != 20) {
        printf("================ MENU BUS ================\n");
        printf("1  - Afficher tous les trajets prévus\n");
        printf("2  - Afficher informations trajet (par numéro de bus)\n");
        printf("3  - Afficher tous les trajets triés (Ville Départ / Date Départ)\n");
        printf("4  - Gestion des passagers (Ajout/Suppression) [NON IMPLÉMENTÉ]\n");
        printf("5  - Modifier Nom/Prix billet d'un passager [NON IMPLÉMENTÉ]\n");
        printf("6  - Sauvegarde des données dans un fichier [NON IMPLÉMENTÉ]\n");
        printf("7  - Filtrer : Trajets partant d'une ville, à une date, arrivant le lendemain [NON IMPLÉMENTÉ]\n");
        printf("8  - Filtrer : Trajets combinant Ville Départ, Ville Arrivée et Date Départ [NON IMPLÉMENTÉ]\n");
        printf("9  - Afficher trajets triés par Chiffre d'Affaires (CA) [NON IMPLÉMENTÉ]\n");
        printf("10 - Suppression des bus à CA négatif et redistribution [NON IMPLÉMENTÉ]\n");
        printf("\n20 - Quitter le programme\n");
        printf("===========================================\n");
        
        printf("Votre choix : ");
        choix = lireEntier(); // Utilisation de la fonction de lecture sécurisée
        
        if (choix == -1) {
            printf("Entrée invalide. Veuillez entrer un numéro.\n");
            choix = 0; // Remettre le choix à une valeur neutre
            continue;
        }

        switch (choix) {
            case 1 :
                // Fonctionnalité 1
                afficherTousTrajets();
                break;
            case 2 :
                // Fonctionnalité 2
                printf("Entrez le numéro du bus à afficher : ");
                num_bus_recherche = lireEntier();
                if (num_bus_recherche != -1) {
                    afficherTrajetParBus(num_bus_recherche);
                } else {
                    printf("Numéro de bus invalide.\n");
                }
                break;
            case 3 :
                // Fonctionnalité 3
                afficherTrajetsTries();
                break;
            case 4 :
                // Fonctionnalité 4 (A implémenter)
                printf("Fonctionnalité 4 : Ajout et suppression de clients. (A implémenter)\n");
                break;
            case 5 :
                // Fonctionnalité 5 (A implémenter)
                printf("Fonctionnalité 5 : Modification Nom/Prix Billet. (A implémenter)\n");
                break; 
            case 6 :
                // Fonctionnalité 6 (A implémenter)
                printf("Fonctionnalité 6 : Sauvegarde des données. (A implémenter)\n");
                break;
            case 7 :
                // Fonctionnalité 7 (A implémenter)
                printf("Fonctionnalité 7 : Filtrage (Ville Départ, Date Départ, Arrivée J+1). (A implémenter)\n");
                break;
            case 8 :
                // Fonctionnalité 8 (A implémenter)
                printf("Fonctionnalité 8 : Filtrage (Ville Départ, Ville Arrivée, Date Départ). (A implémenter)\n");
                break;
            case 9 :
                // Fonctionnalité 9 (A implémenter)
                printf("Fonctionnalité 9 : Affichage des trajets triés par CA. (A implémenter)\n");
                break;
            case 10 :
                // Fonctionnalité 10 (A implémenter)
                printf("Fonctionnalité 10 : Suppression des bus à CA négatif. (A implémenter)\n");
                break;
            case 20 :
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez sélectionner une option valide.\n");
                break;
        }
    
    }
    
    // Pas besoin de fclose, car le fichier est fermé dans chargerTrajets
    return EXIT_SUCCESS;
}