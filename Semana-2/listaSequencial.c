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
    if (li->qtd < MAX_VETOR)
    {
        li->dados[li->qtd] = dados;
        (li->qtd)++;
        return 1;
    }
    return 0;
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

        printf("li->qtd = %d \n", li->qtd);
    }

    li->dados[0] = dados;
    (li->qtd)++;
}

int insere_lista_ordenada(Lista *li, struct ED_LE ed_le)
{
    if (li == NULL)
        return 0;
    if (li->qtd == MAX_VETOR)
    {
        printf("\nLISTA CHEIA!.\n");
        return 0;
    }
    int k, i = 0;
    while (i < li->qtd && li->dados[i].dado < ed_le.dado)
        i++;
    for (k = li->qtd - 1; k >= i; k--)
        li->dados[k + 1] = li->dados[k];
    li->dados[i] = ed_le;
    li->qtd++;
    return 1;
}

void imprime_lista(Lista *li)
{
    if (li == NULL)
        return;
    int i;
    for (i = 0; i < li->qtd; i++)
    {
        printf("Dado n%d: %d\n", i + 1, li->dados[i]);
        printf("---------------------------------------------\n");
    }
}

int remove_lista_final(Lista *li)
{
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int remove_inicio_lista(Lista *li)
{
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    int k = 0;
    for (k = 0; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

int remove_lista(Lista *li, int num)
{
    if (li == NULL)
        return 0;
    if (li->qtd == 0)
        return 0;
    int k, i = 0;
    while (i < li->qtd && li->dados[i].dado != num)
        i++;
    if (i == li->qtd) //elemento nao encontrado
        return 0;
    for (k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

int consulta_lista_pos(Lista *li, int pos)
{
    if (li == NULL || pos < 0 || pos > li->qtd)
        return 0;
    return 1;
}

int consulta_lista_conteudo(Lista *li, int num)
{
    if (li == NULL)
        return 0;
    int i = 0;
    while (i < li->qtd && li->dados[i].dado != num)
        i++;
    if (i == li->qtd)
        return 0;
    return 1;
}

int main()
{
    Lista *li;
    int opcao, num;
    struct ED_LE dado;

    while (opcao != 12)
    {
        printf("Selecione uma opcao:\n\n");
        printf("1)Criar lista estatica\n2) Liberar lista estatica\n3) Inserir no inicio\n4) Inserir no fim\n5) Inserir no meio (ordenado)\n6) Remover do inicio\n7) Remover do fim\n8) Remover do meio\n9) Consultar pelo conteudo\n10) Consultar pela posicao\n11) Imprimir lista estatica\n12) Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            li = cria_lista();
            break;
        }

        case 2:
        {
            liberaLista(li);
            break;
        }

        case 3:
            if (li == NULL)
            {
                printf("Lista inexistente\n");
                break;
            }
            else
            {
                printf("Qual numero deseja inserir? ");
                scanf("%d", &num);
                // printf("%d",num);
                dado.dado = num;
                insere_lista_inicio(li, dado);
            }
            break;

        case 4:
            if (li == NULL)
            {
                printf("Lista inexistente\n");
                break;
            }
            else
            {
                printf("Qual numero deseja inserir? ");
                scanf("%d", &num);
                // printf("%d",num);
                dado.dado = num;
                insere_lista_final(li, dado);
            }
            break;

        case 5:
            if (li == NULL)
            {
                printf("Lista inexistente\n");
                break;
            }
            if (lista_cheia(li))
            {
                printf("Lista cheia!\n");
                break;
            }
            else
            {

                printf("Qual numero deseja inserir? ");
                scanf("%d", &num);
                // printf("%d",num);
                dado.dado = num;
                insere_lista_ordenada(li, dado);
            }
            break;

        case 6:
            remove_inicio_lista(li);
            break;
        case 7:
            remove_lista_final(li);
            break;

        case 8:
        {
            printf("Qual numero deseja remover? ");
            scanf("%d", &num);
            // printf("%d",num);

            remove_lista(li, num);
        }

        break;

        case 9:
            printf("Qual numero deseja consultar? ");
            scanf("%d", &num);
            printf("\n");
            if (consulta_lista_conteudo(li, num))
            {
                printf("Elemento %d: [%d]\n", num, li->dados[num]);
                printf("\n");
            }
            else
                printf("ELEMENTO INEXISTENTE!\n\n");
            break;

        case 10:
        {
            printf("Qual posição deseja consultar? ");
            scanf("%d", &num);
            if (consulta_lista_pos(li, num))
            {
                printf("Elemento: %d \n", li->dados[num]);
            }
            else
            {
                printf("Posição vazia! \n");
            }
        }
        break;

        case 11:
            imprime_lista(li);
            break;
        }
    }
}