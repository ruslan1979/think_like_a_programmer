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
        int sourceLength = length(source);
        
        bool isReplaced = false;
        for (int i = 0; i != (sourceLength - targetLength); ++i) {
            // 
            
            for (int j = 0; j != targetLength; j++) {
                if (source[i + j] != target[j]) {
                    isReplaced = false;
                    break;
                }
                
                isReplaced = true;
            }
            
            
        }
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
	substringTester2();
	return 0;
}
