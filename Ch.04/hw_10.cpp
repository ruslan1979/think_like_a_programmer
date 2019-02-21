/* ЗАДАЧА 10:
        Создайте для списка с цифрами из предыдущего упражнения
    функцию, которая принимает в качестве параметров два таких
    списка и возвращает новый список, представляющий сумму их
    чисел.
*/

#include <iostream>

using namespace std;

struct intListNode {
    int elem;
    intListNode * next;
};

intListNode* intToList(int digit) {
	intListNode* result = new intListNode();
	
	if (digit == 0){
		result->elem = digit;		
		return result;
	}
		
	int tempInt = digit;
	result->elem = (tempInt % 10);
	tempInt /= 10;
	
	while (tempInt != 0) {
		intListNode* temp = new intListNode();	
		temp->elem = (tempInt % 10);
		temp->next = result;
		result = temp;
		
		tempInt /= 10;				
	}
			
    return result;
}

void intToListTest1() {
    int digit = 0;

    intListNode* presentedList = intToList(digit);
    while (presentedList != nullptr) {
        cout << presentedList->elem << " ";
        presentedList = presentedList->next;
    }
}

void intToListTest2() {
    int digit = 1234;

    intListNode* presentedList = intToList(digit);
    while (presentedList != nullptr) {
        cout << presentedList->elem << " ";
        presentedList = presentedList->next;
    }
}

int main() {
    intToListTest2();
    return 0;
}
