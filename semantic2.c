#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "semantic.h"


int number_errors = 0 ;
typedef
struct listeDescripteursTypes {
    struct descripteurType *info;
    struct listeDescripteursTypes *suivant;
} listeDescripteursTypes;
void concatenateTypeList(listeDescripteursTypes * list1,listeDescripteursTypes * list2)
{
    listeDescripteursTypes * curr = list1 ;
    if (list1== NULL)
        {list1 = list2 ;
         return ;}
    while (curr->suivant)
        curr = curr-> suivant ;
    curr-> suivant = list2 ;
}
const char* getTypeName(typePossible type)
{
   switch (type)
   {
      case tChar: return "tChar";
      case tShort: return "tShort";
      case tInt: return "tInt";
      case tLong: return "tLong";
      case tFloat: return "tFloat";
      case tDouble: return "tDouble";
      case tTableau: return "tTableau";
      case tFonction: return "tFonction";
      case tProcedure: return "tProcedure";
      case tProgram: return "tProgram";
      case tString: return "tString";
      case tBool: return "tBool";
      case tVoid: return "tVoid";
   }
}
const typePossible getTypeByName(char *  type)
{

      if( strcmp("tChar",type)==0 ) return tChar;
      if( strcmp( "tShort",type)==0 ) return tShort;
      if( strcmp( "integer",type)==0 ) return tInt;
      if( strcmp( "tLong",type)==0 ) return tLong;
      if( strcmp( "tFloat",type)==0 ) return tFloat;
      if( strcmp( "double",type)==0 ) return tDouble;
      if( strcmp( "tTableau",type)==0 ) return tTableau;
      if( strcmp( "function",type)==0 ) return tFonction;
      if( strcmp( "procedure",type)==0 ) return tProcedure;
      if( strcmp( "program",type)==0 ) return tProgram;
      if( strcmp( "string",type)==0 ) return tString;
      if( strcmp( "bool",type)==0 ) return tBool;
      if( strcmp( "void",type)==0 ) return tVoid;

}
typedef
struct descripteurType {
    typePossible classe;
    union {
        struct {
            int indiceDebut;
            int indiceFin;
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

descripteurType * nouveau(typePossible classe) {
    descripteurType *res = malloc(sizeof(descripteurType));

    assert(res != NULL);
    res->classe = classe;

    return res;
}

struct {
    char *lexeme;
    int uniteLexicale;
} motRes[50];

int memeListeTypes(listeDescripteursTypes *a, listeDescripteursTypes *b);
int memeType(descripteurType *a, descripteurType *b) {
    if (a->classe != b->classe)
    return 0;
    switch (a->classe) {
        case tTableau:
            return (a->attributs.casTableau.indiceDebut ==
                   b->attributs.casTableau.indiceDebut)
                &&
                   (a->attributs.casTableau.indiceFin ==
                   b->attributs.casTableau.indiceFin)
                && memeType(a->attributs.casTableau.typeElement,
                            b->attributs.casTableau.typeElement);
        case tProcedure:
            return memeListeTypes(a->attributs.casProcedure.typesArguments,
                                  b->attributs.casProcedure.typesArguments);
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
        a = a->suivant;
        b = b->suivant;
    }
    return a == NULL && b == NULL;
}

typedef
struct {
    char *identif;
    descripteurType type;
    int used  ;
    int declarationLine ;
    int initialised ;
} ENTREE_DICO;

#define TAILLE_INITIALE_DICO 200
#define INCREMENT_TAILLE_DICO 25

ENTREE_DICO * dico ;
int maxDico, sommet, base;
void erreurFatale(char *message) {
    fprintf(stderr, "Erreur fatale !!!!!!! :\n%s\n", message);
    exit(1);
}
void creerDico() {
    maxDico = TAILLE_INITIALE_DICO;
    dico = (ENTREE_DICO*)  malloc(maxDico * sizeof(ENTREE_DICO));
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
void printCurrentDict() ;
int primitiveType (descripteurType  type){
    if ((type.classe==tChar)|| (type.classe==tShort)||( type.classe==tInt)||(type.classe== tLong)|| (type.classe==tFloat))
        return 1 ;

    if ((type.classe==tDouble)||(type.classe==tTableau)||(type.classe==tProgram)||(type.classe==tString)||(type.classe==tBool))
        return 1;
    return 0;
}
int verifAjout(char *identif, descripteurType  type){
    int i ;
    for (i=base ;i<sommet;i++)
        if (!strcmp(identif,dico[i].identif)){
            if ((primitiveType(type)&& primitiveType(dico[i].type))||memeType(&type,&dico[i].type))
                return dico[i].declarationLine ;
    }
    return -1 ;
}

typePossible verifMethodCall(char * identif , listeDescripteursTypes * liste ){
    int i ;
    for (i=base ;i<sommet;i++)
        if (!strcmp(identif,dico[i].identif)){
<<<<<<< HEAD

            if (!primitiveType(dico[i].type)){

                if (dico[i].type.classe ==tProcedure){

                    if (memeListeTypes(dico[i].type.attributs.casProcedure.typesArguments,liste)){
                        return tVoid;
                    }
                }
                else if (dico[i].type.classe ==tFonction){
                    if (memeListeTypes(dico[i].type.attributs.casFonction.typesArguments,liste)){
                        return dico[i].type.attributs.casFonction.typeResultat->classe;
=======
            if ((!primitiveType(dico[i].type)){
                if (dico[i].type->classe ==tProcedure){
                    if memeListeTypes(dico[i].type->attributs.casProcedure.typesArguments,liste){
                        return tVoid;
                    }
                }
                else if (dico[i].type->classe ==tFonction){
                    if memeListeTypes(dico[i].type->attributs.casFonction.typesArguments,liste){
                        return dico[i].type->attributs.casFonction->typeResultat;
>>>>>>> master
                    }
                }
            }
        }
<<<<<<< HEAD
    //printCurrentDict();
    printf("appel methode incorrect \n");
=======
    erreurFatale("appel methode incorrect \n");
>>>>>>> master
    number_errors ++ ;
    return tVoid;
}

int ajouterEntree(char *identif, descripteurType type,int declarationLine) {
    if (sommet >= maxDico)
        agrandirDico();
    dico[sommet].identif = malloc(strlen(identif) + 1);
    if (dico[sommet].identif == NULL)
        {
            fprintf(stderr,"Erreur interne (pas assez de mémoire)");
            number_errors ++ ;
            return -1 ;
        }
    int dec=verifAjout(identif,type);
    if(dec !=-1)
    {
        number_errors++ ;
        printf("Identificateur %s dupliqué a la ligne %d declare deja a la ligne %d\n",identif,declarationLine,dec);
        return -1;
    }
    strcpy(dico[sommet].identif, identif);
    dico[sommet].type = type;
    dico[sommet].used = 0 ;
    dico[sommet].declarationLine = declarationLine ;
    sommet++;
    return sommet-1 ;
}
void printCurrentDict(){
    int i=0 ;
    printf("La base = %d Le sommet = %d\n",base,sommet);
    if(base!=0)
    {
        printf("Nous sommes dans un scope local\n") ;
    }
    else printf("Nous sommes dans un scope global\n") ;
    for (i= base;i<sommet;i++)
    {
        printf("L'entree num %d a l'identificateur %s et le type %s declaré a la ligne %d\n",i-base+1,dico[i].identif,getTypeName(dico[i].type.classe),dico[i].declarationLine) ;
        if(dico[i].type.classe == tProcedure || dico[i].type.classe==tFonction)
        {
            int j =1 ;
            listeDescripteursTypes * argHead ;
            if(dico[i].type.classe == tProcedure )
            argHead = dico[i].type.attributs.casProcedure.typesArguments ;
            else argHead = dico[i].type.attributs.casFonction.typesArguments ;
            while (argHead!=NULL)
            {
                printf("Argument num %d de type %s\n",j,getTypeName(argHead->info->classe));
                argHead= argHead->suivant ;
            }
        }
    }
}
void upScope(){
    base = sommet ;
}
ENTREE_DICO * search_variable(char * identif){
    int i = base ;
    for (;i<sommet;i++)
    {
        if(primitiveType(dico[i].type))
        if((!strcmp(identif,dico[i].identif))&&primitiveType(dico[i].type))
        return &dico[i] ;

    }

    number_errors++ ;
    fprintf(stderr,"Aucune variable avec l'identificateur %s n'est declarée \n",identif);
    return NULL ;
}
void downScope(){
    sommet = base ;
    base = 0 ;
}
typePossible verifCompare(typePossible a,typePossible b){

    if(a==tString&&a==tString)
        return tBool;
    if((a==tInt || a==tDouble)&& (b==tInt || b==tDouble))
        return tBool;
    number_errors ++ ;
    fprintf(stderr,"membres de comparaison n'ont pas de types compatibles\n") ;
    return tVoid ;
}
/*********************************************************************************************\
\*********************************************************************************************/


// A linked list (LL) node to store a queue entry
typedef struct QNode {
    char * key;
    struct QNode* next;
}QNode;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct Queue {
    struct QNode *front, *rear;
}Queue;

// A utility function to create a new linked list node.
QNode* newNode(char * k)
{
    QNode* temp = (QNode*)malloc(sizeof(QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueue(Queue* q, char* k)
{
    // Create a new LL node
    QNode* temp = newNode(k);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
// The function to concatenate two queues
void enQueueQueue(Queue* q,Queue* p)
{
    // If second queue is empty, then new node is front and rear both
    if(p->rear == NULL)
    {
        return ;
    }
    // If first queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = p->front;
        q->rear  = p->rear;
        return;
    }
    q->rear->next = p->front ;
    q->rear = p->rear ;
}
// Function to remove a key from given queue q
void deQueue(Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    QNode* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}


/*********************************************************************************************\
\*********************************************************************************************/
/*

// A linked list (LL) node to store a queue entry
typedef struct QNodeType {
    typePossible key;
    struct QNodeType* next;
}QNode;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct QueueType {
    struct QNodeType *front, *rear;
}QueueType;

// A utility function to create a new linked list node.
QNodeType* newNodeType(typePossible k)
{
    QNodeType* temp = (QNodeType*)malloc(sizeof(QNodeType));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// A utility function to create an empty queue
QueueType* createQueueType()
{
    QueueType* q = (QueueType*)malloc(sizeof(QueueType));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enQueueType(QueueType* q, typePossible k)
{
    // Create a new LL node
    QNodeType* temp = newNodeType(k);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}
// The function to concatenate two queues
void enQueueQueueType(QueueType* q,QueueType* p)
{
    // If second queue is empty, then new node is front and rear both
    if(p->rear == NULL)
    {
        return ;
    }
    // If first queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = p->front;
        q->rear  = p->rear;
        return;
    }
    q->rear->next = p->front ;
    q->rear = p->rear ;
}
// Function to remove a key from given queue q
void deQueueType(QueueType* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    QNodeType* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}*/
