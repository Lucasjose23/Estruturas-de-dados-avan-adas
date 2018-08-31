#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
void hanoi(int n, char ori, char aux, char dest);

void main()
{
	int n = 3;
	hanoi(n, 'a', 'b', 'c');




	

}
void hanoi(int n, char ori, char aux, char dest)
{
	if (n == 1)
	{
		cout<<"Mover disco  da torre "<<ori<<" para a torre "<<dest << endl;
		
	}
	else
	{
		hanoi(n - 1, ori, aux, dest);
		cout << "Mover disco  da torre " << ori << " para a torre " << dest <<endl;
		hanoi(n - 1, aux, dest, ori);
		
	}
}