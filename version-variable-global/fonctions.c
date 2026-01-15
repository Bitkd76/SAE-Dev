#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" 


Bus b[MAX_BUS];
Passager p[MAX_PASSAGERS];

long long C = 0;

//== Bilal ==// 
void implementation_struct(FILE *f) {
    char line[6000];
    int bus_index = 0;

    while (fgets(line, sizeof(line), f) != NULL && bus_index < MAX_BUS) {
        int i = 0, k = 0;
        char temp[100];

        // ---- numBus ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].numBus = -1;
        else
            b[bus_index].numBus = atoi(temp);

        if (line[i] == ',') i++;

        // ---- villeDepart ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].villeDepart[0] = '\0';
        else
            strcpy(b[bus_index].villeDepart, temp);

        if (line[i] == ',') i++;

        // ---- villeArrivee ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].villeArrivee[0] = '\0';
        else
            strcpy(b[bus_index].villeArrivee, temp);

        if (line[i] == ',') i++;

        // ---- dateDepart : jour ----
        k = 0;
        while (line[i] != '/' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].d.j = -1;
        else
            b[bus_index].d.j = atoi(temp);

        if (line[i] == '/') i++;

        // ---- dateDepart : mois ----
        k = 0;
        while (line[i] != '/' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].d.m = -1;
        else
            b[bus_index].d.m = atoi(temp);

        if (line[i] == '/') i++;

        // ---- dateDepart : annee ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].d.a = -1;
        else
            b[bus_index].d.a = atoi(temp);

        if (line[i] == ',') i++;

        // ---- horaireDepart ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].horaireDepart = -1;
        else
            b[bus_index].horaireDepart = atoi(temp);

        if (line[i] == ',') i++;

        // ---- horaireArrivee ----
        k = 0;
        while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
            temp[k++] = line[i++];
        temp[k] = '\0';

        if (strlen(temp) == 0)
            b[bus_index].horaireArrivee = -1;
        else
            b[bus_index].horaireArrivee = atoi(temp);

        if (line[i] == ',') i++;

        // ---- passagers ----
        int pass_index = 0;
        while (line[i] != '\0' && line[i] != '\n' && pass_index < MAX_PASSAGERS) {

            // ---- id ----
            k = 0;
            while (line[i] != ':' && line[i] != '\0' && line[i] != '\n')
                temp[k++] = line[i++];
            temp[k] = '\0';

            if (strlen(temp) == 0)
                b[bus_index].p[pass_index].id = -1;
            else
                b[bus_index].p[pass_index].id = atoi(temp);

            if (line[i] == ':') i++;

            // ---- nom ----
            k = 0;
            while (line[i] != ':' && line[i] != '\0' && line[i] != '\n')
                temp[k++] = line[i++];
            temp[k] = '\0';

            if (strlen(temp) == 0)
                b[bus_index].p[pass_index].nom[0] = '\0';
            else
                strcpy(b[bus_index].p[pass_index].nom, temp);

            if (line[i] == ':') i++;

            // ---- prix ----
            k = 0;
            while (line[i] != ',' && line[i] != '\0' && line[i] != '\n')
                temp[k++] = line[i++];
            temp[k] = '\0';

            if (strlen(temp) == 0)
                b[bus_index].p[pass_index].prixBillet = -1.0;
            else
                b[bus_index].p[pass_index].prixBillet = atof(temp);

            pass_index++;
            if (line[i] == ',') i++;
        }

        bus_index++;
    }
}


