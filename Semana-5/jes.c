
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
// #include <time.h>

typedef struct soldado SLista;

struct soldado
{
    char nome[20];
    int num;
    SLista *prox;
};

// Auxiliares
SLista *cria_soldado(char *nome, int numero);
SLista *remove_soldado(SLista *lista, SLista *soldado);

SLista *inicializa();
int verificaCircVazio(SLista *lista);
SLista *insereSoldadoNoCirc(SLista *lista, char *nome, int num);
void imprimeSoldadosCirc(SLista *lista);
int verificaQteSoldados(SLista *lista);
SLista *executaJosephus(SLista *lista, int quantidade, int num_iteracoes);

int main(void)
{

    int i = 0, num_iteracoes;
    SLista *listax = inicializa();
    char nome[1];
    // scanf("Digite o nome do soldado:%s", entrada);
    while (nome[0] != ':')
    {   
        i = i + 1;
        printf("Digite o nome: ");
        scanf("%s", nome);
        if(nome[0]!=":")
         listax = insereSoldadoNoCirc(listax, nome, (i));
        printf("\nO nome armazenado foi: %s na posição %d \n", nome, i);
         
    }
   
    printf("Defina qual será o número de iterações: \n");
     scanf("%s", num_iteracoes);
       

    // Quantidade de soldados na lista
    int quantidade = verificaQteSoldados(listax);
    //printf("\nQuantidade de Soldados: %d\n\n", quantidade);

    // =======================
    // Execução de Josephus
    // =======================
    listax = executaJosephus(listax, quantidade, 4);

    // Imprime
    printf("\nSoldado a executar a tarefa:\n");
    imprimeSoldadosCirc(listax);

    return EXIT_SUCCESS;
}

/*
 * Função que aloca na memória um soldado apontando pra ele mesmo
 */
SLista *cria_soldado(char *nome, int numero)
{

    // Aloca na memória o espaço de um soldaddo
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

    // Verifica se a lista só tem um soldado
    if (soldado == aux && soldado->prox == aux)
    {
        lista = inicializa();

        // Verifica se o soldado é o primeiro da lista
    }
    else if (soldado == aux)
    {
        lista = soldado->prox;

        do
        {
            aux = aux->prox;
        } while (aux->prox->prox != lista);

        aux->prox = lista;

        // Qualquer outra posição da lista
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
 * Função Josephus
 */
SLista *executaJosephus(SLista *lista, int quantidade, int num_iteracoes)
{

    int i, num_soldado;

    // Verifica se o circulo esta vazio
    if (verificaCircVazio(lista))
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

    return executaJosephus(lista, quantidade - 1, num_iteracoes);
}

/*
 * Função que insere um soldado na lista
 */
SLista *insereSoldadoNoCirc(SLista *lista, char *nome, int num)
{

    // Alocação do soldado na memória
    SLista *soldado = cria_soldado(nome, num);
printf("Nome do sildado: %s Numero: %d\n", nome,num);
    
    if (!verificaCircVazio(lista))
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

    if (!verificaCircVazio(lista))
    {
        do
        {
            printf("[Num. %d] %s [%p]->[%p]\n", aux->num, aux->nome, aux, aux->prox);
            aux = aux->prox;

        } while (aux != lista);
    }
}

/*
 * Função que inicializa a lista
 */
SLista *inicializa()
{
    return NULL;
}

/*
 * Função que verifica se a lista está vazia
 */
int verificaCircVazio(SLista *lista)
{
    return !lista;
}

/*
 * Função que verifica a quantidade de soldados na lista
 */
int verificaQteSoldados(SLista *lista)
{
    int qtd = 0;
    SLista *aux = lista;

    if (!verificaCircVazio(lista))
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