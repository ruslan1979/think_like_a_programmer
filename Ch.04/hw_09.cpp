/* ������ 9:
        �����������, ��� ���������� ������� ������, � ����� ��������
        ������ �������� �������� ����� �� 0 �� 9 � ������� int. ���������
        �������� ������� ������, �� ����� ����������� ������������� �����
        ������ �������. ����� 149, ��������, ����� ������������ � ����
        �������� ������, � ������ ���� �������� ����� ��������� ����� 1,
        �� ������ � 4, � � ������� � ��������� � 9. �������� �������
        intToList, ������� ��������� � �������� ��������� ����� � �������
        �������� ������� ������.
        ���������: ��������, ��� ��������� ����� ������� �������
        ������ � �������� �������, ��������, ���� ����� 149, �� � ������ ���� �������� 9.
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

