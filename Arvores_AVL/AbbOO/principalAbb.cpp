#include <iostream>
#include "arvores.h"
using namespace std;


void main()
{
	arvore <int> *T1 = new arvore<int>();
	T1->insere(15);
	T1->insere(10);
	T1->insere(5);

	T1->mostra(); cout << endl;

	T1->insere(3);
	T1->insere(8);
	T1->insere(7);

	T1->mostra();  cout << endl;

	system("pause");
}