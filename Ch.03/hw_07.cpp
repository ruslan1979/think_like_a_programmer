/**
    Напишите программу, которой дан массив целых чисел и которая определяет моду, то есть 
    наиболее часто встречающееся в массиве число.    
    
    ** Массив целых чисел заполняется в этой реализации случайными числами
*/

using namespace std;

#include <iostream>
#include <ctime>

// значения можно менять -)
#define SIZE_ARRAY 100
#define RANGE_NUMBERS 24

// генератор значений в массиве
int* generateNumbers(const int SIZE, const int RANGE){
    int* numbers = new int[SIZE];
    for (int i = 0; i != SIZE; ++i)
        numbers[i] = rand() % RANGE;
    
    return numbers;
}

int main() {    
    srand(time(nullptr));
    int * numbers = new int[SIZE_ARRAY];
            
    // генерируем массив и проверяем - совпадают ли значения с порядковым номером массива    
    numbers = generateNumbers(SIZE_ARRAY, RANGE_NUMBERS);    
    
    //создаем гистограмму
    int * hystogram  = new int[RANGE_NUMBERS];
    
    //заполнение гистограммы нулями
    for (int i = 0; i != RANGE_NUMBERS; ++i)
        hystogram[i] = 0;
        
    //подсчет
    for (int i = 0; i != SIZE_ARRAY; ++i){
        int val = numbers[i];
        hystogram[val]++;
    }
    
    //поиск часто встречающегося числа
    int max = hystogram[0];
    for (int i = 1; i != RANGE_NUMBERS; ++i){
        if (max < hystogram[i])
            max = hystogram[i];
    }
    
    cout << max;
        
    // очистка памяти
    delete[] numbers;
    numbers = nullptr;

    delete[] hystogram;
    hystogram = nullptr;
    
    return 0;
}
