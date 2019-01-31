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
void replaceString(arrayString& source, const arrayString& target, const arrayString& replaceText) {
    int sourceLength = length(source);
    int targetLength = length(target);
    int replaceLength = length(replaceText);

    int countReplace = 0; // сколько раз будет замена
    for (int i = 0, repl_it = 0; i != sourceLength - (targetLength - 1); ++i) {

        bool isReplaced = true;
        // есть ли шаблон текста, который надо менять
        for (int j = 0; j != targetLength; ++j)
            if (source[i + j] != target[j]) {
                isReplaced = false;
                break;
            }

        countReplace += (isReplaced) ? 1 : 0;
    }

    // если нет шаблона для поиска - просто прекращаем работу
    if (countReplace == 0)
        return;

	// длина итоговой выходной строки
    int resultLength = countReplace * (replaceLength - targetLength) + sourceLength + 1; // 1 - место для нулевого символа
    arrayString result = new char[resultLength];

    for (int i = 0, repl_it = 0; i <= sourceLength; ) {
        bool isReplaced = true;
        // есть ли шаблон текста, который надо менять
        for (int j = 0; j != targetLength; ++j)
            if (source[i + j] != target[j]) {
                isReplaced = false;
                break;
            }

        // ничего нет на замену
        if (!isReplaced) {
            result[repl_it] = source[i];
            i++;
            repl_it++;
            continue;
        }

        for (int j = 0; j != replaceLength; ++j) {
            result[repl_it + j] = replaceText[j];
        }

        i += targetLength;
        repl_it += replaceLength;
    }

    result[resultLength-1] = 0;
    for (int i = 0; i != resultLength; ++i)
        source[i] = result[i];

    delete[] result;
}

// -----------------------------   TESTS begin -----------------------------------------------
// replaceText - 2 символа (1 - буква, 1 - нулевой символ)
// target - 2 символа (1 - буква, 1 - нулевой символ)
void replaceStringTest1() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;
    cout << "Before replacement: " << test << endl;

    arrayString targ = new char[2]; targ[0] = 'l'; targ[1] = 0;

    arrayString replaceText = new char[2]; replaceText[0] = 'z'; replaceText[1] = 0;

    replaceString(test, targ, replaceText);

    cout << "After replacement: " << test << endl;

    delete[] test;
}

// replaceText - 3 символа (2 - буква, 1 - нулевой)
// target - 3 символа (2 - буква, 1 - нулевой)
void replaceStringTest2() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;

    arrayString targ = new char[3]; targ[0] = 'l'; targ[1] = 'd'; targ[2] = 0;

    arrayString replaceText = new char[3]; replaceText[0] = 'z'; replaceText[1] = 'k'; replaceText[2] = 0;

    cout << "Before replacement: " << test << endl;

    replaceString(test, targ, replaceText);

    cout << "After replacement: " << test << endl;

    delete[] test;
}

// replaceText - 3 символа (2 - буква, 1 - нулевой)
// target - 2 символа (1 - буква, 1 - нулевой)
void replaceStringTest3() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;
    cout << "Before replacement: " << test << endl;

    arrayString targ = new char[3]; targ[0] = 'l'; targ[1] = 'l'; targ[2] = 0;

    arrayString replaceText = new char[2]; replaceText[0] = 'z'; replaceText[1] = 0;

    replaceString(test, targ, replaceText);

    cout << "After replacement: " << test << endl;

    delete[] test;
}

// replaceText - 2 символа (1 - буква, 1 - нулевой)
// target - 3 символа (2 - буква, 1 - нулевой)
void replaceStringTest4() {
    arrayString test = new char[11];
    test[0] = 'H'; test[1] = 'e'; test[2] = 'l'; test[3] = 'l'; test[4] = 'o'; test[5]='W'; test[6] = 'o'; test[7] = 'r'; test[8] = 'l'; test[9] = 'd'; test[10] = 0;
    cout << "Before replacement: " << test << endl;

    arrayString targ = new char[2]; targ[0] = 'l'; targ[1] = 0;
    arrayString replaceText = new char[3]; replaceText[0] = 'z'; replaceText[1] = 'k'; replaceText[2] = 0;

    replaceString(test, targ, replaceText);

    cout << "After replacement: " << test << endl;

    delete[] test;
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
	replaceStringTest4();
	return 0;
}
