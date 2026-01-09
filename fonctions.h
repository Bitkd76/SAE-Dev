#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "type.h"
#include <stdio.h>

void afficher_tous_trajets(FILE *f);

void implementation_struct(FILE *f);

void afficher_selon_num(FILE *f);

void trier_par_ville_et_date(FILE *f);

void supprimer_passager(FILE *f);

void ajouter_passager(FILE *f);

void modif_nom_prix(FILE *f);

void maj_nv_fichier();

void combiner_villedep_villearriv_datedep(FILE *f);

void ca_triee(FILE *f);

#endif 