#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "type.h"
#include <stdio.h>

/**
 * Affiche tous les trajets existants.
 * Pré-cond: b[i] initialisés pour 0 <= i < MAX_BUS
 * Post-cond: Affichage des informations de tous les bus et leurs passagers
 */
void afficher_tous_trajets(void);

/**
 * Remplit le tableau de bus et de passagers à partir d'un fichier CSV.
 * Entrée: f : FILE* ouvert en lecture
 * Pré-cond: f non NULL, format CSV correct pour les bus et passagers
 * Post-cond: b[i] et p[i] sont initialisés avec les données du fichier
 */
void implementation_struct(FILE *f);

/**
 * Affiche les informations d’un bus selon son numéro.
 * Entrée: numBus saisi par l’utilisateur
 * Pré-cond: b[i] initialisés
 * Post-cond: Affichage des informations du bus et de ses passagers
 */
void afficher_selon_num(void);

/**
 * Trie le tableau de bus par ville de départ puis par date.
 * Pré-cond: b[i] initialisés
 * Post-cond: b[i] triés par ordre alphabétique de ville puis par date croissante
 */
void trier_par_ville_et_date(void);


/**
 * Filtre et affiche les trajets partant d’une ville et arrivant le lendemain.
 * Entrée: ville de départ saisie par l’utilisateur
 * Pré-cond: b[i] initialisés
 * Post-cond: Affichage des bus correspondant à ce critère
 */
void filtre_ville_date_lendemain(void);


#endif
