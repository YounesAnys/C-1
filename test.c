#include<stdio.h>
/*------------------------------------------------------------------
Fichier: volumeCylindre.c
Description: Montre commen le volume d'un liquide dans un cylindre � l'horizontal
             ou � la vertical selon la profondeur du liquide.
---------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
// Des constantes symboliques comme index dans un tableau
#define VRAI 1
#define FAUX 0
#define NBR_VALEURS 20  // Nombre de paires de valeurs � afficher dans un tableau
#define P_IX 0 // Index pour �lements contenants les valeurs de profondeurs (rang�e 0)
#define V_IX 1 // index pour �l�ments contenants les valeur de volume (rang�e 1)
// D�finitions de structure
typedef struct
{
    char orientation;  // h pour horizontal et v pour vertical
    double rayon;
    double longueur;
} CYLINDRE;
// Prototypes de fonction
double getValeurPositive();
char getOrientation();
double calculeVolume(CYLINDRE, double);
/*---------------------------------------------------------------------
Fonction: main
Description: Obtient de l'utilisateur le rayon et la longueur du cylindre
             ainsi que son orientation.  Rempli un tableau avec des valeurs
             temps/vitesse pour ensuite afficher un tableau avec ces valeurs.
------------------------------------------------------------------------*/
int main(void)
{
    // d�clarations des variables
    CYLINDRE cyl;
    // � notez que qu'avec le tableau 2D suivant
    //      valeurs[P_IX] est un tableau 1D contenant les valeurs de profondeur
    //      valeurs[V_IX] est un tableau 1D contenant les valeurs de volume
    double valeurs[2][NBR_VALEURS];
    // Pour remplir le tableau
    double profondeur; // profondeur du liquide
    int ix; // index de colonne.
    double inc;  // Incr�mentation de la profondeur

    // Demande � l�utilisateur d�entrer les donn�es
    printf("Veuillez entrer une valeur pour le rayon: ");
    cyl.rayon = getValeurPositive();
    printf("Veuillez entrer les valeurs pour la longueur: ");
    cyl.longueur = getValeurPositive();
    cyl.orientation = getOrientation();
    // Remplir le tableau 2D avec paires de valeurs profondeur/volume
    profondeur = 0;
    if(cyl.orientation == 'v') inc = cyl.longueur/(NBR_VALEURS-1);
    else inc = cyl.rayon/(NBR_VALEURS-1);
    for(ix = 0; ix < NBR_VALEURS; ix = ix + 1)
    {
        valeurs[P_IX][ix] = profondeur;
        valeurs[V_IX][ix] = calculeVolume(cyl, profondeur);
        profondeur = profondeur + inc;
    }
    // Afficher un tableau � l'�cran du changement de volume avec la profondeur du liquide
    printf("Pour un cylindre de rayon %.3f et longeur %.3f",
           cyl.rayon, cyl.longueur);
    if(cyl.orientation == 'v') printf("a la vertical\n");
    else printf("a l'horizontal\n");
    printf("%10s    %10s\n","Profondeur", "Volume");
    printf("-------------------\n");
    for(ix = 0; ix <= NBR_VALEURS; ix = ix + 1)
        printf("%10.3f %10.2f\n",valeurs[V_IX][ix], valeurs[P_IX][ix]); // Affiche rang�e
    return(0);
}
/*-----------------------------------------------------------------------
Fonction: getValeurPositive
Retourne:  Une valeur strictement positive (>0).
Description: Lit une valeur r�elle de l'utilisateur, verifie la valeur
             (doit �tre strictement positive), et retourne la valeur.
------------------------------------------------------------------------*/
double getValeurPositive()
{
    double valeur;
    do
    {
        scanf("%lf", &valeur);
        if(valeur <= 0.0)
            printf("La valeur doit etre plus grand que zero: ");
    }
    while(valeur <= 0.0);
    return(valeur);
}
/*-----------------------------------------------------------------------
Fonction: getOrientation
Retourne: 'v' pour vertical et 'h' pour horizontal.
Description: Demande � l'utilisateur l'orientation du cylindre: v pour
             vertical et h pour horizontal.
------------------------------------------------------------------------*/
char getOrientation()
{
    char orientation;
    int drapeau;
    do
    {
        drapeau = FAUX;
        printf("Donnez l'orientation du cylindre, v pour vertical, h pour horizontal: ");
        fflush(stdin);
        scanf("%c", &orientation);
        if(orientation != 'v' && orientation != 'h')
        {
            printf("Mauvaise entree.\n");
            drapeau = VRAI;
        }
    }
    while(drapeau);
    return(orientation);
}
/*-----------------------------------------------------------------------
Fonction: calculeVolume
Param�tres:
    cyl - variable de structure donnant caract�ristiques du cylindre.
    profondeur - la profondeur du volume
Retourne: le volume du liquide dans le cylindre.
Description: Calcule le volume d'un liquide dans un cylindre de rayon r,
             longueur lng, et ayant une profondeur donn�e par le param�tre.
------------------------------------------------------------------------*/
double calculeVolume(CYLINDRE cyl, double profondeur)
{
    // D�clarations de variables
    double vol;  // volume du liquide
    // le calcule d�pend de l'orientation du cylindre
    if(cyl.orientation = 'v')
        vol = M_PI*cyl.rayon*cyl.rayon*profondeur;
    else
    {
        // Utilise plusieurs intructions pour faire le calcule
        // Les valeurs interm�diaires sont accumul�es dans vol
        vol = sqrt(2*cyl.rayon*profondeur - profondeur*profondeur);
        vol = (cyl.rayon - profondeur)*vol;
        vol = (pow(cyl.rayon,2)*acos((cyl.rayon - profondeur)/cyl.rayon)) - vol;
        vol = vol*cyl.longueur;
    }
    return(vol);
}
