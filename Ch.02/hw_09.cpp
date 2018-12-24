/** Задача :
Напишите программу, которая считывала бы строку текста, подсчитывая количество слов и вычисляя длину самого длинного
слова, наибольшее количество гласных букв в слове и/или любую другую статистику, какую вы можете себе представить
(длина самого короткого слова, наименьшее количество согласных)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    
    cout << "Enter initial basis:" ;
    int initBasis;
    cin >> initBasis;

    cout << "Enter end basis:" ;
    int endBasis;
    cin >> endBasis;

    cout << "Enter number:" ;
    string strNumber;
    cin >> strNumber;
   
    char buf[100];
    int outInt = stoi(strNumber, nullptr , initBasis);
    
    itoa(outInt, buf, endBasis);
    cout << "Output: " << buf << endl;            
    
    return 0;
}

