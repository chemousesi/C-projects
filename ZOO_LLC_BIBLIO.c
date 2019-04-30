#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#include <windows.h>
#include <time.h>
#include "ZOO_LLC_BIBLIO.h"
//#include "conio21/conio2.h"
#define MaxChar 5000




/*implementation de la liste des animaux*/
void allouer(ptr_llc_animal *p) {
    *p = (struct maillon_animal *)malloc(sizeof(struct maillon_animal));
}

void liberer(ptr_llc_animal p) {
    free(p);
}

ptr_llc_animal suivant(ptr_llc_animal p) {
    return p->adr;
}

int valeur(ptr_llc_animal p) {
    return p->nom;
}

void aff_adr(ptr_llc_animal p,ptr_llc_animal q) {
    p->adr = q;
}
/*implementation de la liste des enclos*/
void allouer_enclo(ptr_llc_enclo *p) {
    *p = (struct maillon_enclo *)malloc(sizeof(struct maillon_enclo));
}

void liberer_enclo(ptr_llc_enclo p) {
    free(p);
}

ptr_llc_enclo suivant_enclo(ptr_llc_enclo p) {
    return p->adr;
}

int valeur_enclo(ptr_llc_enclo p) {
    return p->nom;
}

void aff_adr_enclo(ptr_llc_enclo p,ptr_llc_enclo q) {
    p->adr = q;
}
/*implementation de la liste de depart*/
void allouer_depart(ptr_llc_depart *p) {
    *p = (struct maillon_depart *)malloc(sizeof(struct maillon_depart));
}

void liberer_depart(ptr_llc_depart p) {
    free(p);
}

ptr_llc_depart suivant_depart(ptr_llc_depart p) {
    return p->adr;
}

int valeur_depart(ptr_llc_depart p) {
    return p->nom;
}

void aff_adr_depart(ptr_llc_depart p,ptr_llc_depart q) {
    p->adr = q;
}
/*implementation de la liste des affectations*/
void allouer_affect(ptr_llc_affect *p) {
    *p = (struct maillon_affect *)malloc(sizeof(struct maillon_affect));
}

void liberer_affect(ptr_llc_affect p) {
    free(p);
}

ptr_llc_affect suivant_affect(ptr_llc_affect p) {
    return p->adr;
}

int valeur_affect(ptr_llc_affect p) {
    return p->animal;
}

void aff_adr_affect(ptr_llc_affect p,ptr_llc_affect q) {
    p->adr = q;
}
void ecrire_list_enc(ptr_llc_enclo enclos)
{
    ptr_llc_enclo p_enclos;
     p_enclos=enclos;

    while (p_enclos!=NULL)
    {
        printf("%s",p_enclos->nom);
        p_enclos=suivant_enclo(p_enclos);
        printf(" | ");
    }
}

/*************************************************/
void ecrire_list_enc_poids(ptr_llc_enclo enclos)
{
    ptr_llc_enclo p_enclos;
     p_enclos=enclos;

    while (p_enclos!=NULL)
    {
        printf("%s %d Kg %d ",p_enclos->nom,p_enclos->poid,p_enclos->nbr_max);
        p_enclos=suivant_enclo(p_enclos);
        printf(" | ");
    }
}
/************************************************/
void ecrire_list_animaux(ptr_llc_animal tete)
{
    ptr_llc_animal p;
     p=tete;

    while (p!=NULL)
    {
        printf("%s",p->nom);
        p=suivant(p);
        printf(" | ");
    }
}

void affectation_info_enclo(ptr_llc_enclo p,ptr_llc_enclo q) /**  on prend toutes les information de p et on les affecte dans les champs de q*/
{
    strcpy(q->nom,p->nom);
    q->longeur=p->longeur;
    q->largeur=p->largeur;
    q->nbr_max=p->nbr_max;
    q->poid=p->poid;
    strcpy(q->type,p->type);
    strcpy(q->etat,p->etat);
}


void affectation_info_animal(ptr_llc_animal p,ptr_llc_animal q) /**  on prend toutes les information de p et on les affecte dans les champs de q*/
{
    strcpy(q->nom,p->nom);
    strcpy(q->race,p->race);
    strcpy(q->espece,p->espece);
    strcpy(q->regime,p->regime);
    q->poid=p->poid;
    strcpy(q->naissance,p->naissance);
    strcpy(q->entree,p->entree);
    strcpy(q->origine,p->origine);
}





/*charger les listes essentiels pour le travaille*/
void charger_llc_animaux(ptr_llc_animal *tete)
{
    char nom[20],race[20],espece[20],regime[20],naissance[20],entree[20],origine[20];
    int poid;
    FILE *fichier1;
    fichier1=fopen("animaux.txt","r");
    ptr_llc_animal p,q;
    allouer(&p);
    *tete=p;
    q=p;

    while(!feof(fichier1))
   {
       fscanf(fichier1,"%s %s %s %s %d %s %s %s",p->nom,p->race,p->espece,p->regime,&p->poid,p->naissance,p->entree,p->origine);
    if (feof(fichier1)) break;
       allouer(&p);
       aff_adr(q,p);
       aff_adr(p,NULL);
       q=p;
   }
}

void charger_llc_enclos(ptr_llc_enclo *tete)
{
    char nom[20],type[20],etat[20];
    int longeur,largeur,nbr_max,poid;
    FILE *fichier2;
    fichier2=fopen("enclos.txt","r");
    ptr_llc_enclo p,q;
    allouer_enclo(&p);
    *tete=p;
    q=p;
    while (!feof(fichier2))
    {
        fscanf(fichier2,"%s %d %d %d %d %s %s",p->nom,&p->longeur,&p->largeur,&p->nbr_max,&p->poid,p->type,p->etat);
        if (feof(fichier2)) break;
        allouer_enclo(&p);
       aff_adr_enclo(q,p);
       aff_adr_enclo(p,NULL);
       q=p;
    }
}

