#include <stdio.h>

struct node
{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* findvot(struct node** head,struct node** tail);

struct node* createnode(int data)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->prev=n->next=NULL;
	return n;
}

void insert(struct node** head,int d)
{
	struct node* last=*head;
	while(last->next)
	{
		last=last->next;
	}
	last->next=createnode(d);
	last->next->prev=last;
}

void quicksort(struct node** h,struct node** e)
{
	struct node* head=*h;
	struct node* end=*e;
	struct node *addrs=&head;
	struct node *addre=&end;
	//printf("%d-%d\n",addrs,addre);
//	printf("%d\n",head->next->next->data);
	if(head<end && (head && end)) 
	{
	//	printf("hello");
		struct node* pivot=findvot(&head,&end);
		//printf("%d\n",pivot==NULL);
		quicksort(&head,&pivot->prev);
		quicksort(&pivot->next,&end);
	}
}

void swap(struct node** x,struct node** y)
{
	struct node* a=*x;
	struct node* b=*y;
	
		int d=b->data;
		b->data=a->data;
		a->data=d;
	  
}

struct node* findvot(struct node** hd,struct node** tl)
{
	struct node* head=*hd;
	struct node* tail=*tl;
	struct node* i=NULL;
	struct node* pivot=&tail;
	struct node* j;
	//printf("%d-%d\n",head->data,tail->data);
	for(j=head;j!=(tail);j=j->next)
	{
		if(j->data<=tail->data)
		{
			if(i==NULL)
			   i=head;
			else
		       i=i->next;
			swap(&i,&j);
		}
	}
//	printf("%d\n",i->next->data);
    struct node* k;
    if(i==NULL)
       k=head;
    else
       k=i->next;
	swap(&k,&tail);
	return k;
}

void print(struct node** head)
{
	struct node* last=*head;
	while(last)
	{
		printf("%d<=>",last->data);
		last=last->next;
	}
	printf("NULL\n");
}

main()
{
	struct node* head=createnode(16);
	insert(&head,14);
	insert(&head,1003);
	insert(&head,-3000);
	insert(&head,20);
	printf("Before Sorting: ");
	print(&head);
	struct node* last=head;
	while(last->next)
	{
		last=last->next;
	}
	quicksort(&head,&last);
	//swap(&head,&head->next->next);
	//printf("%u-%u\n",head,last);
	printf("After Sorting: ");
	print(&head);
}
