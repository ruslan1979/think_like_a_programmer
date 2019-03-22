/*
    Возьмите функции для строк переменной длины из главы 4 (append,
    concatenate и characterAt) и используйте их для создания
    класса для строк переменной длины. Убедитесь, что вы реализо-
    вали все необходимые конструкторы, деструктор, а также пере-
    грузили оператор присваивания.
*/

#include <iostream>
#include <string>

using namespace std;

class variableString {
    private:
        typedef char * arrayString;
    public:
        variableString(char * inputString);  
        variableString();
        ~variableString();
        
        char characterAt(arrayString s, int position);
        void append(arrayString& s, char c);
        void concatenate(arrayString &s1, arrayString &s2);
        variableString& operator=(variableString & vs);
    private:
        arrayString str; 
        delete
};

variableString::variableString(char * inputString){
    str = inputString;
}

variableString::variableString(){
    str = new arrayString();
}

char variableString::characterAt(arrayString s, int position) {
    return s[position];
}

void variableString::append(arrayString& s, char c){
  	int oldLength = length(s);
	
	arrayString newS = new char[oldLength + 2];
	for (int i = 0; i != oldLength; ++i) {
		newS[i] = s[i];
	}
	
	newS[oldLength] = c;
	newS[oldLength + 1] = 0;
	delete[] s;
	s = newS;
};

void variableString::concatenate(arrayString &s1, arrayString &s2){
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

variableString::~variableString(){
    delete[] str;
};

void variableString::clearString(arrayString &inputString){
    while (inputString != NULL) {
        arrayString temp = inputString;
        inputString = listPtr->next;
        delete temp;
    }
}

variableString& operator=(variableString & vs) {
    if (this != &vs) {
            
    }
};
int main() {

    return 0;
}
