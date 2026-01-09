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
 * Supprime un passager d’un bus selon l’ID.
 * Entrées: numBus et id du passager saisis par l’utilisateur
 * Pré-cond: b[i] initialisés
 * Post-cond: Passager supprimé du bus si trouvé, sinon message d’erreur
 */
void supprimer_passager(void);

/**
 * Ajoute un passager à un bus selon son numéro.
 * Entrées: numBus, id, nom et prix saisis par l’utilisateur
 * Pré-cond: b[i] initialisés, bus non plein
 * Post-cond: Nouveau passager ajouté au bus
 */
void ajouter_passager(void);

/**
 * Modifie le nom ou le prix d’un passager d’un bus.
 * Entrées: numBus et id du passager, choix (1=nom, 2=prix)
 * Pré-cond: b[i] initialisés, passager existant
 * Post-cond: Nom ou prix modifié selon le choix
 */
void modif_nom_prix(void);

/**
 * Met à jour le fichier de sauvegarde des trajets et passagers.
 * Pré-cond: b[i] initialisés
 * Post-cond: Écriture de tous les bus et passagers dans "sauvegarde_trajet_bus.csv"
 */
void maj_nv_fichier(void);

/**
 * Filtre et affiche les trajets partant d’une ville et arrivant le lendemain.
 * Entrée: ville de départ saisie par l’utilisateur
 * Pré-cond: b[i] initialisés
 * Post-cond: Affichage des bus correspondant à ce critère
 */
void filtre_ville_date_lendemain(void);

/**
 * Affiche les trajets correspondant à une ville de départ, une ville d’arrivée et une date.
 * Entrées: villeDep, villeArriv, jour, mois, annee saisis par l’utilisateur
 * Pré-cond: b[i] initialisés
 * Post-cond: Affichage des bus correspondant à ces critères
 */
void combiner_villedep_villearriv_datedep(void);

/**
 * Calcule et trie les trajets selon le chiffre d’affaires généré par les passagers.
 * Pré-cond: b[i] et passagers initialisés
 * Post-cond: Affichage des bus triés par chiffre d’affaire croissant
 */
void ca_triee(void);

#endif
