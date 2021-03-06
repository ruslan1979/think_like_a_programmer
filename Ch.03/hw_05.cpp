/**
    Сделайте так, чтобы предыдущая программа преобразовывала
    зашифрованный текст обратно в открытый текст для проверки
    корректности кодирования и декодирования.

    Входные данные:  DFBJNH EUMJQO
    Выходные данные:  PRIVET CHUVAK


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
