#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
struct Node{
int data;
struct Node *next;	
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n)
{
	int i;
	struct Node *t, *last;
	first=(struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;
	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
	
}
void create2(int A[],int n)
{
	int i;
	struct Node *t, *last;
	second=(struct Node *)malloc(sizeof(struct Node));
	second->data=A[0];
	second->next=NULL;
	last=second;
	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
	
}
int count(struct Node*p)
{
int l=0;
while(p)
{
	l++;
	p=p->next;
}
return l;
}
int Rcount(struct Node*p)
{
if(p!=NULL)
	return Rcount(p->next)+1;
else
	return 0;
}

int sum(struct Node *p)
{
	int s=0;
	while(p!=NULL)
	{
		s+=p->data;
		p=p->next;
	}
	return s;
}
int Rsum(struct Node *p)
{
if(p==NULL)
return 0;
else
return Rsum(p->next)+p->data;
}
void Display(struct Node *p)
{
	while(p!=NULL)
	{
		printf("\n");
		printf("%d",p->data);
		p=p->next;
	}

}
//void RDisplay(struct Node *p)
//{
//	while(p!=NULL)
//	{
//		printf("\n");
//		printf("%d",p->data);
//		RDisplay(p->next);
//	}
//}

int Max(struct Node *p)
{
	int max=INT_MIN;
	while(p)
	{
		if(p->data>max)
		max=p->data;
		p=p->next;
		
	}
	return max;
}
struct Node * LSearch(struct Node *p,int key)
{
	while(p!=NULL)
	{
		if(key==p->data)
		return p;
		p=p->next;
	}
	return NULL;
}
struct Node * RSearch(struct Node *p,int key)
{
	if (p==NULL)
	return NULL;
	if(key==p->data)
	return p;
	return RSearch(p->next,key);
}
void Insert(struct Node *p,int index,int x)
{
	struct Node *t;
	int i;
	if (index<0 || index>count(p))
	return;	
	
	t=(struct Node*)malloc(sizeof(struct Node));
	t->data=x;
	if(index==0)
	{
		t->next=first;
		first=t;
	}
	else
	{
		for(i=0;i<index-1;i++)
	  p=p->next;
	  t->next=p->next;
	  p->next=t;	
	
	}
}
int isSorted(struct Node *p)
{
	int x=-65536;
	while(p!=NULL)
	{
		if(p->data<x)
		return 0;
		
		x=p->data;
		p-p->next;
	}
	
return 1;		
				
}
int  Delete(struct Node *p, int index)
{
	struct Node *q;
	int x=-1,i;
	if(index <1|| index > count(p))
	return -1;
	
	if(index==1)
	{
		q=first;
		x=first->data;
		first=first->next;
		free( q);
		return x;
	}
	else
	{
		for(i=0;i<index-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		free (p);
		return x;
	}
}
void RemoveDuplicate(struct Node *p)
{
	struct Node *q=p->next;
	while(q!=NULL)
	{
		if(p->data!=q->data)
		{
			p=q;
			q=q->next;
		}
		else
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}
void Reverse1(struct Node *p)
{
	int *A,i=0;
	struct Node *q=p;
	
	A=(int*)malloc(sizeof(int)*count(p));
	
	while(q!=NULL)
	{
		A[i]=q->data;
		q=q->next;
		i++;
	}
	q=p;
	i--;
	while(q!=NULL)
	{
		q->data=A[i];
		q=q->next;
		i--;
	}
	
}
void Reverse2(struct Node *p)
{
	struct Node *q=NULL,*r=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	first=q;
}
void Reverse3(struct Node *q, struct Node *p)
{
	if(p)
	{
		Reverse3(p,p->next);
		p->next=q;
	}
	else
	first=q;
}
void Concat(struct Node *p,struct Node *q)
{
	third=p;
	while(p->next!=NULL)
	p=p->next;
	p->next=q;
}
void Merge(struct Node *p,struct Node*q)
{
	struct Node*last;
	if(p->data <q->data)
	{
		third=last=p;
		p=p->next;
		third->next=NULL;
		
	}
	else
	{
		third=last=q;
		q=q->next;
		third->next=NULL;
		
	}
	while( p&& q)
	{
		if(p->data <q->data)
		{
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
			
		}
		else
		{
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
			
		}
	}
	if(p)last->next=p;
	if(q)last->next=q;
	
	
	
	
}
int isLoop(struct Node *f)
{
	struct Node *p,*q;
	p=q=f;
	do{
		p=p->next;
		q=q->next;
		q=q?q->next:q;
	}
	while(p && q && p!=q);
	if(p==q)
	return 1;
	
	else
	return 0;
}
int main()
{
	struct Node *t1,*t2;
	int A[]={10,20,30,40,50};
//	int B[]={15,25,35,45,55};
	create(A,5);
	t1=first->next->next;
	t2=first->next->next->next->next;//pointing to last node
	t2->next=t1;
	
//	create2(B,5);
//	struct Node*temp;
//	temp=RSearch(first,15);
//		printf("%d\n",isSorted(first));
//	if(temp)
//		printf("Key is found %d",temp->data);
//		
//		else
//		printf("Key not found");
//	// RDisp		printf("\n");
//		printf("Max is %d",Max(first));	
//		
//		Insert(first,0,780);
//Reverse1(first);
//Reverse2(first);
//Reverse3(NULL,first);
  // RemoveDuplicate(first);
	//Delete(first,4);
//	printf("First list\n");
//	Display(first);
//	printf("\n");
//	printf("Second\n \n");
//		Display(second);
////		printf("\n");
//	printf("length is %d",Rcount(first));
//		printf("\n");
//	printf("SUM is %d",Rsum(first));
//Concat(first,second);
//printf("concatinated\n");
//Display(third);
//printf("\n\n");
//Merge(first,second);
//Display(third);
//printf("\n\n");
printf("%d\n",isLoop(first));

	return 0;
}
