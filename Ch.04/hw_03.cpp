/* ЗАДАЧА 3:

    Создайте для нашей динамической строки функцию replaceString,
    которая получает три параметра в формате arrayString:
    source, target и replaceText. Функция заменяет каждое появление
    строки target в строке source на строку replaceText. Например,
    если source указывает на массив, содержащий abcdabee,
    target указывает на ab, а replaceText — на xyz, то после
    завершения работы функции source будет указывать на массив,
    содержащий xyzcdxyzee.

*/

#include <iostream>
#include <assert.h>

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

arrayString substring(arrayString& s, int pos, int len) {
    pos--;

    int len_sub = (pos + len > length(s)) ? (len - (pos + 1)) : len;

    arrayString out = new char[len_sub];
    for (int i = 0; i != len_sub; ++i) {
        out[i] = s[i + pos];
    }

    return out;
}

// hw03 is started
void replaceString(arrayString& source, arrayString& target, arrayString& replaceText) {
    int targetLength = length(target);
    cout << "targetText : " << target << endl;
    cout << "targetLength : " << targetLength;
    int sourceLength = length(source);

    arrayString result = new char[sourceLength];

    for (int i = 0; i != sourceLength - (targetLength - 1); ++i) {
        bool isReplaced = true;
        // есть ли шаблон текста, который надо менять
        for (int j = 0; j != targetLength; ++j)
            if ((source[i + j] != target[j]) && (target[j] != 0))
                isReplaced = false;

        // такой шаблон найден
        if (isReplaced){
            for (int j = 0; j != targetLength; ++j)
                result[i + j] = replaceText[j];
        }
        //если такого шаблона нет
        else
            result[i] = source[i];
    }

    source = result;

    delete[] result;
}

// -----------------------------   TESTS begin -----------------------------------------------
// replaceText - 1 символа (1 - буква)
// target - 1 символа (1 - буква)
void replaceStringTest1() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;

    arrayString targ = new char[1]; targ[0] = 'l';

    arrayString replaceText = new char[1]; replaceText[0] = 'z';

    replaceString(test, targ, replaceText);

    arrayString res = new char[11];
    res[0] = 'H'; res[1] = 'e'; res[2] = 'z'; res[3] = 'z'; res[4] = 'o'; res[5]='W'; res[6] = 'o'; res[7] = 'r'; res[8] = 'z'; res[9] = 'd'; res[10] = 0;

    assert(res == test);

    delete[] test;
    delete[] res;
}

// replaceText - 3 символа (2 - буква, 1 - нулевой)
// target - 3 символа (2 - буква, 1 - нулевой)
void replaceStringTest2() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;

    arrayString targ = new char[3]; targ[0] = 'l'; targ[1] = 'd'; targ[2] = 0;

    arrayString replaceText = new char[3]; replaceText[0] = 'z'; replaceText[1] = 'k'; replaceText[3] = 0;

    replaceString(test, targ, replaceText);

    arrayString res = new char[11];
    res[0] = 'H'; res[1] = 'e'; res[2] = 'z'; res[3] = 'z'; res[4] = 'o'; res[5]='W'; res[6] = 'o'; res[7] = 'r'; res[8] = 'z'; res[9] = 'k'; res[10] = 0;

    assert(res == test);

    delete[] test;
    delete[] res;
}

// replaceText - 3 символа (2 - буква, 1 - нулевой)
// target - 3 символа (2 - буква, 1 - нулевой)
void replaceStringTest3() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;

    arrayString targ = new char[1]; targ[0] = 'l';

    arrayString replaceText = new char[1]; replaceText[0] = 'z';

    replaceString(test, targ, replaceText);

    arrayString res = new char[11];
    res[0] = 'H'; res[1] = 'e'; res[2] = 'z'; res[3] = 'z'; res[4] = 'o'; res[5]='W'; res[6] = 'o'; res[7] = 'r'; res[8] = 'z'; res[9] = 'd'; res[10] = 0;

    assert(res == test);

    delete[] test;
    delete[] res;
}

// -----------------------------   TESTS end -----------------------------------------------

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

void substringTester() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = '!'; a[5] = 0;

    arrayString b = new char[4];
    b = substring(a, 1, 4);
    cout << b << endl;
    delete[] a;
    delete[] b;
}

void substringTester2() {
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = '!'; a[5] = 0;

    arrayString b = new char[4];
    b = substring(a, 1, 46);
    cout << b << endl;
    delete[] a;
    delete[] b;
}



int main() {
	replaceStringTest1();
	return 0;
}
