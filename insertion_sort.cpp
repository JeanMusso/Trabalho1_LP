#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;
};

// Função para adicionar um novo nó ao final da lista
void adicionar(No** cabecaLista, int novoDado) {
    No* novoNo = new No();
    novoNo->dado = novoDado;
    novoNo->proximo = nullptr;

    if (*cabecaLista == nullptr) {
        *cabecaLista = novoNo;
    } else {
        No* ultimo = *cabecaLista;
        while (ultimo->proximo != nullptr) {
            ultimo = ultimo->proximo;
        }
        ultimo->proximo = novoNo;
    }
}

// Função para inserir um nó em uma lista ordenada
void inserirOrdenado(No** cabecaLista, No* novoNo) {
    if (*cabecaLista == nullptr || (*cabecaLista)->dado >= novoNo->dado) {
        novoNo->proximo = *cabecaLista;
        *cabecaLista = novoNo;
    } else {
        No* atual = *cabecaLista;
        while (atual->proximo != nullptr && atual->proximo->dado < novoNo->dado) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

// Função para ordenar a lista encadeada usando Insertion Sort
void insertionSort(No** cabecaLista) {
    No* ordenado = nullptr;  // Lista encadeada ordenada
    No* atual = *cabecaLista;

    while (atual != nullptr) {
        No* proximo = atual->proximo;  // Armazena o próximo nó
        inserirOrdenado(&ordenado, atual);  // Insere o nó atual na lista ordenada
        atual = proximo;  // Move para o próximo nó
    }

    *cabecaLista = ordenado;  // Atualiza a cabeça para apontar para a lista ordenada
}

// Função para imprimir os elementos da lista encadeada
void imprimirLista(No* no) {
    while (no != nullptr) {
        cout << no->dado << " ";
        no = no->proximo;
    }
    cout << endl;
}

int main() {
    No* cabeca = nullptr;

    // Adicionando elementos à lista
    adicionar(&cabeca, 5);
    adicionar(&cabeca, 3);
    adicionar(&cabeca, 8);
    adicionar(&cabeca, 1);
    adicionar(&cabeca, 4);

    cout << "Lista antes da ordenação: ";
    imprimirLista(cabeca);

    insertionSort(&cabeca);

    cout << "Lista após a ordenação: ";
    imprimirLista(cabeca);

    return 0;
}
