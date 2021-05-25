#include "drb.h"
/* Single Linked List */

typedef struct rawNode
{
    int roll;
    struct rawNode *link;
} sNode;

int checkAvail(sNode *data, sNode *upto, int value)
{
    int retVal = 0;
    if (data != upto)
    {
        if (data->roll == value)
        {
            retVal = 1;
            return retVal;
        }
        retVal = checkAvail(data->link, upto, value);
    }
    return retVal;
}

int addNode(sNode *data, sNode *stData)
{
    int inpData = 0;
L1:
    printf("\nEnter the Number to add : ");
    scanf("%d", &inpData);
    if (inpData != -1)
    {
        if (checkAvail(stData, data, inpData))
        {
            printf("Number already Exist !");
            goto L1;
        }
        data->roll = inpData;
        data->link = (sNode *)malloc(sizeof(sNode));
        if (addNode(data->link, stData) == 0)
        {
            data->link = NULL;
            free(data->link);
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void sNodeTraverse(sNode *data)
{
    if (data->link != NULL)
    {
        printf("%d->", data->roll);
        sNodeTraverse(data->link);
    }
    else
    {
        printf("%d", data->roll);
    }
}

int sNodeSearchPOS(sNode *data, int value, int *pos)
{
    int retVal = 0;
    if (data->link != NULL)
    {
        (*pos)++;
        if (data->roll == value)
        {
            retVal = 1;
            return retVal;
        }
        retVal = sNodeSearchPOS(data->link, value, pos);
    }
    else
    {
        if (data->roll == value)
            retVal = 1;
    }
    return retVal;
}

int sNodeSearch(sNode *data, int value)
{
    int retVal = 0;
    if (data->link != NULL)
    {
        if (data->roll == value)
        {
            retVal = 1;
            return retVal;
        }
        retVal = sNodeSearch(data->link, value);
    }
    else
    {
        if (data->roll == value)
            retVal = 1;
    }
    return retVal;
}

int sNodeCount(sNode *data)
{
    if (data->link == NULL)
        return 1;
    return 1 + sNodeCount(data->link);
}

void d_program()
{
    int findRoll, rollPos = 0;
    sNode *a;
    a = (sNode *)malloc(sizeof(sNode));
    printf(" *** ( -1 to stop ) *** \n\n");
    addNode(a, a);
    printf("\nThe List is : \n");
    sNodeTraverse(a);
    printf("\n\nNumber of items in the list : %d", sNodeCount(a));
}

// struct SLL * Insert(struct SLL *in)
// {
//     int k;
//     struct SLL *t,*p;
//     t=(struct SLL *)malloc(sizeof(struct SLL));
//     printf("\nEnter an element for new node:");
//     scanf("%d",&t->v);

//     printf("\nEnter the key element(0 for last node):");
//     scanf("%d",&k);
//     if(k==in->v)
//     {
//         t->n=in;
//         in=t;
//     }
//     else if(k!=0)
//     {
//         p=prev_node(in,k);
//         t->n=p->n;
//         p->n=t;
//     }
//     else
//     {
//         p=last_node(in);
//         p->n=t;
//         t->n=NULL;
//     }
//     return in;
// }