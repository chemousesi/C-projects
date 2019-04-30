#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include <time.h>
#include <windows.h>
#include "ZOO_LLC_BIBLIO.h"

void delay(int number_of_seconds);

int main()
{
    intro();
    system("pause");
    system("cls");
    esi_logo();
    logo();

    system("cls");

    Loop : ; //etiquette pour reprendre le menu et redemarrer le programme
    printf("\n\n\n            ********************************************************");

    /** decalaration */
    ptr_llc_animal tete_animaux;
    charger_llc_animaux(&tete_animaux);
    ptr_llc_enclo tete_enclos;
    charger_llc_enclos(&tete_enclos);
    ptr_llc_depart tete_depart;
    charger_llc_depart(&tete_depart);
    ptr_llc_affect tete_affect;
    charger_llc_affectation(&tete_affect);


    short select;char option;//pour la selection des operations


    affichage_menu(); //affichage_menu des choix


    printf("\n FAITES LE CHOIX DE L'OPERATION : ");scanf("%d",&select);


switch (select)
{
        case 1 :
            system("cls");
            affichage_listes(tete_enclos,tete_animaux,tete_affect);
            break;



        case 2 :
              system("cls");
              printf("\n\n2.Option sur les annimaux : ");
                printf("\n      a.Ajoute/Supprimer un animal.");
                printf("\n      b.Ajouter/Supprimer un enclos.");
                printf("\n      c.Affecter un animal a un enclos. ");
                printf("\n      d.Deplacer un animal d'un enclos vers un autre.");

          printf("\n FAITES LE CHOIX DE L'OPERATION : ");scanf("%s",&option);
         // option=strlwr(option);
                switch (option)
                {
                case 'a' :
                     printf("\n   *********************");
                    printf("\n Ajouter / supprimer un animal ");
                    ptr_llc_animal s;
                    ajouter_supprimer_animale(&tete_animaux,s);
                    break;
                case 'b' :
                     printf("\n   *********************");
                    printf("\n Ajouter / supprimer un enclos ");
                    ajouter_supprimer_enclo(&tete_enclos);
                    break;
                case 'c' :
                    printf("\n   *********************");
                    printf("\n Affecter un animal a un enclos ");
                    affecter_animal();
                        break;
                case 'd':
                    printf("\n   *********************");
                    printf("\nDeplacer un animal d'un enclos vers un autre.");
                    break;
                }
                break;
                case 3 :
                        system("cls");
                    printf("\n3.Rechercher les animaux arrivant au Zoo: ");
                    recherche_par_temps(tete_animaux);
                    break;
                case 4 :
                    system("cls");
                    eclatement_enclos(tete_enclos);
                    break;
                case 5 :
                    system("cls");
                    animaux_mm_pays(tete_animaux);
                    break;
                case 6 :
                    system("cls");
                    printf("\n chercher les animaux du meme pays: ");
                    chercher_enclos_mm_pays();//chercher dans les enclos les animaux de meme pays d'origine
                    break;;
                case 7 :
                    system("cls");
                    printf("\n7.Chercher tous les animaux ayant quitté le zoo une année apres leur arrivée (suite a un depart )");
                    checher_apr_anne();
                    break;
                case 8 :
                    system("cls");
                    exit(1);
                    break;

}

char reponsefin[10];
textcolor(4);

    printf("\n\n\n        Voulez-vous revenir au debut du programme ?  repondez (y/n) : ");
    scanf("%s",&reponsefin);


    textcolor(0);
    strcpy(reponsefin,strlwr(reponsefin));

if (strcmp(reponsefin,"y")==0)
      {
        system("cls");
        goto Loop;//brachement au debut du programme
      }
     printf("\n");
     system("pause");

}








