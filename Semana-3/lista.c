#include <stdio.h>
#include <stdlib.h>

struct ED_LE
{
    int dado;
};

typedef struct elemento *Lista; //1

struct elemento
{
    struct ED_LE dados;    //2
    struct elemento *prox; //3
};

typedef struct elemento Elem; //4

//Funcao para criar a lista
Lista *cria_lista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista)); //5 reservando memoria para o primeiro no da lista
    if (li != NULL)
        *li = NULL; //6 ultimo elemento aponta para null
    printf("Lista criada.\n\n");
    return li;
}

//Funcao para liberar a lista
void libera_lista(Lista *li)
{ //7
    if (li != NULL)
    {
        Elem *no;
        while ((*li) != NULL)
        {                      //enquanto a lista nao for vazia
            no = *li;          //no recebe inicio da lista
            *li = (*li)->prox; //inicio da lista vai apontar para o proximo elemento
            free(no);          //libera antigo inicio
        }
        free(li); //libera inicio da lista
    }
    printf("Lista liberada.\n\n");
}

//Funcao para saber o tamanho da lista
int tamanho_lista(Lista *li)
{
    if (li == NULL)
        return 0;
    int i = 0;
    Elem *no = *li;
    while (no != NULL)
    {
        i++;
        no = no->prox;
    }
    return i;
}

//Funcao para saber se a lista esta cheia
int lista_cheia(Lista *li)
{ //8
    return 0;
}

//Funcao para saber se a lista esta vazia
int lista_vazia(Lista *li)
{
    if (li == NULL) //lista nula
        return 1;
    if (*li == NULL) //primeiro elemento apontando pra null
        return 1;
    return 0;
}

//Funcao para inserir elemento no final da lista
int insere_lista_final(Lista *li, struct ED_LE ed_le)
{
    if (li == NULL)
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = ed_le;
    no->prox = NULL;
    if ((*li) == NULL)
    {
        *li = no;
    }
    else
    {
        Elem *aux = *li; //SEMPRE percorrer a lista com um aux, nunca com o inicio da lista
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no; //insere no final o novo no
    }
    return 1;
}

//Funcao para inserir elemento no inicio da lista e lista vazia
int insere_lista_inicio(Lista *li, struct ED_LE ed_le)
{
    if (li == NULL)
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL) //nao foi possivel alocar memoria para o no
        return 0;
    no->dados = ed_le; //copia dados
    no->prox = (*li);  //proximo elemento = propria lista
    *li = no;          //muda inicio da lista
    return 1;
}

