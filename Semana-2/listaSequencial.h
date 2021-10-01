

typedef struct ED_LE
{

    int dado;
};

typedef struct lista Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int lista_cheia(Lista *li);

int insere_lista_final(Lista *li, struct ED_LE dados);

int insere_lista_inicio(Lista *li, struct ED_LE dados);

int insere_lista_ordenada(Lista *li, struct ED_LE dados);
