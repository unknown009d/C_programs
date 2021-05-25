/* 

    Linked List Operations:
    -----------------------

    1. Creating
    2. Inserting (User Choice)
    3. Traversing
    4. Searching
    5. Deleting
    6. Updating


*/
#include "drb.h"
#include "string.h"
#define MAX_text 50

void inpText(char textDP[], char mainArr[])
{
    printf("%s", textDP);
    for (int i = 0; i < MAX_text; i++)
    {
        scanf("%c", &mainArr[i]);
        if (mainArr[i] == 10)
        {
            mainArr[i] = '\0';
            break;
        }
    }
}
void CapitalizeText(char data[])
{
    if (data[0] >= 97 && data[0] < 123)
        data[0] -= 32;
    for (int i = 1; data[i] != '\0'; i++)
    {
        if (data[i] == 32)
        {
            if (data[i + 1] >= 97 && data[i + 1] < 123)
                data[i + 1] -= 32;
        }
    }
}

typedef struct rawNode
{
    char name[MAX_text];
    int roll;
    struct rawNode *link;
} node;

void showNodes(node *items)
{
    node *data = items;
    printf("\n\nStudents Details : \n\n");
    while (data != NULL)
    {
        printf("Name : %s\n", data->name);
        printf("Roll : %d\n", data->roll);
        printf("Link : %p\n\n", data->link);
        data = data->link;
    }
}

int checkRoll(node *mainData, node *current, int roll)
{
    int valid = 0;
    if (mainData != current)
    {
        if (mainData->roll == roll)
        {
            valid = 1;
            return valid;
        }
        valid = checkRoll(mainData->link, current, roll);
    }
    return valid;
}
int checkRollNULL(node *mainData, int roll)
{
    int valid = 0;
    if (mainData->link != NULL)
    {
        if (mainData->roll == roll)
        {
            valid = 1;
            return valid;
        }
        valid = checkRollNULL(mainData->link, roll);
    }
    else
    {
        if (mainData->roll == roll)
        {
            valid = 1;
            return valid;
        }
    }
    return valid;
}

node *insertNodes(int size)
{
    node *data, *stData;
    data = (node *)malloc(sizeof(node));
    stData = data;
    printf("\nEnter Students Data :\n-----------------\n");
    while (size != 0)
    {
        scanf("%c", &data->name[0]);
        inpText("\nEnter the Name : ", data->name);
        CapitalizeText(data->name);
    retryRoll:
        printf("Enter the Roll No : ");
        scanf("%d", &data->roll);
        if (checkRoll(stData, data, data->roll))
        {
            printf("Roll Number already Exist. Try Again \n");
            goto retryRoll;
        }
        if (size == 1)
            data->link = NULL;
        else
            data->link = (node *)malloc(sizeof(node));
        data = data->link;
        --size;
    }
    return stData;
}

node *findLastNode(node *data)
{
    if (data->link == NULL)
        return data;
    return findLastNode(data->link);
}

node *findSelectedRollBefore(node *data, int roll)
{
    if (data->link->roll == roll)
        return data;
    return findSelectedRollBefore(data->link, roll);
}

node *findSelectedRoll(node *data, int roll)
{
    if (data->roll == roll)
        return data;
    return findSelectedRollBefore(data->link, roll);
}

int checkValidInpRoll(node *mainData, int roll)
{
    int valid = 0;
    if (roll == 0)
        return 1;
    if (mainData->link != NULL)
    {
        if (mainData->roll == roll)
        {
            valid = 1;
            return valid;
        }
        valid = checkRollNULL(mainData->link, roll);
    }
    else
    {
        if (mainData->roll == roll)
        {
            valid = 1;
            return valid;
        }
    }
    return valid;
}

