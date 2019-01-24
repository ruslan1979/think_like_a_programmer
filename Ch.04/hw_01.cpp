/* Придумайте свое собственное упражнение: возьмите задачу, ко-
   торую вы умеете решать с применением массивов, но которая
   ограничена размером массива. Перепишите код, сняв ограниче-
   ние с помощью динамических массивов.

   ОСНОВА ЗАДАЧИ:
   Вы разочарованы тем, что мы мало занимались сортировкой?
   Я знаю, как это исправить. Чтобы убедиться в том, что вы освоились
   с функцией qsort, напишите код, в котором эта функция
   используется для сортировки массива студенческой структуры
   struct.
   Сначала попробуйте сортировать по оценкам,
   а затем попытайтесь сделать это, используя идентификатор студента.

*/
#include <iostream>

# define ARRAY_SIZE 10

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

    //недостаток - захардкожены значения элементов массива
    student * studentArray = new student[ARRAY_SIZE]
    {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };


    // сортировка по оценкам
    cout << "==Sort by grades " << endl;
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrade);

	for (int i = 0; i != ARRAY_SIZE; ++i ){
    	cout << "Name: " << studentArray[i].name << endl;
    	cout << "Grade: " << studentArray[i].grade << endl;
	}

    // сортировка по studentId
    cout << "===Sort by student IDs " << endl;
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareId);

	for (int i = 0; i != ARRAY_SIZE; ++i){
    	cout << "Name: " << studentArray[i].name << endl;
    	cout << "Student id: " << studentArray[i].studentID << endl;
    	cout << "Grade: " << studentArray[i].grade << endl;
	}

    delete[] studentArray;
    
    return 0;
}
