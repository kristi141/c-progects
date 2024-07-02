/*Условие:
Сегодня Мерлин в плохом настроении. Он только кричит "Avada-ke-davra" да 
ворчит что-то непонятное. Его послушникам не хотелось бы попасть под горячую 
руку хозяина. Так как речь Мерлина равномерна (слова произносятся с 
постоянной скоростью), то достаточно знать индекс начала подстроки с 
заклинанием в речи Мерлина, чтобы избежать смерти. Напишите программу, 
которая поможет послушникам Мерлина.

Входные данные:
Вам дано некоторое количество строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Для каждой строки, начинающейся с подстроки "Merlin speaks", выведите через 
пробел номер данной строки и номер начала подстроки "Avada-ke-davra". 
Гарантируется, что в каждой строке с "Merlin speaks" есть "Avada-ke-davra", 
причем только одна.*/

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string line;
    regex pattern("Merlin speaks");
    regex speak("Avada-ke-davra");
    int lineNumber = 1;

    while (getline(cin, line)) {
        if (regex_search(line, pattern)) {
            smatch match;
            regex_search(line, match, speak);
            
            if (match.size() > 0) {
                cout << lineNumber << " " << match.position() + 1 << endl;
            }
        }
        lineNumber++;
    }

    return 0;
}