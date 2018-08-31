#include <iostream>

template <class Elem>
class arvore
{
private:
	struct no{
		Elem info;
		char fbal;
		no *esq, *dir;
	} *T;
	char H;
	void insavl(no **, Elem,char *);
	void rd(no **);
	void np(no *);
public:
	arvore();
	void insere(Elem);
	void mostra();
};

template <class Elem>
arvore<Elem>::arvore()
{
	T = NULL;
}

template <class Elem>
void arvore<Elem>::insere(Elem X)
{
	insavl(&T, X,&H);
}

template <class Elem>
void arvore<Elem>::mostra()
{
	np(T);
}

template <class Elem>
void arvore<Elem>::np(no *T)
{
	if (T == NULL)
		cout << ".";
	else
	{
		cout  << " " << T->info;
		np(T->esq);
		np(T->dir);
	}
}

template <class Elem>
void arvore<Elem>::insavl(no **T, Elem X,char *H)//insere na avl
{
	if (*T == NULL)//se t igual a null ele faz a inserçaos
	{
		*T = new no;
		(*T)->info = X;
		(*T)->esq = (*T)->dir = NULL;
		(*T)->fbal = 0;//todo no folha o fator de balanceamento e igual a 0
		*H = 1;
	}
	else//se nao
	{
		if (X <= (*T)->info)//se o elemento for menor que o atualp
		{
			insavl(&((*T)->esq), X, H);//chamada recursiva a esquerda
			if (H)//se h for direfente de 0
				switch ((*T)->fbal)//depois que ele sai da chama recursiva ele pergunta
				{
				case 1:(*T)->fbal = 0; *H = 0; break;//se o fator for igual a um quer dizer que tem um elemento a direitae apos essa inserçao a raiz e igual a 0
				case 0:(*T)->fbal = -1; break;//se for 0 entao quer dizer que um novo elemnto foi colocado do lado esquerdo entao e -1
				case -1:rd(T); *H = 0;//e se caso ele ja for menos 1 entao acontece a rotaçao a direita
				}
		}
		else//se o elemnto for maior que o atual
		{
			insavl(&((*T)->dir), X, H);
			if (H)//se h for 1
				switch ((*T)->fbal)
				{
				case -1:(*T)->fbal = 0; *H = 0; break;//se o valor da raiz for menos 1 entao a inserçao a direita vai equilibrar
				case 0:(*T)->fbal = 1; break;//se for 0 e porq ja estava equilibrado e a inserçao a direita desequilibro deixando 1
				//case 1:re(T); *H = 0;//se for um ja entao tem a rotaçao a direita
				}
		}
	}
}
template <class Elem>
void arvore<Elem>::rd(no **T)
{
	no *pB = (*T)->esq;//ja cria uma variavel auxiliar que tem a informaçao do lado esquerdo da raiz
	if (pB->fbal == -1) //rotação simples//se o fb for igual a menos 1 os sinais sao iguais entao e rotaçao simples
	{
		(*T)->esq = pB->dir;//a esquerda que ja foi alterada entao pode ser mudada
		pB->dir = *T;//a esquerda do t recebeu a direita do pb entao a direita do pb recebe o t
		(*T)->fbal = 0;
		*T = pB;//e pb passa a ser a raiz
	}
	else//rotaçao dupla a direita
	{
		no *pC = pB->dir;//se e rotalçao dupla e porque o sinal do balanceamento do pb nao é igual da rais entao se cria uma aux que ercebe oq esta a direita de pb
		pB->dir = pC->esq;//a direita de pb fica livre para receber oq esta a esquerda de pc
		pC->esq = pB;//a esquerda de pc fica livre para receber o prorpio pb//rotaçao a esquerda
		(*T)->esq = pC->dir;//rotaçao a direita agora usando pc
		pC->dir = *T;//e a direita do pc recebe o proprio t deixando b a esquerda e a a direita e trasnformando c em rais
		if (pC->fbal == -1)
		{
			(*T)->fbal = 1;
			pB->fbal = 0;
		}
		else
		{
			(*T)->fbal = 0;
			pB->fbal = -1;
		}
		*T = pC;
	}
	(*T)->fbal = 0;
}
