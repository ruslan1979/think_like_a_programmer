/* Стр 99
        Пример использования динамического массива
*/
#include <iostream>

using namespace std;

int main() {
    int array_size;
    
    cout << "Number of survey responses:";
    cin >> array_size;
    
    int *survey_data = new int[array_size];
    for (int i = 0; i != array_size; ++i) {
        cout << "Survey resonse " << i + 1 << ":";
        cin >> survey_data[i];
    }
    
    // подсчитать гистограмму
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    
    for (int i = 0; i != MAX_RESPONSE; ++i)
        histogram[i] = 0;
    
    for (int i = 0; i != array_size; ++i)
        histogram[survey_data[i] - 1]++;
    
    int mostFrequent = 0;
    for (int i = 0; i < MAX_RESPONSE; ++i) {
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;        
    }
    
    mostFrequent++;

    cout << "Most frequent value is " << mostFrequent;
    
    // очистка данных
    delete[] survey_data;
   
    return 0;
}
