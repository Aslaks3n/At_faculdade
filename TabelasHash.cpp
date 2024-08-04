//Tabela Hash
//Ana Carolina Barreto, João Bizzo, Sarah Ramos e Victor Beloto

#include <stdio.h>
#include <stdbool.h>

//Tamanho das tabelas hash
#define TABLE_SIZE 11

// Estrutura da tabela hash
struct HashTab {
    int tab1[TABLE_SIZE];
    int tab2[TABLE_SIZE];
};

//hash para a tabela T1
int hashFun1(int key) {
    return key % TABLE_SIZE;
}

//hash para a tabela T2
int hashFun2(int key) {
    return (int)(TABLE_SIZE * (key * 0.9 - (int)(key * 0.9)));
}

//Inserir uma chave nas tabelas hash
bool insert(struct HashTab* hashTab, int key);

//buscar posição de uma chave nas tabelas hash
int findKey(struct HashTab* hashTab, int key);

//excluir uma chave das tabelas hash 
bool deleteKey(struct HashTab* hashTab, int key);

//imprimir os valores das tabelas hash
void printHashTabVal(struct HashTab* hashTab);

// Implementação das funções
bool insert(struct HashTab* hashTab, int key) {
    int index1 = hashFun1(key);

    //posição na T1 está vazia ou excluída
    if (hashTab->tab1[index1] == 0) {
        hashTab->tab1[index1] = key;
        return true; // Chave inserida em T1
    }

    // Verifica se houve colisão em T1
    if (hashFun1(hashTab->tab1[index1]) == hashFun1(key)) {
        int currentKey = hashTab->tab1[index1];

        // Copia currentKey de T1 para T2 usando h2(currentKey)
        int index2 = hashFun2(currentKey);
        if (hashTab->tab2[index2] == 0) {
            hashTab->tab2[index2] = currentKey;
        } else {
        }

        //nova chave na posição h1(kj) de T1
        hashTab->tab1[index1] = key;
        return true; // Chave inserida em T1 após a operação de Cuckoo
    }

    return false; // Chave não inserida devido a colisões
}

int findKey(struct HashTab* hashTab, int key) {
    int index1 = hashFun1(key);
    int index2 = hashFun2(key);

    // Verifica se a posição na T1 está vazia
    if (hashTab->tab1[index1] == 0) {
        return -1; // Retorna -1 para indicar que a chave não existe
    }

    // Verifica se a chave está na tabela T1
    if (hashTab->tab1[index1] == key) {
        return index1; // Retorna a posição na T1 onde a chave foi encontrada
    }

    // Verifica se a chave está na tabela T2
    if (hashTab->tab2[index2] == key) {
        return index2; // Retorna a posição na T2 onde a chave foi encontrada
    }

    return -1; // Chave não encontrada
}

bool deleteKey(struct HashTab* hashTab, int key) {
    int index1 = hashFun1(key);
    int index2 = hashFun2(key);

    // Verifica se a chave está na posição calculada por h2(ki) em T2 e exclui, se for o caso
    if (hashTab->tab2[index2] == key) {
        hashTab->tab2[index2] = 0; // Remove da T2
        return true; // Chave excluída 
    }

    // Verifica se a chave está na posição calculada por h1(ki) em T1
    if (hashTab->tab1[index1] == key) {
        hashTab->tab1[index1] = 0; // Remove da T1

        // Marca a posição em T1 como excluída para evitar falso positivo em busca
        hashTab->tab1[index1] = -1; // Marca como excluída
        return true; // Chave excluída
    }
    return false; // Chave não encontrada ou não excluída
}

void printHashTabVal(struct HashTab* hashTab) {
    // Percorre as tabelas hash para imprimir as chaves e posições
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hashTab->tab1[i] != 0) {
            printf("%d, T1, %d\n", hashTab->tab1[i], i);
        }
        if (hashTab->tab2[i] != 0) {
            printf("%d, T2, %d\n", hashTab->tab2[i], i);
        }
    }
}

int main() {
    struct HashTab hashTab; // Cria as tabelas hash
    
    // Inicialize as tabelas hash
    char operation;
    int key;

    while (scanf("%c %d", &operation, &key) == 2) {
        if (operation == 'i') {
            insert(&hashTab, key); // Chama a função de inserção
        } else if (operation == 'r') {
            deleteKey(&hashTab, key); // Chama a função de exclusão
        } else{
		}
		}
    
    	printHashTabVal(&hashTab);
    	return 0;
    }

