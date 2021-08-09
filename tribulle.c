#include<stdio.h>
#include<stdlib.h>

#define N 10


void AfficherTableau(int *tab, int n)
{
    int i=0;
    printf("[");
    while(i<n)
    {
      
        printf("%d ", *(tab+i));
        i++;
    }
    printf("]");
}

int main()
{
    int tableau[N]={5,1,6,7,9,2,3,0,4,8};
    int i,tmp,ok;

    // Tableau before
    printf("Before:\t");
    AfficherTableau(tableau, N);
    printf("\n");
    do
    {
        ok=0;
        for(i=0;i<N-1;i++)
        {
            if(tableau[i]<tableau[i+1])
            {
                tmp=tableau[i];
                tableau[i]=tableau[i+1];
                tableau[i+1]=tmp;
                ok=1; // Something changes
            }
        }
    }while(ok);

    // Tableau after
    printf("After:\t");
    AfficherTableau(tableau, N);
    printf("\n");

    return 0;
}