void charger_llc_depart(ptr_llc_depart *tete)
{
    char nom[20],date_entr[200],date_dprt[200];
    FILE *fichier3;
    fichier3=fopen("depart.txt","r");
    ptr_llc_depart p,q;
    allouer_depart(&p);
    *tete=p;
    q=p;
    while (!feof(fichier3))
    {
        fscanf(fichier3,"%s %s %s\n",p->nom,p->date_entr,p->date_dprt);
        if (feof(fichier3)) break;
        allouer_depart(&p);
       aff_adr_depart(q,p);
       aff_adr_depart(p,NULL);
       q=p;
    }
}

void charger_llc_affectation(ptr_llc_affect *tete)
{
    char animal[20],enclos[20],date_aff[10];
    FILE *fichier4;
    fichier4=fopen("affectations.txt","r");
    ptr_llc_affect p,q;
    allouer_affect(&p);
    *tete=p;
    q=p;
    while (!feof(fichier4))
    {
        fscanf(fichier4,"%s %s %s\n",p->animal,p->enclo,p->date_affect);
        allouer_affect(&p);
       aff_adr_affect(q,p);
       aff_adr_affect(p,NULL);
       q=p;
    }
}


/*Procédures pour remplire les fichiers de bases en cas d'ajout*/
/*les procédures suivantes ajoutent le contenu de dernier element de la liste llc*/
void remp_fich_animaux(ptr_llc_animal tete)
{
    FILE *fichier1;
    fichier1=fopen("animaux.txt","a");
    if (fichier1==NULL)
        printf("pas de fichier");
    ptr_llc_animal p;
    p=tete;
    while(suivant(p)!=NULL)
    {
        p=suivant(p);
    }
    fprintf(fichier1,"\n%s %s %s %s %d %s %s %s",p->nom,p->race,p->espece,p->regime,p->poid,p->naissance,p->entree,p->origine);
}

void remp_fich_enclo(ptr_llc_enclo tete)
{
    FILE *fichier2;
    fichier2=fopen("enclos.txt","a");
    if (fichier2==NULL)
        printf("pas de fichier");
    ptr_llc_enclo p;
    p=tete;
    while (suivant_enclo(p)!=NULL)
    {
        p=suivant_enclo(p);
    }
    fprintf(fichier2,"\n%s %d %d %d %d %s %s",p->nom,p->longeur,p->largeur,p->nbr_max,p->poid,p->type,p->etat);
}
void remp_fich_departs(ptr_llc_depart s)
{
    FILE *fichier3 = NULL;
    fichier3=fopen("depart.txt","a");
    if (fichier3==NULL)
        printf("pas de fichier de depart");
    fprintf(fichier3,"%s %s %s\n",s->nom,s->date_entr,s->date_dprt);
    printf("\n");
}

void remp_fich_affectations(ptr_llc_affect tete)
{
    FILE *fichier4;
    fichier4=fopen("affectations.txt","a");
    if (fichier4==NULL)
        printf("pas de fichier des affectations");
    ptr_llc_affect p;
    p=tete;
    while (suivant_affect(p)!=NULL)
    {
        p=suivant_affect(p);
    }
    fprintf(fichier4,"%s %s %s",p->animal,p->enclo,p->date_affect);
}
/*supprimer une ligne dans le fichier de base de données lorsequ'on supprime un element*/
void supprimer_ligne_animaux()
{
    FILE *fichier;
    FILE *fichier2;
    fichier=fopen("animaux.txt","r");
    fichier2=fopen("support1.txt","w");
    char nom[20],race[20],lenom[20],espece[20],regime[20],naissance[20],entree[20],origine[20];
    int poid;

        while (!feof(fichier))//copier en premier lieu tout le contenu de fichier de base dans un autre de support
        {
            fscanf(fichier,"%s %s %s %s %d %s %s %s\n",nom,race,espece,regime,&poid,naissance,entree,origine);
            fprintf(fichier2,"%s %s %s %s %d %s %s %s\n",nom,race,espece,regime,poid,naissance,entree,origine);
        }
        fclose(fichier2);
        fichier2=fopen("support1.txt","r");
        fclose(fichier);
        fichier=fopen("animaux.txt","w");
        printf("saisir le nom  \n");

        scanf("%s",&lenom);//que je vais comparer
        while (!feof(fichier2))//c'est maintenant qu'on va verifier
        {
            fscanf(fichier2,"%s %s %s %s %d %s %s %s\n",nom,race,espece,regime,&poid,naissance,entree,origine);
            if (strcmp(nom,lenom)!=0)//il doient etre different pour faire le collage dans le fichier de base
            {
                fprintf(fichier,"%s %s %s %s %d %s %s %s\n",nom,race,espece,regime,poid,naissance,entree,origine);
            }
        }


        fclose(fichier2);
    fclose(fichier);
}
void supprimer_ligne_enclo()
{
    FILE *fichier;
    FILE *fichier2;
    fichier=fopen("enclos.txt","r");
    fichier2=fopen("support2.txt","w");
    char nom[20],type[20],lenom[20],etat[20];
    int poid,longueur,largeur,nbr_max;

        while (!feof(fichier))
        {
            fscanf(fichier,"%s %d %d %d %d %s %s\n",nom,&longueur,&largeur,&nbr_max,&poid,type,etat);
            fprintf(fichier2,"%s %d %d %d %d %s %s\n",nom,longueur,largeur,nbr_max,poid,type,etat);
        }
        fclose(fichier2);
        fichier2=fopen("support2.txt","r");
        fclose(fichier);
        fichier=fopen("enclos.txt","w");
        printf("vous allez le supprimer de fichier de base. \n");
        printf("saisir le nom d'enclo \n");

        scanf("%s",&lenom);//que je vais comparer
        while (!feof(fichier2))
        {
            fscanf(fichier2,"%s %d %d %d %d %s %s\n",nom,&longueur,&largeur,&nbr_max,&poid,type,etat);
            if (strcmp(nom,lenom)!=0)
            {
                fprintf(fichier,"%s %d %d %d %d %s %s\n",nom,longueur,largeur,nbr_max,poid,type,etat);
            }
        }
        fclose(fichier2);
    fclose(fichier);
}
void supprimer_ligne_affectations()
{
FILE *fichier;
    FILE *fichier2;
    fichier=fopen("affectations.txt","r");
    fichier2=fopen("support1.txt","w");
    char nom[200],enclo[200],lenom[200],date_i[100];

        while (!feof(fichier))
        {
            fscanf(fichier,"%s %s %s\n",nom,enclo,date_i);
            printf("%s",nom);
            fprintf(fichier2,"%s %s %s\n",nom,enclo,date_i);
        }
        fclose(fichier2);
        fichier2=fopen("support1.txt","r");
        fclose(fichier);

        fichier=fopen("affectations.txt","w");

        printf("saisir le nom de l'annimal : ");
        scanf("%s",lenom);
        while (!feof(fichier2))
        {
            fscanf(fichier2,"%s %s %s\n",nom,enclo,date_i);
            if (strcmp(nom,lenom)!=0)
            {
                fprintf(fichier,"%s %s %s\n",nom,enclo,date_i);
            }
        }
        fclose(fichier2);
    fclose(fichier);
}

