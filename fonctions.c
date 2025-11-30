#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fonctions.h"


//===== [Bilal] =====//
int max_caracter_ligne(FILE *f) {
    int max = 0;
    char limite[5000];

    while (fgets(limite, sizeof(limite), f)) {
        int len = 0;
        while (limite[len] != '\0' && limite[len] != '\n') len++;
        if (len > max) max = len;
    }

    rewind(f);                 // Remet le curseur au début du fichier pour eviter des probleme quand on lit apres
    return max;
}

//===== [Bilal] =====//
void affichage_tout_traget(FILE *f){ // afficher ville depart arrive, date/horaire depart arrivee
    char ligne[max_caracter_ligne(f)];//---------------------------------------------lecture ligne par ligne
    int m,h,horaire;
    //======== Boucle Pour lire chaque ligne du fichier ========//
    while (fgets(ligne, sizeof(ligne), f)) {
        ligne[strcspn(ligne, "\n")] = 0;

//--------------------- ensuite je separe ligne avec separateur , -----------//
        char* separateur;
        int champ = 0;

        separateur = strtok(ligne, ",");
//--------------------------------------------------------------------------//
        //-- variable champ debute a 0 (idbus) /!\ --//
        while (separateur != NULL) {
            switch (champ) {
                case 1: 
                    printf("Ville depart : %s\n", separateur);
                    break;
                case 2: 
                    printf("Ville arrivee : %s\n", separateur);
                    break;
                case 3: 
                    printf("Date depart : %s\n", separateur);
                    break;
                case 4:
                    horaire = atoi(separateur); // aoi ( vien de stdlib.h et sert a convertir une chaine de caractere en int)
                    h = horaire / 100;
                    m = horaire % 100;
                    printf("Horaire depart : %02d:%02d\n", h, m);
                    break;
                case 5:
                    horaire = atoi(separateur); // aoi ( vien de stdlib.h et sert a convertir une chaine de caractere en int pas vue en class)
                    h = horaire / 100;
                    m = horaire % 100;
                    printf("Horaire arrivee : %02d:%02d\n", h, m);
                    break;
            }
            champ++;    //------------------------------------------ Prend valeur des differents champs selon le format qu'on a vue en cours ----------------//
            separateur = strtok(NULL, ","); //-- null pour qu'il continue a separer la meme ligne --//
        }
        printf("\n----------------------------------\n\n");
    }
}



//===== [Bilal] =====//
void affichage_trajet_selon_bus(FILE *f){
//----- demander le numero du bus -----//
    int numbus;
    printf("Saisir le numero du bus : ");
    scanf("%d", &numbus);

//----- initialisation des variables -----//
    char ligne[max_caracter_ligne(f)];
    char ligne_orig[max_caracter_ligne(f)];

//----- lecture ligne par ligne -----//
    rewind(f);
    while (fgets(ligne, sizeof(ligne), f)) {
        ligne[strcspn(ligne, "\n")] = 0;       // retirer le \n a la fin de la ligne
        strcpy(ligne_orig, ligne);              // copie la ligne originel(/!\) doit etre apres le while, pour qu'il puissent copier une ligne deja lue
        char *num = strtok(ligne, ",");         // vue que j'ai besoin que du premier champs( champ 0 ) je le recupere avec strtok qui vas recuperer la chaine de caractere jusqu'a tomber sur le ,
        if (num != NULL && numbus == atoi(num)) { // atoi convertie la chaine de caractere en int pour pouvoir comparer
            printf("Trajet du bus numero %d : %s\n", numbus, ligne_orig);
        }
    }
}


