#pragma once
void recins(no**L, int x)//insere na lista
{
	if ((*L == NULL) || (x < *L->info))//se nao tiver nenhum ou o o valor for menor que o que esta no no atual
	{
		no*aux = new no;
		aux->info = x;
		aux->prox = *L;
		*L = aux;
	}
	else recins(&(*L)->prox,x)//chama denovo ate dar a condiçao



}
char recrem(no **L, x)
{
	if ((*L == NULL) || (x < *L->info))//se nao ter nenhun ou for menor que o primeiro
		return 0;
	else
	{
		if (x == ((*L)->info)//se for igual a informaçao daquele no
		{
			no*aux = *L;
			*L = aux->prox;
			delete aux;
			return 1;
		}
		else return recrem(&(*L)->prox, x);//senao chama a funçao recursiva para o proximo
	}
}
void rectodos(no**L)
{
	if (*L != NULL)
	{
		no*aux = *L;
		*L = aux->prox;
		delete aux;
		rectodos(&(*L));
	}
}
