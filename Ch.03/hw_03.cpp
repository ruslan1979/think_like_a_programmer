/**
    Напишите функцию bool, которой передается массив и количество
    элементов в этом массиве и которая определяет, будут ли
    данные в этом массиве сортироваться. Для этого требуется только 
    одна передача!
*/

#include <iostream>

#define NUM_AGENTS 3
#define NUM_MONTHS 12

using namespace std;

struct agentStruct{
    int monthlySales[NUM_MONTHS];
};

int compareSales(const void * A, const void * B) {
        int * stdA = *(int **)(A);
        int * stdB = *(int **)(B);
        return stdA - stdB;
}

// нахождение медианы
double arrayMedian(int intArray[], const int ARRAY_SIZE) {
    double result = 0;

    // если количество элементов четное
    if (ARRAY_SIZE / 2 == 0)
        result = (intArray[(ARRAY_SIZE - 1)/2] + intArray[ARRAY_SIZE/2])/2.0;
    // если нечетное
    else
        result = intArray[ARRAY_SIZE/2];

    return result;
}

int main() {
    agentStruct agents[NUM_AGENTS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    qsort(agents[0].monthlySales, NUM_MONTHS, sizeof(int), compareSales);
    double highestMedian = arrayMedian(agents[0].monthlySales, NUM_MONTHS);

    for (int agent = 1; agent < NUM_AGENTS; ++agent) {
        qsort(agents[agent].monthlySales, NUM_MONTHS, sizeof(int), compareSales);
        double agentMedian = arrayMedian(agents[agent].monthlySales, NUM_MONTHS);
        if (agentMedian > highestMedian)
            highestMedian = agentMedian;
    }

    cout << "Highest monthly median sales: " << highestMedian << endl;

}
