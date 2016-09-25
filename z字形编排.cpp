/*
z字形编排
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
	//初始化矩阵
	for(i=0;i<size*size;i++)
		*p++=i;
	//打印原始矩阵
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			cout<<setw(4)<<*(*(matrix+i)+j);
		cout<<endl;
	}
	i=0;j=0;
	//进行z字排列
	for(x=0;x<size;x++)
	{
		for(y=0;y<size;y++)
		{
			*(*(a+i)+j)=*(*(matrix+x)+y);
			if((i==0||i==size-1)&&j%2==0)	//情况1 
			{
				j++;
				continue; 					//因为情况1和情况2中包含情况3或4，所以先考虑1和2 
			} 								//然后结束本次循环，不让程序去判断3和4的条件 
			if((j==0||j==size-1)&&i%2==1)	//情况2 
			{
				i++;
				continue;
			}
			if((i+j)%2==1)					//情况3 
			{
				i++;
				j--;
			}
			
			if((i+j)%2==0)					//情况4 
			{
				i--;
				j++;
			} 
		}
	 } 
	 cout<<"经过z字形编排后的矩阵如下："<<endl;
	 for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			cout<<setw(4)<<*(*(a+i)+j);
		cout<<endl;
		
	}
 } 
