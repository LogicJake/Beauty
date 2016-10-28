 /*
 ������ʽ�е���ĸ������˫Ŀ������������ɡ�
 ��дһ���㷨����һ��ͨ����д��ʽ����д��ȷ�ı��ʽת��Ϊ�沨�����ʽ��
����ı��ʽ������Ϊ#...#��ʽ
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
# define INFEASIBLE -1
# define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int ElemType;
typedef int Status;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}StackNode;
typedef struct Node *Stack; 
Status InitStack(Stack &top)
{
	top = (Stack)malloc(sizeof(StackNode));
	if (top == NULL)
		exit(OVERFLOW);
	else
	{
		top->next = NULL;
		return OK;
	}
}
Status DestroyStack(Stack &top)
{
	Stack p;
	if (!top)	
		return INFEASIBLE;
	else
	{
		while(top)
		{
			p = top;
			top = top->next;
			free(p);
		}
		return OK;
	}
}
Status ClearStack(Stack &top)
{
	Stack p = top->next, q;
	if (!top)
		return INFEASIBLE;
	else
	{
		while(p)
		{
			q = p->next;
			free(p);
			p = q;
		}
		top->next = NULL;
	}
}
Status StackEmpty(Stack top)
{
	if (!top)
		return INFEASIBLE;
	else if (top->next == NULL)
		return TRUE;
	else
		return FALSE;
}
Status StackLength(Stack top)
{
	Stack p;
	int i = 0; 
	if (!top)
		return INFEASIBLE;
	else 
	{
		p = top->next;
		while(p)
		{
			i++;
			p = p->next;
		}
	}
	return i;
}
Status GetTop(Stack top, ElemType &e)
{
	if (!top)
		return INFEASIBLE;
	else 
	{
		if(top->next != NULL)
		{
			e = top->next->data;
			return OK;
		}
		else
			return ERROR;
	}
}
Status Push(Stack &top, ElemType e)
{
	if (!top)
		return INFEASIBLE;
	else
	{
		Stack p = (Stack)malloc(sizeof(StackNode));
		p->data = e;
		p->next = top->next;
		top->next = p;
		return OK;
	}
}
Status Pop(Stack &top, ElemType &e)
{
	Stack p;
	if (!top||!top->next)
		return INFEASIBLE;
	else
	{
		p = top->next;
		top->next = p->next;
		e = p->data;
		free(p);
		return OK;
	}
}
void reverse(Stack &L)
{
	Stack p,q;
	p = L->next;L->next = NULL;
	while(p)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
Status StackTraverse(Stack top)
{
	reverse(top);			//��ջ�׿�ʼ��� 
	Stack p = top->next; 
	while(p)
	{
		printf("%c",p->data);
		p = p->next;
	}
}
Status IsOperator(char c)
{
	if(c == '#'||c == '('||c == '+'||c == '-'||c == '*'||c == '/'||c == ')')
		return TRUE;
	else
		return FALSE; 
}
Status Prior(char c1,char c2)
{
	char ch[] = "#(+-*/)";
	int i = 0,j = 0;
	while(ch[i] && ch[i] != c1) i++;
	if(i == 3) i--;	// �Ӻͼ�����Ϊ��ͬ����������
	if(i == 5) i--;	// �˺ͳ�����Ϊ��ͬ����������
	while(ch[j] && ch[j] != c2) j++;
	if(j == 3) j--;
	if(j == 5) j--;
	if(i >= j) 
		return TRUE;
	else 
		return FALSE;
}
void InversePolandExpression(char Buffer[], Stack &s1)
{
	Stack s2;
	InitStack(s1);
	InitStack(s2);
	int i=0;
	ElemType e;
	Push(s2,Buffer[i]);
	i++;
	while(Buffer[i] != '#')
	{
		if(!IsOperator(Buffer[i]))// �ǲ�����
		{	
			Push(s1,Buffer[i]);
			i++;
		}
		else// �ǲ�����
		{	
			if(Buffer[i] == '(')
			{
				Push(s2,Buffer[i]);
				i++;				
			}
			else
			{
				if(Buffer[i] == ')')
				{
					Pop(s2,e);
					while(e != '(')
					{
						Push(s1,e);
						Pop(s2,e);
					}
					i++;
				}
				else
				{
					GetTop(s2,e);
					if(Prior(e,Buffer[i]))
					{
						while(Prior(e,Buffer[i]))// ��ջ������Ȩ���ڵ�ǰ����ʱ����ջ
						{
							Pop(s2,e);
							Push(s1,e);
							GetTop(s2,e);
						}
						Push(s2,Buffer[i]);
						i++;
					}
					else
					{
						Push(s2,Buffer[i]);
						i++;
					}
				}
			}
		}
	}
	while(!StackEmpty(s2))
	{
		Pop(s2,e);
		Push(s1,e);
	}
}
int main()
{
	Stack s;
	char buff[] = "#9+(3-1)*3+10/2#";
	InversePolandExpression(buff,s);
	StackTraverse(s);
}
