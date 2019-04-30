
/** implementation des listes  */
typedef enum{false,true} booleen;

typedef struct maillon_animal *ptr_llc_animal;
struct maillon_animal
{
    char nom[20];
    char race[20];
    char espece[20];
    char regime[20];
    char naissance[20];
    char entree[20];
    char origine[20];
    int poid;
    ptr_llc_animal adr;
};

typedef struct maillon_enclo *ptr_llc_enclo;
struct maillon_enclo
{
    char nom[20];
    int longeur,largeur,nbr_max,poid;
    char type[20];
    char etat[20];
    ptr_llc_enclo adr;
};

typedef struct maillon_depart *ptr_llc_depart;
struct maillon_depart
{
    char nom[20];
    char date_dprt[120];
    char date_entr[10];
    ptr_llc_depart adr;
};

typedef struct maillon_affect *ptr_llc_affect;
struct maillon_affect
{
    char animal[20];
    char enclo[20];
    char date_affect[10];
    ptr_llc_affect adr;
};






