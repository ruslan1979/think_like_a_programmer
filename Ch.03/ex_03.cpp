/* Продолжение прошлого примера - кодирование данных.
   Т.е. строку надо закодировать в цифры
   Пример:
   Right? Yes!
   Вывод:
   18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10
*/
#include <iostream>
#include <string>

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
                
        if (inputChar >= 'a' && inputChar <= 'z') {
            //LOWERCASE            
            if (mode != LOWERCASE) {
                outputString +=  ',' + to_string((rand() % 100 + 1) * 27);
                mode = LOWERCASE;
            }
            outputString += ((countChar == 0) ? "" : ",") + to_string(digit - 'a' + 1);
        }
        else if (inputChar >= 'A' && inputChar <= 'Z') {
            //UPPERCASE            
            if (mode != UPPERCASE) { 
                outputString +=  ',' + to_string((rand() % 100 + 1) * 27);
                mode = UPPERCASE;
            }
            outputString += ((countChar == 0)? "" : ",") + to_string(digit - 'A' + 1);                
        }

        else {
            //PUNCTUATIN            
            if (mode != PUNCTUATION){
                outputString += ',' + to_string((rand() % 100 + 1) * 9);
                mode = PUNCTUATION;
            }
            
            const int ARRAY_SIZE = 8;
            const char punctuation[8] = {'!', '?', ',', '.', ' ', ';', '"', '\''};
            
            int targetPos = 0;
            while (punctuation[targetPos] != inputChar & targetPos < ARRAY_SIZE)
                targetPos++;
                        
            int punctuationCode = targetPos + 1;
                
            outputString += ((countChar == 0)? "" : ",") + to_string(punctuationCode); 
        }
        
        countChar++;
        inputChar = cin.get();
    } 
    
    cout << outputString;
    
    return 0;
}