//Funcao para inserir elemento de forma ordenada
int insere_lista_ordenada(Lista *li, struct ED_LE ed_le)
{
    if (li == NULL)
        return 0;
    Elem *no = (Elem *)malloc(sizeof(Elem));
    if (no == NULL)
        return 0;
    no->dados = ed_le;
    if (lista_vazia(li))
    {
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else
    {
        Elem *ant, *atual = *li;
        while (atual != NULL && atual->dados.dado < ed_le.dado)
        { //comparando qual e maior
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li)
        { //insere no inicio, caso o elemento nao seja maior que nenhum outro
            no->prox = (*li);
            *li = no;
        }
        else
        { //insere no meio ou no final
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
}

//Funcao para remover elemento do final da lista
int remove_lista_final(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //lista vazia
        return 0;
    Elem *ant, *no = *li;
    while (no->prox != NULL)
    { //percorre a lista ate o final
        ant = no;
        no = no->prox;
    }
    if (no == (*li)) //no e o inicio da lista (lista com apenas um elemento)
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    printf("ELEMENTO REMOVIDO!\n\n");
    return 1;
}

//Funcao para remover elemnento do inicio da lista
int remove_inicio_lista(Lista *li)
{
    if (li == NULL)
        return 0;
    if ((*li) == NULL) //lista vazia
        return 0;
    Elem *no = *li; //auxiliar
    *li = no->prox; //inicio da lista aponta para o proximo elemento do no
    free(no);       //libera no
    printf("ELEMENTO REMOVIDO!\n\n");
    return 1;
}

//Funcao para remover um elemento qualquer
int remove_lista(Lista *li, int num)
{
    if (li == NULL)
        return 0;
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.dado != num)
    { //percorrendo lista
        ant = no;
        no = no->prox;
    }
    if (no == NULL) //elemento nao encontrado
        return 0;
    if (no == *li) //elemento e o primeiro da lista
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    printf("ELEMENTO REMOVIDO!\n\n");
    return 1;
}

//Funcao para consultar por posicao
int consulta_lista_pos(Lista *li, int pos, struct ED_LE *ed_le)
{
    if (li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while (no != NULL && i < pos)
    {
        no = no->prox;
        i++;
    }
    if (no == NULL) //lista vazia ou posicao nao encontrada
        return 0;
    else
    {
        *ed_le = no->dados;
        return no->dados.dado;
    }
}

//Funcao para consultar por conteudo
int consulta_lista_conteudo(Lista *li, int num, struct ED_LE *ed_le)
{
    int pos = 1;
    if (li == NULL)
        return 0;
    Elem *no = *li;
    while (no != NULL && no->dados.dado != num)
    {
        no = no->prox;
        pos++;
    }
    if (no == NULL)
        return 0;
    else
    {
        *ed_le = no->dados;
        return pos;
    }
}

//Funcao para imprimir lista
void imprime_lista(Lista *li)
{
    if (li == NULL)
    {
        return;
    }
    Elem *no = *li;
    while (no != NULL)
    {
        printf("Dado: %d\n", no->dados.dado);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

int main()
{

    int entrada, entrada_numero, pos, num, tam;
    struct ED_LE ed_le;
    Lista *li; //ponteiro para a struct elemento. ponteiro de ponteiro

    while (entrada != 12)
    {
        printf("Selecione uma opcao:\n\n");
        printf("1) Criar a lista dinamica por contiguidade\n2) Liberar lista dinamica por contiguidade\n3) Inserir no inicio\n4) Inserir no fim\n5) Inserir no meio (ordenado)\n6) Remover do inicio\n7) Remover do fim\n8) Remover do meio\n9) Consultar pelo conteudo\n10) Consultar pela posicao\n11) Imprimir Lista Dinamica por Contiguidade\n12) Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &entrada);
        printf("\n");
        system("cls");
        switch (entrada)
        {
        case 1:
        {
            li = cria_lista();
            printf("Qual o tamanho da lista que você deseja criar?");
            scanf("%d", &tam);
            break;
        }
        case 2:
            libera_lista(li);
            break;
        case 3:
            if (tamanho_lista(li) >= tam)
            {
                printf("A lista já está cheia!\n\n");
                break;
            }
            printf("Qual numero deseja inserir? ");
            scanf("%d", &entrada_numero);
            printf("\n");
            ed_le.dado = entrada_numero;
            insere_lista_inicio(li, ed_le);
            break;
        case 4:
            if (tamanho_lista(li) >= tam)
            {
                printf("A lista já está cheia!\n\n");
                break;
            }
            printf("Qual numero deseja inserir? ");
            scanf("%d", &entrada_numero);
            printf("\n");
            ed_le.dado = entrada_numero;
            insere_lista_final(li, ed_le);
            break;
        case 5:
            if (tamanho_lista(li) >= tam)
            {
                printf("A lista já está cheia!\n\n");
                break;
            }
            printf("Qual numero deseja inserir? ");
            scanf("%d", &entrada_numero);
            printf("\n");
            ed_le.dado = entrada_numero;
            insere_lista_ordenada(li, ed_le);
            break;
        case 6:
            break;
        case 7:
            remove_lista_final(li);
            break;
        case 8:
        {
            printf("Qual numero deseja remover? ");
            scanf("%d", &entrada_numero);
            printf("\n");
            ed_le.dado = entrada_numero;
            int x = remove_lista(li, entrada_numero);
            break;
        }
        case 9:
            printf("Qual numero deseja consultar? ");
            scanf("%d", &entrada_numero);
            printf("\n");
            int x = consulta_lista_conteudo(li, entrada_numero, &ed_le);
            if (x)
            {
                printf("Elemento %d: [%d]\n", entrada_numero, x);
                printf("\n");
            }
            else
                printf("ELEMENTO INEXISTENTE!\n\n");
            break;
        case 10:
            printf("Qual posicao deseja consultar? ");
            scanf("%d", &entrada_numero);
            printf("\n");
            int teste = consulta_lista_pos(li, entrada_numero, &ed_le);
            if (teste)
            {
                printf("Elemento [%d]: %d\n", entrada_numero, teste);
                printf("\n");
            }
            else
                printf("ELEMENTO INEXISTENTE!\n\n");
            break;
        case 11:
            imprime_lista(li);
            break;
        }
    }

    system("pause");
    return 0;
}