/*procedure qui verifie qu'un enclo est vide lors la suppression*/
/*elle prend en depart une variable *vide passage par variable */
/*nous allons verifier que le nom d'enclo n'existe pas dans le fichier des affectations donc pas d'animaux affectés a cet enclo*/
void verif_enclo_vide(int *vide)
{
    char lenom[20];
    printf("nous allons verifier que c'est un enclo vide\n");
    printf("saisir le nom de l'enclo   : ");
    scanf("%s",lenom);
    *vide=0;
    ptr_llc_affect tete,p;
    charger_llc_affectation(&tete);
    p=tete;
    while (suivant_affect(p)!=NULL)
    {
        if (!strcmp(lenom,p->enclo)) {*vide=1;}
        p=suivant_affect(p);
    }
}
/****************************************************************/

  ptr_llc_animal finList_animal(ptr_llc_animal tete) //fonction retourne l'adresse du dernier maillon de la liste
    {
        ptr_llc_animal p=tete,fin_li;
        while (p!=NULL)
        {
            fin_li=p;
            p=suivant(p);
        }
            return fin_li;
    }

 /****************************************************/
/*procedure essentiel pour ajouter un animal*/
void ajouter_supprimer_animale(ptr_llc_animal *tete)
{
    char nom_animal[20];
    ptr_llc_animal s,p,fin_li_an;
    int n;
    p=*tete;
    printf("\n");
    printf("voulez-vous ajouter(0) ou supprimer(1) un animal ??   ");
    scanf("%d",&n);
    if (n==0)//il veut ajouter un animale dans la liste des animaux
    {//elle va ajouter a la fain de la liste
       while(suivant(p)!=NULL){p=suivant(p);}
       allouer(&s);
       {   printf("saisir le nom\n");
           scanf("%s",s->nom);
           printf("saisir la race\n");
           scanf("%s",s->race);
           printf("saisir le espece\n");
           scanf("%s",s->espece);
           printf("saisir le regime avec'/' apres chaque repas\n");
           scanf("%s",s->regime);
           printf("saisir la date de naissance JJ/MM/AAAA\n");
           scanf("%s",s->naissance);
           printf("saisir la date de entree JJ/MM/AAAA\n");
           scanf("%s",s->entree);
           printf("saisir les origines\n ");
           scanf("%s",s->origine);
           printf("saisir le poid\n");
           scanf("%d",&s->poid);
       }
    aff_adr(p,s);
    aff_adr(s,NULL);//un chainage important avec le dernier maillon de la liste ancienne
    remp_fich_animaux(*tete);//enregistrer les derniers modifications elle va toute seul acceder au nouveau dernier maillon
    charger_llc_animaux(&(*tete));
    }
    else
    {   int c;
    FILE *fichier3 = NULL;
    fichier3=fopen("depart.txt","a");
        printf("donc vous voulez supprimer\n");
        printf("est-ce que c'est pour un deces(0) ou depart(1)   : ");
        scanf("%d",&c);
        if (c==1)//dans c'est a cause d'un depart
        {
           char nom1[10];
            int trouve=0;
            printf("vous allez enregistrer ce depart dans la base de données de depart de tous les animaux\n ");
            ptr_llc_depart tete_depart,p_depart,s_depart;
            ptr_llc_animal p_animal;
            p_animal=*tete;
            charger_llc_depart(&tete_depart);
            p_depart=tete_depart;
            while(suivant_depart(p_depart)!=NULL){p_depart=suivant_depart(p_depart);}
            allouer_depart(&s_depart);
            printf("saisir le nom\n");
            scanf("%s",s_depart->nom);
            while (suivant(p_animal)!=NULL && trouve==0)
            {
                if (!strcmp(s_depart->nom,p_animal->nom))
                {
                    printf("sa date de entree est   :   ");
                    printf("%s",p_animal->entree);
                    trouve=1;
                    strcpy(nom1,p_animal->entree);
                    strcpy(s_depart->date_entr,nom1);
                    printf("sa date de entree dans le maillon des depart est   : ");
                    printf("%s",s_depart->date_entr);

                }
                p_animal=suivant(p_animal);
            }
            printf("saisir la date de depart\n");
            scanf("%s",s_depart->date_dprt);

            //printf("%s %s %s",s_depart->nom,s_depart->date_entr,s_depart->date_dprt);
            fprintf(fichier3,"%s %s %s\n",s_depart->nom,s_depart->date_entr,s_depart->date_dprt);
            aff_adr_depart(p_depart,s_depart);
            aff_adr_depart(s_depart,NULL);
            //remp_fich_departs(tete_depart);
        }
        printf("\n");
        printf("vous allez supprimer son existance dans le fichier de nos animaux\n");
        supprimer_ligne_animaux();
        printf("\n");
        printf("vous allez supprimer son existance dans le fichier des affectations\n");
        supprimer_ligne_affectations();
        charger_llc_animaux(&(*tete));
    }
}
void ajouter_supprimer_enclo(ptr_llc_enclo *tete)
{
    char nom_enclo[20];
    ptr_llc_enclo s,p;
    int n;
    p=*tete;
    printf("\n");
    printf("voulez-vous ajouter(0) ou supprimer(1) un enclo??  ");
    scanf("%d",&n);
    if (n==0)
    {
       while(suivant_enclo(p)!=NULL){p=suivant_enclo(p);}
       allouer_enclo(&s);
       {   printf("saisir le nom\n");
           scanf("%s",s->nom);
           printf("saisir la longeur\n");
           scanf("%d",&s->longeur);
           printf("saisir la largeur\n");
           scanf("%d",&s->largeur);
           printf("saisir le nombre maximale\n");
           scanf("%d",&s->nbr_max);
           printf("saisir le poid maximale\n");
           scanf("%d",&s->poid);
           printf("saisir le type \n");
           scanf("%s",s->type);
           printf("saisir le etat\n ");
           scanf("%s",s->etat);
       }
    aff_adr_enclo(p,s);
    aff_adr_enclo(s,NULL);
    remp_fich_enclo(*tete);
    charger_llc_enclos(&(*tete));
    }
    else
    {
        int vide;
        printf("donc vous voulez supprimer\n");
        verif_enclo_vide(&vide);
        if (vide==0){
        supprimer_ligne_enclo();
        charger_llc_enclos(&(*tete));
        printf("l'enclo est bien supprimer .\n");}
        else{printf("*********impossible de supprimer car l'enclo est chargé**********");}
    }
}
int date(char chaine[10])//une fonction qui prend une date en chaine de caracteres et la transforme en entier qui represente le nombre de seconde à partir 01/01/1900
{
    int jour,moi,anne;
    sscanf(chaine,"%d/%d/%d",&jour,&moi,&anne);//permet de lire un texte suivant un format speciale qui est définie au milieu et ranger dans le resultat
    time_t temps;//des declarations prédéfinies
    struct tm date;//une déclaration prédéfinie
    int qq;//variable intermediare parceque j'ai pas pu faire directement return temps.
    date.tm_year=anne-1900;
    date.tm_mon=moi-1;
    date.tm_mday=jour;
    date.tm_hour=0;//pour initialiser à minuit
    date.tm_min=0;//pour initialiser à minuit
    date.tm_sec=0;//poir initialiser à minuit
    temps=mktime(&date);//une fonction predefinie elle va produire les secondes
    qq=temps;
    return qq;
}

