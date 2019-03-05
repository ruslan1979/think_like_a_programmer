/* Задача список класса:
    Спроектируем класс или набор классов для использования в программе, которая
    поддерживает список класса. Для каждого студента будем хранить его фамилию,
    идентификатор и результат выпускного экзамена в числовом диапазоне от 0 до 100.
    Программа должна позволять добавлять и удалять записи, отображать записи по 
    конкретному студенту, идентифицируемому по ID с оценкой, представленной в числовом
    или буквенном формате, и отображать среднюю оценку класса. Соответствующая
    буквенная оценка для каждого результата представлена ниже
    ! Диапазон результатов ! Буквенная оценка !
    !    93-100            !       A          !
    !    90-92             !       A-         !
    !    87-89             !       B+         !
    !    83-86             !       B          !
    !    80-82             !       B-         !
    !    77-79             !       C+         !
    !    73-76             !       C          !
    !    70-72             !       C-         !
    !    67-69             !       D+         !
    !    60-66             !       D          !
    !     0-59             !       F          !
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
    private:
        int _grade;
        int _studentID;
        string _name;
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