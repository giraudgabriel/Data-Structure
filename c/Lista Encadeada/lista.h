typedef struct lista Lista;

// funcao de criar lista

Lista* criar_lista();

// funcao de inserir no inicio da lista

Lista* inserir_lista(Lista *l, int i);

// funcao para imprimir elementos da lista

void imprimir_lista(Lista *l);

// funcao para verificar lista vazia

int vazia(Lista *l);

// funcao para buscar na lista

Lista* buscar(Lista *l, int v);

//funcao remover elemento

Lista* remover(Lista* l, int v);

//funcao comparar lista

int comparar(Lista* l1, Lista* l2);