void recherche_par_temps(ptr_llc_animal tete)
{ /*une procédure trés simple je vais recupere les dates d'entree de chaque animale puis faire des comparaisons selon un critere précis*/
    /*soit apres/avant une date ou entre deux dates*/
    char ctf[10];
    int n,tf,ti;
    ptr_llc_animal p;
    p=tete;
    printf("vous allez faire une recherche par date d'entrée;\n");
    printf("voulez-vous :\n");
    printf("1-rechercher avant une date;\n");
    printf("2-rechercher apres une date;\n");
    printf("3-rechercher entre deux dates;\n");
    printf("vous voulez  : ");
    scanf("%d",&n);
    if (n==1)
    {
       printf("saisir la date d'arrive  : ");
       scanf("%s",&ctf);
       tf=date(ctf);
       while (p!=NULL)
       {
           ti=date(p->entree);
           if (ti<tf){printf(p->nom);printf("|");}
           p=suivant(p);
       }
    }
    else
    {
        if (n==2)
        {
         printf("saisir la date de depart  : ");
         scanf("%s",&ctf);
         tf=date(ctf);
         while(p!=NULL)
         {
             ti=date(p->entree);
             if (ti>tf)
                {printf("%s",p->nom);printf("|");}
             p=suivant(p);
         }
        }
        else
        {   char cti1[10];
            int ti1;
            printf("saisir la date de depart  : ");
            scanf("%s",&cti1);
            ti1=date(cti1);
            printf("saisir la date d'arrive  : ");
            scanf("%s",&ctf);
            tf=date(ctf);
            while (p!=NULL)
            {
                ti=date(p->entree);
                if ((ti<tf)&&(ti>ti1))
                {
                    printf(p->nom);
                    printf("|");
                }
                p=suivant(p);
            }
        }
    }

}

void checher_apr_anne()
{
    char animal[20],date_entr[20],date_dprt[20];
    int ti,tf;
    FILE *fichier3;
    fichier3=fopen("depart.txt","r");
    while (!feof(fichier3))
    {
        fscanf(fichier3,"%s %s %s",animal,date_entr,date_dprt);
        tf=date(date_dprt);
        ti=date(date_entr);
        if (tf-ti==31622400)
        {
            printf("\n\n        l'animal  %s est parti une année apres sa rentree c'est bizare",animal);
        }
    }
}

/********************************************************************************************/
/** eclatement des listes des enclos */

ptr_llc_enclo finList_enlos(ptr_llc_enclo tete) /***fonction retourne l'adresse du dernier maillon de la liste*/
    {
        ptr_llc_enclo p=tete,fin_li;
        while (p!=NULL)
        {
            fin_li=p;
            p=suivant_enclo(p);
        }
            return fin_li;
    }
