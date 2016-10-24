#include<stdio.h>
#include<stdlib.h>
#define ok 1
#define error 0
typedef int Status;
typedef int ElemType;
typedef struct node
{
	ElemType info;
	struct node *next;
}*LinkList,NODE;
Status CreatList(LinkList &L,int m)
{
	LinkList p,q;
	int i;
	L=(LinkList)malloc(sizeof(NODE));
	L->next=L;
	p=(LinkList)malloc(sizeof(NODE));
	p->info=m;
	p->next=L->next;
	L->next=p;
	q=p;
	for(i=m-1;i>0;i--)
	{
		p=(LinkList)malloc(sizeof(NODE));
		p->info=i;
		p->next=L->next;
		L->next=p;
	}
	q->next = L->next;			//循环链表不加入表头 
	return ok;
}
void Delete_Linklist(LinkList &L,int n,int k)
{

      int i;
      LinkList p,q;
      p=L->next;
      i=1;
      while(i<k)				//跳到第k个人 
      {
      	p = p->next;
      	i++;
	  }
      while(p->next!=p)			//当队列中只剩下一个人跳出循环 
      {
             for(i=1;i<n-1;i++)	 
                p=p->next;
             q=p->next;
             printf("%d ",q->info);
             p->next=q->next;
             free(q);
             p=p->next;
      }
      printf("%d ",p->info);	//输出最后一个人 
      free(p);
      L=NULL;
}
int main()
{
	int m,n,k;
	scanf("%d",&m);
	scanf("%d",&k);
	scanf("%d",&n);
	LinkList La;
	CreatList(La,m);
	Delete_Linklist(La,n,k);		 
	return 0;
}
