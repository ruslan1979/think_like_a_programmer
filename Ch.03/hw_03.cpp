/**
    Напишите функцию bool, которой передается массив и количество
    элементов в этом массиве и которая определяет, будут ли
    данные в этом массиве сортироваться. Для этого требуется только
    одна передача!
*/

#include <iostream>

#define NUM_ELEMENTS 10

using namespace std;


bool isSortable(int arr[], const int NUMBER_ELEMENTS) {
    for (int i = 0; i != NUMBER_ELEMENTS - 1; ++i) {
        if (arr[i] > arr[i + 1])
            return true;
    }

    return false;
}


int main() {
    int number_array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Is array sortable: " << boolalpha << isSortable(number_array1, NUM_ELEMENTS) << endl;

    int number_array2[] = {1, 2, 123, 4, 5, 6, 7, 8, 9, 10};
    cout << "Is array sortable: " << boolalpha << isSortable(number_array2, NUM_ELEMENTS) << endl;

    return 0;
}
