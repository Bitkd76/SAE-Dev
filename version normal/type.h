#ifndef TYPES_H
#define TYPES_H

#define FICHIER "trajets_bus.csv" 
#define MAX_CARAC 50
#define MAX_PASSAGERS 55
#define MAX_BUS 5000

typedef struct 
{
    int idbus;
    double chiffre_affaire;
}CA;


typedef struct {
    int id;
    char nom[MAX_CARAC];
    float prixBillet;
} Passager;

typedef struct 
{
    int j;
    int m;
    int a;
}date;


typedef struct {
    int numBus;
    char villeDepart[MAX_CARAC];
    char villeArrivee[MAX_CARAC];
    date d;
    int horaireDepart;
    int horaireArrivee;
    Passager p[MAX_PASSAGERS];
} Bus;


#endif 