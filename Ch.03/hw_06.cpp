/**
    Для усложнения задачи шифрования текста сделайте так, чтобы
    ваша программа случайным образом генерировала шифровальный 
    массив вместо жестко закодированного массива const. Фактически 
    это означает помещение случайного символа в каждый элемент 
    массива, однако помните, что вы не можете заменить букву 
    самой собой. Итак, первым элементом не может быть буква A, 
    и вы не можете использовать ту же букву для двух подстановок, 
    то есть, если первым элементом является буква S, ни один
    другой элемент не может быть буквой S.
*/

#include <iostream>
#include <ctime>
#define CHARS_COUNT 26

using namespace std;

// генератор значений в массиве
int* generateNumbers(const int COUNT){
    int* numbers = new int[COUNT];
    for (int i = 0; i != COUNT; ++i)
        numbers[i] = rand() % COUNT;
    
    return numbers;
}

// определение равно ли значение элемента массива своему порядковому номеру в массиве
bool isEqualed(int array[], const int COUNT) {
    for (int i = 0; i != COUNT; ++i) {
        if (array[i] == i)
            return true;
    }
    
    return false;
}


int main() {
    string phrase;
    cout << "ENTER A PHRASE BY CAPITAL LETTERS : ";
    getline(cin, phrase);

    // генерация массива случайных чисел от 0 до 25
    srand(time(nullptr));
    int * numbers = new int[CHARS_COUNT];
        
    bool isTheSame = true;    
    // генерируем массив и проверяем - совпадают ли значения с порядковым номером массива
    while (isTheSame == true) {
        numbers = generateNumbers(CHARS_COUNT);
        isTheSame = isEqualed(numbers, CHARS_COUNT);
    }
    
    for (auto ch : phrase) {
        if ((ch >= 'A') && (ch <= 'Z')) {
            // номер позиции в массиве
            int pos_elem = ch - 'A';
            char elem = numbers[pos_elem] + 'A';
            cout << elem;
        }
        else
            cout << ch;
    }
    
    delete[] numbers;
    numbers = nullptr;

    return 0;
}