/****************************************************************/
/*
  ptr_llc_animal finList_animal(ptr_llc_animal tete_anim) //fonction retourne l'adresse du dernier maillon de la liste
    {
        ptr_llc_animal p=tete,fin_li;
        while (p!=NULL)
        {
            fin_li=p;
            p=suivant(p);
        }
            return fin_li;
    }
    */
 /****************************************************/


void insert_fin_enclos(ptr_llc_enclo tete,ptr_llc_enclo *fin_li,ptr_llc_enclo p/**la case de la liste (enclos) q'on veut inserer  */,int test /**vrai si la tete est rempli*/)       /**procedure qui insert à la fin de la liste elle met a jour la fin de la liste */
                {

                    if ( (*fin_li==tete) && (test=0))
                    {
                        test=1;
                        affectation_info_enclo(p,tete);
                    }
                else {
                    ptr_llc_enclo l;
                    allouer_enclo(&l);
                    affectation_info_enclo(p,l);
                    aff_adr_enclo(*fin_li,l);
                    aff_adr_enclo(l,NULL);
                    *fin_li=l;
                      }
                }
/************************************************************************************************/
void insert_fin_animal(ptr_llc_animal tete,ptr_llc_animal *fin_li,ptr_llc_animal p,int test /**vrai si la tete est rempli*/)       /**procedure qui insert à la fin de la liste elle met a jour la fin de la liste */
                {

                    if ((test=0))
                    {
                        test=1;
                        affectation_info_animal(p,tete);
                    }
                else {
                    ptr_llc_animal l;
                    allouer(&l);
                    affectation_info_animal(p,l);
                    aff_adr(*fin_li,l);
                    aff_adr(l,NULL);
                    *fin_li=l;
                      }
                }

void eclatement_enclos(ptr_llc_enclo enclos)// reponse de la question 4 du tp
                                            // eclater la liste en sou liste selon le type de l'enclos et lies trier selon les poids et fusionner à la fin
     {
         printf("\n__________________________________________________________________________________");
        printf("\n*****eclater la liste des enclos en quatres sous-listes selon le type d'enclos \n");
         printf("*******************************************************************************");
     char select[100];
     int tst1=0,tst2=0,tst3=0,tst4=0;
     //ces testes seront utilise pour dire que la tete n'existe pas encore à 0 si ils sont à 1 la tete de la liste existe deja
     ptr_llc_enclo fin_li1,fin_li2,fin_li3,fin_li4,
     tCage1,tVoliere2,tAquarium3,tInsectarium4,
     p=enclos;
     // allocation
     allouer_enclo(&tCage1);
     allouer_enclo(&tVoliere2);
     allouer_enclo(&tAquarium3);
     allouer_enclo(&tInsectarium4);

// ici on fait l'affecation des pointeurs de la fin des listes
fin_li1=tCage1;
fin_li2=tVoliere2;
fin_li3=tAquarium3;
fin_li4=tInsectarium4;

         while (p!=NULL)
      {
                strcpy(select,p->type);
                if (strcmp(select,"cage")==0)
                {
                        if (tst1==0)
                            {
                            insert_fin_enclos(&tCage1,&fin_li1,p,0);
                            tst1=1;
                            }
                            else insert_fin_enclos(&tCage1,&fin_li1,p,1);
                }
                if (strcmp(select,"voliere")==0)
                {
                        if (tst2==0)
                    {
                        tst2=1;
                        insert_fin_enclos(&tVoliere2,&fin_li2,p,0);
                    }
                        else insert_fin_enclos(&tVoliere2,&fin_li2,p,1);

                }
                if (strcmp(select,"aquarium")==0)
                    {
                        if (tst3==0)
                        {
                        tst3=1;
                        insert_fin_enclos(&tAquarium3,&fin_li3,p,0);
                        }
                        else insert_fin_enclos(&tAquarium3,&fin_li3,p,1);
                    }
                if (strcmp(select,"insectarium")==0)
                        {
                        if (tst4==0)
                        {
                        tst4=1;
                        insert_fin_enclos(&tInsectarium4,&fin_li4,p,0);
                        }
                            else insert_fin_enclos(&tInsectarium4,&fin_li4,p,1);

                        }
                        p=suivant_enclo(p);
           }
           printf("\n la liste des enclos de type \nCAGE : ");
           ecrire_list_enc(tCage1);
           printf(" \nVOLIERE : ");
           ecrire_list_enc(tVoliere2);
           printf("\nAQUARIUM : ");
           ecrire_list_enc(tAquarium3);
           printf("\nINSECTARIUM : ");
           ecrire_list_enc(tInsectarium4);

            //le tri selon le poids des enclos
            printf("\n\n\n              ______________________________\n\n");
           printf("********LE TRI DES SOUS-LISTES SELON LE POIDS DES ENCLOS******* ");
           printf("\n la liste des enclos de type \nCAGE : ");
           tri_bull_enclos_poids(tCage1);
           ecrire_list_enc(tCage1);
           printf(" \nVOLIERE : ");
           tri_bull_enclos_poids(tVoliere2);
           ecrire_list_enc(tVoliere2);
           printf("\nAQUARIUM : ");
           tri_bull_enclos_poids(tAquarium3);
           ecrire_list_enc(tAquarium3);
           printf("\nINSECTARIUM : ");
           tri_bull_enclos_poids(tInsectarium4);
           ecrire_list_enc(tInsectarium4);
           printf("\n\n*****************************\n\n\n\n\n\n");

//            la fusion des quatres sou listes trier
           printf("\n        ________________________ \n");
           printf("voulez vous fusionner les sous-listes trier ? ");
            printf("\n 1.Oui \n2.Non \n Selectionner 1 ou 2 : ");
            short rep;scanf("%d",&rep);
            if (rep==1)
            {
                ptr_llc_enclo liste_fusionnee;
                liste_fusionnee=tCage1;
                fin_li1->adr=tVoliere2;
                fin_li2->adr=tAquarium3;
                fin_li3->adr=tInsectarium4;

                printf("\nVotre liste fusionnee est : \n");
                ecrire_list_enc(liste_fusionnee);

            } else printf("merci , a bientot");

      }


