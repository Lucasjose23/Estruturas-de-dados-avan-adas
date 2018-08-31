#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
//template <class ELEM>

template <class Elem>
class Listas
{
private:
	int TAM;
	struct  no
	{
		Elem info;
		no *prox;
	} *L;

public:
	Listas();
	~Listas();
	void insere(Elem);
	char learq(string);
	void geraarq(string);
	Elem remove(Elem);
	string mostra();

};

template <class Elem>
void Listas<Elem>::geraarq(string endereco)
{
	ofstream myfile(endereco);//gera um arquivo pra escrita
	myfile.is_open();//abbre ele
	no *AUX = L;
	while (AUX)
	{
		myfile << AUX->info << endl;//dentro do arquivo guarda a informaçao de aux
		AUX = AUX->prox;
	}
	myfile.close();
}

template <class Elem>
char Listas<Elem>::learq(string endereco)
{
	Elem line;
	ifstream myfile(endereco); // ifstream = padrão ios:in//abre o arquivo que for passado no endereço para leitura
	if (myfile)//se existir o arquivo
	{
		while (!myfile.eof()) //enquanto end of file for false continua
		{
			getline(myfile, line); // como foi aberto em modo texto(padrão)//vai pluando linha e guardando na variavel line
								   //e não binário(ios::bin) pega cada linha
			insere(line);//insere na lista
			cout << line << endl;
		}
		myfile.close();
		return 1;
	}

	else return 0;

}

template <class Elem>
Listas<Elem>::Listas()
{

}

template <class Elem>
Listas<Elem>::~Listas()
{

}
template <class Elem>
void Listas<Elem>::insere(Elem x)
{
	no *aux = new no();
	aux->info = x;
	if ((L == NULL) || (x < L->info))//primeiro ou nenhum
	{
		aux->prox = L;
		L = aux;

	}
	else
	{
		no *P = L;
		while ((P->prox) && (x>P->prox->info))
			P = P->prox;
		aux->prox = P->prox;
		P->prox = aux;
	}
}
template <class Elem>
Elem Listas<Elem>::remove(Elem x)
{
	no *P = L;
	if (x < L->info)
		return 0;
	else
	{

		if (x == L->info)
		{


			L = P->prox;
			Elem z = P->info;
			delete P;
			return z;
		}
		else
		{
			while ((P->prox) && (x > P->prox->info))
				P = P->prox;
			if ((P->prox) && (x == P->prox->info))
			{
				no* aux = P->prox;
				P->prox = aux->prox;
				Elem z = aux->info;
				delete aux;
				return z;

			}

		}
	}

}
template <class Elem>
string Listas<Elem>::mostra()
{
	no *aux = L;
	ostringstream S;
	S << "[";
	while (aux)
	{
		S << aux->info;
		aux = aux->prox;
		if (aux)
		{
			S << ",";
		}
	}
	S << "]";
	return S.str();
}