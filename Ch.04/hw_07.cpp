/* ЗАДАЧА 7:
        В продолжение предыдущего упражнения реализуйте функцию
        concatenate. Не забудьте, что, если мы вызываем функцию
        concatenate(s1, s2), где оба параметра — это указатели на пер-
        вые узлы соответствующих связных списков, функция должна
        создавать копию каждого узла из списка s2 и добавлять ее в ко-
        нец списка s1, а не просто помещать указатель на первый узел
        списка s2 в поле next последнего узла списка s1.
*/

#include <iostream>

using namespace std;

struct stringListNode {
    char elem;
    stringListNode * next;
};

typedef stringListNode * arrayString;

char characterAt(arrayString& s, int position) {
	arrayString as = s;
	int count = 0;

	if (position == 0) {
		return as->elem;
	}

	while (as != NULL) {
		if (count == position) {
			return as->elem;
		}
		as = as->next;
		count++;
	}

	return 0;
}

// ---------------------- tests characterAt begin ------------

void characterAtTest1() {
    stringListNode * sLN0 = new stringListNode; sLN0->elem = 'a';
	stringListNode * sLN1 = new stringListNode; sLN1->elem = 'b';
	stringListNode * sLN2 = new stringListNode; sLN2->elem = 'c';

	sLN0->next = sLN1; sLN1->next = sLN2; sLN2->next = NULL;
	arrayString as = sLN0;

	sLN0 = sLN1 = sLN2 = NULL;

	cout << characterAt(as, 0);

	delete [] as;
}

void characterAtTest2() {
    stringListNode * sLN0 = new stringListNode; sLN0->elem = 'a';
	stringListNode * sLN1 = new stringListNode; sLN1->elem = 'b';
	stringListNode * sLN2 = new stringListNode; sLN2->elem = 'c';

	sLN0->next = sLN1; sLN1->next = sLN2; sLN2->next = NULL;
	arrayString as = sLN0;

	sLN0 = sLN1 = sLN2 = NULL;

	cout << characterAt(as, 2);

	delete [] as;
}

void characterAtTest3() {
    stringListNode * sLN0 = new stringListNode; sLN0->elem = 'a';
	stringListNode * sLN1 = new stringListNode; sLN1->elem = 'b';
	stringListNode * sLN2 = new stringListNode; sLN2->elem = 'c';

	sLN0->next = sLN1; sLN1->next = sLN2; sLN2->next = NULL;
	arrayString as = sLN0;

	sLN0 = sLN1 = sLN2 = NULL;

	cout << characterAt(as, -1);

	delete [] as;
}

void characterAtTest4() {
    stringListNode * sLN0 = new stringListNode; sLN0->elem = 'a';
	stringListNode * sLN1 = new stringListNode; sLN1->elem = 'b';
	stringListNode * sLN2 = new stringListNode; sLN2->elem = 'c';

	sLN0->next = sLN1; sLN1->next = sLN2; sLN2->next = NULL;
	arrayString as = sLN0;

	sLN0 = sLN1 = sLN2 = NULL;

	cout << characterAt(as, 8888);

	delete [] as;
}

// ---------------------- tests characterAt end ------------

void append(arrayString& s, char c) {
    stringListNode * newNode = new stringListNode; newNode->elem = c; newNode->next=NULL;

    if (s == NULL) {
        s = newNode;
        return;
    }

    stringListNode * node = s;
    while (node->next != NULL) {
		node = node->next;
	}

    node->next = newNode;
}

// ---------------------- tests append begin ------------

void appendTest1() {
    stringListNode * sLN0 = new stringListNode; sLN0->elem = 'a';
	stringListNode * sLN1 = new stringListNode; sLN1->elem = 'b';
	stringListNode * sLN2 = new stringListNode; sLN2->elem = 'c';

	sLN0->next = sLN1; sLN1->next = sLN2; sLN2->next = NULL;
	arrayString as = sLN0;

	sLN0 = sLN1 = sLN2 = NULL;

    char c = 'd';

    append(as, c);

    while (as != NULL) {
        cout << "ArrayString " << as->elem << endl;
		as = as->next;
	}

	delete [] as;
}

// ---------------------- tests append end ------------

void concatenate(arrayString& s1, arrayString& s2) {
    stringListNode * node1 = s1;
    stringListNode * node2 = s2;

    while (node1->next != NULL) {
		node1 = node1->next;
	}

    while (node2 != NULL) {
        node1->next = node2;
        //node1 = node2;
        node2 = node2->next;
        node1 = node1->next;
    }

}

// ---------------------- tests concatenate begin ------------

void concatenateTest1() {
    stringListNode * sLN0 = new stringListNode; sLN0->elem = 'a';
	stringListNode * sLN1 = new stringListNode; sLN1->elem = 'b';
	stringListNode * sLN2 = new stringListNode; sLN2->elem = 'c';

	sLN0->next = sLN1; sLN1->next = sLN2; sLN2->next = NULL;
	arrayString as1 = sLN0;

	sLN0 = sLN1 = sLN2 = NULL;

    stringListNode * sLN5 = new stringListNode; sLN5->elem = 'd';
	stringListNode * sLN6 = new stringListNode; sLN6->elem = 'e';
	stringListNode * sLN7 = new stringListNode; sLN7->elem = 'f';

	sLN5->next = sLN6; sLN6->next = sLN7; sLN7->next = NULL;
	arrayString as2 = sLN5;

	sLN5 = sLN6 = sLN7 = NULL;

    concatenate(as1, as2);

    while (as1 != NULL) {
        cout << "ArrayString " << as1->elem << endl;
		as1 = as1->next;
	}

	delete [] as2;
	delete [] as1;
}

void concatenateTest2() {
    stringListNode * sLN0 = new stringListNode;

	arrayString as1 = sLN0;

	//sLN0 = sLN1 = sLN2 = NULL;

    stringListNode * sLN5 = new stringListNode; sLN5->elem = 'd';
	stringListNode * sLN6 = new stringListNode; sLN6->elem = 'e';
	stringListNode * sLN7 = new stringListNode; sLN7->elem = 'f';

	sLN5->next = sLN6; sLN6->next = sLN7; sLN7->next = NULL;
	arrayString as2 = sLN5;

	sLN5 = sLN6 = sLN7 = NULL;

    concatenate(as1, as2);

    while (as1 != NULL) {
        cout << "ArrayString " << as1->elem << endl;
		as1 = as1->next;
	}

	delete [] as2;
	delete [] as1;
}

// ---------------------- tests concatenate end ------------

int main() {
	concatenateTest1();
	return 0;
}
