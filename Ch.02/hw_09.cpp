/** Задача :
Напишите программу, которая считывала бы строку текста, подсчитывая количество слов и вычисляя длину самого длинного
слова, наибольшее количество гласных букв в слове и/или любую другую статистику, какую вы можете себе представить
(длина самого короткого слова, наименьшее количество согласных)
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    
    char inputChar = cin.get();

    int countWords = 0, // количество слов
    lengthWord = 0, // длина слова
    maxLengthWord = 0, // длина самого длинного слова
    minLengthWord = 0, // длина самого короткого слова
    countVowels = 0, // количество гласных букв
    maxCountVowels = 0, // наибольшее количество гласных
    countConsonants = 0, // количество согласных в слове
    minCountConsonants = 0; // наименьшее количество согласных букв
    
    while (inputChar != 10) {
        if (inputChar == ' ') {
            // определеяем минимальную длину слова
            if (countWords == 0) {
                // если это первое слово, то минимальная длина - длина первого слова
                minLengthWord = lengthWord;
                // и минимальное количество согласных - их число в первом слове
                minCountConsonants = countConsonants;
            }
            else {
                // если слово не первое , то ищем что короче
                minLengthWord = (minLengthWord > lengthWord) ? lengthWord : minLengthWord;
                // и ищем минимальное количество согласных 
                minCountConsonants = (minCountConsonants > countConsonants) ? countConsonants : minCountConsonants;                
            }
                
            countWords++;
            maxCountVowels = (maxCountVowels < countVowels) ? countVowels : maxCountVowels;
            maxLengthWord = (maxLengthWord < lengthWord) ? lengthWord : maxLengthWord;
            
            // готовимся к новому слову
            countVowels = 0;
            lengthWord = 0;
            countConsonants = 0;
        }
        
        if ((inputChar == 'a') || (inputChar == 'e') || (inputChar == 'i') || (inputChar == 'o') || (inputChar == 'u'))
            countVowels++;
        
        if (!((inputChar == 'a') || (inputChar == 'e') || (inputChar == 'i') || (inputChar == 'o') || (inputChar == 'u')))
            countConsonants++;
        
        lengthWord++;
        inputChar = cin.get();
    }
    
    //ввод завершен - нужно посчитать еще одно слово
    countWords++;
    maxCountVowels = (maxCountVowels < countVowels) ? countVowels : maxCountVowels;
    maxLengthWord = (maxLengthWord < lengthWord) ? lengthWord : maxLengthWord;

    // если слово не первое , то ищем что короче
    minLengthWord = (minLengthWord > lengthWord) ? lengthWord : minLengthWord;
    // и ищем минимальное количество согласных 
    minCountConsonants = (minCountConsonants > countConsonants) ? countConsonants : minCountConsonants;                
    
    
    // выводим статистику
    cout << "1) Count of words is " << countWords << endl;
    cout << "2) Length of the longest word is " << maxLengthWord << endl;
    cout << "3) Max quantity of vowels in a word is " << maxCountVowels << endl;
    cout << "4) Length of the shortest word is " << minLengthWord << endl;
    cout << "5) Min quantity of consonants in a word is " << minCountConsonants << endl;
    return 0;
}
