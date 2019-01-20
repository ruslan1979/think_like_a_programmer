/* Операции со строками переменной длины.
    Напишите, используя кучу, реализацию трех основных функций строковых переменных:
    append  Функция получает в качестве параметров строку и символ и добавляет
    символ к конец строки.
    concatenate Функция получает две строки и добавляет символы второй строки
    к первой.
    characterAt Функция получает строку и число и возвращает символ, находящийся на соответствующей числу позиции (нумерация символов начинается с нуля).
    При написании кода учитывайте, что функция characterAt будет применяться часто, в
        то время как две другие функции — достаточно редко. Частота вызовов отразит относительную эффективность операций.A
*/
#include <iostream>

using namespace std;

typedef char * arrayString;

char characterAt(arrayString s, int position) {
	return s[position];
}

void append(arrayString& s, char c) {
	int oldLength = 0;
	while (s[oldLength] != 0) {
		oldLength++;
	}
	
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i != oldLength; ++i) {
		newS[i] = s[i];
	}
	
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
}

void appendTester1() {
	arrayString a = new char[5];
	a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
	append(a, '!');
	cout << a << "\n";	
}

void appendTester2() {
	arrayString a = new char[1];
	a[0] = 0;
	append(a, '!');
	cout << a << "\n";	
}

int main() {
	appendTester1();
	return 0;
}
