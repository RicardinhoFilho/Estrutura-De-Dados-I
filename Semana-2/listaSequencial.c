#include <stdio.h>
#include "listaSequencial.h"

#include <stdio.h>
#define MAX_VETOR 5
// // Definição da Estrutura Lista Linear Sequencial Estática

struct lista
{
    int qtd;
    struct ED_LE dados[MAX_VETOR];
};

Lista *cria_lista()
{
    Lista *li;
    li = (Lista *)malloc(sizeof(struct lista));
    if (li != NULL)
    {
        li->qtd = 0;
    }
    printf("Lista criada com sucesso!\n");
    return li;
}

void liberaLista(Lista *li)
{
    free(li);
    printf("Lista liberada com sucesso!\n");
}

int tamanho_lista(Lista *li)
{
    if (li == NULL)
    {
        return -1;
    }
    else
    {
        return li->qtd;
    }
}

int lista_vazia(Lista *li)
{
    if (li->qtd == 0)
        return 1;
    return 0;
}

int lista_cheia(Lista *li)
{
    if (li->qtd == MAX_VETOR)
        return 1;
    return 0;
}

int insere_lista_final(Lista *li, struct ED_LE dados)
{
    if (li == NULL)
    {
        return 0;
    }
    if (lista_cheia(li))
    {
        return 0;
    }
    li->dados[li->qtd] = dados;
    li->qtd;
}

int insere_lista_inicio(Lista *li, struct ED_LE dados)
{
    if (li == NULL)
    {
        return 0;
    }
    if (lista_cheia(li))
    {
        return 0;
    }
    int i;
    for (i = li->qtd - 1; i >= 0; i--)
    {
        li->dados[i + 1] = li->dados[i];
        li->dados[0];
        li->qtd++;
        return 1;
    }

    li->dados[li->qtd] = dados;
    li->qtd;
}

int insere_lista_ordenada(Lista *li, struct ED_LE dados)
{
    if (li == NULL)
    {
        return 0;
    }
    if (lista_cheia(li))
    {
        return 0;
    }
    int k, i = 0;

    while (i < li->qtd && li->dados[i].dado < li->dados)
    {
        i++;
    }

    for (k - li->qtd - 1; k >= i; k--)
    {
        li->dados[k + 1] = li->dados[k];
        li->dados[i] = dados;
        li->qtd++;
        return 1;
    }

    li->dados[li->qtd] = dados;
    li->qtd;
    return 1;
}

int main()
{
    Lista *li = cria_lista();
    struct ED_LE dados;

    dados.dado = 9;
    liberaLista(li);
    printf("teste");

    int t = tamanho_lista(li);
    int c = lista_cheia(li);
    int v = lista_vazia(li);
    insere_lista_inicio(li, dados);
    printf("Tamanho = %d \n", t);
    printf(" %d \n", c);
    printf("%d \n", v);

    printf("Lista: %d", li->dados[0]);
}