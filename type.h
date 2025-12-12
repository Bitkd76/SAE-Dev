// types.h
#ifndef TYPES_H
#define TYPES_H

// Constantes
#define MAX_LIGNES 100
#define MAX_PASSAGERS 55
#define TAILLE_LIGNE 4096
#define TAILLE_CHAINE 50

// --- Structures de données ---
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    int heure;
    int minute;
} Heure;

typedef struct {
    int id;
    char nom_prenom[TAILLE_CHAINE];
    float prixBillet;
} Passager;

typedef struct {
    int numBus;
    char villeDepart[TAILLE_CHAINE];
    char villeArrivee[TAILLE_CHAINE];
    Date dateDepart;
    Heure horaireDepart;
    Heure horaireArrivee;
    Passager passagers[MAX_PASSAGERS];
    int nombrePassagers;
} Trajet;

// Déclaration des variables globales
extern Trajet trajets[MAX_LIGNES];
extern int nombreTrajets;

#endif // TYPES_H