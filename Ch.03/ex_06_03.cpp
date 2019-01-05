/* Стр 98
    Нахождение самого высокого уровня ежемесячных продаж у любого агента
    Рефакторинг примера
*/
#include <iostream>

#define NUM_AGENTS 3
#define NUM_MONTHS 12

using namespace std;

struct agentStruct{
    int monthlySales[NUM_MONTHS];
};

// нахождение среднего значения
double arrayAverage(int intArray[], const int ARRAY_SIZE) {
    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += intArray[i];        
    }
    double average = sum / ARRAY_SIZE;
    return average;
}

int main() {
    agentStruct agents[NUM_AGENTS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}        
    };
    
    double highestAverage = arrayAverage(agents[0].monthlySales, NUM_MONTHS);
    for (int agent = 1; agent < NUM_AGENTS; ++agent) {
        double agentAverage = arrayAverage(agents[agent].monthlySales, NUM_MONTHS);
        if (agentAverage > highestAverage)
            highestAverage = agentAverage;
    }
    
    cout << "Highest monthly average sales: " << highestAverage << endl;

}
