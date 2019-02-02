/* ЗАДАЧА 5:
     Реализуйте функцию removeRecord, которая принимает в каче-
     стве параметров указатель на коллекцию studentCollection и
     номер студента, а затем удаляет учетную карточку с этим студен-
     ческим номером из коллекции.
*/

#include <iostream>

using namespace std;

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};

typedef listNode * studentCollection;

void addRecord(studentCollection &sc, int stuNum, int gr) {
    listNode * node = new listNode;
    node->studentNum = stuNum;
    node->grade = gr;
    node->next = sc;

    sc = node;
}

void removeRecord(studentCollection &sc, int stuNum) {
    if (sc == NULL)
        return;

    // если удаляем головной элемент
    if (sc->studentNum == stuNum) {
    	sc = sc->next;    	
    	return;
	}

    listNode * loopPtr = sc;
    listNode * prevPos = sc;
    
    while (loopPtr != NULL && loopPtr->studentNum != stuNum) {
            prevPos = loopPtr;
            loopPtr = loopPtr->next;
    }

    prevPos->next = loopPtr->next;
    
    //копируем элементы в исходный список
    while (prevPos != NULL) {
    	sc = prevPos;
    	prevPos = prevPos->next;
	}

    delete loopPtr;
    delete prevPos;
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
    node2->studentNum = 1012; node2->grade = 144;

    listNode * node3 = new listNode;
    node3->studentNum = 1076; node3->grade = 85;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    node1 = node2 = node3 = NULL;

    //добавляем студента
    addRecord(sc, 1000, 91);

    int avg = averageRecord(sc);
    cout << "Average before removal: " << avg << endl;

    listNode * pm = sc;

    // удалим студента
    removeRecord(sc, 1000);

    avg = averageRecord(sc);
    cout << "Average after removal: " << avg << endl;

	return 0;
}
