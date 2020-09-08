/*
    Écrire un programme C qui:

    1. Lit un chiffre et l'affiche
    2. Lit un nombre et l'affiche

    par Joseph Konka (Le Koin C)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 // Nombre de chiffres maximal
#define HEIGHT 5 // Hauteur des chiffres


// Fonctions brique pour afficher les lignes
void print111()
{
    printf("###");
}
void print101()
{
    printf("# #");
}
void print001()
{
    printf("  #");
}
void print100()
{
    printf("#  ");
}
// Ligne 1
void printLigne1(int digit)
{
    printf(" ");
    switch(digit)
    {
        case 0:
        print111();
        break;
        case 1:
        print001();
        break;
        case 2:
        print111();
        break;
        case 3:
        print111();
        break;
        case 4:
        print101();
        break;
        case 5:
        print111();
        break;
        case 6:
        print111();
        break;
        case 7:
        print111();
        break;
        case 8:
        print111();
        break;
        case 9:
        print111();
        break;
    }
}
// Ligne 2
void printLigne2(int digit)
{
    printf(" ");
    switch(digit)
    {
        case 0:
        print101();
        break;
        case 1:
        print001();
        break;
        case 2:
        print001();
        break;
        case 3:
        print001();
        break;
        case 4:
        print101();
        break;
        case 5:
        print100();
        break;
        case 6:
        print100();
        break;
        case 7:
        print001();
        break;
        case 8:
        print101();
        break;
        case 9:
        print101();
        break;
    }
}
// Ligne 3
void printLigne3(int digit)
{
    printf(" ");
    switch(digit)
    {
        case 0:
        print101();
        break;
        case 1:
        print001();
        break;
        case 2:
        print111();
        break;
        case 3:
        print111();
        break;
        case 4:
        print111();
        break;
        case 5:
        print111();
        break;
        case 6:
        print111();
        break;
        case 7:
        print001();
        break;
        case 8:
        print111();
        break;
        case 9:
        print111();
        break;
    }
}
// Ligne 4
void printLigne4(int digit)
{
    printf(" ");
    switch(digit)
    {
        case 0:
        print101();
        break;
        case 1:
        print001();
        break;
        case 2:
        print100();
        break;
        case 3:
        print001();
        break;
        case 4:
        print001();
        break;
        case 5:
        print001();
        break;
        case 6:
        print101();
        break;
        case 7:
        print001();
        break;
        case 8:
        print101();
        break;
        case 9:
        print001();
        break;
    }
}
// Ligne 5
void printLigne5(int digit)
{
    printf(" ");
    switch(digit)
    {
        case 0:
        print111();
        break;
        case 1:
        print001();
        break;
        case 2:
        print111();
        break;
        case 3:
        print111();
        break;
        case 4:
        print001();
        break;
        case 5:
        print111();
        break;
        case 6:
        print111();
        break;
        case 7:
        print001();
        break;
        case 8:
        print111();
        break;
        case 9:
        print111();
        break;
    }
}
// Fonction qui affiche une ligne (niveau) d'un chiffre
void AfficherUneLigneDuChiffre(int line, int digit)
{
    switch(line)
    {
        case 1:
        printLigne1(digit);
        break;
        case 2:
        printLigne2(digit);
        break;
        case 3:
        printLigne3(digit);
        break;
        case 4:
        printLigne4(digit);
        break;
        case 5:
        printLigne5(digit);
        break;
    }
}
// Fonction qui affiche un chiffre
void AfficherUnChiffre(int digit)
{
    int i;

    for(i=0; i<HEIGHT; i++)
    {
        AfficherUneLigneDuChiffre(i+1, digit);
        printf("\n");
    }
}
// Fonction qui affiche une ligne (niveau) d'un nombre
void AfficherUneLigneDuNombre(int line, int *number, int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        AfficherUneLigneDuChiffre(line, number[i]);
    }
    printf("\n");
}
// Fonction qui affiche un nombre
void AfficherUnNombre(int *number, int length)
{
    int ligne;
    
    for(ligne=1; ligne<HEIGHT+1; ligne++)
    {
        AfficherUneLigneDuNombre(ligne, number, length);
    }
    printf("\n");
}
// Fonction qui convertit la chaine en tableaux d'entier
void CharVersInt(char *car, int *number, int length)
{
    int i;

    for(i=0; i<length; i++)
    {
        number[i] = car[i] - '0';
    }
}

int main()
{
    int ligne, chiffre, longueur;
    char nombre[N+1];
    int Nombre[N]={0,1,2,3,4,5,6,7,8,9};

    // Démo
    AfficherUnNombre(Nombre, N);
    printf("\n");
    
    // Lecture et Affichage du chiffre
    printf("Entrer un chiffre\n");
    printf(">>> ");
    scanf("%d", &chiffre);
    printf("\n");
    AfficherUnChiffre(chiffre);
    printf("\n");
    
    // Lecture et Affichage du nombre
    printf("Entrer un nombre\n");
    printf(">>> ");
    scanf("%s", nombre);
    printf("\n");

    longueur = strlen(nombre);

    // Conversion en nombre
    CharVersInt(nombre, Nombre, longueur);

    AfficherUnNombre(Nombre, longueur);
    
    return 0;
}