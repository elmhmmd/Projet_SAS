#include <stdio.h>
#include <string.h>

int main()
{
	int i = 7, j = 0;
	

	struct contact {
	
                         char nom[100];       
                         char numero[100];       
                         char email[100];       
	};
	struct contact contacts[100];
	while (i!=0) {
		printf("que voulez vous faire? \n");
		printf("0. Quittez \n");
		printf("1. Ajouter un contact \n");
                printf("2. Modifier un contact \n");

			scanf("%d",&i);

               int chercher_un_contact(char nom_du_contact[]) {
                               for (int k=0;k<j;k++)
                               {
                                          if (strcmp(contacts[k].nom,nom_du_contact)==0){
                                          break; 
}
                                             return k;                                          
}}

		switch(i)

		{
			case 1:
				printf("\n");
				printf("Veuillez saisir le nom du contact \n");
				scanf("%s",contacts[j].nom);
				printf("Veuillez saisir le numero de telephone du contact \n");
				scanf("%s",contacts[j].numero);
				printf("Veuillez saisir l'adresse email du contact \n");
				scanf("%s",contacts[j].email);
                                j++;
                                break;                                
                        case 2:
			        printf("\n");
                                char contact_a_modifier[100];
                                char nouveau_email[100];
                                char nouveau_numero[100];
                                printf("Veuillez saisir le nom du contact dont vous voulez modifiez \n");
                                scanf("%s",contact_a_modifier);
                                printf("Veuillez saisir le nouveau numero du contact \n");
                                scanf("%s",nouveau_numero);
                                printf("Veuillez saisir le nouveau email du contact \n");
                                scanf("%s",nouveau_email);
                                scanf("%s",contact_a_modifier);
                                int indice = chercher_un_contact(contact_a_modifier); 
                                strcpy(contacts[indice].numero,nouveau_numero); 
				strcpy(contacts[indice].email,nouveau_email);
				break;
                        case 3:          
			        printf("\n");
			        char nom_a_supprimer;
                                printf("Veuillez saisir le nom du contact dont vous voulez supprimer \n");
                                scanf("%s",nom_a_supprimer);
                                int index = chercher_un_contact(nom_a_supprimer);
				for(int x=index;x<j-1;x++)
				{
                                        strcpy(contacts[x].nom,contacts[x+1].nom);
                                        strcpy(contacts[x].email,contacts[x+1].email);
					contacts[x].numero= contacts[x+1].numero;
					}
				}
				j--;
				break;
                        case 4:
			        for(int a=0;a<j;a++)
				{
                                    printf("Nom: %s, Numero: %s, Email: %s",Contacts[a].nom,Contacts[a].numero,Contacts[a].email);
				    printf("\n");
				}
				break;
}}}

