#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date { int jour; int mois; int annee;}date;

char nom_etudiant[1000], prenom_etudiant[1000];

typedef enum Departement {
MATHEMATIQUES,
PHYSIQUE,
CHIMIE,
BIOLOGIE,
GEOLOGIE,
INFORMATIQUE}Departement;

struct etudiant {
int id;
char nom[100];
char prenom[100];
date date_de_naissance;
Departement departement;
float Note_generale;};

int i,e=10,c,p=11,et,o;
float seuil;


struct etudiant etudiants[1000] = {

    {1, "Amrani", "Youssef", {5, 7, 1998}, INFORMATIQUE, 15.75},
    {2, "Benali", "Fatima", {12, 3, 1999}, MATHEMATIQUES, 18.50},
    {3, "Chakir", "Mohammed", {20, 11, 1997}, PHYSIQUE, 12.25},
    {4, "Doukkali", "Laila", {8, 9, 2000}, CHIMIE, 9.75},
    {5, "El Fassi", "Karim", {15, 1, 1998}, BIOLOGIE, 14.00},
    {6, "Fathi", "Amina", {3, 6, 1999}, GEOLOGIE, 16.50},
    {7, "Ghali", "Omar", {25, 4, 1997}, INFORMATIQUE, 11.25},
    {8, "Hassani", "Nadia", {10, 8, 2000}, MATHEMATIQUES, 19.75},
    {9, "Idrissi", "Rachid", {18, 2, 1998}, PHYSIQUE, 13.50},
    {10, "Jilali", "Sanaa", {30, 10, 1999}, CHIMIE, 8.25}
}; 

int rechercher_par_id(int identifiant) {
for (int x = 0; x < e; x++) {
if (etudiants[x].id == identifiant) {
          return x;
			        }
				    }
				        return -1; 
					}			
						
void tri_etudiants_par_note(struct etudiant etd[], struct etudiant etd_tries[]) {

    for (int g = 0; g < e; g++) {
        etd_tries[g] = etd[g];
    }
    
    
    for (int m = 0; m < e - 1; m++) {
        for (int l = 0; l < e - m - 1; l++) {
            if (etd_tries[l].Note_generale < etd_tries[l + 1].Note_generale) {
                struct etudiant temp = etd_tries[l];
                etd_tries[l] = etd_tries[l + 1];
                etd_tries[l + 1] = temp;
            }
        }
    }		}
    
    void tri_etudiants_par_moyenne(struct etudiant etd[], int ordre) {
    for (int iters = 0; iters < e - 1; iters++) {
        for (int its = 0; its < e - iters - 1; its++) {
            if ((ordre == 1 && etd[its].Note_generale < etd[its + 1].Note_generale) ||
                (ordre == 2 && etd[its].Note_generale > etd[its + 1].Note_generale)) {
                struct etudiant tamp = etd[its];
                etd[its] = etd[its + 1];
                etd[its + 1] = tamp;
            }
        }
    }
}


					
					
