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
    size_t elem;
    intListNode * next;
};

//typedef stringListNode * arrayString;
intListNode* intToList(size_t digit) {
    intListNode* result = new intListNode;
    intListNode* temp = new intListNode;
    size_t tempInt = digit;

    while (tempInt != -1) {
        int remainder = digit % 10;
        result->elem = remainder;
    }

}

void intToListTest1() {
    size_t digit = 123;

    intListNode* presentedList = intToList(digit);
    while (presentedList != nullptr) {
        cout << presentedList->elem << " ";
        presentedList = presentedList->next;
    }
}

int main() {
    intToListTest1();
    return 0;
}

int main() {
	removeCharsTest1();
	return 0;
}