void fin_list_enc(ptr_llc_enclo tete,ptr_llc_enclo *fin_li) //retourne l'adresse du dernier maillon de la liste
    {
        ptr_llc_enclo p=tete;
        while (p!=NULL)
        {
            *fin_li=p;
            p=suivant_enclo(p);
        }
    }

/***************************************/
void chercher_enclos_mm_pays()
{
    char nom1[20],nom2[20],origine1[20],origine2[20];
    BOOLEAN trouve=false;

    ptr_llc_affect tete_aff,p_aff,q_aff;
    ptr_llc_animal tete_animal,q_animal,p_animal;
    charger_llc_affectation(&tete_aff);
    q_aff=tete_aff;
    charger_llc_animaux(&tete_animal);
    q_animal=tete_animal;
    p_animal=tete_animal;
    printf("les enclos contennants au moins deux animaux de meme pays sont   :  ");
    printf("\n");
    while (suivant_affect(q_aff)!=NULL)
    {
        p_aff=suivant_affect(q_aff);
        while(suivant_affect(p_aff)!=NULL)
        {
            if (strcmp(p_aff->enclo,q_aff->enclo)==0)
            {
                strcpy(nom1,q_aff->animal);
                printf("\n");
                strcpy(nom2,p_aff->animal);
                while (suivant(q_animal)!=NULL)
                {
                    if (!strcmp(nom1,q_animal->nom)){strcpy(origine1,q_animal->origine);}
                    q_animal=suivant(q_animal);
                }
                while(suivant(p_animal)!=NULL)
                {
                    if (strcmp(nom2,p_animal->nom)==0){strcpy(origine2,p_animal->origine);}
                    p_animal=suivant(p_animal);
                }
                BOOLEAN trouve=false;
                if (!strcmp(origine1,origine2))
                {   trouve=true;
                    printf("%s  ",p_aff->enclo);
                    printf(" | ");
                }

            }

            p_aff=suivant_affect(p_aff);
        }
        if (trouve==false ) printf("il n'ya pas ");
        q_aff=suivant_affect(q_aff);
    }
}





/*****************************************************************/


void animaux_mm_pays(ptr_llc_animal tete) /** cette procedure crée une liste des animaux ayant un pays d'origine commun de tete vers anim_mm_pays */
{
    ptr_llc_animal anim_mm_pays;
    ptr_llc_animal p=tete,fin_li;
    char pays[20];// pays va etre donne par l'utilisateur
    int test=0;
    allouer(&anim_mm_pays);
     printf("   les pays disponibles sont : \n");


    while (p!=NULL)  /** boucle pour afficher les pays disponibles  */
    {
        printf("%s | ",p->origine);
        p=suivant(p);
    }

    printf("\n Ecrire votre pays : ");
    scanf("%s",pays); strcpy(pays,strlwr(pays));

    p=tete;
    fin_li=anim_mm_pays;
    /** <------ ici l'allocation de la tete !!!!!! */


    while (p!=NULL)
    {
        if (strcmp(pays,p->origine)==0)
    {
       if  (test=0)
       {
           test=1;
           insert_fin_animal(anim_mm_pays,&fin_li,p,0);
       } else insert_fin_animal(anim_mm_pays,&fin_li,p,1);


    }
     p=suivant(p);
    }

    printf("\n\n les animaux");
    ecrire_list_animaux(anim_mm_pays);

    printf(" \n ********classement des animaux:******** \n");
    printf("********************************************\n");
    char espece[50];
    printf("\n\n\n");
    printf("\nClasse selon l'espece :");
    printf("\n les especes disponibles :");

            p=anim_mm_pays;
            while (p!=NULL)//affichage des especes disponibles
            {
                printf(" %s | ",p->espece);
                p=suivant(p);
            }
    printf("\nChoisser une espece :");
    scanf("%s",espece);
    p=anim_mm_pays;
    printf("\nliste des animaux (espece: %s ): ",espece);
    while (p!=NULL) //ecriture des animaux de l'espece selectionnee
    {
        if (strcmp(p->espece,espece)==0)
            printf("%s | ",p->nom);
            p=suivant(p);
    }
    printf("\nclassement selon race");
    printf("\n\nles races disponibles :");
    p=anim_mm_pays;
    while (p!=NULL) //affichage des races disponibles
    {
        printf("%s  | ",p->race);
        p=suivant(p);
    }
    char race[20];
    printf("\nChoisisser une race :");
    scanf("%s",&race);
    p=anim_mm_pays;
    while (p!=NULL)  //ecriture des animaux de la race selectionée
    {
        if (strcmp(p->race,race)==0)
            printf("%s | ",p->nom);

        p=suivant(p);

    }
}

/******************************************************************************/
void acceder_animal(ptr_llc_animal *s,char nom[20])//s va contenir tous les informations de animal
{
    int trouve=0;
    ptr_llc_animal tete,p;
    charger_llc_animaux(&tete);
    p=tete;
    while (suivant(p)!=NULL&&trouve==0)
    {
        if (!strcmp(p->nom,nom)){affectation_info_animal(p,*s);
        trouve=1;}
        p=suivant(p);
    }
}
void poid_utilise(char enclo[20],int *nbr,int *poid)//elle retourne le poid utilise dans un enclo
{
    ptr_llc_affect tete,p;
    ptr_llc_animal s;
    int nbrk=0;
    int poidk=0;
    charger_llc_affectation(&tete);
    p=tete;
    while (suivant_affect(p)!=NULL)
    {
        if (!strcmp(p->enclo,enclo))//donc je suis dans le bon enclo
        {
            nbrk=nbrk+1;//calculer le nombre de animal dans cet enclo
            acceder_animal(&s,p->animal);//acceder au animal pour reccuperer son poid
            poidk=poidk+s->poid;
        }
        p=suivant_affect(p);
    }
    *nbr=nbrk;
    *poid=poidk;
}


