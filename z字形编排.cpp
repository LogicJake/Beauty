/*
z���α���
by:Max 
*/
#include<iostream>
#include<iomanip>
#define size 8
using namespace std;
int main()
{
	int matrix[size][size]={0};
	int a[size][size]={0};
	int i,j,x,y,value=0;
	int *p;
	p=&matrix[0][0];
	//��ʼ������
	for(i=0;i<size*size;i++)
		*p++=i;
	//��ӡԭʼ����
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			cout<<setw(4)<<*(*(matrix+i)+j);
		cout<<endl;
	}
	i=0;j=0;
	//����z������
	for(x=0;x<size;x++)
	{
		for(y=0;y<size;y++)
		{
			*(*(a+i)+j)=*(*(matrix+x)+y);
			if((i==0||i==size-1)&&j%2==0)	//���1 
			{
				j++;
				continue; 					//��Ϊ���1�����2�а������3��4�������ȿ���1��2 
			} 								//Ȼ���������ѭ�������ó���ȥ�ж�3��4������ 
			if((j==0||j==size-1)&&i%2==1)	//���2 
			{
				i++;
				continue;
			}
			if((i+j)%2==1)					//���3 
			{
				i++;
				j--;
			}
			
			if((i+j)%2==0)					//���4 
			{
				i--;
				j++;
			} 
		}
	 } 
	 cout<<"����z���α��ź�ľ������£�"<<endl;
	 for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			cout<<setw(4)<<*(*(a+i)+j);
		cout<<endl;
		
	}
 } 
