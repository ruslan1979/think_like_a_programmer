/** 
    Перепишите код для нахождения агента с наивысшим среднемесячным объемом продаж так, 
    чтобы он находил агента с самым высоким медианным объемом продаж. Как указывалось
    ранее, медиана набора значений представляет собой такое значение, находящееся в 
    середине, что половина значений набора больше него, а другая половина меньше. При 
    наличии четного количества значений медиана является простым средним двух
    значений в середине. Например, в наборе 10, 6, 2, 14, 7, 9 значения, находящиеся 
    в середине, — это 7 и 9. Среднее значение 7 и 9 равно 8, поэтому 8 — это медиана.
*/

#include <iostream>

using namespace std;

struct student {
    int grade;
    int studentID;
    string name;
};

int compareGrade(const void * A, const void * B) {
        student * stdA = (student *)(A);
        student * stdB = (student *)(B);
        return stdA->grade - stdB->grade;
}

int compareId(const void * A, const void * B) {
        student * stdA = (student *)(A);
        student * stdB = (student *)(B);
        return stdA->studentID - stdB->studentID;
}

int main() {
    const int ARRAY_SIZE = 10;

    student studentArray[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"},
    };

    
    // сортировка по оценкам
    cout << "==Sort by grades " << endl;
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrade);  
    
	for (auto stud: studentArray){
    	cout << "Name: " << stud.name << endl;
    	cout << "Grade: " << stud.grade << endl;
	}
    
    // сортировка по studentId
    cout << "===Sort by student IDs " << endl;
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareId);
    
	for (auto stud: studentArray){
    	cout << "Name: " << stud.name << endl;
    	cout << "Student id: " << stud.studentID << endl;
    	cout << "Grade: " << stud.grade << endl;
	}
}
