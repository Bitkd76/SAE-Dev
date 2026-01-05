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
        printf("Erreur lors de l ouverture du fichier.\n");
        return 1;
    }
    else{
        printf("Implementation en cours...\n");
        implementation_struct(f);
        printf("Implementation Terminer \n");
        while (choix != 20) {
        printf("================ MENU BUS ================\n");
        printf("1  - Afficher tous les trajets prevus\n");
        printf("2  - Afficher informations trajet (par numero de bus)\n");
        printf("3  - Afficher tous les trajets tries (Ville Depart / Date Depart)\n");
        printf("4  - Gestion des passagers (Ajout/Suppression) \n");
        printf("5  - Modifier Nom/Prix billet d un passager \n");
        printf("6  - Sauvegarde des donnees dans un fichier \n");
        printf("7  - Filtrer : Trajets partant d une ville, à une date, arrivant le lendemain \n");
        printf("8  - Filtrer : Trajets combinant Ville Depart, Ville Arrivee et Date Depart \n");
        printf("9  - Afficher trajets tries par Chiffre d Affaires (CA) \n");
        printf("10 - Suppression des bus a CA negatif et redistribution \n");
        printf("\n20 - Quitter le programme\n");
        printf("===========================================\n");
        
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1 :
                afficher_tous_trajets(f);
                break;
            case 2 :
                afficher_selon_num(f);
                break;
            case 3 :
                trier_par_ville_et_date(f);
                afficher_tous_trajets(f);
                break;
            case 4 :
                
                printf("1 - Ajout de client \n");
                printf("2 - Supperssion de client de client \n");
                printf("Votre choix: ");
                scanf("%d",&casechoix);
                if(casechoix==1){
                    ajouter_passager(f);
                    while (casechoix==1){
                        printf("1 - Ajouter un autre passager\n");
                        printf("20 - retour\n");
                        printf("Votre Choix:");
                        scanf("%d",&casechoix);
                        ajouter_passager(f);
                    }
                }
                else if (casechoix==2){
                    while (casechoix==2)
                    {
                        printf("1 - Supprimer un autre passager\n");
                        printf("20 - retour\n");
                        printf("Votre Choix:");
                        scanf("%d",&casechoix);
                        supprimer_passager(f);
                    }
                    
                }
                else{
                    printf("Choix invalide!\n");
                }
                break;
            case 5 :
                modif_nom_prix(f);
                break; 
            case 6 :
                maj_nv_fichier();
                break;
            case 7 :

                break;
            case 8 :

                break;
            case 9 :

                break;
            case 10 :

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