//八皇后问题
//每一行，每一列，每一条对角线只能有一个皇后
//用栈来储存每一行皇后所在的列数
#include <iostream>
#include <stdlib.h> 
#include <conio.h>
using namespace std;
#define MAX 8 
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2
typedef int SElemType;
typedef int Status;
int sum = 0;		//总共有几组解；
typedef struct 
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
Status InitStack(SqStack &S)
{
	S.base = (SElemType *)malloc(MAX * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAX;
	return OK;
}
Status Push(SqStack &S, SElemType e)
{
	*S.top = e;
	S.top++;
	return OK;
}
Status Pop(SqStack &S, SElemType &e)
{
	if (S.top == S.base)
		return ERROR;
	else
	{
		S.top--;
		e = *(S.top);
		return OK;
	}
}
Status StackTraverse(SqStack S)
{
	SElemType *p; 
	p = S.base;
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			if(j == *p)
				cout<<"●";
			else 
				cout<<"○";
		}
		p++;
		cout<<endl;
	}
}
int IsValid(SqStack S, int n)		//位置符合条件返回1 否则返回0
{
	int i = 0;
	for( i = 0; i < n; i++)
	{
		if (S.base[i] == S.base[n] || (S.base [i] - S.base[n] == (n-i)) || (S.base [n] - S.base[i] == (n-i)))
			return 0;		
	}
	return 1;
}
void PlaceQueue(SqStack &S, int i)		//在第i行放置皇后
{
	SElemType e = 0;
	for (int j = 0; j < MAX; j++)
	{
		if (i == MAX)
		{
			sum++;
			cout<<"第"<<sum<<"组解："<<endl;
			StackTraverse(S);
			cout<<endl<<endl; 
			return;
		}
		Push(S,j);
		if (IsValid(S,i))	//第i个皇后位置合法则放第i+1个皇后
		{
			PlaceQueue(S,i+1);
			Pop(S,e);			//问题的关键所在：假如回溯，则要将位置退出 
		}	
		else				//不合法则重选位置
			Pop(S,e);
	}
}
int main()
{
	SqStack S;
	InitStack(S);
	PlaceQueue(S,0);
	return 0;
}
