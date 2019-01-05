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
        cout << "Survey resonse:" << i + 1 << ":";
        cin >> survey_data[i];
    }
    
    // подсчитать гистограмму
    delete[] survey_data;
   
}
