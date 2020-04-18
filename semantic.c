enum TYPE_SYMBOL = { Int=1 , Float=2, String=3 , Procedure=4 , Function=5,Program =6,Void= 7 } ;
typedef struct node node ;
typedef struct nodeList nodeList ;
struct node {
    char * name ;
    TYPE_SYMBOL type ;
    int isInit ;
    int isUsed ;
    int argNumb ;
    struct node * next ;
    struct node * previous ;
    struct nodeList * subList ;
    struct node * parent;
};
struct nodeList {
    node * symBlockHead ;
    node * symBlockTail ;
};
TYPE_SYMBOL getType(char * type)
{
    if (!(strcmp(type,"integer"))
    {
        return Int ;
    }
    if (!(strcmp(type,"double"))
    {
        return Double ;
    }
    if (!(strcmp(type,"string"))
    {
        return String ;
    }
    if (!(strcmp(type,"function"))
    {
        return Function ;
    }
    if (!(strcmp(type,"procedure"))
    {
        return Procedure ;
    }
    if (!(strcmp(type,"program"))
    {
        return program ;
    }
    if (!(strcmp(type,"void"))
    {
        return program ;
    }
}

nodeList *  initSubList()
{
    nodeList * list = (nodeList*) malloc(sizeof(nodeList*)) ;
    nodeList->symBlockHead=null ;
    nodeList->symBlockTail=null ;
    return list ;
}
nodeList * initSubListWithList(node * list)
{
    nodeList * subList = initSubList () ;
    subList->symBlockHead = list ;
    node * curr = list ;
    while (curr->next)
    {
        curr = curr->next ;
    }
    subList->symBlockTail = curr ;
    return subList ;
}
/*
*   block is a node which can be a simple variable or a complex scope
*   ex : function has a type and a list of other nodes
*   adds a block to a sub list of blocks in a scope
*/
node * createNode(char * name , char * type ,node * parent ){
    node * newNode = (node*)malloc(sizeof(node*)) ;
    newNode->name = name ;
    newNode->TYPE_SYMBOL = getType(type) ;
    newNode->isInit = 0 ;
    newNode->isUsed = 0 ;
    // ba3d ki nebdew na9raw fil args na3mlou parent -> argnum ++ ;
    newNode->argNumb = 0 ;
    newNode->parent =parent;
    newNode->next =null;
    newNode->previous = null ;
    newNode->subList = initSubList() ;
}

void pushBlockSubList(nodeList * subList,node * block){
    if(!subList->symBlockHead){
        subList->symBlockHead=block ;
        subList->symBlockTail=block ;
    }
    else
    subList->symBlockTail->next = block ;
}

node * popSymBlock(nodeList * subList){
    subList->symBlockTail->previous->next = null ;
    node * toPop = subList->symBlockTail ;
    subList->symBlockTail = toPop->previous ;
    return toPop ;
}

//Search for conflict in block name
int searchConflict(node * block, char * name, TYPE_SYMBOL type )
{
    node * curr = block->next  ;
    while (curr)
    {
        if (curr->name == block->name)
    }
}

void addTypeToSiblings(node * block ,TYPE_SYMBOL type)
{
    node * curr = block  ;
    while (curr)
    {
        curr->type= type ;
        curr=curr->next ;
    }
}

void addSibling(node * block ,node * blockList)
{
    block->next = blockList ;
    if (blockList != NULL)
        blockList->previous = block ;
}
// concatenate two lists of nodes for exemple a list of arguments and a list of declarations
node * concatenateSiblingLists(node * list1, node * list2 )
{
    if (list1 == NULL )
        return list2 ;
    else
    {
        node * curr = list1 ;
        while (curr-> next)
        {
        curr = curr-> next ;
        }
        curr-> next = list2 ;
    }
    return list1 ;
}


instconst(), instlabel(), insttype(), instvar(): Respectively, adds a new constant, label, type, or variable declaration inside the top block on the symbol table (stack).
makeptrtype(), makeenumtype(), makerangetype(), makeidtype(), makerectype(), makearraytype(), makeuniontype(), makesettype(), makefiletype(): Creates various type nodes. Type of a variable is stored on the symbol table in a special variant data structure, which varies for each type.