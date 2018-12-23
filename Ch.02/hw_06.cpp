/** Задача :
Если вы изучали двоичные числа и знаете, как преобразовывать
десятичные числа в двоичные и наоборот, попробуйте написать
программу для выполнения таких преобразований. При этом чис-
ла должны быть неограниченной длины (но вы можете предполо-
жить, что числа должны быть достаточно небольшими, чтобы их
можно было сохранить в стандартной переменной int языка С++).
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    enum modeType {BIN2DEC, DEC2BIN};
    modeType mode = BIN2DEC;

    cout << "Enter digits: ";

    char digitChar = cin.get();
    string number = "";

    while (digitChar != 10) {
        number += digitChar;

        // если вводимая цифра больше 1 - переключаем режим
        if ((digitChar - '0') > 1)
            mode = DEC2BIN;

        digitChar = cin.get();
    } ;

    
    switch (mode) {
        case BIN2DEC:
            cout << endl << "Binary 2 decimal mode is switched on" << endl;
            cout << stoi(number, nullptr, 2) << endl;            
            break;
        case DEC2BIN:
            cout << endl << "Decimal 2 binary mode is switched on" << endl;
            char buf[100];
            itoa(stoi(number), buf, 2);
            cout << buf << endl;
            break;
    }    

    return 0;
}

