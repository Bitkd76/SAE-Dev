#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fonctions.h"
#include "type.h"

//========== format fichierhier:   numBus,villeDepart,villeArrivee,dateDepart,horaireDepart,horaireArrivee,id:nom:prixBillet,.. =========== //
//========= Beaucoup de ligne/fonctions... differentes donc ne pas hesiter de commenter ==========//

//====[BILAL]====//
int main(){
    int choix;
    int i=0;
    printf("1 - tous les trajets prevus \n");
    printf("2 - afficher toutes les informations sur le traget a partir du numeros d'un bus\n");
    printf("3 - affichage de tous les trajtes tries par ville de depart et date de depart \n");
    printf("4 - ajout et suppression de clients a partir du numero d'un bus\n");
    printf("5 - ajouter/modifier le nom/prix billet d'un client selon num bus + iDclient  \n");
    printf("6 - Sauvegarde des donnees dans un fichier \n");
    printf("7 - Trajets partant d une ville, partant a une date, arrivant le lendemain \n");
    printf("8 - Trajets combinant ville de depart, ville arrivee et date de depart \n");
    printf("9 - Trajets tries par CA \n"); //(difference entre les prix des billets payes par les passagers et le cout du trajet supporte par l’entreprise)//, 
    // en dernier si on a finit 10- facultatif //
    printf("10 - Suppression des bus avec CA negatif, en repartissant les passagers sur les trajets identiques, en priorisant les passagers ayant paye le plus sur les dates et horaires les plus proches du trajet initial. Il faudra indiquer le gain genere par cette operation \n");
    printf("\n\n");

    FILE *fichier = fopen(trajet, "r") ;
    if( fichier == NULL) {
        perror("fopen") ;
        printf("Erreur lors de l'ouverture du fichierhier des trajets.\n");
        exit(EXIT_FAILURE) ;
    }
    else{
        while (i==0)
        {
        printf("Votre choix : ");
        scanf("%d", &choix);
            switch (choix)
            {
            case 1 :
                affichage_tout_traget(fichier);
                i= 1;
                break;
            case 2 :
                affichage_trajet_selon_bus(fichier);
                i= 1;
                break;
            case 3 :
                // affichage de tous les trajtes tries par ville de depart et par date de depart
                i= 1;
                break;
            case 4 :
                // a partir du numero d'un bus, ajout et suppression de clients
                i= 1;
                break;
            case 5 :
                // a partir du numero d'un bus et id cleint, modifichieration ou ajout du nom client ou prix de son billet
                i= 1; 
                break;
            case 6 :
                // la sauvegarde des donnees dans un fichierhier
                i= 1;
                break;
            case 7 :
                // un filtre sur les trajets partant d’une ville, partant a une date, arrivant le lendemain
                i= 1;
                break;
            case 8 :
                // un filtre sur les trajets combinant ville de depart, ville d’arrivee et date de depart
                i= 1;
                break;
            case 9 :
                // l’affichage des trajets tries par chiffre d’affaires (difference entre les prix des billets payes par les passagers et le coût du trajet supporte par l’entreprise), avec affichage de ce chiffre d’affaires
                i= 1;
                break;
            case 10 :
                // La possibilite de supprimer tous les bus avec un chiffre d’affaires negatif, en repart   
                // issant les passagers sur les trajets identiques, en priorisant les passagers ayant paye le plus sur les dates et horaires les plus proches du trajet initial. Il faudra indiquer le gain genere par cette operation
                i= 1;
                break;
                
            default:
                printf("Choix invalide.\n");
                break;
            } 
    }
    fclose(fichier) ;
    return EXIT_SUCCESS ;

    }
}