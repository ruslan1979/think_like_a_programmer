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
    

	return 0;
}

// ---------------------- tests characterAt begin ------------

void characterAtTest() {
    
}

// ---------------------- tests characterAt end ------------
void append(arrayString& s, char c) {
	int oldLength = length(s);

	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i != oldLength; ++i) {
		newS[i] = s[i];
	}

	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

int main() {
	replaceStringTest4();
	return 0;
}
