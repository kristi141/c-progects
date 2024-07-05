/*RU
Условие:
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
причем только одна.

Входные данные:
Merlin speaksAvada-ke-davra$##*#$!
Avada-ke-davra
Merlin speaks77Avada-ke-davra295459588257665357:949;66466

Выходные данные:
1 14
3 16

ENG
Condition:
Merlin is in a bad mood today. He just shouts "Avada-ke-davra" yeah
grumbles something incomprehensible. His novices would not want to get caught 
in hot water the owner's hand. Since Merlin's speech is uniform (words are 
pronounced with constant speed), then it is enough to know the index of the 
beginning of the substring with spell in Merlin's speech to avoid death. 
Write a program which will help Merlin's novices.

Input data:
You are given a number of lines separated by symbols
line break.

Output:
For each line starting with the substring "Merlin speaks", print through
space the number of this line and the number of the beginning of the 
substring "Avada-ke-davra".
It is guaranteed that every line with "Merlin speaks" contains "Avada-ke-davra",
and only one.

Input data:
Merlin speaksAvada-ke-davra$##*#$!
Avada-ke-davra
Merlin speaks77Avada-ke-davra295459588257665357:949;66466

Output:
1 14
3 16                                              */

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