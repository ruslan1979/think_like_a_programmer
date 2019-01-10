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
#define CHARS_COUNT 26

using namespace std;

int findElement(char input, const char TEMPLATE[]) {
    // а если это последний элемент массива
    if (input = TEMPLATE[CHARS_COUNT - 1])
        return CHARS_COUNT - 1;
    
    for (int i = 0; ; ++i) {
        if (input == TEMPLATE[i])
            return i;
    }
}

int main() {
    const char ALPHABET[] = {
                             'Q', 'W', 'E', 'R',
                             'N', 'T', 'Y', 'U',
                             'B', 'I', 'O', 'P',
                             'V', 'A', 'S', 'D',
                             'C', 'F', 'G', 'H',
                             'M', 'J', 'K', 'L',
                             'Z', 'X'
                            };

    string phrase;
    cout << "ENTER A PHRASE BY CAPITAL LETTERS : ";
    getline(cin, phrase);

    for (auto ch : phrase) {
        if ((ch >= 'A') && (ch <= 'Z')) {
            // номер позиции в массиве
            int numPos = findElement(ch, ALPHABET);
            char elem = numPos + 'A';
            cout << elem;
        }
        else
            cout << ch;
    }

    return 0;
}
