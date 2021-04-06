#include "drb.h"

void armstrong()
{
    int n,m,p=0,i,j,r=0;
    printf("Enter num : ");
    scanf("%d", &n);
    for(i=n;i!=0;i/=10) p++;
    printf("\n---\n");
    for(i=n;i!=0;i/=10)
    {	
    	m=1;
		for(j=0;j<p;j++) m*=i%10;
		r+=m;
    }
    r==n?printf("Armstrong")
     	:printf("Not Armstrong");

}

void fibonacci()
{
	int n[3]={0,1,0},i,r;
	printf("Enter Number : ");
	scanf("%d", &r);
	printf("%d %d", n[0], n[1]);
	for(i=2;i<r;i++)
	{
		n[2]=n[1]+n[0];
		printf(" %d", n[2]);
		n[0]=n[1];
		n[1]=n[2];
	}
}

void primeNumber()
{
	int c,n,p=1;
	printf("Enter Number : ");
	scanf("%d", &n);
	for(c=2;c<n;c++) if(n%c==0) p=0;
	p?printf("Prime Number\n"):printf("Not Prime Number\n");
}

struct node
{
	int data;
	struct node *link;
};

int countList(struct node *head)
{
	int count = 0;
	if(head == NULL)
		return 0;
	struct node *ptr = NULL;
	ptr = head->link;
	while(ptr != NULL)
	{	
		count++;
		ptr = ptr->link;
	}
	return count;
}

void printList(struct node *head)
{
	if(head == NULL)
		return;
	struct node *ptr = NULL;
	ptr = head->link;
	while(ptr != NULL)
	{	
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
}

void d_program()
{
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));

	struct node *current = NULL;
	current = (struct node *)malloc(sizeof(struct node));
	current->data = 5;
	current->link = NULL;
	head->link = current;

	current = (struct node *)malloc(sizeof(struct node));
	current->data = 10;
	current->link = NULL;
	head->link->link = current;

	current = (struct node *)malloc(sizeof(struct node));
	current->data = 15;
	current->link = NULL;
	head->link->link->link = current;

	printList(head);

}