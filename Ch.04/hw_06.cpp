/* ЗАДАЧА 6:
     Напишите реализацию строковой переменной, которая использует связный список для хранения символов 
     вместо динамического массива. То есть у нас будет связный список, в котором в качестве полезных дан
     ных будут храниться одиночные символы.
    Такая реализация позволит увеличивать размер строки без создания нового массива. Вам стоит начать с 
    реализации функций append и charactertAt.     
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
//void append(arrayString& s, char c) {
	//int oldLength = length(s);

	//arrayString newS = new char[oldLength + 2];
	//for (int i = 0; i != oldLength; ++i) {
	//	newS[i] = s[i];
	//}

	//newS[oldLength] = c;
	//newS[oldLength + 1] = 0;
	//delete[] s;
	//s = newS;
//}

int main() {
	characterAtTest4();
	return 0;
}
