//�˻ʺ�����
//ÿһ�У�ÿһ�У�ÿһ���Խ���ֻ����һ���ʺ�
//��ջ������ÿһ�лʺ����ڵ�����
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
int sum = 0;		//�ܹ��м���⣻
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
				cout<<"��";
			else 
				cout<<"��";
		}
		p++;
		cout<<endl;
	}
}
int IsValid(SqStack S, int n)		//λ�÷�����������1 ���򷵻�0
{
	int i = 0;
	for( i = 0; i < n; i++)
	{
		if (S.base[i] == S.base[n] || (S.base [i] - S.base[n] == (n-i)) || (S.base [n] - S.base[i] == (n-i)))
			return 0;		
	}
	return 1;
}
void PlaceQueue(SqStack &S, int i)		//�ڵ�i�з��ûʺ�
{
	SElemType e = 0;
	for (int j = 0; j < MAX; j++)
	{
		if (i == MAX)
		{
			sum++;
			cout<<"��"<<sum<<"��⣺"<<endl;
			StackTraverse(S);
			cout<<endl<<endl; 
			return;
		}
		Push(S,j);
		if (IsValid(S,i))	//��i���ʺ�λ�úϷ���ŵ�i+1���ʺ�
		{
			PlaceQueue(S,i+1);
			Pop(S,e);			//����Ĺؼ����ڣ�������ݣ���Ҫ��λ���˳� 
		}	
		else				//���Ϸ�����ѡλ��
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
