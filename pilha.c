#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int valor;
	struct No *prox;
}No, TipoNo;

typedef struct{
	TipoNo *topo;
	int tamanho;
}Pilha, TipoPilha;

void IniciaPilha(TipoPilha *pilha){
	pilha->topo = NULL;
	pilha->tamanho = 0;
}

int Vazia(TipoPilha *pilha){
	return (pilha->topo == NULL);
}

void Empilha(int x, TipoPilha *pilha){
	TipoNo *aux;
	aux = (TipoNo *) malloc(sizeof(TipoNo));
	aux->valor = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

int Desempilha(TipoPilha *pilha){
	TipoNo *q; int v;
	if (Vazia(pilha)) {
		printf("Lista vazia\n"); return 0;
	}	
	q = pilha->topo;
	pilha->topo = q->prox;
	v = q->valor;
	free(q);
	pilha->tamanho--;
	return v;
}



int main() {
	int i, numero, max=5;
	TipoPilha *pilha;
	pilha = (TipoPilha *) malloc (sizeof(TipoPilha));
	IniciaPilha(pilha);
	for (i=0;i<max;i++) {
		printf("Leitura do valor (%d) : ",i); scanf("%d",&numero);
		Empilha(numero, pilha);
		printf("Empilhou: %d \n", numero);
	}
	for(i=0;i<max;i++) {
		numero = Desempilha (pilha);
		printf ("Desempilhou: %d \n", numero);
	}
}

