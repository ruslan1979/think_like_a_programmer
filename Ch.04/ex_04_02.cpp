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

int length(arrayString s){
	int count = 0;
	while (s[count] != 0)
		count++;
	
	return count;
}


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

void concatenate(arrayString &s1, arrayString &s2) {
	int s1_oldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_oldLength + s2_Length;    
    arrayString newS = new char[s1_NewLength + 1];
    	
	for (int i = 0; i != s1_oldLength; ++i) {
		newS[i] = s1[i];
	}
    
	for (int i = 0; i != s2_Length; ++i) {
		newS[i + s1_oldLength] = s2[i];
	}
    	
	newS[s1_NewLength] = 0;
	delete[] s1;
	s1 = newS;    
}

void concatenateTester1() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    arrayString b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 's'; b[3] = 0;
    concatenate(a, b);
    
    cout << a << "\n" << endl;
}

void concatenateTester2() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    arrayString b = new char[1];
    b[0] = 0;
    concatenate(b, a);
    
    cout << a << "\n" << b << endl;
    
    cout << (void *)a << "\n" << (void *)b << endl;
}


int main() {
	concatenateTester2();    
	return 0;
}
