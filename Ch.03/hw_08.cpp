/**    
    Напишите программу, которая обрабатывает массив объектов
    student и определяет квартили оценок, то есть оценки, которые
    необходимо получить студенту, чтобы успевать также хорошо
    или лучше, чем 25% студентов, 50% студентов и 75% студентов.    
    
    квартиль: определение из википедии https://en.wikipedia.org/wiki/Quartile
    технология расчета: https://stackoverflow.com/questions/43792127/compute-the-quartiles-of-a-given-list-of-numbers
    пример: https://github.com/nextgis/nextgisqgis/blob/eeb0861312272aee99bba8ed91103c5c1cb3e7de/src/core/qgsstatisticalsummary.cpp (искать  mFirstQuartile )
*/

using namespace std;

#include <iostream>

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

// нахождение медианы
double getMedian(student array[], int size) {
    double result = 0;

    // если количество элементов четное
    if (size / 2 == 0)
        result = (array[(size - 1)/2].grade + array[size/2].grade)/2.0;
    // если нечетное
    else
        result = array[size/2].grade;

    return result;
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
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareGrade);  
    
    int med = 
    cout << getMedian(studentArray, ARRAY_SIZE);
   
    return 0;
}
