#include<stdio.h>
#include<stdlib.h>
struct node *head;
struct node
{
char data[10];
int num;
struct node *next;
}; 
struct node *create(int n)
{
int i;
struct node *head,*pnew,*ptail;
pnew=(struct node*)malloc(sizeof(struct node));
scanf("%d%s",&pnew->num,pnew->data);
head=pnew;
ptail=pnew;
for(i=1;i<n;i++)
{
	pnew=(struct node*)malloc(sizeof(struct node));
	scanf("%d%s",&pnew->num,pnew->data);
    ptail->next=pnew;
    ptail=pnew;
	
}
ptail->next=NULL;
return head;
}
struct node *insert(struct node *head)
{
	struct node *p,*pold,*pnew;
	pnew=(struct node*)malloc(sizeof(struct node));
	scanf("%d%s",&pnew->num,pnew->data);
	p=head;
	if(pnew->num>head->num)
	{
	pnew->next=head;
	head=pnew;}
	else{
		while(p!=NULL&&pnew->num>p->num)
		{
			pold=p;
			p=p->next;
			
		}
		pnew->next=NULL;
		pold->next=pnew;
		
	}
	
	return head;
}
void print(struct node *head)
{
	struct node *p=head;
	while(p!=NULL)
	printf("%d %s",p->num,p->data);
}
struct node *sdelete(struct node *head,int grade)
{
	struct node *p,*pold;
	p=head;
	while(head!=NULL&&head->num==grade)
	{
	head=head->next;
	free(p);
    p=head;

}
if(head==NULL)
{
return head;
}
p=head->next;
pold=head;
while(p!=NULL)
{
if(p->num==grade)
{
pold->next=p->next; 
free(p);
p=pold->next;
}
else
{
	pold=p;
	p=p->next;
}
}
return head;
}

int main()
{
int n;
printf("结点个数");
head=create(n);
print(head);
return 0;
}
