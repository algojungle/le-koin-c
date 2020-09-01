/*
    Statistique descriptive - Diagramme en bâtons
    par Joseph Konka
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10 //nombre maximal de modalités
#define MAX 18 //Valeur maximale

void AfficherTableauEffectifs(char *mod, int *eff)
{
    //Cette fonction affiche le tableau des effectifs
    int i;
    
    //Ligne
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("--------");
        i++;
    }
    printf("\n");
    //Modalités
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("%c\t",*(mod+i));
        i++;
    }
    printf("\n");
    //Ligne
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("--------");
        i++;
    }
    printf("\n");
    //Effectifs
    i=0;
    while(*(eff+i)!=NULL)
    {
        printf("%d\t",*(eff+i));
        i++;
    }
    printf("\n");
    //Ligne
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("--------");
        i++;
    }
    printf("\n");
}

void DessinerDiagramme(char *mod, int *eff)
{
    int i,j;

    //Ligne
    printf("-");
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("--------");
        i++;
    }
    printf("\n");
    for(i=0; i<MAX; i++)
    {
        printf("%d", MAX-i);
        j=0;
        while(*(mod+j)!='\0')
        {
            if(*(eff+j)>=(MAX-i))
            {
                printf("\t#");
            }
            else
            {
                printf("\t ");
            }
            j++;
        }
        printf("\n");
    }
    //Ligne
    printf("-");
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("--------");
        i++;
    }
    printf("\n");
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("\t%c",*(mod+i));
        i++;
    }
    //Ligne
    printf("\n-");
    i=0;
    while(*(mod+i)!='\0')
    {
        printf("--------");
        i++;
    }
    printf("\n");
}

int main()
{
    char modalites[N]="ABCDE";
    int effectifs[N]={12,9,15,7,18};
    
    printf("Tableau des effectifs\n");
    AfficherTableauEffectifs(modalites, effectifs);
    
    printf("Diagramme en batons\n");
    DessinerDiagramme(modalites, effectifs);
    
    return 0;
}