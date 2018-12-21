/** Задача :
Если вы изучали двоичные числа и знаете, как преобразовывать
десятичные числа в двоичные и наоборот, попробуйте написать
программу для выполнения таких преобразований. При этом чис-
ла должны быть неограниченной длины (но вы можете предполо-
жить, что числа должны быть достаточно небольшими, чтобы их
можно было сохранить в стандартной переменной int языка С++).
*/

#include <iostream>
#include <conio.h>

using namespace std;

string bin2dec(string input) {
    for (auto s: input) {
        int digit = stoi(s);


    }
}

int main() {
    enum modeType {BIN2DEC, DEC2BIN};
    modeType mode = BIN2DEC;

    cout << "Enter digits: ";

    char digitChar = cin.get();
    string figure;

    while (digitChar != 10) {
        int number = (digitChar - '0');

        // если введено больше 12 цифр - переключаем режим
        if (number > 1)
            mode = DEC2BIN;

        figure += digitChar;
        digitChar = cin.get();
    } ;

    switch (mode) {
        case BIN2DEC:
            break;
        case DEC2BIN:
            break;
    }

    return 0;
}

