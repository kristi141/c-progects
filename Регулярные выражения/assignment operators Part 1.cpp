/*RU
Условие:
Вам дан набор строк, разделенных между собой символами переноса строки.
Вам необходимо найти все подстроки, являющиеся корректными операциями 
простого присваивания.
Общая формула для корректной операции присваивания: «x = y;», где x – первый 
операнд, y - второй операнд. Учтите, что между операндами может стоять 
несколько символов пробела.
В данной задаче «корректными операциями присваивания» являются:
присваивание переменной значения численной константы;
присваивание переменной значения другой переменной.
Например, корректными являются строки вида: «a9f = 7;», «a=b;» 
(обратите внимание, операция присваивания оканчивается символом «;»).
Cтроки вида: «a=6», «a-=10;», «d=#$&_h» - являются некорректными.

Входные данные:
Во входном файле вам дан набор строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все наибольшие корректные подстроки в порядке их следования в тексте, 
каждую в отдельной строке.

Входные данные:
hello>a=18;a=rrr
846h4r890a*=10;xd
s=a;g=yur;d=q::*

Выходные данные:
a=18;
s=a;
g=yur;

ENG
Condition:
You are given a set of lines separated by line breaks.
You need to find all substrings that are valid operations
simple assignment.
The general formula for a correct assignment operation is: “x = y;”, where x 
is the first operand, y is the second operand. Please note that between the 
operands there may be several space characters.
In this problem, the “correct assignment operations” are:
assigning a variable the value of a numerical constant;
assigning a variable a value to another variable.
For example, correct lines are: “a9f = 7;”, “a=b;”
(note that the assignment operation ends with a “;”).
Lines like: “a=6”, “a-=10;”, “d=#$&_h” are incorrect.

Input data:
In the input file you are given a set of lines separated by characters
line break.

Output:
Print all the largest valid substrings in the order they appear in the text,
each on a separate line.

Input data:
hello>a=18;a=rrr
846h4r890a*=10;xd
s=a;g=yur;d=q::*

Output:
a=18;
s=a;
g=yur;                                                   */

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string line;
    
    while (getline(cin, line)) {
        regex validSubstrings("[a-zA-Z0-9_]+\\s*=\\s*[a-zA-Z0-9_]+;");
        smatch match;
        
        while (regex_search(line, match, validSubstrings)) {
            cout << match.str() << endl;
            line = match.suffix().str();
        }
    }
    
    return 0;
}