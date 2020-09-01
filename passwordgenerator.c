/*
    Générateur de mot.
    On choisit le nombre de caractères
    On choisit les caractères au hazard


    par Joseph Konka
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 8
#define MAX 15
#define BEGIN 48 // code ASCII du caractère 0
#define END 122 // code ASCII du caractère z

char TirerUnCaractere(void)
{
    int code;
    char car;
    
    // On tire un nombre entre 
    code = rand()%(END-BEGIN+1)+BEGIN;
    // Conversion du code en caractère
    car = code;
    
    return car;
}

void GenererPassword()
{
    char password[MAX]="";
    int i,n, lg;
    
    // On tire un nombre entre 8 et 15, taille du mot de passe
    n = rand()%(MAX-MIN+1)+MIN;
    
    for(i=0;i<n;i++)
    {
        password[i] = TirerUnCaractere();
    }
    printf("Longueur: %d\tMot de passe: %s\n", n, password);
}

int main()
{
    int i;
    
    srand(time(NULL));
    
    printf("******************************\n");
    printf("* Générateur de mot de passe *\n");
    printf("******************************\n");
    
    for(i=0;i<10;i++)
    {
        GenererPassword();
    }
    printf("** FIN **\n");
    
    return 0;
}