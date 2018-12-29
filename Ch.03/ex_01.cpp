/* Задача: нахождение моды
В статистике мода набора значений представляет собой самое часто встречающееся
значение. Напишите код, который обрабатывает массив данных опроса, в ходе которого 
респонденты отвечали на вопрос с помощью цифры от 1 до 10, чтобы определить
моду набора данных. Для нашей цели можно выбрать любую моду, если их окажется
несколько.
*/
#include <iostream>

using namespace std;

int compareFunc(const void * A, const void * B) {
        int * intA = (int *)(A);
        int * intB = (int *)(B);
        return *intA - *intB;
}

int main() {
    const int ARRAY_SIZE = 12;
    int surveyData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    
    // для проверки решения:
    // 1) расскомментировать решения до рефакторинга и закомментить решение после рефакторинга
    // 2) наоборот
    
    //-------------------------------------------------------------------
    //решение до рефакторинга
    // обычно такое подается в вузах
    //qsort(surveyData, ARRAY_SIZE, sizeof(int), compareFunc);
    //int mostFrequent;
    //int highestFrequency = 0;
    //int currentFrequency = 0;
    //
    //for (int i = 0; i != ARRAY_SIZE; i++) {
    //    if (i == ARRAY_SIZE - 1 || surveyData[i] != surveyData[i + 1]) {
    //        if (currentFrequency > highestFrequency) {
    //            highestFrequency = currentFrequency;
    //            mostFrequent = surveyData[i];
    //        }
    //         
    //          currentFrequency = 0;
    //    }
    //    currentFrequency++;
    //}
    
    //------------------------------------------------------------------
    // решение отрефакторенное 
    // т.н. "промышленное" решение
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    for (int i = 0; i != MAX_RESPONSE; ++i)
        histogram[i] = 0;
    
    for (int i = 0; i != ARRAY_SIZE; ++i) 
        histogram[surveyData[i] - 1]++;

    int mostFrequent = 0;
    for (int i = 1; i != MAX_RESPONSE; ++i) {
        if (histogram[i] > histogram[mostFrequent])
            mostFrequent = i;
    }
    mostFrequent++;
    
    cout << "Most frequent " << mostFrequent;
    return 0;
}
