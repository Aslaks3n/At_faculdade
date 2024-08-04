//Grupo: Ana Carolina, João Bizzo e Sarah 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente {
    char nome[100];
    char estado[10];
    struct Paciente* prox;
};


struct FilaPrioridades {
    struct Paciente* regular;
    struct Paciente* ruim;
    struct Paciente* pessimo;
};


void inicializarFilaPrioridades(struct FilaPrioridades* fila) {
    fila->regular = NULL;
    fila->ruim = NULL;
    fila->pessimo = NULL;
}


void inserirPaciente(struct FilaPrioridades* fila, struct Paciente* paciente) {
    if (strcmp(paciente->estado, "regular") == 0) {
        paciente->prox = fila->regular;
        fila->regular = paciente;
    } else if (strcmp(paciente->estado, "ruim") == 0) {
        paciente->prox = fila->ruim;
        fila->ruim = paciente;
    } else if (strcmp(paciente->estado, "péssimo") == 0) {
        paciente->prox = fila->pessimo;
        fila->pessimo = paciente;
    }
}


struct Paciente* proximoPaciente(struct FilaPrioridades* fila) {
    struct Paciente* paciente = NULL;
    
    if (fila->pessimo != NULL) {
        paciente = fila->pessimo;
        fila->pessimo = fila->pessimo->prox;
    } else if (fila->ruim != NULL) {
        paciente = fila->ruim;
        fila->ruim = fila->ruim->prox;
    } else if (fila->regular != NULL) {
        paciente = fila->regular;
        fila->regular = fila->regular->prox;
    }
    
    return paciente;
}

int main() {
    struct FilaPrioridades fila;
    inicializarFilaPrioridades(&fila);
    char nome;
    char estado;

printf("Nome do paciente: ");
scanf("\n%s", &nome);
print("Classificação de urgência: ");
scanf("\n%s", &estado);
    struct Paciente paciente1 = { "Paciente 1", "ruim", NULL };
    struct Paciente paciente2 = { "Paciente 2", "regular", NULL };
    struct Paciente paciente3 = { "Paciente 3", "péssimo", NULL };

    inserirPaciente(&fila, &paciente1);
    inserirPaciente(&fila, &paciente2);
    inserirPaciente(&fila, &paciente3);

   
    struct Paciente* prox = proximoPaciente(&fila);
    if (prox != NULL) {
        printf("Próximo paciente: %s (%s)\n", prox->nome, prox->estado);
    }

    return 0;
}

