/* ЗАДАЧА: Отслеживание неизвестного количества студенческих карточек
        В этой задаче вы должны будете реализовать функции для создания и управления сту-
    денческими карточками. Такая карточка содержит числовые данные: номер студента и
    балл. Нужно реализовать две функции:
        addRecord - Функция получает указатель на коллекцию студенческих карточек,
    номер студента и балл и добавляет новую запись с этими данными в коллекцию.
        averageRecord - Функция получает указатель на коллекцию студенческих карто-
    чек и возвращает среднее значение баллов студентов этой коллекции в формате
    double.
    Коллекция может быть любого размера. Предполагается, что функция addRecord бу-
    дет использоваться часто, следовательно, она должна быть реализована наиболее
    эффективным способом.
*/
#include <iostream>

using namespace std;

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
}

typedef listNode * studentCollection;

void addRecord(studentCollection &sc, int stuNum, int gr) {
    listNode * node = new listNode;
    node->studentNum = stuNum; 
    node->grade = gr;
    node->next = sc;
    
    sc = newNode;    
}

double averageRecord(studentCollection sc) {
    if (sc == NULL)
        return 0;
    
    int count = 0;
    double sum = 0;
    listNode * loopPtr = sc;
    while (loopPtr != NULL) {
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    
    double average = sum / count;
    return average;
}

int main() {
    studentCollection sc;
    listNode * node1 = new listNode;    
    node1->studentNum = 1001; node1->grade = 78;
    
    listNode * node2 = new listNode;
    node2->studentNum = 1012; node1->grade = 93;
    
    listNode * node3 = new listNode;
    node2->studentNum = 1076; node1->grade = 85;
    
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    node1 = node2 = node3 = NULL;    
    
    //добавляем студента
    addRecord(sc, 1274, 91);
    
    int avg = averageRecord(sc);
	return 0;
}
