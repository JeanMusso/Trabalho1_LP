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

// Função para dividir a lista encadeada em duas metades
void dividir(No* cabeca, No** metade1, No** metade2) {
    No* lento = cabeca;
    No* rapido = cabeca->proximo;

    // Movemos os ponteiros para encontrar o meio
    while (rapido != nullptr) {
        rapido = rapido->proximo;
        if (rapido != nullptr) {
            lento = lento->proximo;
            rapido = rapido->proximo;
        }
    }

    *metade1 = cabeca;
    *metade2 = lento->proximo;
    lento->proximo = nullptr;
}

// Função para mesclar duas listas encadeadas ordenadas
No* mesclar(No* lista1, No* lista2) {
    if (lista1 == nullptr) return lista2;
    if (lista2 == nullptr) return lista1;

    if (lista1->dado <= lista2->dado) {
        lista1->proximo = mesclar(lista1->proximo, lista2);
        return lista1;
    } else {
        lista2->proximo = mesclar(lista1, lista2->proximo);
        return lista2;
    }
}

// Função recursiva para ordenar a lista encadeada usando Merge Sort
No* mergeSort(No* cabeca) {
    if (cabeca == nullptr || cabeca->proximo == nullptr) {
        return cabeca;
    }

    No* metade1 = nullptr;
    No* metade2 = nullptr;

    dividir(cabeca, &metade1, &metade2);

    // Recursão nas duas metades
    metade1 = mergeSort(metade1);
    metade2 = mergeSort(metade2);

    // Mescla as duas metades ordenadas
    return mesclar(metade1, metade2);
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

    cabeca = mergeSort(cabeca);

    cout << "Lista após a ordenação: ";
    imprimirLista(cabeca);

    return 0;
}
