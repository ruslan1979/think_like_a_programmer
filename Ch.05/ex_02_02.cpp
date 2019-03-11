/* Задача: отслеживание неизвестного количества записей студентов
        В этой задаче вы создадите класс с методами для хранения и манипулирования 
        коллекцией записей студентов. Запись студента содержит номер студента, оценку, 
        оба параметра целочисленные, и фамилию студента (строковая переменная). 
        Необходимо реализовать следующие функции:
            addRecord Этот метод принимает номер, фамилию и оценку студента и добавляет 
        новую запись с этими данными в коллекцию.
            recordWithNumber Эта функция принимает номер студента и возвращает из
        коллекции запись для студента с этим номером.
            removeRecord Эта функция принимает номер студента и удаляет из коллекции
        запись студента с этим номером.
        Коллекция может быть любого размера. Ожидается, что операция addRecord будет
        выполняться часто, потому она должна быть реализована эффективно.
*/
#include <iostream>

using namespace std;

class studentRecord {
    public:
        studentRecord();
        studentRecord(int newGrade, int newId, string newName);
        int grade();
        void setGrade(int newGrade);
        int studentID();
        void setStudentID(int newID);
        string name();
        void setName(string newName);
        string letterGrade();
        
    private:
        int _grade;
        int _studentID;
        string _name;        
}

class studentCollection {
    private:
        struct studentNode {
            studentRecord studentData;
            studentNode *next;
        }
    public:
        studentCollection();
        studentCollection(const studentCollection &original);
        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);
        ~studentCollection();
        studentCollection& operator=(const studentCollection & rhs);        
    private:
        typedef studentNode *studentList;
        studentList _listHead;
        void deleteList(studentList &listPtr);
        studentList copiedList(const studentList original);
}

studentRecord::studentRecord() {
    setGrade(0);
    setStudentID(-1);
    setName("");
}

studentRecord::studentRecord(int newGrade, int newId, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    if ((newGrade >= 0) && (newGrade <= 100))
        _grade = newGrade;
}

int studentRecord::studentID() {
    return _studentID;
}

void studentRecord::setStudentID(int newID){
    _studentID = newID;
}

string studentRecord::name() {
    return _name;
}

void studentRecord::setName(string newName) {
    _name = newName;
}

string studentRecord::letterGrade(){
	if (!isValidGrade(_grade))
		return "!ERROR";
		
	const int NUMBER_CATEGORIES = 11;
	const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
	const int LOWEST_GRADE_SCORE[] = {0, 60, 67,  70, 73, 77, 80, 83, 87, 90, 93};
	int category = 0;
	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;
	return GRADE_LETTER[CATEGORY - 1];
}

studentCollection::studentCollection(){
    _listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent){
    studentNode * newNode = new StudentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum){
    studentNode * loopPtr = _listHead;
    while (loopPtr->studentData.studentId() != idNum)
        loopPtr = loopPtr->next;
    
    return loopPtr->studentData;
}

studentRecord studentCollection::recordWithNumber(int idNum){
    studentNode * loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.studentId() != idNum)
        loopPtr = loopPtr->next;
    
    if (loopPtr == NULL){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    }
    else {
        return loopPtr->studentData;
    }        
}

void studentCollection::removeRecord(int idNum){
    studentNode * loopPtr = _listHead;
    studentNode * trailing = NULL;
    while (loopPtr != NULL && loopPtr->studentData.studentId() != idNum){
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    
    if (loopPtr == NULL)
        return;
    if (trailing == NULL) {
        _listHead = _listHead->next;
    }
    else {
        trailing->next = loopPtr->next;
    }
    
    delete loopPtr;
}

void studentCollection::deleteList(studentList &listPtr){
    while (listPtr != NULL) {
        studentNode * temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
}

studentList studentCollection::copiedList(const studentList original){
    if (oroginal == NULL)
        return NULL;
    
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;
    while (oldLooptPtr != NULL) {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    
    newLoopPtr->next = NULL;
    return newList;
};

studentCollection& studentCollection::operator=(const studentCollection & rhs){
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);        
    }
    
    return *this;
    
};

studentCollection::studentCollection(const studentCollection &original){
    _listHead = copiedList(original._listHead);
};

/* tests section */
void StudentCollectionTest1() {
    studentCollection s;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.removeRecord(4875);
}

void StudentCollectionTest2() {
    studentCollection s1;
    studentCollection s2;
    studentRecord r1(85, 99837, "John");
    s2.addRecord(r1);
    studentRecord r2(77, 4765, "Elsie");
    s2.addRecord(r2);
    s1 = s2;
    s2.removeRecord(4875);    
}

void StudentCollectionTest3() {
    studentCollection s;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    s.addRecord(stu3);
    s.addRecord(stu2);
    s.addRecord(stu1);
    s.removeRecord(4875);

    studentCollection s2(s);
}