#include "drb.h"
#define MAX 69

typedef struct rawnode
{
    int id;
    struct rawnode *link;
} node;

int create(node *cr1)
{
    printf("\nEnter Element : ");
    scanf("%d", &cr1->id);

    if (cr1->id == -1)
        return 0;
    else
    {
        cr1->link = (node *)malloc(sizeof(node));
        if (create(cr1->link) == 0)
        {
            free(cr1->link);
            cr1->link = NULL;
        }
    }
}

void showNode(node *data)
{
    if (data->link != NULL)
    {
        printf("%d ", data->id);
        showNode(data->link);
    }
    else
    {
        printf("%d", data->id);
    }
}

void d_program()
{
    node *a;
    a = (node *)malloc(sizeof(node));
    create(a);
    printf("\nList is : \n");
    showNode(a);
}