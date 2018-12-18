/** Задача :
Если вам понравилась задача с формулой Луна, попробуйте написать программу для другой системы с проверочной цифрой,
например для 13-значной системы ISBN. Программа должна
принимать идентификационный номер и верифицировать его
либо принимать номер без проверочной цифры и генерировать
такую цифру.
*/

#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    char digitChar;
    int countNumber = 0, sum = 0;

    cout << "Enter 12 digits: ";
    do {
        digitChar = getch();
        cout << digitChar;

        int number = (digitChar - '0');
        if (countNumber % 2 == 0)
            sum += (number * 1);
        else if (countNumber % 2 != 0)
            sum += (number * 3);

        countNumber++;
    } while (countNumber != 12);

    // сгенерируем проверочную цифру
    if (sum % 10 != 0)
        cout << endl << "CheckNumber is " << (10 - (sum % 10)) << endl;
     else
        cout << endl << "CheckNumber is 0 " << endl;
    return 0;
}
