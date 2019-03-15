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
        car(string manufacturer, string model, int year);
        void setManufacturer(string name);
        string manufacturer();
        void setModel(string name);
        string model();
        void setReleaseYear(int year);
        int releaseYear();

        int carAge();
        string description();
    private:
        string nameOfManufacturer;
        string nameOfModel;
        int year;
};

car::car(string manufacturer, string model, int year) {
    setManufacturer(manufacturer);
    setModel(model);
    setReleaseYear(year);
}

void car::setManufacturer(string name) {
    if (name == "")
        return;

    // for simplicity I don't clean the string
    // am just compare with empty string
    if (name.empty())
        return;

    nameOfManufacturer = name;
}

string car::manufacturer(){
    return nameOfManufacturer;
}

void car::setModel(string name) {
    if (name == "")
        return;

    // for simplicity I don't clean the string
    // am just compare with empty string
    if (name.empty())
        return;

    nameOfModel = name;
}

string car::model() {
    return nameOfModel;
}

void car::setReleaseYear(int year){
    if ((year <= 1900) || (year > 2019))
        return;

    this->year = year;
}

int car::releaseYear() {
    return year;
}

string car::description(){
    return to_string(releaseYear()) +
        " " + manufacturer() +
        " " + model();
}

int car::carAge(){
    return 2019 - releaseYear();
};

int main() {
    car cr("Chevrolet", "Impala", 1957);
    cout << cr.description() << endl;
    cout << cr.carAge() << endl;

    car cr1("Ford", "Focus", 2017);
    cout << cr1.description() << endl;
    cout << cr1.carAge() << endl;

    return 0;
}
