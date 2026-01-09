#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" 


Bus b[MAX_BUS];
Passager p[MAX_PASSAGERS];

//== Bilal ==// 
void implementation_struct(FILE *f) {
    char line[6000];
    int bus_index = 0;

    while (fgets(line, sizeof(line), f) != NULL && bus_index < MAX_BUS) {
        int i = 0, j = 0, k = 0;
        char temp[100];

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
        while (line[i] != '/')
            temp[k++] = line[i++];
        temp[k] = '\0';
        b[bus_index].d.j = atoi(temp);
        k = 0;
        while (line[i] != '/')
            temp[k++] = line[i++];
        temp[k] = '\0';
        b[bus_index].d.m = atoi(temp);
        k = 0;
        while (line[i] != '/')
            temp[k++] = line[i++];
        temp[k] = '\0';
        b[bus_index].d.a = atoi(temp);
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
        printf(" Date : %d/%d/%d\n", b[i].d.j,b[i].d.m,b[i].d.a);
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
            printf(" Date : %d/%d/%d\n", b[i].d.j,b[i].d.m,b[i].d.a);
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
    int cmp;
    for (int i = 0; i < MAX_BUS - 1; i++) {
        for (int j = 0; j < MAX_BUS - i - 1; j++) {
            cmp = strcmp(b[j].villeDepart, b[j + 1].villeDepart);
            if (cmp > 0 
                || b[j].d.a > b[j+1].d.a // annee bus j sup a annee bus j+1
                || b[j].d.a == b[j+1].d.a && b[j].d.m > b[j+1].d.m // annee pareil mais mois diff
                || b[j].d.a == b[j+1].d.a && b[j].d.m > b[j+1].d.m && b[j].d.j > b[j+1].d.j // annee & mois apreil mais j diff
            ) {
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
        fprintf(s, "%d,%s,%s,%d/%d/%d,%s,%s",
                b[i].numBus,
                b[i].villeDepart,
                b[i].villeArrivee,
                b[i].d.j,
                b[i].d.m,
                b[i].d.a,
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

//== Bilal ==//
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
// a faire si le temps le permet 
//== Bilal ==//
void filtre_ville_date_lendemain(FILE *f){
    char villedep[MAX_CARAC];
    char date[MAX_CARAC];
    printf("Veuillez saisr la ville de depart: ");
    scanf("%s",villedep);
    printf("La date de depart: ");
    scanf("%s",date);
    /*
    for(int i=0; i<MAX_BUS;i++){
        if(villedep == b[i].villeDepart && ) // ajout de condition arriver le lendemain mais a cause de la structure de mes date il est impossible 
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
            printf(" Date : %d/%d/%d\n", b[i].d.j,b[i].d.m,b[i].d.a);
            printf(" Horaire : %s - %s\n", b[i].horaireDepart, b[i].horaireArrivee);
            printf("------------------\n");
        }
    }
}

//== Bilal ==//
void ca_triee(FILE *f){
    CA trajet[MAX_BUS];
    int somme_par_trajet;
    for (int i=0; i<MAX_BUS; i++){
        somme_par_trajet = 0;
        for(int j=0;j<MAX_PASSAGERS;j++){
            somme_par_trajet = somme_par_trajet + b[i].p[j].prixBillet;
        }
        trajet[i].idbus = b[i].numBus;
        trajet[i].chiffre_affaire= somme_par_trajet;
    }
    for(int i=0; i<MAX_BUS;i++){
        double tmp;
        for (int j = 0; j < MAX_BUS - i - 1; j++)
        {
            if(trajet[j].chiffre_affaire > trajet[j+1].chiffre_affaire){
                tmp = trajet[j].chiffre_affaire;
                trajet[j].chiffre_affaire = trajet[j+1].chiffre_affaire;
                trajet[j+1].chiffre_affaire = tmp;
            }
        } 
    }
    for(int i=0; i<MAX_BUS;i++){
        printf("--------------\n");
        printf("Bus: %d \n",trajet[i].idbus);
        printf("CA: %.2lf eu\n", trajet[i].chiffre_affaire);
        printf("--------------\n");
    }

}