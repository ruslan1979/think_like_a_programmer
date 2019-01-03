/* Продолжение прошлого примера - кодирование данных.
   Т.е. строку надо закодировать в цифры
   Пример:
   Right? Yes!
   Вывод (например):
   18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10

   Корректность работы можно проверить в дешифровщике
*/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;


int main() {
    string outputString; // строка вывода результата
    enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION}; // режимы шифрования

    modeType mode = UPPERCASE; // по умолчанию зашивровывается по алгоритму для заглавных букв
    char inputChar = cin.get();

    int countChar = 0;
    while (inputChar - 0 != 10) {
    	//cout << "Salam: " << inputChar << inputChar - 0	 << endl;
        int digit = inputChar;
		srand(time(0));
        if (inputChar >= 'a' && inputChar <= 'z') {
            //LOWERCASE
            if (mode != LOWERCASE) {
                mode = LOWERCASE;
                // вывод флага-перехода к другому регистру
                cout << ',' << (rand() % 1000) * 27;
            }

            outputString = ((countChar == 0) ? "" : ",") + to_string((digit - 'a' + 1) + (rand() % 1000) * 27);
        }

        else if (inputChar >= 'A' && inputChar <= 'Z') {
            //UPPERCASE
            if (mode != UPPERCASE) {
                mode = UPPERCASE;
                // вывод флага-перехода к другому регистру
                cout << ',' << (rand() % 1000) * 27;
            }

            outputString = ((countChar == 0)? "" : ",") + to_string((digit - 'A' + 1) + (rand() % 1000) * 27);
        }

        else {
            // флаг-переход к знакам препинания не должен быть краток 27, но должен быть краток 9
            // генерируемое число не дожно быть кратным 3, т.к. будет умножаться на 9
            int rand_num = 0;
            do {
				rand_num = rand() % 1000 + 1;
			}
            while (rand_num % 3 != 0);

            //PUNCTUATIN
            if (mode != PUNCTUATION){
                mode = PUNCTUATION;
                cout << ',' << to_string(rand_num * 9);
            }

            const int ARRAY_SIZE = 8;
            const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};

            int targetPos = 0;
            while (punctuation[targetPos] != inputChar & targetPos < ARRAY_SIZE)
                targetPos++;

            int punctuationCode = targetPos + 1;

            outputString = ((countChar == 0)? "" : ",") + to_string(punctuationCode + rand_num * 9);
        }

        countChar++;
        inputChar = cin.get();
        cout << outputString;
    }

    cout << endl;

    return 0;
}
