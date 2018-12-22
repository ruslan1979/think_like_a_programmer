/** Задача :
Если вы изучали двоичные числа и знаете, как преобразовывать
десятичные числа в двоичные и наоборот, попробуйте написать
программу для выполнения таких преобразований. При этом чис-
ла должны быть неограниченной длины (но вы можете предполо-
жить, что числа должны быть достаточно небольшими, чтобы их
можно было сохранить в стандартной переменной int языка С++).
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long int dec2bin(long int input) {
    string stroutput = "";
    for(int i = 0; input != 0; ++i) {
        //преобразовываем в строку - так легче вычислять
        char charDigit = (input % 2) + '0';
        stroutput = charDigit + stroutput;
        input /= 2;
    }

    long int output = stol(stroutput);
    return output;
}

long int bin2dec(long int input) {
    long int output = 0;
    //максимальная степень
    int power = 0;

    while (input != 0) {
        output += (input % 10) * pow(2, power);
        power++;
        input /= 10;
    }

    return output;
}

int main() {
    enum modeType {BIN2DEC, DEC2BIN};
    modeType mode = BIN2DEC;

    cout << "Enter digits: ";

    char digitChar = cin.get();
    long int number = 0;

    while (digitChar != 10) {
        number = number * 10 + (digitChar - '0');

        // если введено больше 12 цифр - переключаем режим
        if ((digitChar - '0') > 1)
            mode = DEC2BIN;

        digitChar = cin.get();
    } ;

    long int outputValue;
    switch (mode) {
        case BIN2DEC:
            cout << endl << "Binary 2 decimal mode is switched on" << endl;
            outputValue = bin2dec(number);
            break;
        case DEC2BIN:
            cout << endl << "Decimal 2 binary mode is switched on" << endl;
            outputValue = dec2bin(number);
            break;
    }

    cout << outputValue << endl;

    return 0;
}

