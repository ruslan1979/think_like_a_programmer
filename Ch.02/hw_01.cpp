/** Задача :
Используя только инструкции вывода одного символа, которые
выводят на экран символ #, пробел или конец строки, напишите
программу, которая распечатывает следующую фигуру:
########
 ######
  ####
   ##
*/

#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i != 4; ++i) {
        for (int j = 0; j != i; ++j)
            cout << " ";

        for (int j = 0; j != 8 - 2 * i; ++j)
              cout << "#";
        cout << endl;
    }
}
