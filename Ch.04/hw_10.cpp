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

int listToInt(intListNode* list) {
	int result = 0;;
	
	while (list != NULL) {	
		result = result * 10 + list->elem;		
		list = list->next;
	}
	
	return result;
}

intListNode* sumToList(intListNode* list1, intListNode* list2) {
	int num1 = listToInt(list1);
	int num2 = listToInt(list2);
	
	int sum = num1 + num2;
	
	return intToList(sum);	
}

void sumToListTest1() {
    int digit1 = 0, digit2 = 0;
    intListNode* l1 = intToList(digit1);
    intListNode* l2 = intToList(digit2);

    intListNode* presentedList = sumToList(l1, l2);
    while (presentedList != nullptr) {
        cout << presentedList->elem << " ";
        presentedList = presentedList->next;
    }
}

void sumToListTest2() {
    int digit1 = 1234, digit2 = 5678;
    intListNode* l1 = intToList(digit1);
    intListNode* l2 = intToList(digit2);

    intListNode* presentedList = sumToList(l1, l2);
    while (presentedList != nullptr) {
        cout << presentedList->elem << " ";
        presentedList = presentedList->next;
    }
}

int main() {
    sumToListTest2();
    return 0;
}
