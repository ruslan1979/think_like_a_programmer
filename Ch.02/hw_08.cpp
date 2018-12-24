/** Задача :
Обобщите код предыдущего
упражнения для создания программы, конвертирующей любое
число с базисом 16 или меньше в число с любым другим базисом.
Так, например, программа должна смочь преобразовать число с
базисом 9 в число с базисом 4.
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

