#include <iostream>
using namespace std;
#include "Listas.h"

void main()
{
	Listas<string> *F1 = new Listas<string>();
	F1->learq("dados.txt");
	//cout << F1->mostra() << endl;
	F1->geraarq("aaaa.txt");
	system("pause");
}