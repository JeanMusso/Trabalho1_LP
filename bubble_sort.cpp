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

// Função para realizar o Bubble Sort na lista encadeada
void bubbleSort(No* cabeca) {
    if (cabeca == nullptr) return;

    bool trocou;
    No* ptr1;
    No* lptr = nullptr; // Ponteiro para o último nó ordenado na iteração atual

    do {
        trocou = false;
        ptr1 = cabeca;

        while (ptr1->proximo != lptr) {
            if (ptr1->dado > ptr1->proximo->dado) {
                swap(ptr1->dado, ptr1->proximo->dado);
                trocou = true;
            }
            ptr1 = ptr1->proximo;
        }
        lptr = ptr1;
    } while (trocou);
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

    bubbleSort(cabeca);

    cout << "Lista após a ordenação: ";
    imprimirLista(cabeca);

    return 0;
}
