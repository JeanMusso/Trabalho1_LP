//Código para contar “nice pairs” em um array
//Onde encontrar o problema no leetcode: //https://leetcode.com/problems/count-nice-pairs-in-an-array/
//NOME: Jean Musso Jaques 
//DRE:123260921

#include <iostream>
#define MOD 1000000007 //constante com o valor 10^9+7
using namespace std;

// função que recebe um número x e retorna a sua versão com os dígitos invertidos
int reverse(int x) {
	int rev = 0;
	while (x > 0) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev;
}

// função que combina dois subarrays ordenados em um único array ordenado.
void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int L[1000], R[1000]; 

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		} else {
			arr[k++] = R[j++];
		}
	}

	while (i < n1) {
		arr[k++] = L[i++];
	}

	while (j < n2) {
		arr[k++] = R[j++];
	}
}

//função que divide o array em duas metades até que cada metade tenha um elemento
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right); //combina as duas metades de volta em uma ordem ordenada
	}
}

//função que transforma os elementos de nums, ordena e conta os "nice pairs".
int countNicePairs(int nums[], int n) {
	int transformed[1000]; // assumindo um tamanho máximo de 1000 elementos no array

	for (int i = 0; i < n; i++) { // calcula o valor transformado para cada elemento
		transformed[i] = nums[i] - reverse(nums[i]); //guarda as diferenças entre cada número e sua versão invertida
	}

	// ordena o array transformado para que os "nicepairs" fiquem juntos
	mergeSort(transformed, 0, n - 1);

	// Conta os pares "nice"
	long long nicePairs = 0;
	long long count = 1;

	for (int i = 1; i < n; i++) {
		if (transformed[i] == transformed[i - 1]) {
			count++;
		} else {
			nicePairs = (nicePairs + (count * (count - 1)) / 2) % MOD;
			count = 1;
		}
	}
	nicePairs = (nicePairs + (count * (count - 1)) / 2) % MOD;

	return nicePairs;
}

int main() {
	int nums[] = {57, 3, 9, 97};
	int n = sizeof(nums) / sizeof(nums[0]);
	cout << "Número de nice pairs: " << countNicePairs(nums, n) << endl;
	return 0;
}