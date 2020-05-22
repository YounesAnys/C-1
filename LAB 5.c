#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Constantes symboliques
#define G 9.8  // en m/s^2
#define Nbr 50   // nombre de points à calculer
#define VRAI 1
#define FAUX 0
#define NBR 2
// Structure pour entrée de l'utilisateur
// et tableaux pour données de sortie

typedef struct
{
    // Ajouter les membres de la structure
    double masse; // en kg
    double trainee;
    double Tmax;
} PARACHUTISTE;
// Prototype de fonction
void obtientEntree(PARACHUTISTE *);
double calculeVitesse( PARACHUTISTE *, double);
void afficheTable(PARACHUTISTE *);

void main()
{

PARACHUTISTE para;

double t;

obtientEntree(&para);

calculeVitesse(&para, t);

afficheTable(&para);

}

void obtientEntree(PARACHUTISTE *Ptr)
{
     // Déclaration de variable
    int intro;

    // obtient l'entrée de l'utilsateur
do {intro = FAUX;
    printf("La valeur de la masse : ");
    scanf("%lf", &Ptr->masse);
    if(&Ptr->masse >=0) intro = VRAI;}
        while(intro == FAUX);

do {intro = FAUX;
    printf("La valeur de la trainee de trainee : ");
    scanf("%lf", &Ptr->trainee);
    if(&Ptr->trainee >=0) intro = VRAI;}
        while(intro == FAUX);

do {intro = FAUX;
    printf("Donnez le temps maximal : ");
    scanf("%lf", &Ptr->Tmax);
    if(&Ptr->Tmax >=0) intro = VRAI;}
        while(intro == FAUX);
 }
/*-----------------------------------------------------------------------
Function: calculeVitesse
Parameters:
    pPtr   - pointeur à une structure du type PARACHUTISTE
Description: Avec la masse, le coeff. de trainée, et le temps final
             donnés dans la structure référée, calcule et stocke N+1 points
             dans les deux tableaux retrouvés dans la variable structure référée.
------------------------------------------------------------------------*/
double calculeVitesse(PARACHUTISTE *Ptr, double t)
{
    double vitesse;
    vitesse = ((G*Ptr->masse)/Ptr->trainee);
    vitesse = vitesse*(1-exp(-(Ptr->trainee*t/Ptr->masse)));
    return vitesse;
}
/*-------------------------------------------------------------------------*/
void afficheTable(PARACHUTISTE *Ptr)
{
    // Déclaration des variables

    int ix;
    double t;
    double temps[Nbr];
    double vitesse[Nbr];
    double inc = (Ptr->Tmax)/Nbr;
    for(int x = 0; x<Nbr-1; x++)
    {
        temps[x] = t;
        vitesse[x] = calculeVitesse(PARACHUTISTE *Ptr, double t);
        t = t + inc;
    }
    printf("La variation de la vitesse d un parachutiste avec une masse de %.2lf kg, un coefficient de trainee de %.2lf kg/s est :\n", Ptr->masse, Ptr->trainee);
    printf("%10s        %10s\n", "Temps t1", "Vitesse ");
    printf("-----------------\n");
    for(ix = 0; ix < Nbr-1; ix = ix +1)
        printf("%10.3f      %10.2f\n", temps[ix], vitesse[ix]);
}
