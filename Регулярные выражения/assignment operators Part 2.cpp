/*RU
Условие:
Вам дан набор строк, разделенных между собой символами переноса строки.
Вам необходимо найти все подстроки, являющиеся корректными операциями простого 
присваивания.
Общая формула для корректной операции присваивания: «x = y;», где x – первый 
операнд, y - второй операнд. Учтите, что между операндами может стоять 
несколько символов пробела.
В данной задаче «корректными операциями присваивания» являются:
присваивание переменной значения численной константы;
присваивание переменной значения другой переменной;
присваивание переменной значения арифметического выражения;
присваивание переменной значения элемента массива, индекс которого является 
либо числовым значением, либо переменной.
Например, корректными являются строки вида: «a3r=7;», «a = b ;», «a[i]=b[j];», 
«a=z[2];», «a=f*2;», «a[5]=z+a;», «a = z[i] + 11;» (обратите внимание, 
операция присваивания оканчивается символом «;»)
Cтроки вида: «a=6», «a-=10;», «a+=n;», «d=#$&_h», «a*=r;»- являются некорректными.

Входные данные:
Во входном файле вам дан набор строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все наибольшие корректные подстроки в порядке их следования в тексте, 
каждую в отдельной строке.

Входные данные:
hello>a=18;a=rrr
846y=t+2;h4r890a*=10;xd[b]=7;
s=a;g=yur;d=q::*
f = b[2];

Выходные данные:
a=18;
y=t+2;
xd[b]=7;
s=a;
g=yur;
f = b[2];

ENG
Condition:
You are given a set of lines separated by line breaks.
You need to find all substrings that are valid prime operations
assignments.
The general formula for a correct assignment operation is: “x = y;”, where x 
is the first operand, y is the second operand. Please note that between the 
operands there may be several space characters.
In this problem, the “correct assignment operations” are:
assigning a variable the value of a numerical constant;
assigning a variable a value to another variable;
assigning a variable the value of an arithmetic expression;
assigning a variable the value of an array element whose index is
either a numeric value or a variable.
For example, correct lines are: “a3r=7;”, “a = b ;”, “a[i]=b[j];”,
“a=z[2];”, “a=f*2;”, “a[5]=z+a;”, “a = z[i] + 11;” (note,
The assignment operation ends with the symbol ";")
Lines like: “a=6”, “a-=10;”, “a+=n;”, “d=#$&_h”, “a*=r;” - are incorrect.

Input data:
In the input file you are given a set of lines separated by characters
line break.

Output:
Print all the largest valid substrings in the order they appear in the text,
each on a separate line.

Input data:
hello>a=18;a=rrr
846y=t+2;h4r890a*=10;xd[b]=7;
s=a;g=yur;d=q::*
f = b[2];

Output:
a=18;
y=t+2;
xd[b]=7;
s=a;
g=yur;
f = b[2];                                            */

#include <iostream>
#include <regex>
using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        string value = "([a-zA-Z]+)([a-zA-Z0-9_]+)*";
        string elemArr = "(\\s*\\[[a-zA-Z0-9_]+\\])*";
        string expression = "([a-zA-Z0-9_+\\s*\\+\\-\\*\\/\\s*\\[\\]]+)*";

        regex validSubstrings(value + elemArr + "\\s*=\\s*([a-zA-Z0-9_]+)" + 
            elemArr + expression + "\\s*;");
        smatch match;

        while (regex_search(line, match, validSubstrings)) {
            cout << match.str() << endl;
            line = match.suffix().str();
        }
    }

    return 0;
}