//== Bilal ==//
void afficher_tous_trajets() {
    for (int i = 0; i < MAX_BUS; i++){
        printf("------------------\n");
        printf(" Bus %d \n Depart: %s \n Arivee: %s\n", b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
        printf(" Date : %02d/%02d/%d\n", b[i].d.j,b[i].d.m,b[i].d.a);
            printf(" Horaire : %02d:%02d - %02d:%02d\n", 
                b[i].horaireDepart/100,b[i].horaireDepart%100, 
                b[i].horaireArrivee/100,b[i].horaireArrivee%100
            );
        printf("------------------\n");
    }
}

//== Bilal ==// 
// aurait du faire une recherche dichotomique mais manque de temps ! 
// Fonction avec variable global !-----------------------------------------------------------------------------------------------------------
void afficher_selon_num() {
    int num; 
    C = 0; 

    printf("Saisir numero de bus souhaite: ");
    scanf("%d", &num);
    
    for (int i = 0; i < MAX_BUS; i++) {
        C++;
        if ( b[i].numBus == num) {
            C++;
            printf("------------------\n");
            printf("Bus %d\nDepart: %s\nArrivee: %s\n",
                   b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
            printf(" Date : %02d/%02d/%d\n", b[i].d.j,b[i].d.m,b[i].d.a);
            printf(" Horaire : %02d:%02d - %02d:%02d\n", 
                b[i].horaireDepart/100,b[i].horaireDepart%100, 
                b[i].horaireArrivee/100,b[i].horaireArrivee%100
            );
            printf("--------------\n");
            printf("Passagers:\n");
            for (int j = 0; C++, j < MAX_PASSAGERS; j++) {
                C++;
                if (C++, b[i].p[j].id == 0) break; 
                printf("%d %s %.2f eu\n",
                       b[i].p[j].id,
                       b[i].p[j].nom,
                       b[i].p[j].prixBillet);
            }
            printf("------------------\n");
            printf("\nNombre d'operation: %lld\n",C);
            return; 
        }
    }
    printf("Pas de bus trouver avec ce num \n");
    printf("\nNombre d'operation: %lld\n",C);
}


//== Bilal ==//
// Fonction avec variable global !-----------------------------------------------------------------------------------------------------------
void trier_par_ville_et_date() {
    int cmp;
    C = 0;

    for (int i = 0; i < MAX_BUS - 1; i++) {
        C++;

        for (int j = 0; j < MAX_BUS - i - 1; j++) {
            C++;

            cmp = strcmp(b[j].villeDepart, b[j + 1].villeDepart);
            C++;

            C++;
            C++;
            C++; 
            C++; 
            C++;

            if (cmp > 0 
                || b[j].d.a > b[j+1].d.a
                || (b[j].d.a == b[j+1].d.a && b[j].d.m > b[j+1].d.m)
                || (b[j].d.a == b[j+1].d.a && b[j].d.m == b[j+1].d.m && b[j].d.j > b[j+1].d.j)) 
            {
                Bus temp = b[j]; C++;
                b[j] = b[j + 1]; C++;
                b[j + 1] = temp; C++;
            }
        }
    }

    printf("\nNombre d'operation: %lld\n", C);
}




//== Bilal ==//
// Fonction avec variable global !-----------------------------------------------------------------------------------------------------------
void filtre_ville_date_lendemain(){
    C = 0;

    char villedep[MAX_CARAC];
    int j, m, a;

    printf("Veuillez saisir la ville de depart: ");
    scanf("%s", villedep);
    printf("Veuillez saisir la date de depart sous format JJ MM AAAA : ");
    scanf("%d %d %d", &j, &m, &a);

    for(int i = 0; i < MAX_BUS; i++){
        C++;

        C++; 
        C++;
        C++;
        C++;
        C++; 
        C++;
        C++; 

        if (strcmp(villedep, b[i].villeDepart) == 0 
            && j == b[i].d.j && m == b[i].d.m && a == b[i].d.a
            && b[i].horaireArrivee < b[i].horaireDepart 
            && b[i].horaireDepart >= 0 && b[i].horaireArrivee >= 0)
        {
            printf("------------------\n");
            printf(" Bus %d\n Depart: %s\n Arrivee: %s\n",
                   b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
            printf(" Date : %02d/%02d/%d\n", b[i].d.j,b[i].d.m,b[i].d.a);
            printf(" Horaire : %02d:%02d - %02d:%02d\n", 
                    b[i].horaireDepart/100,b[i].horaireDepart%100, 
                    b[i].horaireArrivee/100,b[i].horaireArrivee%100
            );
            printf("--------------\n");
        }
    }
    printf("\nNombre d'operation: %lld\n", C);
}


