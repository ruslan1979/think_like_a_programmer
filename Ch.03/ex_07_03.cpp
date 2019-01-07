/* Стр 102
        рефакторинг предыдущего примера.
        vector вообще-то бесполезен. Ест память.
*/
#include <vector>
#include <iostream>

using namespace std;

int main() {   
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    
    for (int i = 0; i != MAX_RESPONSE; ++i)
        histogram[i] = 0;
    
    int surveyResponse;
    cout << "Enter next survey response or -1 to complete:" ;

    cin >> surveyResponse;
    while (surveyResponse != -1) {
        histogram[surveyResponse - 1]++;
        cout << "Enter next survey response or -1 to complete:" ;
        cin >> surveyResponse;
    }
    
    int mostFrequent = 0;
    for (int i = 0; i < MAX_RESPONSE; ++i) {
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;        
    }
    
    mostFrequent++;

    cout << "Most frequent value is " << mostFrequent;
    
    return 0;
}
