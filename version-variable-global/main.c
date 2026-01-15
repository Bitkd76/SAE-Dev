#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include "type.h"



//====[BILAL]====//
int main() {
    int choix = 0;
    int num_bus_recherche;
    int casechoix;
    FILE *f = fopen(FICHIER, "r+"); 
    if (f == NULL) {
        printf("Erreur lors de l ouverture  du fichier.\n");
        return 1;
    }
    else{
        printf("Implementation en cours...\n");
        implementation_struct(f);
        printf("Implementation Terminer \n");
        while (choix != 20) {
        printf("================ MENU BUS avec le compteur de complexite ================\n");
        printf("1 - Recherche: Afficher informations trajet (par numero de bus) \n");
        printf("2 - Trie: Afficher tous les trajets tries (Ville Depart / Date Depart)\n");
        printf("3 - Filtre : Trajets partant d une ville, a une date, arrivant le lendemain \n");
        printf("\n20 - Quitter le programme\n");
        printf("===========================================\n");
        
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1 :
                afficher_selon_num();
                break;
            case 2 :
                trier_par_ville_et_date();
                afficher_tous_trajets();
                break;
            case 3 :
                filtre_ville_date_lendemain();
                break;
            case 20 :
                printf("Fermeture. \n");
                break;
            default:
                printf("Choix invalide. Veuillez selectionner une option valide.\n");
                break;
        }
    }
}   
    fclose(f);
    return 0;

}