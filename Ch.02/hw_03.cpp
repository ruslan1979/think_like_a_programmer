/** Задача :
Используя только инструкции вывода одного символа, которые
выводят на экран символ #, пробел или конец строки, напишите
программу, которая распечатывает следующую фигуру:
#            #
 ##        ##
  ###    ###
   ########
   ########
  ###    ###
 ##        ##
#           #
*/

#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i != 4; ++i) {
        for (int j = 0; j != i; ++j)
            cout << " ";
        
        for (int j = 0; j != (i+1); ++j)
        	cout << "#";
        	
        for (int j = 0; j != 12 - (4 * i); ++j)
            cout << " ";
            
        for (int j = 0; j != (i+1); ++j)
        	cout << "#";

    	cout << endl;
    }
    
    for (int i = 3; i != -1; --i) {
        for (int j = 0; j != i; ++j)
            cout << " ";
        
        for (int j = 0; j != (i+1); ++j)
        	cout << "#";
        	
        for (int j = 0; j != 12 - (4 * i); ++j)
            cout << " ";
            
        for (int j = 0; j != (i+1); ++j)
        	cout << "#";

    	cout << endl;
    }

}
