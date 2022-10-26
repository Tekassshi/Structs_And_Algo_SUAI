// Var 12

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>

using namespace std;

void insertSort(int* arr, int size) {
	int temp = 0, j = 0, exc = 0, comps = 0;

	for (int i = 0; i < size; i++) {
		temp = arr[i];

		for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
			arr[j + 1] = arr[j];
			comps += 1;
		}

		if (arr[j] < temp)
			comps += 1;

		if (arr[j + 1] != temp)
			exc += 1;

		arr[j + 1] = temp;
	}

	cout << "\n\nМассив отсортирован!\n";
	cout << "Перестановок: " << exc << endl;
	cout << "Сравнений: " << comps << endl;
	return;
}

void findPos(int* arr, int size, int ind) {
	if (ind >= size) {
		cout << "\n\nНесуществующая позиция! (" << ind << ")\n";
		return;
	}

	cout << "\n\nЭлемент найден!\n";
	cout << "Позиция: " << ind << ", значение: " << arr[ind] << endl;
}

void findVal(int* arr, int size, int value) {
	int f = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			cout << "\n\nЭлемент найден!\n";
			cout << "Позиция: " << i << ", значение: " << arr[i];
			f = 1;
			cout << "\n";
			break;
		}
	}
	if (f != 1)
		cout << "\n\nЭлемент (" << value << ") не найден!\n";
}

int* add(int* arr, int* size, int value) {

	int new_size = *size + 1;
	int* new_arr = new int[new_size];

	for (int i = 0; i < *size; i++) {
		new_arr[i] = arr[i];
	}

	new_arr[new_size - 1] = value;
	*size = new_size;
	delete[] arr;

	insertSort(new_arr, *size);
	return new_arr;
}

int* remove(int* arr, int* size, int ind) {

	int new_size = *size - 1;
	int* new_arr = new int[new_size];
	int k = 0;

	for (int i = 0; i < *size; i++) {
		if (i != ind) {
			new_arr[k] = arr[i];
			k += 1;
		}
	}
	*size = new_size;
	delete[] arr;

	insertSort(new_arr, *size);
	return new_arr;
}

void findRepSum(int* arr, int size) {
	int c = 1, temp = arr[0];
	cout << endl;

	for (int i = 1; i <= size; i++) {
		if (arr[i] == arr[i - 1]) {
			c += 1;
			temp = arr[i];
		}
		else {
			cout << "Значение: " << temp << ", повторений: " << c << endl;
			c = 1;
		}
		temp = arr[i];
	}
}

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите размер массива: "; cin >> n;

	int* arr = new int[n];

	cout << "\nВведите элементы массива по одному:\n";

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	insertSort(arr, n);
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\nФункция \"findPos\":";
	findPos(arr, n, 5);

	cout << "\nФункция \"findVal\":";
	findVal(arr, n, 10);

	int val = -125;
	cout << "\n\nФункция \"add\" (" << val << "):";
	arr = add(arr, &n, -125);
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	int ind = 0;
	cout << "\n\nФункция \"remove\" (" << ind << "):";
	arr = remove(arr, &n, 0);
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	cout << "\n\nФункция \"findRepSum\":";
	findRepSum(arr, n);
	cout << endl;

	delete[] arr;
	_CrtDumpMemoryLeaks();
}