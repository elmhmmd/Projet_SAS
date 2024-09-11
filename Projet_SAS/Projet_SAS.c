#include <stdio.h> struct date { int jour; int mois; int an;}


struct etudiant {
int id;
char nom[];
char prenom[];
date date_de_naissance;
Departement departement;
int Note_generale;}

enum Departement {

MATH,
PHYSIQUE,
CHIMIE,
BIOLOGIE,
GEOLOGIE,
INFORMATIQUE,}


int main() {
printf("Que voulez-vous faire?\n");
printf("1. Ajouter un etudiant\n");
printf("2. Modifier ou supprimer un etudiant\n");
printf("3. Afficher les details d'un etudiant\n");
printf("4. Calculer la moyenne generale\n");
printf("5. Consulter les statistiques\n");
printf("6. Rechercher un etudiant\n");    
printf("7. Trier les etudiants\n");
}
