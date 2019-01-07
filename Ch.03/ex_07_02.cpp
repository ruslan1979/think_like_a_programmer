/* Стр 100
        Пример использования вектора
*/
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> surveyData;
    surveyData.reserve(30);
    int surveyResponse;
    cout << "Enter next survey response or -1 to complete:" ;

    cin >> surveyResponse;
    while (surveyResponse != -1) {
        surveyData.push_back(surveyResponse);
        cout << "Enter next survey response or -1 to complete:" ;
        cin >> surveyResponse;
    }
    
    int vectorSize = surveyData.size();
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    
    for (int i = 0; i != MAX_RESPONSE; ++i)
        histogram[i] = 0;
    
    for (int i = 0; i != vectorSize; ++i)
        histogram[surveyData[i] - 1]++;
    
    int mostFrequent = 0;
    for (int i = 0; i < MAX_RESPONSE; ++i) {
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;        
    }
    
    mostFrequent++;

    cout << "Most frequent value is " << mostFrequent;
    
    return 0;
}
