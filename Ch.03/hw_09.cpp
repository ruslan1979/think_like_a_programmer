/**
    Рассмотрите следующую модификацию массива sales: поскольку
    продавцы приходят и уходят в течение года, теперь мы отмеча-
    ем месяц, предшествующий найму торгового агента или следую-
    щий за последним месяцем его работы, значением –1. Перепи-
    шите код для нахождения самого высокого значения среднего
    объема продаж или наибольшего значения медианного объема
    продаж, чтобы это компенсировать.
*/

#include <iostream>

using namespace std;

#define NUM_AGENTS 3
#define NUM_MONTHS 12

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

// нахождение медианы
double getMedian(int array[], const int SIZE) {
    double median = 0;

    // если количество элементов четное
    if (SIZE / 2 == 0)
        median = (array[(SIZE - 1)/2] + array[SIZE/2])/2.0;
    // если нечетное
    else
        median = array[SIZE/2];

    return median;
}

int main() {
    agentStruct agents[NUM_AGENTS] = {
        {-1, -1, -1, 87478, 328, 2653, 387, 3754, -1, -1, -1, -1},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    double highestAverage = arrayAverage(agents[0].monthlySales, NUM_MONTHS);
    for (int agent = 1; agent < NUM_AGENTS; ++agent) {
        double agentAverage = arrayAverage(agents[agent].monthlySales, NUM_MONTHS);
        if (agentAverage > highestAverage)
            highestAverage = agentAverage;
    }

    double highestMedian = getMedian(agents[0].monthlySales, NUM_MONTHS);
    for (int agent = 1; agent < NUM_AGENTS; ++agent) {
        double averageMedian = getMedian(agents[agent].monthlySales, NUM_MONTHS);
        if (averageMedian > highestMedian)
            highestMedian = averageMedian;
    }


    cout << "Highest monthly average sales: " << highestAverage << endl;
    cout << "Highest monthly median sales: " << highestMedian << endl;

}
