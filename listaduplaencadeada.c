#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuo{
	int valor;
	struct NoDuo *prox;
	struct NoDuo *prev;
} NoDuo, TipoNoDuo;

typedef struct{
	TipoNoDuo *inicio;
	TipoNoDuo *fim;
	int tamanho;
} ListaDuo, TipoListaDuo;

void InicialListaDuo(TipoListaDuo *lista){
	lista -> inicio = NULL;
	lista -> fim = NULL;
	lista -> tamanho = 0;
}

int VazioListaDuo(TipoListaDuo *lista){
	return(lista -> inicio == NULL);
}

void InsereInicio(int x, TipoListaDuo *lista){
	TipoNoDuo *new =(TipoNoDuo *)malloc(sizeof(TipoNoDuo));
	new -> valor = x;
	new -> prox = lista -> inicio;
	new -> prev = NULL;
	
	if (lista -> inicio)
	   lista -> inicio -> prev = new;
	else
	    lista -> fim = new;
	    
	lista -> inicio = new;
	lista -> tamanho++;
}

int RemoveInicio(TipoListaDuo *lista){
	if(VazioListaDuo(lista)){
		printf("LISTA VAZIA\n");
		return 0;
	}
	
	TipoNoDuo *a = lista -> inicio;
	int b = a -> valor;
	lista -> inicio = a -> prox;
	
	if(lista -> inicio)
	   lista -> inicio -> prev = NULL;
	else
	    lista -> fim = NULL;
	    
	free(a);
	lista -> tamanho--;
	
	return b;
}

int main() {
    int i, num, max = 5;
    TipoListaDuo *lista;
    lista = (TipoListaDuo *)malloc(sizeof(TipoListaDuo));
    IniciaListaDuo(lista);

    for (i = 0; i < max; i++) {
        printf("Leitura do valor (%d): ", i);
        scanf("%d", &num);
        InsereInicio(num, lista);
        printf("Inseriu: %d \n", num);
    }

    for (i = 0; i < max; i++) {
        num = RemoveInicio(lista);
        printf("Removeu: %d \n", num);
    }
    
    free(lista);

    return 0;
}
