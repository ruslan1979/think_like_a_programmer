/*
    Добавьте в наш автомобильный класс из предыдущего упражне-
    ния служебный метод, возвращающий полное описание авто-
    мобиля в формате строки, например, «1957 Chevrolet Impala».
    Добавьте второй служебный метод, возвращающий возраст ав-
    томобиля в годах.
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


