#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" 


Bus b[MAX_BUS];
Passager p[MAX_PASSAGERS];

//== Bilal ==// //== IMPLEMENTATION NE FONCTIONNE PLUS JSP POURQUOI JVAIS TOUT CASSER ==//
void implementation_struct(FILE *f) {
    char line[2000];
    int bus_index = 0;

    while (fgets(line, sizeof(line), f) != NULL && bus_index < MAX_BUS) {
        int i = 0, j = 0, k = 0;
        char temp[50];

        // ---- numBus ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';
        b[bus_index].numBus = atoi(temp);
        if (line[i] == ',') i++;

        // ---- villeDepart ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';
        strcpy(b[bus_index].villeDepart, temp);
        if (line[i] == ',') i++;

        // ---- villeArrivee ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';
        strcpy(b[bus_index].villeArrivee, temp);
        if (line[i] == ',') i++;

        // ---- dateDepart ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';
        strcpy(b[bus_index].dateDepart, temp);
        if (line[i] == ',') i++;

        // ---- horaireDepart ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';
        strcpy(b[bus_index].horaireDepart, temp);
        if (line[i] == ',') i++;

        // ---- horaireArrivee ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';
        strcpy(b[bus_index].horaireArrivee, temp);
        if (line[i] == ',') i++;

        // ---- passagers ----
        int pass_index = 0;
        while (line[i] != '\0' && line[i] != '\n' && pass_index < MAX_PASSAGERS) {
            // id
            k = 0;
            while (line[i] != ':' && line[i] != '\0' && line[i] != '\n') temp[k++] = line[i++];
            temp[k] = '\0';
            b[bus_index].p[pass_index].id = atoi(temp);
            if (line[i] == ':') i++;

            // nom
            k = 0;
            while (line[i] != ':' && line[i] != '\0' && line[i] != '\n') temp[k++] = line[i++];
            temp[k] = '\0';
            strcpy(b[bus_index].p[pass_index].nom, temp);
            if (line[i] == ':') i++;

            // prix
            k = 0;
            while (line[i] != ',' && line[i] != '\0' && line[i] != '\n') temp[k++] = line[i++];
            temp[k] = '\0';
            b[bus_index].p[pass_index].prixBillet = atof(temp);

            pass_index++;
            if (line[i] == ',') i++;
        }

        bus_index++;
    }
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
        if (b[i].numBus == num) {
            printf("------------------\n");
            printf("Bus %d\nDepart: %s\nArrivee: %s\n",
                   b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
            printf("Date : %s\n", b[i].dateDepart);
            printf("Horaire : %s - %s\n", b[i].horaireDepart, b[i].horaireArrivee);
            printf("--------------\n");
            printf("Passagers:\n");
            for (int j = 0; j < MAX_PASSAGERS; j++) {
                if (b[i].p[j].id == 0) break; 
                printf("%d %s %.2f eu\n",
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
