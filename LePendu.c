# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "Fonctions.h"
# define COUPS_MAX 10
/*-----------------------------------------
|                                          |
|           Programme le Pendu             |
|                                          |
-----------------------------------------*/


int main(int argc, char *argv[])
{
    int coupsRestant = COUPS_MAX;
    char *mot=NULL;
    mot = recupererUnMotDansLeDictionnaire(mot);
    dictLettreTrouveGenerator();
    char *copieMot;
    char proposition;
    int nombreDeCoups;
    int gagne=0;
    copieMot = malloc(sizeof( mot ));
    copieMot = strcpy(copieMot, mot);
    printf("Bienvenue dans le pendu\n\n");
    while (gagne!=1 && coupsRestant>0)
    {
        printf("Il vous reste %d essai(s)", coupsRestant);
        printf("Quel est le mot secret ?\t");
        Etoile(mot, copieMot);
        printf("%s", copieMot);
        proposition = lireLettre();
        nombreDeCoups++;
        miseAJour(mot, proposition);
        punisher(mot, proposition, &coupsRestant);
        gagne = statut(gagne);
        if(gagne)
        {
            printf("Vous avez gagne en %d coups\n", nombreDeCoups);
            printf("Le mot était %s\n", mot);
            free(copieMot);
        }
    }
    if(coupsRestant == 0)
    {
        puts("Vous avez perdu");
        printf("Le mot était %s\n", mot);
        free(copieMot);
    }
    return 0;
}


/*--------------------------------- Fin du programme -----------------------------------*/
