/*4��Լɪ�����⡣����n��������Բ����Χ���ӵ�s���˿�ʼ����������m���˳��У�Ȼ���ٴ���һ���˿�ʼ������
����m�����ֳ��У�����ظ���ֱ�����е��˶�����Ϊֹ��Ҫ�󰴳��е��Ⱥ�˳�����ÿ���˵���Ϣ��(ѡ����)
�ṹ��ͽ����Բ������д��룺
typedef char datatype;
typedef struct node
{
datatype info;
struct node *next;
} NODE;
*/
#include <stdio.h>
#include <malloc.h>
typedef char datatype;
int n;//��¼����
typedef struct node
{
datatype info;
struct node *next;
} NODE,*Linklist;
int CreatList(Linklist &L,int n)
{
	int i;
	Linklist p,head;
	L=(Linklist)malloc(sizeof(NODE)); /* ����ͷ���,��ʹLָ���ͷ��� */
	L->info = 0;
    head = L;
	if(L==NULL) /* �洢����ʧ�� */
            return -1;
	L->next = head;
    for (i = n; i >0; i--)
	{
		p = (Linklist)malloc(sizeof(NODE));
		p->info = i;
		p->next = L->next;
		L->next = p;
	}
	return 1;
}

void DestroyList(Linklist &L)
{
	Linklist p,q;
	p=L->next;           /*  pָ���һ����� */
	while(p)                /*  û����β */
	{
		q=p->next;
		free(p);
		p=q;
	}
	free(L);        /* �ͷ�ͷ�ڵ�Ŀռ� */
}
void ListJump(Linklist &L,int s,int m)
{
	Linklist p,q;
	int i;
	p=L->next;
	while(p->info<s)
	{
		p = p->next;
	}
	while(p->next!=p)  
    {  
        if(p->info == 0)//����ͷ���
			p=p->next;
		else
		{
			for(i=1;i<m-1;i++)	//����
			{
				p=p->next;
				if(p->info == 0)	//����ͷ���
					p=p->next;
			}
			if(p->next->info == 0)
				q = p->next->next;
			else
				q = p->next;
			p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
			printf("%d ",q->info);
			free(q); 
			n--;
			if(n==1)
				break;
			p=p->next;
		}
    }
	printf("%d",p->info);
}
int main()
{
	int s,m;
	scanf("%d",&n);
	scanf("%d",&s);
	scanf("%d",&m);
	Linklist L;
	CreatList(L,n);
	ListJump(L,s,m);
	return 0;
}
