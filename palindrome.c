/*
	Plindrome
	Un mot est dit palindrome s'il est le même lu à l'envers.
	par Joseph Konka
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void SaisirChaineDeCaracteres(char *chaine)
{
	printf(">>>");
	scanf("%s", chaine);
}

int EstPalindrome(char *chaine)
{
	int oui=1, n, i;

	n=strlen(chaine);
	i=0;
	while(oui && i<n)
	{
		if(*(chaine+i)!=(*(chaine+n-1-i)))
		{
			oui=0;
		}
		i++;
	}
	return oui;
}

int main()
{
	char motLu[MAX];

	printf("Entrer une chaîne de caractère\n");
	SaisirChaineDeCaracteres(motLu);

	printf("Test Palindrome: %d\n", EstPalindrome(motLu));

	return 0;
}