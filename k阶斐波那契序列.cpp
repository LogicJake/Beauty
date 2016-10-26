/* 
������ѭ�����б�д��k��쳲�����������ǰn+1����㷨��Ҫ�����㣺
 fn<=max,fn+1>max ����maxΪĳ��Լ��������
 (ע�⣺��������ѭ�����е�������Ϊk, �����㷨ִ�н���ʱ������ѭ�������е�Ԫ��Ӧ������k��쳲����������е����k��)
*/
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2
#define k 8
typedef int ElemType;
typedef struct{
    int *base;
    int front;
    int rear;
}SqQueue;
void InitQueue(SqQueue &Q)
{
    Q.base = (int *)malloc(k * sizeof(ElemType));
    if(!Q.base)
        exit(OVERFLOW);
    Q.front = Q.rear = 0;
}
int EnQueue(SqQueue &Q, ElemType e)
{
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % k;
    return OK;
}
int DeQueue(SqQueue &Q, ElemType &e)
{
    e = Q.base[Q.front];
    Q.front = (Q.front+1)%k;
    return OK;
}
int fun(int m)
{
    if(m < k-1)
        return 0;
    if(m == k-1)
    	return 1;
    else if(m > k-1)
    {
    	int i,sum = 0;
    	for(i = 1; i <= k; i++)
    		sum += fun(m-i);
    	return sum;
	}
}
int main()
{
  	SqQueue Q;
    InitQueue(Q);
  	int e;
  	int s = 0,i = 0,max,len;
  	printf("������Լ�����������");
  	scanf("%d",&max);
  	while(1)
 	{
 		s = fun(i);
 		if(s <= max)
 		{
 			if(i > 7)	//�����ӳ� ��ɾһ���ټ�һ�� 
 				DeQueue(Q,e);
 			EnQueue(Q,s);	
		}	 	
 		else
 			break;
		i++;	
  	}
  	i = 0;
  	while(i < k)
  	{
   		DeQueue(Q,e);
   	  	printf("%d\n",e);
   	  	i++;
  	}
  	return 0;
}
