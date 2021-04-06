#include "drb.h"

/* Multiple Data Insertion */
struct node
{
	int data;
	struct node *link;
};

struct node *HEAD = NULL;

void appendItem(int x)
{
	struct node *_temp = NULL;
	_temp = (struct node *)malloc(sizeof(struct node));
	_temp->data = x;
	_temp->link = NULL;
	if(HEAD == NULL)
		HEAD = _temp;
	else
	{
		struct node *p;
		p=HEAD;
		while(p->link != NULL)
			p = p->link;
		p->link = _temp;
	}
}

void showItems(struct node *head)
{
	struct node *p;
	p=head;
	while(p->link != NULL)
	{	
		printf("%d ", p->data);
		p = p->link;
	}
}

void d_program()
{
	printf("Enter the Numbers : (press x to stop)\n");
	int i;
	for(i = 0; ;i++)
	{
		int inpVal = 0;
		int inpChk = scanf("%d", &inpVal);
		if(!inpChk) break;
		appendItem(inpVal);
	}
	i--;
	printf("\nEntered Items are :\n[ ");
	showItems(HEAD);
	printf("]\n");
	printf("\nNumber of Items %d\n", i);

}