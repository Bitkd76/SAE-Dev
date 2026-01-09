#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" 


//== faudrais commenter le tout pour mieux retenir chaque fonction faites ==//

Bus b[MAX_BUS];
Passager p[MAX_PASSAGERS];

//== Bilal ==// 
void implementation_struct(FILE *f) {
    char line[6000];
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


//== Bilal ==//
void trier_par_ville_et_date(FILE *f) {
    for (int i = 0; i < MAX_BUS - 1; i++) {
        for (int j = 0; j < MAX_BUS - i - 1; j++) {
            int cmp = strcmp(b[j].villeDepart, b[j + 1].villeDepart);
            if (cmp > 0 || (cmp == 0 && strcmp(b[j].dateDepart, b[j + 1].dateDepart) > 0)) {
                Bus temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}


//== Bilal ==//
void ajouter_passager(FILE *f) {
    int num;
    printf("Numero du bus : ");
    scanf("%d", &num);

    for (int i = 0; i < MAX_BUS; i++) {
        if (b[i].numBus == num) {
            int j;
            for (j = 0; j < MAX_PASSAGERS; j++) {
                if (b[i].p[j].id == 0) break;
            }

            if (j == MAX_PASSAGERS) {
                printf("Bus complet !\n");
                return;
            }

            printf("ID : "); 
                scanf("%d", &b[i].p[j].id);
            printf("Nom : "); 
                scanf(" %[^\n]", b[i].p[j].nom); // %[^\n] pour tout caractere exmpl: Jean Simon si %s arret a Jean /!\ //
            printf("Prix billet : "); 
                scanf("%f", &b[i].p[j].prixBillet);

            printf("Passager ajoutee.\n");
            return;
        }
    }
    printf("Bus non trouvee\n");
}

//== Bilal ==//
void supprimer_passager(FILE *f) {
    int num, id;
    printf("Numero du bus : ");
    scanf("%d", &num);
    printf("ID du passager à supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < MAX_BUS; i++) {
        if (b[i].numBus == num) {
            for (int j = 0; j < MAX_PASSAGERS; j++) {
                if (b[i].p[j].id == id) {
                    for (int k = j; k < MAX_PASSAGERS - 1; k++) {
                        b[i].p[k] = b[i].p[k + 1];
                    }
                    b[i].p[MAX_PASSAGERS - 1].id = 0;
                    b[i].p[MAX_PASSAGERS - 1].nom[0] = '\0';
                    b[i].p[MAX_PASSAGERS - 1].prixBillet = 0.0;

                    printf("Passager supprime.\n");
                    return;
                }
            }
            printf("Passager Non trouvee !\n");
            return;
        }
    }
    printf("Bus non trouvee !\n");
}

//== Bilal ==//
void maj_nv_fichier(void){
    FILE *s = fopen("sauvegarde_trajet_bus.csv", "w");
    if (s == NULL){
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < MAX_BUS; i++){
        fprintf(s, "%d,%s,%s,%s,%s,%s",
                b[i].numBus,
                b[i].villeDepart,
                b[i].villeArrivee,
                b[i].dateDepart,
                b[i].horaireDepart,
                b[i].horaireArrivee);

        for (int j = 0; j < MAX_PASSAGERS; j++){
            fprintf(s, ",%d;%s,%.2f",
                    b[i].p[j].id,
                    b[i].p[j].nom,
                    b[i].p[j].prixBillet);
        }
        fprintf(s, "\n");
    }

    fclose(s);
}


void modif_nom_prix(FILE *f){
    int id,num,choix;
    float prix;
    char nom[MAX_CARAC];
    printf("Veuillez saisir le numero du bus: ");
    scanf("%d",&num);
    printf("Veuillez saisir l'id du client: ");
    scanf("%d",&id);
    printf("1 - Modification/Ajout du nom\n");
    printf("2 - Modification du prix du billet\n");
    printf("Choix: ");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        for(int i=0;i<MAX_BUS;i++){
            if (b[i].numBus == num){
                for (int j = 0; j < MAX_PASSAGERS; j++){
                    if (b[i].p[j].id == id){
                        printf("Saisir le nom: ");
                        scanf("%s",&nom);
                        strcpy(b[i].p[j].nom, nom);
                    }
                }
            }
        }
        break;
    
    case 2:
        for(int i=0;i<MAX_BUS;i++){
            if (b[i].numBus == num){
                for (int j = 0; j < MAX_PASSAGERS; j++){
                    if (b[i].p[j].id == id){
                        printf("Saisir le prix du billet: ");
                        scanf("%f",&prix);
                        b[i].p[j].prixBillet = prix;
                    }
                }
            }
        }
        break;
    default:
        printf("Choix invalide\n");
        break;
    }
}

// fonction de la 7 mais pas possible avec les strcut que j'ai mis en place pour l'instant car on peut pas checker 2 date diff
void filtre_ville_date_lendemain(FILE *f){
    char villedep[MAX_CARAC];
    char date[MAX_CARAC];
    printf("Veuillez saisr la ville de depart: ");
    scanf("%s",villedep);
    printf("La date de depart: ");
    scanf("%s",date);
    /*
    for(int i=0; i<MAX_BUS;i++){
        if(villedep == b[i].villeDepart && ) // ajout de condition arriver le lendemain mais a cause de la structure de mes date il est impossible ( du moin je pense donc il vas falloir faire comme les passager mais il faut reaminer la date pour la mettre dans un struct apprt et donc ajuster affichage et utilisation des autre code 
    }
    */
}


//== Bilal ==//
void combiner_villedep_villearriv_datedep(FILE *f){
    char villedep[MAX_CARAC];
    char villearriv[MAX_CARAC];
    char date[MAX_CARAC];
    printf("Veuillez saisir la ville de depart: ");
    scanf("%s",villedep);
    printf("La ville d arriver: ");
    scanf("%s",villearriv);
    printf("La date de depart: ");
    scanf("%s",date);
    for(int i=0; i<MAX_BUS;i++){
        if(strcmp(villedep,b[i].villeDepart)== 0 && strcmp(villearriv,b[i].villeArrivee)==0 && strcmp(date,b[i].dateDepart)==0){
            printf("------------------\n");
            printf(" Bus %d \n Depart: %s \n Arivee: %s\n", b[i].numBus, b[i].villeDepart, b[i].villeArrivee);
            printf(" Date : %s\n", b[i].dateDepart);
            printf(" Horaire : %s - %s\n", b[i].horaireDepart, b[i].horaireArrivee);
            printf("------------------\n");
        }
    }
}