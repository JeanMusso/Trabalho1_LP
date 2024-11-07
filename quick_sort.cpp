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

// Função para obter o último nó de uma lista encadeada
No* obterFim(No* no) {
    while (no != nullptr && no->proximo != nullptr) {
        no = no->proximo;
    }
    return no;
}

// Função para particionar a lista encadeada em torno de um pivô
No* particionar(No* cabeca, No* fim, No** novaCabeca, No** novoFim) {
    No* pivo = fim;
    No* anterior = nullptr;
    No* atual = cabeca;
    No* cauda = pivo;

    // Faz a partição dos elementos, colocando menores que o pivô antes dele
    while (atual != pivo) {
        if (atual->dado < pivo->dado) {
            if (*novaCabeca == nullptr) {
                *novaCabeca = atual;
            }
            anterior = atual;
            atual = atual->proximo;
        } else {  // Mover nós maiores que o pivô para o final
            if (anterior) {
                anterior->proximo = atual->proximo;
            }
            No* temp = atual->proximo;
            atual->proximo = nullptr;
            cauda->proximo = atual;
            cauda = atual;
            atual = temp;
        }
    }

    // Atualiza novoFim para o último nó atual
    if (*novaCabeca == nullptr) {
        *novaCabeca = pivo;
    }
    *novoFim = cauda;

    return pivo;
}

// Função recursiva para o Quick Sort em uma lista encadeada
No* quickSortRecursivo(No* cabeca, No* fim) {
    if (!cabeca || cabeca == fim) {
        return cabeca;
    }

    No* novaCabeca = nullptr;
    No* novoFim = nullptr;

    No* pivo = particionar(cabeca, fim, &novaCabeca, &novoFim);

    // Ordena os elementos antes do pivô
    if (novaCabeca != pivo) {
        No* temp = novaCabeca;
        while (temp->proximo != pivo) {
            temp = temp->proximo;
        }
        temp->proximo = nullptr;

        novaCabeca = quickSortRecursivo(novaCabeca, temp);

        temp = novaCabeca;
        while (temp->proximo != nullptr) {
            temp = temp->proximo;
        }
        temp->proximo = pivo;
    }

    // Ordena os elementos após o pivô
    pivo->proximo = quickSortRecursivo(pivo->proximo, novoFim);

    return novaCabeca;
}

// Função para iniciar o Quick Sort em uma lista encadeada
void quickSort(No** cabecaLista) {
    *cabecaLista = quickSortRecursivo(*cabecaLista, obterFim(*cabecaLista));
}
