//Código para classificar as pessoas pela altura
//Onde encontrar o problema no leetcode: https://leetcode.com/problems/sort-the-people/
//NOME: Jean Musso Jaques 
//DRE:123260921

#include <iostream>
#include <string>
using namespace std;

int MAX = 1000; 

//estrutura para armazenar as informações das pessoas
struct Pessoa {
    int altura;
    string nome;
};

//função para imprimir os nomes
void printNomes(Pessoa people[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << people[i].nome << endl;
    }
}

//função para ordenar 
void insertionSort(Pessoa people[], int n) {
    for (int i = 1; i < n; ++i) {
        Pessoa key = people[i];
        int j = i - 1;
                while (j >= 0 && people[j].altura < key.altura) {
            people[j + 1] = people[j];
            j--;
        }
        people[j + 1] = key;
    }
}

int main() {
    int n = 3; 
    Pessoa people[MAX] = {
        {180, "Jean"},
        {165, "Pedro"},
        {170, "Maria"}
    };

    //ordenando
    insertionSort(people, n);

    cout << "Nomes ordenados por altura:" << endl;
    printNomes(people, n);

    return 0;
}