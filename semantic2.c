#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef
enum {
    tChar, tShort, tInt, tLong, tFloat, tDouble,
    tTableau, tFonction, tProcedure ,tProgram
} typePossible;

typedef
struct listeDescripteursTypes {
    struct descripteurType *info;
    struct listeDescripteursTypes *suivant;
} listeDescripteursTypes;

typedef
struct descripteurType {
    typePossible classe;
    union {
        struct {
            int nombreElements;
            struct descripteurType *typeElement;
        } casTableau;
        struct {
            listeDescripteursTypes *typesArguments;
        } casProcedure;
        struct {
            listeDescripteursTypes *typesArguments;
            struct descripteurType *typeResultat;
        } casFonction;
    } attributs;
} descripteurType;

descripteurType *nouveau(typePossible classe) {
    descripteurType *res = malloc(sizeof(descripteurType));
    assert(res != NULL);
    res->classe = classe;
    return res;
}

struct {
    char *lexeme;
    int uniteLexicale;
} motRes[N];


int memeType(descripteurType *a, descripteurType *b) {
    if (a->classe != b->classe)
    return 0;
    switch (a->classe) {
        case tPointeur:
            return memeType(a->attributs.casPointeur.typePointe,
                            b->attributs.casPointeur.typePointe);
        case tTableau:
            return a->attributs.casTableau.nombreElements ==
                   b->attributs.casTableau.nombreElements
                && memeType(a->attributs.casTableau.typeElement,
                            b->attributs.casTableau.typeElement);
        case tStructure:
            return memeListeTypes(a->attributs.casStructure.typesChamps,
                                  b->attributs.casStructure.typesChamps);
        case tFonction:
            return memeType(a->attributs.casFonction.typeResultat,
                            b->attributs.casFonction.typeResultat)
                && memeListeTypes(a->attributs.casFonction.typesArguments,
                                  b->attributs.casFonction.typesArguments);
        default:
            return 1;
    }
}
int memeListeTypes(listeDescripteursTypes *a, listeDescripteursTypes *b) {
    while (a != NULL && b != NULL) {
        if ( ! memeType(a->info, b->info))
            return 0;
        a = a->suiv;
        b = b->suiv;
    }
    return a == NULL && b == NULL;
}

typedef
struct {
    char *identif;
    descripteurType type;
    int used = 0 ;
} ENTREE_DICO;

#define TAILLE_INITIALE_DICO 200
#define INCREMENT_TAILLE_DICO 25


int maxDico, sommet, base;

void creerDico(void) {
    maxDico = TAILLE_INITIALE_DICO;
    dico = malloc(maxDico * sizeof(ENTREE_DICO));
    if (dico == NULL)
        erreurFatale("Erreur interne (pas assez de mémoire)");
    sommet = base = 0;
}

void agrandirDico(void) {
    maxDico = maxDico + INCREMENT_TAILLE_DICO;
    dico = realloc(dico, maxDico);
    if (dico == NULL)
        erreurFatale("Erreur interne (pas assez de mémoire)");
}

void erreurFatale(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(-1);
}

void ajouterEntree(char *identif, descripteurType type) {
    if (sommet >= maxDico)
        agrandirDico();
    dico[sommet].identif = malloc(strlen(identif) + 1);
    if (dico[sommet].identif == NULL)
        erreurFatale("Erreur interne (pas assez de mémoire)");
    strcpy(dico[sommet].identif, identif);
    dico[sommet].type = type;
    sommet++;
}