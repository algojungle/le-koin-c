/*
	Une école qui organise un concours fait appel à vous pour
	écrire un programme pour la gestion des inscriptions et des résultats.

	1. Inscrire les candidats
	2. Ajouter les notes des candidats
	3. Calculer les moyennes et afficher les résultats

	par Joseph Konka
*/

#include <stdio.h>
#include <stdlib.h>


// Longueur maximale des noms
#define LONGUEUR 20
// Nombre maximal d'étudiants
#define NBRE 100


// Modèle du candidat
struct Candidat
{
	char nom[LONGUEUR];
	char prenom[LONGUEUR];
	int age;
	int fr;
	int ang;
	int math;
	int pc;
	float moyenne;
	int rang;
};

// Fonctions
struct Candidat CreerCandidat(void)
{
	// Fonction qui permet de créer un candidat
	struct Candidat candidatx;

	printf("Nom: ");
	scanf("%s", candidatx.nom);
	printf("Prenom: ");
	scanf("%s", candidatx.prenom);
	printf("Age: ");
	scanf("%d", &candidatx.age);

	return candidatx;
}

int SaisirNote(void)
{
	// Fonction qui saisir un entier compris entre 0 et 20 (une note)
	int note=0;

	printf(">>>");
	scanf("%d", &note);

	// On contrôle la valeur saisie
	while(note<0 || note>20)
	{
		printf("Entree invalide - Note entre 0 et 20\n");
		printf(">>>");
		scanf("%d", &note);
	}

	return note;
}

void SaisirTouteLesNotes(struct Candidat *candidatx)
{
	int SaisirNote(void);

	printf("Francais\n");
	candidatx->fr = SaisirNote();
	printf("Anglais\n");
	candidatx->ang = SaisirNote();
	printf("Mathematiques\n");
	candidatx->math = SaisirNote();
	printf("Sciences-Physiques\n");
	candidatx->pc = SaisirNote();

	// Calcul de la moyenne
	candidatx->moyenne = (candidatx->fr+candidatx->ang+candidatx->math+candidatx->pc) / 4.0;
}

void AfficherCandidat(struct Candidat candidatx)
{
	// Indentité
	printf("Nom: %s\n", candidatx.nom);
	printf("Prenom: %s\n", candidatx.prenom);
	printf("Age: %d\n", candidatx.age);

	// Infos académiques - Notes et Moyennes
	if(candidatx.fr)
	{
		printf("Francais: %d\n", candidatx.fr);
	}
	if(candidatx.ang)
	{
		printf("Anglais: %d\n", candidatx.ang);
	}
	if(candidatx.math)
	{
		printf("Mathematiques: %d\n", candidatx.math);
	}
	if(candidatx.pc)
	{
		printf("Sciences-Physiques: %d\n", candidatx.pc);
	}

	if(candidatx.moyenne)
	{
		printf("Moyenne: %0.2f\n", candidatx.moyenne);
	}
}

void AfficherCandidatEnListe(struct Candidat candidatx)
{
	printf("%s\t%s\t%d\n", candidatx.nom, candidatx.prenom, candidatx.age);
}

void AfficherListeCandidats(struct Candidat *liste)
{
	// Afficher la liste des candidats inscrits
	int i=0;

	printf("Nom\tPrenom\tAge\n");
	while(*(liste+i)->nom!=NULL)
	{
		AfficherCandidatEnListe(*(liste+i));
		i++;
	}
}

void AfficherResultats(struct Candidat *liste)
{
	// Afficher la liste des candidats inscrits
	struct Candidat candidatx;
	int i=0;

	printf("Rang\tNom\tPrenom\tMoyenne\n");
	while(*(liste+i)->nom!=NULL)
	{
		candidatx = *(liste+i);
		printf("%d\t%s\t%s\t%0.2f\n", i+1, (candidatx).nom, candidatx.prenom, candidatx.moyenne);
		i++;
	}
}

int OuiNon(void)
{
	// Fonction pour répondre oui ou non
    char saisie[10];
    int verif,choix;
    do
    {
        printf("1- OUI\t0- NON\n");
        do
        {
            printf("Reponse : ");
            scanf("%s", saisie);
            verif=sscanf(saisie,"%d",&choix);
        }while(verif<1);
    }while(choix!=1 && choix!=0);

    return choix;
}

int main()
{
	// Prototypes
	struct Candidat CreerCandidat(void);
	void SaisirTouteLesNotes(struct Candidat *);
	void AfficherListeCandidats(struct Candidat *);
	void AfficherResultats(struct Candidat *);

	// Variables
	struct Candidat candidats[NBRE], tampon;
	int nbre_inscrits=0, reponse=0, i, ok=0;

	/* Début du programme */
	printf("********************************\n");
	printf("************þþþþþþþ*************\n");
	printf("********************************\n");
	printf("\n");

	// Inscrire les candidats
	printf("********************************\n");
	printf("Enregistrement des candidats\n");
	printf("********************************\n");
	do
	{
		nbre_inscrits++;
		printf("Renseigner l'identite du candidat %d\n", nbre_inscrits);
		candidats[nbre_inscrits-1]=CreerCandidat();

		printf("\nY'a t-il encore des candidats à enregistrer ?\n");
		reponse = OuiNon();
		printf("%d\n", reponse);
		printf("\n");
	}while(reponse);

	// Affichage de la liste des inscrits
	printf("********************************\n");
	printf("Liste des candidats inscrits\n");
	printf("********************************\n");
	AfficherListeCandidats(candidats);

	// Saisir les notes des candidats
	printf("\n********************************\n");
	for(i=0; i<nbre_inscrits; i++)
	{
		printf("Saisir les notes de %s %s\n", candidats[i].nom, candidats[i].prenom);
		SaisirTouteLesNotes(&candidats[i]);
		printf("\n");
	}

	// Ranger les candidats suivant les moyennes - Tri bulle
	do
	{
		ok = 0;
		for(i=0; i<nbre_inscrits-1; i++)
		{
			if(candidats[i].moyenne < candidats[i+1].moyenne)
			{
				tampon = candidats[i];
				candidats[i] = candidats[i+1];
				candidats[i+1] = tampon;
				ok = 1;
			}
		}
	}while(ok);

	// Afficher les résulats
	printf("********************************\n");
	printf("Liste des resultats\n");
	printf("********************************\n");
	AfficherResultats(candidats);


	return 0;

	/* Fin du programme  */
}
