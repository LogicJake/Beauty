#include <fstream>
#include <iostream>
using namespace std;
#define numofDisks 5
ofstream file_out("out.txt");
void move(int n, char x, char y)
{
	file_out<<"move "<<n<<" from "<<x<<" to "<<y<<endl;
 } 
void Hannoi(int n, char from, char buffer, char to)		
{
	if(n == 1)
		move(1,from,to);
	else
	{
		Hannoi(n-1,from,to,buffer);
		move(n,from,to);
		Hannoi(n-1,buffer,from,to);
	}
}
int main()
{
	file_out<<"The solution for Hannoi, when the number of disks is "<<numofDisks<<endl;
	Hannoi(numofDisks,'a','b','c');
	file_out.close();
	return 0;
}