void affecter_animal()/** Affectation d'un animal */
{
    char animal[10],enclo[20];
    int trouve=0,poid_animal,poid_utilis,nbr_utilis;
    printf("saisir le nom de animal : ");scanf("%s",animal);printf("\n");
    printf("saisir le nom de enclo : ");scanf("%s",enclo);printf("\n");
    ptr_llc_animal tt_animal,p_animal;
    charger_llc_animaux(&tt_animal);
    acceder_animal(&p_animal,animal);
    poid_animal=p_animal->poid;
    //printf("le poid de cet animal est  : %d",poid_animal);
    ptr_llc_affect t_aff,p_aff,q_aff,j,k;
    charger_llc_affectation(&t_aff);
    j=t_aff;
    while (suivant_affect(j)!=NULL)
    {printf("%s",j->animal);j=suivant_affect(j);}
    ptr_llc_enclo tt_enclo,p_enclo,q_enclo;
    charger_llc_enclos(&tt_enclo);
    ecrire_list_enc_poids(tt_enclo);
    p_enclo=tt_enclo;
    while ((suivant_enclo(p_enclo)!=NULL)&&(trouve==0))
    {
        if (strcmp(enclo,p_enclo->nom)==0){trouve=1;}
        q_enclo=p_enclo;
        p_enclo=suivant_enclo(p_enclo);
    }
    printf("le nom de enclo est   %s",q_enclo->nom);
    printf("\n le poid maximale est: %d et le nombre maximale est  : %d ",q_enclo->poid,q_enclo->nbr_max);
    poid_utilise(enclo,&nbr_utilis,&poid_utilis);
    printf("\n le nombre des animaux est  : %d  et le poid  affecte est  %d",nbr_utilis,poid_utilis);
    if (strcmp(q_enclo->etat,"libre")==0)
    {
        if (((q_enclo->poid)-(poid_animal+poid_utilis)>0)&&((q_enclo->nbr_max)-(nbr_utilis+1)>=0))
        { char date_k;
            allouer_affect(&k);
            printf("saisir la date de affct");
            scanf("%s",date_k);
            strcpy(k->animal,animal);
            printf("\n le nom %s",k->animal);
            strcpy(k->date_affect,date_k);
            printf("\n la date de affectation  %s",k->date_affect);
            strcpy(k->enclo,enclo);
            printf("\n le nom de enclo  %s",k->enclo);
            aff_adr_affect(j,k);
            aff_adr_affect(k,NULL);
            remp_fich_affectations(t_aff);
        }
        else{printf("probleme de poids ou de nombre choisissez un autre enclo  \n");}
    }
    else{printf("il n'est pas libre    \n");}

}



/******************************************************************************/



        void    permut_enclos(ptr_llc_enclo *p,ptr_llc_enclo *q)
                {
                    ptr_llc_enclo i;
                    allouer_enclo(&i);
                    affectation_info_enclo(*p,i);
                    affectation_info_enclo(*q,*p);
                    affectation_info_enclo(i,*q);

                }


/******************************************************************************/

        void tri_bull_enclos_poids(ptr_llc_enclo tet1)//cette procedure fait le tri selon le pids des enlos de la liste à l'entrée tet1
                {

                    ptr_llc_enclo q,p=tet1;int cpt;
                    cpt=1;
                    while (cpt!=0)
                    {
                        cpt=0;
                        p=tet1;
                        while (suivant_enclo(p)!=NULL)
                        {
                            if ( p->poid > (suivant_enclo(p)->poid) )
                            {
                            cpt=cpt+1;
                              q=suivant_enclo(p);
                              permut_enclos(&p,&q);
                            }

                            p=suivant_enclo(p);
                        }

                    }

                }



void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}

/***************************************************************************************************/
void intro()
{
     printf("\n                  TP s2 ALGO -BENAZIZA/BENAKMOUM G:07 ");
    printf("\n                ***************************************");
    printf("\n                ***** BIENVENUE DANS LE PROGRAMME *****");
    printf("\n                    GESTION D'UN PARQUE ZOOLOGIQUE ");
    printf("\n\n\n    __________________________________________________________\n\n");
}

/******************************************************************************************************/
void color(int txt,int fond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,fond*16+txt);
}

void logo()
{
printf("\n          ///////////        /////////          ////////        ");
delay(1);
printf("\n                ////         //     //          //    //        ");
delay(1);
printf("\n              ///            //     //          //    //        ");
delay(1);
printf("\n            ///              //     //          //    //        ");
delay(1);
printf("\n         ////                //     //          //    //        ");
delay(1);
printf("\n        //////////           /////////          ////////        ");
delay(1);
}


void esi_logo()//affiche du logo de l'ecole
{
textcolor(1);
printf("\n                                           __         ");
printf("\n                                          |__|        ");
textcolor(0);
printf("\n                   ______     ______       __         ");
printf("\n                   | ____|    |  ___|     |  |        ");
printf("\n                   | |        | |         |  |        ");
printf("\n                   | |___     | |___      |  |        ");
printf("\n                   |  ___|    |___  |     |  |        ");
printf("\n                   | |            | |     |  |        ");
printf("\n                   | |___     ____| |     |  |        ");
printf("\n                   |_____|   |______|     |__|        ");
textcolor(3);
printf("\n              ***************************************");
textcolor(0);

printf("\n\n");

}


COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void textcolor(int color)
{
    if (color >15 || color <=0)
    {
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon,15);

    }else
    {
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon,color);
    }
}

void affichage_menu()//affichage du menu de l'application
    {
    system("cls");
    gotoxy(20,1);
    textcolor(1);
    printf(" ** Choisissez l'option %c executer :",133);
    textcolor(0);
    gotoxy(10,3);
    printf("1.Afficher les listes LLC des enclos , animaux et affectations.");
    gotoxy(10,5);
    printf("2.Option sur les animaux : \n\n");
    gotoxy(15,6);
    printf("      a.Ajouter/Supprimer un animal.\n");
    gotoxy(15,7);
    printf("      b.Ajouter/Supprimer un enclos.\n");
    gotoxy(15,8);
    printf("      c.Affecter un animal a un enclos. \n");
    gotoxy(15,9);
    printf("      d.Deplacer un animal d'un enclos vers un autre.\n\n");
    gotoxy(10,11);
    printf("3.Rechercher les animaux arrivant au Zoo: ");
    gotoxy(10,13);
    printf("4.Eclater la liste des enclos occupés en 4 sous listes selon le type d'enclos,\n         trier ensuite ces listes selon le poids \n          et enfin les fusionner en une seule liste");
    gotoxy(10,19);
    printf("5.Chercher tous les animaux de meme pays d'origine et les classer selon l'espece puis la race");
    gotoxy(10,21);
    printf("6.Chercher tous les enclos contenant au moins deux animaux du meme pays d'origine");
    gotoxy(10,23);
    printf("7.Chercher tous les animaux ayant quitt%c le zoo une ann%ce apres leur arriv%ce (suite a un depart )",130,130,130);
    gotoxy(10,25);
    printf("8.QUITTER .");






    }

//afffichage des enclos
void afficher_enclo(ptr_llc_enclo p,int x )
{

        gotoxy(1,x);printf("%s",p->nom );
        gotoxy(10,x);printf("%d",p->longeur );
        gotoxy(20,x);printf("%d",p->largeur );
        gotoxy(30,x);printf("%d",p->nbr_max );
        gotoxy(40,x);printf("%d",p->poid );
        gotoxy(50,x);printf("%s",p->type );
        gotoxy(70,x);printf("%s",p->etat );
}

void ecrire_list_enc2(ptr_llc_enclo tete)
{
    system("cls");
    int x=3;
    ptr_llc_enclo p=tete;
        textcolor(2);
        gotoxy(1,x);printf("| Identif" );
        gotoxy(10,x);printf("| Longueur");
        gotoxy(20,x);printf("| Largeur");
        gotoxy(30,x);printf("| Nb_max");
        gotoxy(40,x);printf("| Poids_max");
        gotoxy(50,x);printf("| Type");
        gotoxy(70,x);printf("| Etat");
        x=5;
textcolor(0);
    while (p!=NULL)

    {
        afficher_enclo(p,x);
        x++;
        p=suivant_enclo(p);
    }
}
//affichage des animaux
void afficher_animal(ptr_llc_animal p,int x )
{

        gotoxy(1,x);printf("%s",p->nom );
        gotoxy(10,x);printf("%s",p->race);
        gotoxy(20,x);printf("%s",p->espece );
        gotoxy(30,x);printf("%s",p->regime );
        gotoxy(40,x);printf("%d",p->poid );
        gotoxy(50,x);printf("%s",p->naissance );
        gotoxy(70,x);printf("%s",p->entree );
        gotoxy(90,x);printf("%s",p->origine);
}

void ecrire_list_animaux2(ptr_llc_animal tete)
{


system("cls");
    int x=3;
    ptr_llc_animal p=tete;
textcolor(2);
        gotoxy(1,x);printf("| Nom ");
        gotoxy(10,x);printf("| Race");
        gotoxy(20,x);printf("| Espece ");
        gotoxy(30,x);printf("| Regime ");
        gotoxy(40,x);printf("| Poids " );
        gotoxy(50,x);printf("| Naissance" );
        gotoxy(70,x);printf("| Entree ");
        gotoxy(90,x);printf("| Origine");
x=5;
 textcolor(0);

    while (p!=NULL)
    {
        afficher_animal(p,x);
        x++;
        p=suivant(p);
    }
}


void afficher_affectation(ptr_llc_affect p,int x) // afficher une line d'affectation
{
    gotoxy(15,x);printf("%s",p->animal);
    gotoxy(25,x);printf("%s",p->enclo);
    gotoxy(25,x);printf("%s",p->date_affect);

}

void ecrire_list_aff2(ptr_llc_affect teteaf) //afficher la liste des affectations
{
    system("cls");

    ptr_llc_affect p=teteaf;
    int y=3;
    textcolor(2);
    gotoxy(10,y);printf("| Animal");
    gotoxy(15,y);printf("| Enclos");
    gotoxy(25,y);printf("| Date_affect");

    y=5;
    textcolor(0);


    while (p!=NULL)
    {
        afficher_affectation(p,y);
        p=p->adr;
        y++;
    }

}


void affichage_listes(ptr_llc_enclo tt_enclo,ptr_llc_animal tt_animal,ptr_llc_affect tt_affect)// procedure qui fait le choix et l'affichage entre les trois listes (enclos,animaux, affectations)
{
    short choix;
    system("cls");

    gotoxy(5,5);
    printf("1. Afficher la liste des enclos ");
    gotoxy(5,7);
    printf("2. Afficher la liste des animaux");


    gotoxy(3,13);

    printf(" Faites Votre choix : ");scanf("%d",&choix);

    (choix ==1 ) ? ecrire_list_enc2(tt_enclo) : (choix == 2) ? ecrire_list_animaux2(tt_animal) : printf("DESOLE");

}





