#include <iostream>

using namespace std;

struct no
{
	char info;
	no *esq, *dir;
};

void Tins(no **, char);
void main()
{
	no *T1 = NULL;
	Tins(&T1,5);
	Tins(&T1, 3);
	Tins(&T1, 4);
	system("pause");
}

void Tins(no **T, char X)
{
	if (*T == NULL)
	{
		*T = new no;
		(*T)->info = X;
		(*T)->esq = (*T)->dir = NULL;
	}
	else
	{
		if (X <= (*T)->info)
			Tins(&((*T)->esq), X);
		else
			Tins(&((*T)->dir), X);
		
	}
}
