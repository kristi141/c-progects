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
либо числовым значением, либо переменной, либо арифметическим выражением;
присваивание переменной значения функции.
Например, корректными являются строки вида: «a6k=7;», «a = b;», «a[i]=b[j];», 
«a=z[2];», «a=f*2;», «a[5]=z+a;», «a = z[i+7];», «a = z[i+7]+11;», «a=f();», 
«a = gr(ret);», «a = gr(ret)/2;» (обратите внимание, операция присваивания 
оканчивается символом «;»)
Cтроки вида: «a=6», «a-=10;», «d=#$&_h», «a*=r;», «a = h(kjckd;»- являются 
некорректными.

Входные данные:
Во входном файле вам дан набор строк, разделенных между собой символами 
переноса строки.

Выходные данные:
Выведите все наибольшие корректные подстроки в порядке их следования в тексте, 
каждую в отдельной строке.

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
either a numeric value, a variable, or an arithmetic expression;
assigning a function value to a variable.
For example, correct lines are: “a6k=7;”, “a = b;”, “a[i]=b[j];”,
“a=z[2];”, “a=f*2;”, “a[5]=z+a;”, “a = z[i+7];”, “a = z[i+ 7]+11;”, “a=f();”,
"a = gr(ret);", "a = gr(ret)/2;" (note the assignment operator
ends with the symbol ";")
Lines like: “a=6”, “a-=10;”, “d=#$&_h”, “a*=r;”, “a = h(kjckd;”- are
incorrect.

Input data:
In the input file you are given a set of lines separated by characters
line break.

Output:
Print all the largest valid substrings in the order they appear in the text,
each on a separate line.*/

#include <iostream>
#include <regex>
using namespace std;

regex validSubstrings;

void getValidSubstrings(){
  string value = "([a-zA-Z][a-zA-Z0-9]*)";
        string number = "([1-9][0-9]*|0)";

        string elemArr = "\\s*" + value + "\\[\\s*(" + value + "|" + number + ")\\s*\\]\\s*";
        string expression = "\\s*(" + value + "|" + elemArr + "|" + number + ")\\s*" + "(\\s*[\\+\\-\\*\\/]\\s*" + "(" + value + "|" + elemArr + "|" + number + "))*\\s*";
        string elemFunc = "\\s*" + value + "\\(\\s*(" + value + "|" + number + ")\\s*\\)\\s*";
        
        elemFunc = "\\s*" + value + "\\s*\\(\\s*(" + expression + "|" + number + "|" + value + "|" + elemArr + ")\\s*\\)\\s*|\\s*" + value + "\\(\\s*\\s*\\)\\s*|\\s*" + value + "\\s*\\(\\s*(" + expression + "|" + number + "|" + value + ")(\\,(" + expression + "|" + number + "|" + value + "|" + elemArr + "))*\\s*\\)\\s*";
        elemArr = "\\s*" + value + "\\s*\\[\\s*(" + expression + "|" + number + "|" + value + "|"+ elemFunc + ")\\s*\\]\\s*";
        expression = "\\s*(" + value + "|" + elemArr + "|" + elemFunc + "|" + number + ")" + "(\\s*[\\+\\-\\*\\/]\\s*" + "(" + value + "|" + elemArr + "|" + number + "|" + elemFunc + "))*\\s*";

        string validSubstring = "(" + elemArr + "|" + elemFunc  + "|" + value +")\\s*=\\s*(" + value + "|" + elemArr + "|" + elemFunc + "|" + number +"|" + expression + ")\\s*;";
        
        validSubstrings = regex(validSubstring);
}

void printSubstring(string line){
   smatch match;

        while (regex_search(line, match, validSubstrings)) {
            cout << match.str() << endl;
            line = match.suffix().str();
        }
}

int main() {
    getValidSubstrings();
    string line;

    while (getline(cin, line)) {
         printSubstring(line);
    }

    return 0;
}