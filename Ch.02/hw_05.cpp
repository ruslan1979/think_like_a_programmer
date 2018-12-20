/** Задача :
Если вам понравилась задача с формулой Луна, попробуйте написать программу для другой системы с проверочной цифрой,
например для 13-значной системы ISBN. Программа должна
принимать идентификационный номер и верифицировать его
либо принимать номер без проверочной цифры и генерировать
такую цифру.
*/

#include <iostream>

using namespace std;

int main() {
    enum modeType {GENERATION, VERIFICATION};
    modeType mode = GENERATION;

    cout << "Enter 12 or 13 digits: ";

    char digitChar = cin.get();
    int countNumber = 0, sum = 0, lastDigit = 0;


    while (digitChar != 10) {
        int number = (digitChar - '0');

        // если введено больше 12 цифр - переключаем режим
        if (countNumber >= 12) {
            mode = VERIFICATION;
            lastDigit = number;
            cout << lastDigit << endl;
        }
        // если меньше - подсчитываем сумму произведений разрядов на 1 или 3
        else {
            if (countNumber % 2 == 0)
                sum += (number * 1);
            else if (countNumber % 2 != 0)
                sum += (number * 3);
        }

        countNumber++;
        digitChar = cin.get();
    } ;

    // если ввели недостаточно данных, то выводим сообщение
    if (countNumber < 12) {
        cout << "Data is not enough";
        return 0;
    }

    switch (mode) {
        case GENERATION:
            // сгенерируем проверочную цифру
            if (sum % 10 != 0)
                cout << "CheckNumber is " << (10 - (sum % 10)) << endl;
            else
                cout << "CheckNumber is 0 " << endl;
            break;
        case VERIFICATION:
            // покажем реальную и ожидаемую проверочную цифру
            if (sum % 10 != 0)
                cout << "Expected CheckNumber is " << (10 - (sum % 10));
            else
                cout << "Expected CheckNumber is 0 ";

            cout << ", Your checkout is  " << lastDigit;
            break;
    }

    return 0;
}
