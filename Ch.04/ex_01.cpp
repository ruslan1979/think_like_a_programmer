/* 
*/
#include <iostream>

using namespace std;

void refParamFunction(int & x) {
    x = 10;
}

int main() {
    int data = 5;
    cout << "Before execution data = " << data << endl;
    refParamFunction(data);
    cout << "After execution data = " << data << endl;
    
    return 0;
}
