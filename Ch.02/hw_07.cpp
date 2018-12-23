/** Задача :
Вы изучали шестнадцатеричные числа? Попробуйте написать
программу, которая позволяет пользователю ввести двоичное,
десятичное или шестнадцатеричное число и вывести все три варианта.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    enum modeType {BIN, DEC, HEX};
    modeType mode;

    cout << "Which enter mode do you prefer? Choose 1. Binary 2. Decimal 3. Hexadecimal" ;
    int inputMode;
    cin >> inputMode;

    string number;
    cout << "Enter your number ";
    cin >> number;
    
    //зададим режим
    switch (inputMode) {
        case 1:
            mode = BIN;
            break;
        case 2:
            mode = DEC;
            break;
       case 3:
            mode = HEX;
        
    }
   
    char buf[100];
    int outInt;
    switch (mode) {
        case BIN:
            // надо вывести в 10чном и 16ричном виде            
            //конвертируем в 10ричный и выводим
            outInt = stoi(number, nullptr , 2);                        
            cout << outInt << endl;            
            
            // конвертируем в 16ричный и выводим
            itoa(outInt, buf, 16);
            cout << buf << endl;            
            break;
        case DEC:
            // надо вывести в 2чном и 16ричном
            //выводим в 2чном
            itoa(stoi(number), buf, 2);
            cout << buf << endl;            
            
            //выводим в 16ричном
            itoa(stoi(number), buf, 16);
            cout << buf << endl;            
        	
            break;
        case HEX:
            // надо вывести в 10ричном и 2чном
            //конвертируем в 10ричный и выводим
            outInt = stoi(number, nullptr , 16);                        
            cout << outInt << endl;            

            // конвертируем в 2чный и выводим
            itoa(outInt, buf, 2);
            cout << buf << endl;            
            break;
    }    

    return 0;
}