node *newNode(node *data)
{
    int insertRoll;
    node *retVal;
    retVal = data;
    node *newStu;
    newStu = (node *)malloc(sizeof(node));

    scanf("%c", &newStu->name[0]);
    inpText("\nEnter the Name : ", newStu->name);
    CapitalizeText(newStu->name);
retryRoll1:
    printf("Enter the Roll No : ");
    scanf("%d", &newStu->roll);
    if (checkRollNULL(data, newStu->roll))
    {
        printf("Roll Number already Exist. Try Again \n");
        goto retryRoll1;
    }
L1:
    printf("\n\nEnter Before which Roll Number (0 to add at the End) : ");
    scanf("%d", &insertRoll);
    if (!checkValidInpRoll(data, insertRoll))
    {
        printf("Roll Number doesn't Exist. Try Again \n");
        goto L1;
    }
    if (insertRoll == 0)
    {
        node *lastNode;
        lastNode = findLastNode(data);
        lastNode->link = newStu;
        newStu->link = NULL;
    }
    else if (insertRoll == data->roll)
    {
        newStu->link = data;
        retVal = newStu;
    }
    else
    {
        newStu->link = findSelectedRollBefore(data, insertRoll)->link;
        findSelectedRollBefore(data, insertRoll)->link = newStu;
    }
    return retVal;
}

void searchNode(node *data)
{
    node *_temp;
    int searchRoll;
L2:
    printf("\nEnter the Roll Number to Search : ");
    scanf("%d", &searchRoll);
    if (checkRollNULL(data, searchRoll))
    {
        _temp = findSelectedRoll(data, searchRoll);
    }
    else
    {
        printf("Enter Roll Number doesn't exist. Try again.\n");
        goto L2;
    }
    printf("\nSearch Results :- \n\n");
    printf("Name : %s\nRoll.No.: %d\n", _temp->name, _temp->roll);
    printf("Link : %p\n", _temp->link);
}

node *deleteNode(node *data)
{
    node *current, *before, *retVal;
    int selectedRoll;
L3:
    printf("\nEnter the Roll Number to Delete : ");
    scanf("%d", &selectedRoll);
    if (selectedRoll == data->roll)
    {
        retVal = data->link;
        printf("\nRoll No.: %d has been successfully deleted (%s)", current->roll, current->name);
        free(data);
    }
    else
    {
        retVal = data;
        if (checkRollNULL(data, selectedRoll))
        {
            before = findSelectedRollBefore(data, selectedRoll);
            current = before->link;
        }
        else
        {
            printf("Enter Roll Number doesn't exist. Try again.\n");
            goto L3;
        }
        before->link = current->link;
        current->link = NULL;
        printf("\nRoll No.: %d has been successfully deleted (%s)", current->roll, current->name);
        free(current);
        // printf("%d).\n", current->roll);
    }
    return retVal;
}

void updateNode(node *data)
{
    node *current;
    int selectedRoll;
L3:
    printf("\nEnter the Roll Number to Update : ");
    scanf("%d", &selectedRoll);
    if (checkRollNULL(data, selectedRoll))
        current = findSelectedRoll(data, selectedRoll);
    else
    {
        printf("Enter Roll Number doesn't exist. Try again.\n");
        goto L3;
    }
    printf("\nPrevious Name : %s\n", current->name);
    scanf("%c", &current->name[0]);
    inpText("Enter the Updated Name : ", current->name);
    CapitalizeText(current->name);
    printf("\nRoll No.: %d has been successfully Updated.\n", current->roll);
}

void d_program()
{
    node *students;
    int *numStu, choice;
    numStu = (int *)malloc(sizeof(int));

    printf("Enter the Number of Students to insert : ");
    scanf("%d", numStu);
    students = insertNodes(*numStu);
    showNodes(students);
    printf("\n\n0. Exit\n1. To Continue (Deleting)\n-> ");
    scanf("%d", &choice);
    if (!choice)
        return;
    system("clear");

    printf("Insert a new student :\
    \n-------------------------\n");
    students = newNode(students);
    showNodes(students);
    printf("\n\n0. Exit\n1. To Continue (Searching)\n-> ");
    scanf("%d", &choice);
    if (!choice)
        return;
    system("clear");

    printf("Search students :\n-------------------\n");
    searchNode(students);
    printf("\n\n0. Exit\n1. To Continue (Delete)\n-> ");
    scanf("%d", &choice);
    if (!choice)
        return;
    system("clear");

    printf("Delete student :\n-------------------\n");
    students = deleteNode(students);
    showNodes(students);
    printf("\n\n0. Exit\n1. To Continue (Update)\n-> ");
    scanf("%d", &choice);
    if (!choice)
        return;
    system("clear");

    printf("Update student :\
          \n----------------\n");
    updateNode(students);
    showNodes(students);
}
