/* ЗАДАЧА 4:
        Измените реализацию нашей строки таким образом, чтобы эле-
        мент массива location[0] содержал размер массива (и, соответ-
        ственно, элемент массива location[1] содержал первый храня-
        щийся в массиве символ) и уже не пришлось бы использовать
        нулевой завершающий байт. Реализуйте каждую из трех функ-
        ций append, concatenate и charactertAt, используя, насколько
        это возможно, преимущество сохраненной информации о раз-
        мере массива. Так как мы больше не будем использовать согла-
        шение о нулевом завершающем байте, которое необходимо для
        работы со стандартным потоком вывода, то вам необходимо на-
        писать свою собственную функцию output, которая с помощью
        цикла переберет строковый параметр и выведет на экран сим-
        волы.
*/

#include <iostream>

using namespace std;

typedef char * arrayString;

char characterAt(arrayString s, int position) {
    if ((position > s[0]) || (position < 0))
        return 0;

	return s[position];
}

// --------------   TEST characterAt end ---------------
void characterAtTester1() {
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';

    cout << "Should be e: " <<characterAt(a, 2) << "\n" << endl;
}

void characterAtTester2() {
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';

    cout << "Should be nothing: " <<characterAt(a, 5) << "\n" << endl;
}
// --------------   TEST characterAt end ---------------

void output(arrayString& s) {
    int length = s[0];

    for (int i = 1; i != length + 1; ++i) {
        cout << s[i];
    }
}

void append(arrayString& s, char c) {
	int oldLength = s[0];

	arrayString newS = new char[oldLength + 2];
	for (int i = 1; i != oldLength + 1; ++i) {
		newS[i] = s[i];
	}

	newS[oldLength + 1] = c;
	newS[0] = oldLength + 1;
	delete[] s;
	s = newS;
}
// --------------   TEST append end ---------------
void appendTester1() {
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    cout << "Start value: ";
    output(a);

    char app = 'a';

    append(a, app);

    cout << "\nEnd value: ";
    output(a);
}

void appendTester2() {
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    cout << "Start value: ";
    output(a);

    char app = 0;

    append(a, app);

    cout << "\nEnd value: ";
    output(a);
}
// --------------   TEST append end ---------------

void concatenate(arrayString &s1, arrayString &s2) {
	int s1_oldLength = s1[0];
    int s2_Length = s2[0];
    int s1_NewLength = s1_oldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];

	for (int i = 1; i != s1_oldLength + 1; ++i) {
		newS[i] = s1[i];
	}

	for (int i = 1; i != s2_Length + 1; ++i) {
		newS[i + s1_oldLength] = s2[i];
	}

	newS[0] = s1_NewLength;
	delete[] s1;
	s1 = newS;
}

// --------------   TEST concatenate begin ---------------
void concatenateTester1() {
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    arrayString b = new char[4];
    b[0] = 3; b[1] = 'b'; b[2] = 'e'; b[3] = 's';

    cout << "Start value: ";
    output(a);

    concatenate(a, b);

    cout << "\nEnd value: ";
    output(a);
}

void concatenateTester2() {
    arrayString a = new char[5];
    a[0] = 4; a[1] = 't'; a[2] = 'e'; a[3] = 's'; a[4] = 't';
    arrayString b = new char[1];
    b[0] = 0;
    cout << "Start value: ";
    output(a);

    concatenate(b, a);

    cout << "\nEnd value: ";
    output(b);
}

// --------------   TEST concatenate end ---------------


// ---------------------- MAIN -------------------------

int main() {
	concatenateTester2();
	return 0;
}
