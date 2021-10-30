/*
 ============================================================================
 Name        : josephusProblem.c
 Author      : Natasha Kaweski e Vinícius Ferreira (12-4NA)
 Version     : Version 2.1
 Copyright   : Your copyright notice
 Description : O Problema de Josephus (Tenenbaum, 1989)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct soldado SLista;

struct soldado
{
	char nome[20];
	int num;
	SLista *prox;
};

SLista *cria_soldado(char *nome, int numero);
SLista *remove_soldado(SLista *lista, SLista *soldado);

SLista *inicializa();
int verificaListaVazio(SLista *lista);
SLista *insereSoldado(SLista *lista, char *nome, int num);
void imprimeSoldadosCirc(SLista *lista);
int verificaQteSoldados(SLista *lista);
SLista *executaJosephus(SLista *lista, int quantidade, int contagem);

/*
 * Função para criar um soldado dentro da lista
 */
SLista *cria_soldado(char *nome, int numero)
{

	// Aloca na memória o espaço par aum soldado
	SLista *soldado = (SLista *)malloc(sizeof(SLista));

	// Atribui os parâmetros como os dados armazenados do espaço em memória
	soldado->num = numero;
	strcpy(soldado->nome, nome);
	soldado->prox = soldado;

	return soldado;
}

/*
 * Função que remove um soldado da lista
 */
SLista *remove_soldado(SLista *lista, SLista *soldado)
{

	SLista *aux = lista;

	// Verificar Lista só um soldado
	if (soldado == aux && soldado->prox == aux)
	{
		lista = inicializa();

		// Verificar se é o primeiro
	}
	else if (soldado == aux)
	{
		lista = soldado->prox;

		do
		{
			aux = aux->prox;
		} while (aux->prox->prox != lista);

		aux->prox = lista;

		// Padrão para quaquer outra posição
	}
	else
	{
		do
		{
			if (aux->prox == soldado)
			{
				aux->prox = soldado->prox;
				break;
			}

			aux = aux->prox;

		} while (aux->prox != lista);
	}

	// Limpa esse espaço de memória
	free(soldado);

	// Retorna a nova lista
	return lista;
}

/*
 * Josephus
 */
SLista *executaJosephus(SLista *lista, int quantidade, int contagem)
{

	int i, num_soldado, num_iteracoes;

	// Verificar se não tenho nenhum soldado
	if (verificaListaVazio(lista))
	{
		printf("\n[-] Ops! Círculo esta vazio.\n");
		return lista;
	}

	// Verifica se há apenas um soldado na lista
	if (quantidade == 1)
	{
		printf("\n[!] Soldado escolhido: %s\n", lista->nome);
		return lista;
	}

	num_iteracoes = contagem;
	num_soldado = rand() % quantidade;

	SLista *aux = lista;

	printf("Quantidade de soldados: %d\n\n", quantidade);

	imprimeSoldadosCirc(lista);

	printf("\nSorteando o soldado para iniciar a contagem...\nSorteado %da posição.\n", num_soldado + 1);

	// O soldado sorteado vai ser a X iteração do número sorteado
	for (i = 0; i < num_soldado; i++)
		aux = aux->prox;

	printf("Soldado inicial: %s\nNum. de iterações na adedanha: %d\n", aux->nome, num_iteracoes);

	// Percorre a lista X vezes a partir do soldado sorteado e elimina um soldado da lista
	for (i = 0; i < num_iteracoes; i++)
		aux = aux->prox;

	printf("Soldado eliminado: %s\n", aux->nome);
	lista = remove_soldado(lista, aux);

	printf("\n-----------------------------------------\n");

	return executaJosephus(lista, quantidade - 1, contagem);
}

/*
 * Função que insere um soldado na lista
 */
SLista *insereSoldado(SLista *lista, char *nome, int num)
{

	// Alocação do soldado na memória
	SLista *soldado = cria_soldado(nome, num);
	printf("Nome do sildado: %s Numero: %d\n", nome, num);
	/* Se lista existir (se não estiver vazia),
	 * percorre até encontrar o último elemento.
	 * Liga o 'prox' do último soldado no novo soldado,
	 * liga o 'prox' do novo soldado na lista.
	 */
	if (!verificaListaVazio(lista))
	{
		SLista *aux = lista;

		while (aux->prox != lista)
			aux = aux->prox;

		aux->prox = soldado;   // Liga o último elemento da lista no novo registro
		soldado->prox = lista; // Fecha a lista circular, ligando o novo registro na lista
	}

	return soldado;
}

/*
 * Função que imprime na tela a lista com os soldados inseridos
 */
void imprimeSoldadosCirc(SLista *lista)
{

	SLista *aux = lista;

	if (!verificaListaVazio(lista))
	{
		do
		{
			printf("Soldado Num: %d Nome: %s \n", aux->num, aux->nome);
			aux = aux->prox;

		} while (aux != lista);
	}
}


SLista *inicializa()
{
	return NULL;
}


int verificaListaVazio(SLista *lista)
{
	return !lista;
}


int verificaQteSoldados(SLista *lista)
{
	int qtd = 0;
	SLista *aux = lista;

	if (!verificaListaVazio(lista))
	{
		qtd++;
		while (aux->prox != lista)
		{
			qtd++;
			aux = aux->prox;
		}
	}
	return qtd;
}

int main(void)
{



	// Escolhe um número
	srand(time(0));

	// Declaração de variáveis
	int i = 1;
	SLista *listax = inicializa();
	char nomes[0];
	
	while (nomes[0] != ':')
	{
		scanf("%s", nomes);
		listax = insereSoldado(listax, nomes, (i));
		i++;
	}

	int contagem;
	printf("Selecione o número de contagem:\n");
	scanf("%d", &contagem);

	
	int quantidade = verificaQteSoldados(listax);
	
	listax = executaJosephus(listax, quantidade, contagem);

	// Imprime
	printf("\nSoldado que deverá executar a tarefa:\n");
	imprimeSoldadosCirc(listax);

	return EXIT_SUCCESS;
}
