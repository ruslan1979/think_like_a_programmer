/* Стр 92
   Вычисление стоимости бизнес-лицензии, зависит от значения валового объема продаж.
   В переменной типа double с именем grossSales хранится значение валового объема продаж 
   компании и, исходя изэтого показателя объема продаж, мы хотим присвоить подходящие
   значения переменным int category и double cost.    
*/
#include <iostream>

using namespace std;


int main() {
    double grossSales;
    
    cout << "Enter gross sales value: " ;
    cin >> grossSales;
    
    const int NUM_CATEGORIES = 4;
    const double categoryThresholds[NUM_CATEGORIES] = {0.0, 50000.0, 150000.0, 500000.0};
    const double licenseCost[NUM_CATEGORIES] = {50.0, 200.0, 1000.0, 5000.0};
    
    int category = 0;
    
    while (category <  NUM_CATEGORIES && 
        categoryThresholds[category] <= grossSales) {
            category++;
        }
        
    double cost = licenseCost[category - 1];
    
    cout << "License cost is " << cost;

    return 0;
}
