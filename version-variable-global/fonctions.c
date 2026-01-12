#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "type.h" 

// ===== Définition du compteur global =====
long long C = 0;

Bus b[MAX_BUS];
Passager p[MAX_PASSAGERS];

//== Bilal ==// 
void implementation_struct(FILE *f) {
    char line[6000]; C++;
    int bus_index = 0; C++;

    while ((C++, fgets(line, sizeof(line), f) != NULL) && (C++, bus_index < MAX_BUS)) {
        int i = 0, j = 0, k = 0; C += 3;
        char temp[100]; C++;

        // ---- numBus ----
        k = 0; C++;
        while ((C++, line[i] != ',') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        b[bus_index].numBus = atoi(temp); C++;
        if (C++, line[i] == ','){ i++; C++; }

        // ---- villeDepart ----
        k = 0; C++;
        while ((C++, line[i] != ',') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        strcpy(b[bus_index].villeDepart, temp); C++;
        if (C++, line[i] == ','){ i++; C++; }

        // ---- villeArrivee ----
        k = 0; C++;
        while ((C++, line[i] != ',') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        strcpy(b[bus_index].villeArrivee, temp); C++;
        if (C++, line[i] == ','){ i++; C++; }

        // ---- dateDepart ----
        // jour
        k = 0; C++;
        while (C++, line[i] != '/'){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        b[bus_index].d.j = atoi(temp); C++;
        if(C++, line[i]=='/'){ i++; C++; }
        
        // mois
        k = 0; C++;
        while (C++, line[i] != '/'){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        b[bus_index].d.m = atoi(temp); C++;
        if(C++, line[i]=='/'){ i++; C++; }

        // annee
        k = 0; C++;
        while (C++, line[i] != ','){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        b[bus_index].d.a = atoi(temp); C++;
        if (C++, line[i] == ','){ i++; C++; }

        // ---- horaireDepart ----
        k = 0; C++;
        while ((C++, line[i] != ',') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        b[bus_index].horaireDepart = atoi(temp); C++;
        if (C++, line[i] == ','){ i++; C++; }

        // ---- horaireArrivee ----
        k = 0; C++;
        while ((C++, line[i] != ',') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
            temp[k++] = line[i++]; C += 2;
        }
        temp[k] = '\0'; C++;
        b[bus_index].horaireArrivee = atoi(temp); C++;
        if (C++, line[i] == ','){ i++; C++; }

        // ---- passagers ----
        int pass_index = 0; C++;
        while ((C++, line[i] != '\0') && (C++, line[i] != '\n') && (C++, pass_index < MAX_PASSAGERS)) {

            // id
            k = 0; C++;
            while ((C++, line[i] != ':') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
                temp[k++] = line[i++]; C += 2;
            }
            temp[k] = '\0'; C++;
            b[bus_index].p[pass_index].id = atoi(temp); C++;
            if (C++, line[i] == ':'){ i++; C++; }

            // nom
            k = 0; C++;
            while ((C++, line[i] != ':') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
                temp[k++] = line[i++]; C += 2;
            }
            temp[k] = '\0'; C++;
            strcpy(b[bus_index].p[pass_index].nom, temp); C++;
            if (C++, line[i] == ':'){ i++; C++; }

            // prix
            k = 0; C++;
            while ((C++, line[i] != ',') && (C++, line[i] != '\0') && (C++, line[i] != '\n')){
                temp[k++] = line[i++]; C += 2;
            }
            temp[k] = '\0'; C++;
            b[bus_index].p[pass_index].prixBillet = atof(temp); C++;

            pass_index++; C++;
            if (C++, line[i] == ','){ i++; C++; }
        }
        bus_index++; C++;
    }
}

//== Bilal ==//
void afficher_tous_trajets() {
    for (int i = 0; C++, i < MAX_BUS; i++){
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
void afficher_selon_num() {
    int num; C++;
    printf("Saisir numero de bus souhaite: ");
    scanf("%d", &num);

    for (int i = 0; C++, i < MAX_BUS; i++) {
        if (C++, b[i].numBus == num) {
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
                if (C++, b[i].p[j].id == 0) break; 
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
void trier_par_ville_et_date() {
    int cmp; C++;
    for (int i = 0; C++, i < MAX_BUS - 1; i++) {
        for (int j = 0; C++, j < MAX_BUS - i - 1; j++) {
            cmp = strcmp(b[j].villeDepart, b[j + 1].villeDepart); C++;
            if (C++, (cmp > 0 
                || b[j].d.a > b[j+1].d.a
                || b[j].d.a == b[j+1].d.a && b[j].d.m > b[j+1].d.m
                || b[j].d.a == b[j+1].d.a && b[j].d.m > b[j+1].d.m && b[j].d.j > b[j+1].d.j)) {
                Bus temp = b[j]; C++;
                b[j] = b[j + 1]; C++;
                b[j + 1] = temp; C++;
            }
        }
    }
}

//== Bilal ==//
void ajouter_passager() {
    int num; C++;
    printf("Numero du bus : ");
    scanf("%d", &num);

    for (int i = 0; C++, i < MAX_BUS; i++) {
        if (C++, b[i].numBus == num) {
            int j; C++;
            for (j = 0; C++, j < MAX_PASSAGERS; j++) {
                if (C++, b[i].p[j].id == 0) break;
            }
            if (C++, j == MAX_PASSAGERS) {
                printf("Bus complet !\n");
                return;
            }
            printf("ID : "); 
            scanf("%d", &b[i].p[j].id); C++;
            printf("Nom : "); 
            scanf(" %[^\n]", b[i].p[j].nom); C++;
            printf("Prix billet : "); 
            scanf("%f", &b[i].p[j].prixBillet); C++;
            printf("Passager ajoutee.\n");
            return;
        }
    }
    printf("Bus non trouvee\n");
}

//== Bilal ==//
void supprimer_passager() {
    int num, id; C += 2;
    printf("Numero du bus : ");
    scanf("%d", &num);
    printf("ID du passager à supprimer : ");
    scanf("%d", &id);

    for (int i = 0; C++, i < MAX_BUS; i++) {
        if (C++, b[i].numBus == num) {
            for (int j = 0; C++, j < MAX_PASSAGERS; j++) {
                if (C++, b[i].p[j].id == id) {
                    for (int k = j; C++, k < MAX_PASSAGERS - 1; k++) {
                        b[i].p[k] = b[i].p[k + 1]; C++;
                    }
                    b[i].p[MAX_PASSAGERS - 1].id = 0; C++;
                    b[i].p[MAX_PASSAGERS - 1].nom[0] = '\0'; C++;
                    b[i].p[MAX_PASSAGERS - 1].prixBillet = 0.0; C++;

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
    FILE *s = fopen("sauvegarde_trajet_bus.csv", "w"); C++;
    if (C++, s == NULL){
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; C++, i < MAX_BUS; i++){
        fprintf(s, "%d,%s,%s,%02d/%02d/%d,%04d,%04d",
                b[i].numBus,
                b[i].villeDepart,
                b[i].villeArrivee,
                b[i].d.j,
                b[i].d.m,
                b[i].d.a,
                b[i].horaireDepart,
                b[i].horaireArrivee);

        for (int j = 0; C++, j < MAX_PASSAGERS; j++){
            fprintf(s, ",%d;%s,%.2f",
                    b[i].p[j].id,
                    b[i].p[j].nom,
                    b[i].p[j].prixBillet);
        }
        fprintf(s, "\n");
    }
    fclose(s); C++;
}

//== Bilal ==//
void modif_nom_prix(){
    int id,num,choix; C += 3;
    float prix; C++;
    char nom[MAX_CARAC]; C++;

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
        for(int i=0; C++, i<MAX_BUS; i++){
            if (C++, b[i].numBus == num){
                for (int j = 0; C++, j < MAX_PASSAGERS; j++){
                    if (C++, b[i].p[j].id == id){
                        printf("Saisir le nom: ");
                        scanf("%s",nom); C++;
                        strcpy(b[i].p[j].nom, nom); C++;
                    }
                }
            }
        }
        break;
    
    case 2:
        for(int i=0; C++, i<MAX_BUS; i++){
            if (C++, b[i].numBus == num){
                for (int j = 0; C++, j < MAX_PASSAGERS; j++){
                    if (C++, b[i].p[j].id == id){
                        printf("Saisir le prix du billet: ");
                        scanf("%f",&prix); C++;
                        b[i].p[j].prixBillet = prix; C++;
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

//== Bilal ==//
void filtre_ville_date_lendemain(){
    char villedep[MAX_CARAC],date[MAX_CARAC]; C += 2;
    int horaire; C++;

    printf("Veuillez saisr la ville de depart: ");
    scanf("%s",villedep);

    for(int i=0; C++, i<MAX_BUS; i++){
        if(C++, strcmp(villedep,b[i].villeDepart) == 0 && b[i].horaireArrivee < b[i].horaireDepart){
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
}

//== Bilal ==//
void combiner_villedep_villearriv_datedep(){
    char villedep[MAX_CARAC];
    char villearriv[MAX_CARAC];
    int jour,mois,annee; C += 3;

    printf("Veuillez saisir la ville de depart: ");
    scanf("%s",villedep);
    printf("La ville d arriver: ");
    scanf("%s",villearriv);
    printf("L'annee:  ");
    scanf("%d",&annee);
    printf("Le mois:  ");
    scanf("%d",&mois);
    printf("Le jour:  ");
    scanf("%d",&jour);

    for(int i=0; C++, i<MAX_BUS; i++){
        if(C++, strcmp(villedep,b[i].villeDepart)== 0 
           && strcmp(villearriv,b[i].villeArrivee)==0 
           && jour == b[i].d.j 
           && mois == b[i].d.m 
           && annee == b[i].d.a ){
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
}

//== Bilal ==//
void ca_triee(){
    CA trajet[MAX_BUS]; C++;
    int somme_par_trajet; C++;

    for (int i=0; C++, i<MAX_BUS; i++){
        somme_par_trajet = 0; C++;
        for(int j=0; C++, j<MAX_PASSAGERS; j++){
            somme_par_trajet = somme_par_trajet + b[i].p[j].prixBillet; C++;
        }
        trajet[i].idbus = b[i].numBus; C++;
        trajet[i].chiffre_affaire = somme_par_trajet; C++;
    }

    for(int i=0; C++, i<MAX_BUS; i++){
        double tmp; C++;
        for (int j = 0; C++, j < MAX_BUS-i-1 ; j++){
            if(C++, trajet[j].chiffre_affaire > trajet[j+1].chiffre_affaire){
                tmp = trajet[j].chiffre_affaire; C++;
                trajet[j].chiffre_affaire = trajet[j+1].chiffre_affaire; C++;
                trajet[j+1].chiffre_affaire = tmp; C++;
            }
        } 
    }

    for(int i=0; C++, i<MAX_BUS; i++){
        printf("--------------\n");
        printf("Bus: %d \n",trajet[i].idbus);
        printf("CA: %.2lf eu\n", trajet[i].chiffre_affaire);
        printf("--------------\n");
    }
}
