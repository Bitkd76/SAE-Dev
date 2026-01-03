#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" 


Bus b[MAX_BUS];
Passager p[MAX_PASSAGERS];

//== Bilal ==// //== IMPLEMENTATION NE FONCTIONNE PLUS JSP POURQUOI JVAIS TOUT CASSER ==//
int implementation_struct(FILE *f) {
    int i = 0;

    while (i < MAX_BUS) {
        int ret = fscanf(f, "%d,%49[^,],%49[^,],%49[^,],%49[^,],%49[^,\n]",
                         &b[i].numBus,
                         b[i].villeDepart,
                         b[i].villeArrivee,
                         b[i].dateDepart,
                         b[i].horaireDepart,
                         b[i].horaireArrivee);
        if (ret != 6) break; // fin fichier ou ligne invalide

        // initialiser les passagers
        for (int j = 0; j < MAX_PASSAGERS; j++) {
            b[i].p[j].id = 0;
            b[i].p[j].nom[0] = '\0';
            b[i].p[j].prixBillet = 0.0;
        }

        int j = 0;
        while (j < MAX_PASSAGERS) {
            int id;
            char nom[MAX_CARAC];
            float prix;

            int k = fscanf(f, "%d:%49[^:]:%f", &id, nom, &prix);
            if (k != 3) break;

            b[i].p[j].id = id;
            strcpy(b[i].p[j].nom, nom);
            b[i].p[j].prixBillet = prix;

            j++;

            char c = fgetc(f);
            if (c == '\n' || c == EOF) break;
        }
        
        int c;
        while ((c = fgetc(f)) != '\n' && c != EOF);

        i++;
    }

    return i;
}





//== Bilal ==//
void afficher_tous_trajets(FILE *f) {
    for (int i = 0; i < MAX_BUS; i++){
        printf("------------------\n");
        printf(" Bus %d \n Depart: %s \n Arivee: %s\n", b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
        printf(" Date : %s\n", b[i].dateDepart);
        printf(" Horaire : %s - %s\n", b[i].horaireDepart, b[i].horaireArrivee);
        printf("------------------\n");
    }
}

//== Bilal ==// 
void afficher_selon_num(FILE *f) {
    int num;
    printf("Saisir numero de bus souhaite: ");
    scanf("%d", &num);

    for (int i = 0; i < MAX_BUS; i++) {
        printf("%d\n",b[i].numBus);
        if (b[i].numBus == num) {
            printf("------------------\n");
            printf("Bus %d\nDepart: %s\nArrivee: %s\n",
                   b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
            printf("Date : %s\n", b[i].dateDepart);
            printf("Horaire : %s - %s\n", b[i].horaireDepart, b[i].horaireArrivee);

            printf("Passagers:\n");
            for (int j = 0; j < MAX_PASSAGERS; j++) {
                if (b[i].p[j].id == 0) break; 
                printf("%d %s %.2f€\n",
                       b[i].p[j].id,
                       b[i].p[j].nom,
                       b[i].p[j].prixBillet);
            }
            printf("------------------\n");
            return; 
        }
    }

    printf("Pas de bus trouver avec ce num \n");
}