int main() {


while(1) {

printf("Que voulez-vous faire?\n");
printf("1. Ajouter un etudiant\n");
printf("2. Modifier ou supprimer un etudiant\n");
printf("3. Afficher les details des etudiants\n");
printf("4. Calculer la moyenne generale\n");
printf("5. Consulter les statistiques\n");
printf("6. Rechercher un etudiant\n");    
printf("7. Trier les etudiants\n");
printf("Tapez n'importe quel autre numero pour quitter\n");
scanf("%d",&i);

switch(i) {

case 1: 

etudiants[e].id = p;

printf("Veuillez saisir le nom de l'etudiant\n");
scanf("%s",etudiants[e].nom);
printf("Veuillez saisir le prenom de l'etudiant\n");
scanf("%s",etudiants[e].prenom);
printf("Veuillez saisir la date de naissance de l'etudiant\n");
printf("Veuillez saisir le jour: ");
scanf("%d",&etudiants[e].date_de_naissance.jour);
printf("\nVeuillez saisir le mois: ");
scanf("%d",&etudiants[e].date_de_naissance.mois);
printf("\nVeuillez saisir l'annee: ");
scanf("%d",&etudiants[e].date_de_naissance.annee);
printf("Veuillez choisir le deparement de l'etudiant\n");
printf("0. Mathematiques\n");
printf("1. Physique\n");
printf("2. Chimie\n");
printf("3. Biologie\n");
printf("4. Geologie\n");
printf("5. Informatique\n");
scanf("%d",&etudiants[e].departement);
printf("Veuillez saisir la note generale de l'etudiant\n");
scanf("%f",&etudiants[e].Note_generale);
e++;
p++;
break;

case 2:

printf("Veuillez saisir l'identifiant unique de l'etudiant\n");
scanf("%d",&et);
int etud = rechercher_par_id(et);
printf("Vous voulez...\n");
printf("1. Modifiez cet etudiant\n");
printf("2. Supprimer cet etudiant\n");
scanf("%d",&c);
if (c == 1){
printf("Veuillez saisir le nouveau nom de l'etudiant\n");
scanf("%s",etudiants[etud].nom);
printf("Veuillez saisir le nouveau prenom de l'etudiant\n");
scanf("%s",etudiants[etud].prenom);
printf("Veuillez saisir la nouvelle date de naissance de l'etudiant\n");
printf("Veuillez saisir le jour: ");
scanf("%d",&etudiants[etud].date_de_naissance.jour);
printf("\nVeuillez saisir le mois: ");
scanf("%d",&etudiants[etud].date_de_naissance.mois);
printf("\nVeuillez saisir l'annee: \n");
scanf("%d",&etudiants[etud].date_de_naissance.annee);
printf("Veuillez choisir le nouveau deparement de l'etudiant\n");
printf("0. Mathematiques\n");
printf("1. Physique\n");
printf("2. Chimie\n");
printf("3. Biologie\n");
printf("4. Geologie\n");
printf("5. Informatique\n");
scanf("%d",&etudiants[etud].departement);
printf("Veuillez saisir la nouvelle note generale de l'etudiant\n");
scanf("%f",&etudiants[etud].Note_generale);
}
else if (c == 2){

for (int t=etud;t<e-1;t++)
{
 etudiants[t] = etudiants [t+1];
}
e--;
}
else {printf("erreur, valeur, non valide.");}
break;
case 3:
    printf("Liste des etudiants:\n");
    for (int x = 0; x < e; x++) {
        printf("Etudiant %d:\n", etudiants[x].id);
        printf("Nom: %s\n", etudiants[x].nom);
        printf("Prenom: %s\n", etudiants[x].prenom);
        printf("Date de naissance: %d/%d/%d\n", etudiants[x].date_de_naissance.jour, etudiants[x].date_de_naissance.mois, etudiants[x].date_de_naissance.annee);
        printf("Departement: ");
        switch (etudiants[x].departement) {
            case MATHEMATIQUES:
                printf("Mathematiques\n");
                break;
            case PHYSIQUE:
                printf("Physique\n");
                break;
            case CHIMIE:
                printf("Chimie\n");
                break;
            case BIOLOGIE:
                printf("Biologie\n");
                break;
            case GEOLOGIE:
                printf("Geologie\n");
                break;
            case INFORMATIQUE:
                printf("Informatique\n");
                break;
        }
        printf("Note generale: %f\n\n", etudiants[x].Note_generale);
    }
    break;
case 4:
    printf("Les moyennes generales:\n");
    float somme_notes[6] = {0, 0, 0, 0, 0, 0}; 
    int nb_etudiants[6] = {0, 0, 0, 0, 0, 0}; 
    float somme_notes_totale = 0; 
    int nb_etudiants_total = 0;

    for (int h = 0; h < e; h++) {
        somme_notes_totale += etudiants[h].Note_generale;
        nb_etudiants_total++;

        somme_notes[etudiants[h].departement] += etudiants[h].Note_generale;
        nb_etudiants[etudiants[h].departement]++;
    }

    if (nb_etudiants_total == 0) {
        printf("La moyenne generale de l'universite est : Impossible de calculer (aucun etudiant)\n");
    } else {
        printf("La moyenne generale de l'universite est : %.2f\n", (float)somme_notes_totale / nb_etudiants_total);
    }

    char dept_names[6][100] = {"Mathematiques", "Physique", "Chimie", "Biologie", "Geologie", "Informatique"};

    for (int y = 0; y < 6; y++) {
        printf("La moyenne generale du departement de %s est : ", dept_names[y]);
        if (nb_etudiants[y] == 0) {
            printf("Impossible de calculer (aucun etudiant)\n");
        } else {
            printf("%.2f\n", (float)somme_notes[y] / nb_etudiants[y]);
        }
    }
    printf("\n");
    break;
case 5:   
printf("Vous voulez...\n");
printf("1. Afficher le nombre total d'etudiants\n");
printf("2. Afficher le nombre d'etudiants dans chaque departement\n");
printf("3. Afficher les etudiants ayant une moyenne generale superieure a un seuil choisi\n");
printf("4. Afficher les 3 etudiants ayant les meilleures notes\n"); 
printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");

scanf("%d",&o);

switch (o)
{
case 1:
printf("Le nombre total d'etudiants inscrits est: %d",e);
break;
case 2:
printf("le nombre d'etudiants dans chaque departement: \n\n");
int nb_etudiants_par_departement[6] = {0, 0, 0, 0, 0, 0};

for (int student_index = 0; student_index < e; student_index++) {
nb_etudiants_par_departement[etudiants[student_index].departement]++;
    }

for (int dept_index = 0; dept_index < 6; dept_index++) {
printf("%s : %d\n", dept_names[dept_index], nb_etudiants_par_departement[dept_index]);
}
break;
case 3:
printf("Veuillez saisir le seuil\n");
    scanf("%f",&seuil);
    printf("Les etudiants ayant une moyenne generale superieure a %.2f sont:\n", seuil);
    for (int element = 0; element < e; element ++) {
        if (etudiants[element].Note_generale > seuil) {
            printf("Etudiant %d:\n", etudiants[element].id);
            printf("Nom: %s\n", etudiants[element].nom);
            printf("Prenom: %s\n", etudiants[element].prenom);
            printf("Date de naissance: %d/%d/%d\n", etudiants[element].date_de_naissance.jour, etudiants[element].date_de_naissance.mois, etudiants[element].date_de_naissance.annee);
            printf("Departement: ");
            switch (etudiants[element].departement) {
                case MATHEMATIQUES:
                    printf("Mathematiques\n");
                    break;
                case PHYSIQUE:
                    printf("Physique\n");
                    break;
                case CHIMIE:
                    printf("Chimie\n");
                    break;
                case BIOLOGIE:
                    printf("Biologie\n");
                    break;
                case GEOLOGIE:
                    printf("Geologie\n");
                    break;
                case INFORMATIQUE:
                    printf("Informatique\n");
                    break;
            }
            printf("Note generale: %f\n\n", etudiants[element].Note_generale);
        }
    }
    break;
case 4:
	printf("Les 3 etudiants ayant les meilleures notes sont:\n\n");
    
    struct etudiant etudiants_tries[1000];
    
    tri_etudiants_par_note(etudiants, etudiants_tries);

    int num_to_display = (e < 3) ? e : 3;
    for (int i = 0; i < num_to_display; i++) {
        printf("%d. Etudiant %d:\n", i + 1, etudiants_tries[i].id);
        printf("   Nom: %s\n", etudiants_tries[i].nom);
        printf("   Prenom: %s\n", etudiants_tries[i].prenom);
        printf("   Note generale: %f\n\n", etudiants_tries[i].Note_generale);
    }
    break;


case 5:
printf("Nombre d'etudiants ayant reussi dans chaque departement:\n\n");
char dept_names[6][100] = {"Mathematiques", "Physique", "Chimie", "Biologie", "Geologie", "Informatique"};

int nb_reussis_par_departement[6] = {0, 0, 0, 0, 0, 0};

for (int v = 0; v < e; v++) {
    if (etudiants[v].Note_generale >= 10) {
        nb_reussis_par_departement[etudiants[v].departement]++;
    }
}

for (int w = 0; w < 6; w++) {
    printf("%s : %d\n", dept_names[w], nb_reussis_par_departement[w]);
}

break;
}
break;
case 6: 
printf("Vous voulez...\n");
int vl;
printf("1. Rechercher un etudiant par son nom\n");
printf("2. Afficher la liste des etudiants inscrits dans un departement specifique\n");
scanf("%d",&vl);
if ( vl == 1) {

printf("Veuillez saisir le prenom de l'etudiant ");
scanf("%s", prenom_etudiant);
printf("Veuillez saisie le nom de l'etudiant ");
scanf("%s", nom_etudiant);
for (int st = 0; st < e; st++) {
if (strcmp(etudiants[st].nom, nom_etudiant) == 0 && strcmp(etudiants[st].prenom, prenom_etudiant) == 0) {
            printf("Etudiant %d:\n", etudiants[st].id);
            printf("Nom: %s\n", etudiants[st].nom);
            printf("Prenom: %s\n", etudiants[st].prenom);
            printf("Date de naissance: %d/%d/%d\n", etudiants[st].date_de_naissance.jour, etudiants[st].date_de_naissance.mois, etudiants[st].date_de_naissance.annee);
            printf("Departement: ");
            switch (etudiants[st].departement) {
                case MATHEMATIQUES:
                    printf("Mathematiques\n");
                    break;
                case PHYSIQUE:
                    printf("Physique\n");
                    break;
                case CHIMIE:
                    printf("Chimie\n");
                    break;
                case BIOLOGIE:
                    printf("Biologie\n");
                    break;
                case GEOLOGIE:
                    printf("Geologie\n");
                    break;
                case INFORMATIQUE:
                    printf("Informatique\n");
                    break;
            }
            printf("Note generale: %f\n\n", etudiants[st].Note_generale);
}}}

else if (vl == 2)
{
 int dept_choisi;
 char dept_names[6][100] = {"Mathematiques", "Physique", "Chimie", "Biologie", "Geologie", "Informatique"};
        printf("Choisissez le departement:\n");
        printf("0. Mathematiques\n");
        printf("1. Physique\n");
        printf("2. Chimie\n");
        printf("3. Biologie\n");
        printf("4. Geologie\n");
        printf("5. Informatique\n");
        scanf("%d", &dept_choisi);

        printf("Liste des etudiants inscrits en %s:\n", dept_names[dept_choisi]);
        int etudiants_trouves = 0;
        for (int tr = 0; tr < e; tr++) {
            if (etudiants[tr].departement == dept_choisi) {
                printf("Etudiant %d:\n", etudiants[tr].id);
                printf("Nom: %s\n", etudiants[tr].nom);
                printf("Prenom: %s\n", etudiants[tr].prenom);
                printf("Date de naissance: %d/%d/%d\n", etudiants[tr].date_de_naissance.jour, etudiants[tr].date_de_naissance.mois, etudiants[tr].date_de_naissance.annee);
                printf("Departement: ");
                switch (etudiants[tr].departement) {
                    case MATHEMATIQUES:
                        printf("Mathematiques\n");
                        break;
                    case PHYSIQUE:
                        printf("Physique\n");
                        break;
                    case CHIMIE:
                        printf("Chimie\n");
                        break;
                    case BIOLOGIE:
                        printf("Biologie\n");
                        break;
                    case GEOLOGIE:
                        printf("Geologie\n");
                        break;
                    case INFORMATIQUE:
                        printf("Informatique\n");
                        break;
                }
                printf("Note generale: %f\n\n", etudiants[tr].Note_generale);
                etudiants_trouves++;
            }
        }
        if (etudiants_trouves == 0) {
            printf("Aucun etudiant dans ce departement.\n");
        }
    }
    break;	
case 7:
	printf("Vous voulez...\n");
		int hc;
	printf("1. Trier les etudiants alphabetiquement en fonction de leur nom\n");
	printf("2. Trier les etudiants par moyenne generale\n");
	printf("3. Trier les etudiants selon leur statut de reussite\n");
	scanf("%d",&hc);
	if (hc == 1)
{
	printf("Afficher les etudiants par ordre alphabetique:\n");
printf("1. Ordre croissant (A-Z)\n");
printf("2. Ordre decroissant (Z-A)\n");
int ordre;
scanf("%d", &ordre);

if (ordre == 1 || ordre == 2) {
    
    for (int it = 0; it < e - 1; it++) {
        for (int iter = 0; iter < e - it - 1; iter++) {
            int comp = strcmp(etudiants[iter].nom, etudiants[iter].nom);
            if (comp == 0) {
                comp = strcmp(etudiants[iter].prenom, etudiants[iter+1].prenom);
            }
            if (comp > 0) {
                
                struct etudiant buff = etudiants[iter];
                etudiants[iter] = etudiants[iter+1];
                etudiants[iter+1] = buff;
            }
        }
    }

    
    if (ordre == 2) {
          for (int ite = 0; ite < e / 2; ite++) {
            struct etudiant tp = etudiants[ite];
            etudiants[ite] = etudiants[e - 1 - ite];
            etudiants[e - 1 - ite] = tp;
        }
    }

    
    printf("Liste des etudiants par ordre alphabetique %s:\n\n", 
           ordre == 1 ? "croissant (A-Z)" : "decroissant (Z-A)");
    for (int ord = 0; ord < e; ord++) {
        printf("Etudiant %d:\n", etudiants[ord].id);
        printf("Nom: %s\n", etudiants[ord].nom);
        printf("Prenom: %s\n", etudiants[ord].prenom);
         printf("Date de naissance: %d/%d/%d\n", etudiants[ord].date_de_naissance.jour, etudiants[ord].date_de_naissance.mois, etudiants[ord].date_de_naissance.annee);
                printf("Departement: ");
                switch (etudiants[ord].departement) {
                    case MATHEMATIQUES:
                        printf("Mathematiques\n");
                        break;
                    case PHYSIQUE:
                        printf("Physique\n");
                        break;
                    case CHIMIE:
                        printf("Chimie\n");
                        break;
                    case BIOLOGIE:
                        printf("Biologie\n");
                        break;
                    case GEOLOGIE:
                        printf("Geologie\n");
                        break;
                    case INFORMATIQUE:
                        printf("Informatique\n");
                        break;
                }
                printf("Note generale: %f\n\n", etudiants[ord].Note_generale);
     
        printf("\n");
    }
} else {
    printf("Choix invalide.\n");
}
}else if (hc == 2)
{
	printf("Comment voulez-vous trier les etudiants?\n");
    printf("1. Du plus eleve au plus faible\n");
    printf("2. Du plus faible au plus eleve\n");
    int ordr;
    scanf("%d", &ordr);
    
    if (ordr != 1 && ordr != 2) {
        printf("Option invalide.\n");
        break;
    }
    
    tri_etudiants_par_moyenne(etudiants, ordr);
    
    printf("Liste des etudiants triee par moyenne generale:\n");
    for (int iteras = 0; iteras < e; iteras++) {
        printf("%d. %s %s - Moyenne: %.2f\n", 
               iteras+1, etudiants[iteras].prenom, etudiants[iteras].nom, etudiants[iteras].Note_generale);
    }
    break;
}
else if(hc == 3)
{

    struct etudiant status_reussite[1000];  
    struct etudiant tmpn;
    for (int cpy = 0; cpy < e; cpy++) {
        status_reussite[cpy] = etudiants[cpy];
    }

    for (int varx = 0; varx < e - 1; varx++) {
        for (int vary = 0; vary < e - varx - 1; vary++) {
            if ((status_reussite[vary].Note_generale < 10 && status_reussite[vary+1].Note_generale >= 10) ||
                ((status_reussite[vary].Note_generale >= 10 && status_reussite[vary+1].Note_generale >= 10) ||
                 (status_reussite[vary].Note_generale < 10 && status_reussite[vary+1].Note_generale < 10)) &&
                 status_reussite[vary].Note_generale < status_reussite[vary+1].Note_generale) {
                tmpn = status_reussite[vary];
                status_reussite[vary] = status_reussite[vary+1];
                status_reussite[vary+1] = tmpn;
            }
        }
    }

    printf("Liste des etudiants triee par statut de reussite :\n");
    printf("Etudiants ayant reussi (moyenne >= 10) :\n");
    for (int vara = 0; vara < e; vara++) {
        if (status_reussite[vara].Note_generale >= 10) {
            printf("%s %s - Moyenne : %.2f\n", 
                   status_reussite[vara].prenom, status_reussite[vara].nom, status_reussite[vara].Note_generale);
        } else {
            if (i > 0 && status_reussite[vara-1].Note_generale >= 10) {
                printf("\nEtudiants n'ayant pas reussi (moyenne < 10) :\n");
            }
            printf("%s %s - Moyenne : %.2f\n", 
                   status_reussite[vara].prenom, status_reussite[vara].nom, status_reussite[vara].Note_generale);
        }
    }
    break;
    
}
    default:
    exit(0);
}}




return 0;}
