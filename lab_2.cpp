// Создание новго массива на основе признака отбора положительных чисел с динамическим выделением памяти

#include <iostream>
using namespace std;

int* select(int* arr, int size, int& newSize) {

    newSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];

    int j = 0;

    for(int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            newArr[j] = arr[i];
            j++;
        }
    }

    return newArr;
}

int main() {
    int n;

    cout << "Размер: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Элементы:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newSize;

    int* result = select(arr, n, newSize);

    cout << "Новый массив:\n";
    for (int i = 0; i < newSize; i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    delete[] arr;
    delete[] result;

    return 0;
}