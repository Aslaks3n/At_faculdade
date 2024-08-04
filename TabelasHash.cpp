//Tabela Hash
//Ana Carolina Barreto, Jo�o Bizzo, Sarah Ramos e Victor Beloto

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

//buscar posi��o de uma chave nas tabelas hash
int findKey(struct HashTab* hashTab, int key);

//excluir uma chave das tabelas hash 
bool deleteKey(struct HashTab* hashTab, int key);

//imprimir os valores das tabelas hash
void printHashTabVal(struct HashTab* hashTab);

// Implementa��o das fun��es
bool insert(struct HashTab* hashTab, int key) {
    int index1 = hashFun1(key);

    //posi��o na T1 est� vazia ou exclu�da
    if (hashTab->tab1[index1] == 0) {
        hashTab->tab1[index1] = key;
        return true; // Chave inserida em T1
    }

    // Verifica se houve colis�o em T1
    if (hashFun1(hashTab->tab1[index1]) == hashFun1(key)) {
        int currentKey = hashTab->tab1[index1];

        // Copia currentKey de T1 para T2 usando h2(currentKey)
        int index2 = hashFun2(currentKey);
        if (hashTab->tab2[index2] == 0) {
            hashTab->tab2[index2] = currentKey;
        } else {
        }

        //nova chave na posi��o h1(kj) de T1
        hashTab->tab1[index1] = key;
        return true; // Chave inserida em T1 ap�s a opera��o de Cuckoo
    }

    return false; // Chave n�o inserida devido a colis�es
}

int findKey(struct HashTab* hashTab, int key) {
    int index1 = hashFun1(key);
    int index2 = hashFun2(key);

    // Verifica se a posi��o na T1 est� vazia
    if (hashTab->tab1[index1] == 0) {
        return -1; // Retorna -1 para indicar que a chave n�o existe
    }

    // Verifica se a chave est� na tabela T1
    if (hashTab->tab1[index1] == key) {
        return index1; // Retorna a posi��o na T1 onde a chave foi encontrada
    }

    // Verifica se a chave est� na tabela T2
    if (hashTab->tab2[index2] == key) {
        return index2; // Retorna a posi��o na T2 onde a chave foi encontrada
    }

    return -1; // Chave n�o encontrada
}

bool deleteKey(struct HashTab* hashTab, int key) {
    int index1 = hashFun1(key);
    int index2 = hashFun2(key);

    // Verifica se a chave est� na posi��o calculada por h2(ki) em T2 e exclui, se for o caso
    if (hashTab->tab2[index2] == key) {
        hashTab->tab2[index2] = 0; // Remove da T2
        return true; // Chave exclu�da 
    }

    // Verifica se a chave est� na posi��o calculada por h1(ki) em T1
    if (hashTab->tab1[index1] == key) {
        hashTab->tab1[index1] = 0; // Remove da T1

        // Marca a posi��o em T1 como exclu�da para evitar falso positivo em busca
        hashTab->tab1[index1] = -1; // Marca como exclu�da
        return true; // Chave exclu�da
    }
    return false; // Chave n�o encontrada ou n�o exclu�da
}

void printHashTabVal(struct HashTab* hashTab) {
    // Percorre as tabelas hash para imprimir as chaves e posi��es
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
            insert(&hashTab, key); // Chama a fun��o de inser��o
        } else if (operation == 'r') {
            deleteKey(&hashTab, key); // Chama a fun��o de exclus�o
        } else{
		}
		}
    
    	printHashTabVal(&hashTab);
    	return 0;
    }

