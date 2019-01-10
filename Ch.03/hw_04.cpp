/**
    Вот вариация задания с массивом значений const. Напишите программу 
    для шифрования методом подстановки. При таком шифровании все 
    сообщения состоят из прописных букв и знаков препинания. Исходное 
    сообщение называется открытым текстом, зашифрованный текст создается 
    путем замены каждой буквы другой буквой (например, каждая буква C 
    может стать буквой X). Для этой задачи жестко закодируйте массив const 
    из 26 элементов char для шифрования и сделайте так, чтобы ваша программа 
    прочитывала открытый текст и выводила эквивалент сообщения в виде 
    зашифрованного текста.
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
