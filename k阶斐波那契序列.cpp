/* 
试利用循环队列编写求k阶斐波那契序列中前n+1项的算法。要求满足：
 fn<=max,fn+1>max 其中max为某个约定常数。
 (注意：本题所用循环队列的容量仅为k, 则在算法执行结束时，留在循环队列中的元素应是所求k阶斐波那契序列中的最后k项)
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
  	printf("请输入约定的最大数：");
  	scanf("%d",&max);
  	while(1)
 	{
 		s = fun(i);
 		if(s <= max)
 		{
 			if(i > 7)	//超出队长 先删一个再加一个 
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
