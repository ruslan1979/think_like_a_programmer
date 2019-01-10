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
#include <time>
#define CHARS_COUNT 26

using namespace std;

int main() {
    string phrase;
    cout << "ENTER A PHRASE BY CAPITAL LETTERS : ";
    getline(cin, phrase);

    // генерация массива случайных чисел от 0 до 25
    srand(time(nullptr));
    int numbers[] = new int[CHARS_COUNT];
        
    for (int i = 0; i != CHARS_COUNT; ++i) {
        numbers[i] = rand() % CHARS_COUNT;
    }
    
    for (auto ch : phrase) {
        if ((ch >= 'A') && (ch <= 'Z')) {
            // номер позиции в массиве
            char elem = numPos + 'A';
            cout << elem;
        }
        else
            cout << ch;
    }

    return 0;
}
