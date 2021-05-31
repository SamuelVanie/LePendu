# ifndef DEF_FONCTIONS
# define DEF_FONCTIONS
    char lireLettre();
    void miseAJour(char mot[], char lettre);
    void Etoile(const char mot[], char copieMot[]);
    int statut(int bis);
    void punisher(const char mot[], const char proposition, int* coupsRestant);
    char* recupererUnMotDansLeDictionnaire(char mot[]);
    void dictLettreTrouveGenerator();
    int nombreDeMotDansLeDictionnaire();
# endif