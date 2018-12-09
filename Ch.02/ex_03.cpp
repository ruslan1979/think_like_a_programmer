/** Задача : многозначного числа
Напишите программу, которая считывала бы число символ за символом и 
преобразовывала бы его в целое число, используя только одну переменную типа char и одну
переменую типа int. Число может быть как минимум однозначным.
*/

#include <iostream>

using namespace std;

int main() {
    cout << "Enter a number: ";
    char digitChar = cin.get();
    int digitNumber = (digitChar - '0');
        
    digitChar = cin.get();

    while ( digitChar != 10 ) {
        digitNumber =  digitNumber * 10 + (digitChar - '0');        
        digitChar = cin.get();
    }
    
    cout << "Number entered: " << digitNumber << "\n";
    return 0;
}

