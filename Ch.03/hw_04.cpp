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

    Входные данные:  PRIVET CHUVAK
    Выходные данные: DFBJNH EUMJQO

*/

#include <iostream>

using namespace std;

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
            int pos = ch - 'A';
            cout << ALPHABET[pos];
        }
        else
            cout << ch;
    }

    return 0;
}
