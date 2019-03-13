/*
Давайте попробуем реализовать класс, используя базовый
фреймворк. Рассмотрим класс, хранящий данные по автомоби-
лям. У нас есть три элемента данных: название производителя,
название модели (оба строковые) и год выпуска – целочислен-
ное. Создайте класс с методами get/set для каждого поля клас-
са. Убедитесь, что вы приняли верные решения о деталях, на-
пример имени переменных. Необязательно пользоваться моей
конвенцией наименования, важнее грамотно подходить к при-
нятию решений и быть в них последовательными.
*/

#include <iostream>
#include <string>

using namespace std;

class car {
    public:
        void setManufacturer(string name);        
        string manufacturer();
        void setModel(string name);        
        string model();
        void setReleaseYear(int year);
        int releaseYear();        
    private:
        string manufacturer;
        string model;
        int releaseYear;
}

void car::setManufacturer(string name) {
    if (name == NULL) 
        return;

    // for simplicity I don't clean the string
    // am just compare with empty string
    if (name.empty())
        return;
    
    manufacturer = name;
}

string car::manufacturer(){
    return manufacturer;
}

void car::setModel(string name) {
    if (name == NULL) 
        return;

    // for simplicity I don't clean the string
    // am just compare with empty string
    if (name.empty())
        return;
    
    model = name;
}

string car::model() {
    return model;
}

void car::setReleaseYear(int year){
    if ((year <= 1900) || (year > 2019))
        return 0;
    
    releaseYear = year;
}

int car::releaseYear() {
    return year;    
}


