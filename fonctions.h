// fonctions.h
#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "type.h"

// Fonctions Utilitaires (Parsing CSV)
int extraireEntier(const char *chaine, int *index, char delim);
float extraireFlottant(const char *chaine, int *index, char delim);
void extraireChaine(const char *chaine, int *index, char delim, char *destination);

// Fonction de Chargement
int chargerTrajets(const char *nomFichier);

// Fonctions d'Affichage et de Traitement (Fonctionnalités)
void afficherTrajetSimple(const Trajet *t);
void afficherTousTrajets();                                      // Fonctionnalité 1
void afficherTrajetParBus(int numBusRecherche);                  // Fonctionnalité 2
int comparerTrajets(const Trajet *t1, const Trajet *t2);         // Fonction de comparaison pour le tri
void afficherTrajetsTries();                                     // Fonctionnalité 3

#endif // FONCTIONS_H