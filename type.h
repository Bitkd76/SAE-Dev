#ifndef TYPES_H
#define TYPES_H

#define FICHIER "trajets_bus.csv" 
#define MAX_CARAC 50
#define MAX_PASSAGERS 55
#define MAX_BUS 5000

typedef struct {
    int id;
    char nom[MAX_CARAC];
    float prixBillet;
} Passager;

typedef struct {
    int numBus;
    char villeDepart[MAX_CARAC];
    char villeArrivee[MAX_CARAC];
    char dateDepart[MAX_CARAC];
    char horaireDepart[MAX_CARAC];
    char horaireArrivee[MAX_CARAC];
    Passager p[MAX_PASSAGERS];
} Bus;


#endif 