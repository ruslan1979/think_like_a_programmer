/* ЗАДАЧА 9:
        Представьте, что существует связный список, в узлах которого
        вместо символов хранятся цифры от 0 до 9 в формате int. Используя
        подобный связный список, мы можем реализовать положительные числа
        любого размера. Число 149, например, будет представлено в виде
        связного списка, в первом узле которого будет храниться цифра 1,
        во втором – 4, а в третьем и последнем — 9. Напишите функцию
        intToList, которая принимает в качестве параметра число и создает
        подобный связный список.
        Подсказка: возможно, вам покажется легче строить связный
        список в обратном порядке, например, если число 149, то в первом узле хранится 9.
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
