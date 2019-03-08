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
        string letterGrade();
        
    private:
        int _grade;
        int _studentID;
        string _name;
        bool isValidGrade(int grade);
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

bool studentRecord::isValidGrade()int grade{
	if ((grade >= 0) && (grade <= 100))
		return true;
	
	return false;
}

int studentRecord::grade() {
    return _grade;
}

void studentRecord::setGrade(int newGrade) {
    //if ((newGrade >= 0) && (newGrade <= 100))
    if (isValidGrade(newGrade))
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
