# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "Fonctions.h"
# include <time.h>
# define TAILLE 20
# define DICT "dict.txt"
# define NUMERO_PREMIERE_LIGNE_DICT 1 

/* These are all my functions for my game called LePendu */

char motChoisi[TAILLE] = "";
int *lettreTrouve = NULL;    // dictionnaire contenant 1 a la position adequate si on a trouve la lettre

char lireLettre(){   
    /* lis la lettre que le user a entre */
    char caractere=0;
    caractere = getchar();  // prends la lettre
    caractere = toupper(caractere);
    while (getchar()!='\n');    // vide toutes les autres lettres en memoire
    return caractere;
}

int nombreDeMotDansLeDictionnaire(){
    FILE *fichier = fopen(DICT, "r");
    char unMot[TAILLE];
    int nombre = 0;
    while(!feof(fichier)){
        fgets(unMot, TAILLE, fichier);
        ++nombre;
    }
    return nombre;
}

char* recupererUnMotDansLeDictionnaire(char mot[]){
    /* Va recuperer un mot aleatoire dans notre dictionnaire */
    FILE *file = fopen(DICT, "r");
    if(file==NULL){
        puts("Impossible d'ouvrir le fichier de dictionnaire\n");
        exit(EXIT_FAILURE);
    }
    int numeroDuMot;    
    srand(time(0));
    numeroDuMot =  (rand() % (nombreDeMotDansLeDictionnaire() - NUMERO_PREMIERE_LIGNE_DICT + 1)) + NUMERO_PREMIERE_LIGNE_DICT;
    while(numeroDuMot!=0){
        --numeroDuMot;
        fgets(motChoisi, TAILLE, file);
    }
    fscanf(file, "%[^\n]", motChoisi);
    fclose(file);
    return &motChoisi[0];
}

void dictLettreTrouveGenerator(){
    /* Cette fonction va allouer notre dictionnaire en fonction du nombre de lettre du mot a trouver*/
    lettreTrouve = calloc(strlen(motChoisi), sizeof(int));
}

void miseAJour(char mot[], const char lettre){
    // mise a jour de mon dictionnaire en fonction de la lettre entre
    char *pointeurMot=NULL;
    int parcoureur=0;
    pointeurMot = &mot[0];
    for(parcoureur = 0; parcoureur<strlen(motChoisi); parcoureur++)
    {
        if (lettre == *pointeurMot)
        {
            lettreTrouve[parcoureur] = 1;
            pointeurMot++;
        }
        else pointeurMot++;
    }
}


void Etoile(const char mot[], char copieMot[]){
    // met les etoiles a la position adequate en fonction du contenu du tableau
    int *pointeurSurLettre=NULL;
    char *pointeurMot=NULL, *pointeurCopieMot=NULL;
    pointeurMot = &mot[0];
    pointeurCopieMot = &copieMot[0];
    pointeurSurLettre = &lettreTrouve[0];
    for(int i=0; i<strlen(motChoisi); i++)
    {
        if (*pointeurSurLettre == 1)
        {
            *pointeurCopieMot = *pointeurMot;
            pointeurCopieMot++;
            pointeurMot++;
            pointeurSurLettre++;
        }
        else
        {
            *pointeurCopieMot = '*';
            pointeurCopieMot++;
            pointeurMot++;
            pointeurSurLettre++;
        }
    }
}


int statut(int bis){
    // statut gagne ou pas, maj du booleen
    int *pointeurLettre=NULL;
    pointeurLettre = &lettreTrouve[0];
    for(int i=0; i<strlen(motChoisi); i++)
    {
        if (*pointeurLettre)
        {
            pointeurLettre++;
        }
        else
            return 0;
    }
    free(lettreTrouve); 
    return 1;
}

void punisher(const char mot[], const char proposition, int *coupsRestant){
    // retire 1 sur le nombre de coups restant
    if (strchr(mot, proposition) == NULL) --(*coupsRestant);
}