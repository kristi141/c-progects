/*RU
Условие:
Юный программист написал свою первую тестирующую систему. Он так обрадовался 
тому, что она скомпилировалась, что решил пригласить школьных друзей на свой 
собственный контест. 
Но в конце тура выяснилось, что система не умеет сортировать команды в 
таблице результатов. Помогите начинающему программисту реализовать эту 
сортировку. 
Команды упорядочиваются по правилам: 
по количеству решённых задач в порядке убывания; 
при равенстве количества решённых задач — по штрафному времени в порядке 
возрастания; 
при прочих равных — по номеру команды в порядке возрастания. 
В реализации необходимо использовать структуры данных. 

Входные данные:
Первая строка содержит натуральное число n (1≤n≤105) — количество команд, 
участвующих в контесте. 
В i-й из следующих n строк записано количество решенных задач S (0≤S≤102) и 
штрафное время T (0≤T≤105) 
команды с номером i. 

Выходные данные:
В выходной файл должны быть выведены n чисел — номера команд в отсортированном 
порядке

ENG
Condition:
The young programmer wrote his first testing system. He was so happy
that she was complied with, that she decided to invite her school friends to 
her own contest.
But at the end of the tour it turned out that the system does not know how to 
sort teams into results table. Help a novice programmer implement this
sorting.
The teams are ordered according to the following rules:
by the number of solved problems in descending order;
if the number of solved problems is equal, the penalty time is ok
increasing;
all other things being equal - by team number in ascending order.
The implementation must use data structures.

Input data:
The first line contains the natural number n (1≤n≤105) — the number of 
commands, participating in the contest.
The i-th of the next n lines contains the number of solved problems S (0≤S≤102) and
penalty time T (0≤T≤105)
commands numbered i.

Output:
The output file should contain n numbers - the numbers of commands in the 
sorted ok*/

#include <iostream>
#include <vector>
using namespace std;

struct Team {
    int teamNumber;
    int solvedProblems;
    int penaltyTime;
};

void merge(vector<Team>& teams, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Team> leftArray(n1);
    vector<Team> rightArray(n2);

    for (int i = 0; i < n1; i++){
        leftArray[i] = teams[left + i];      
    }

    for (int j = 0; j < n2; j++){
        rightArray[j] = teams[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i].solvedProblems > rightArray[j].solvedProblems ||
            (leftArray[i].solvedProblems == rightArray[j].solvedProblems &&
             leftArray[i].penaltyTime < rightArray[j].penaltyTime) ||
            (leftArray[i].solvedProblems == rightArray[j].solvedProblems &&
             leftArray[i].penaltyTime == rightArray[j].penaltyTime &&
             leftArray[i].teamNumber < rightArray[j].teamNumber)) {
            teams[k] = leftArray[i];
            
            i++;
        } else {
            teams[k] = rightArray[j];
            
            j++;
        }
        k++;
    }

    while (i < n1) {
        teams[k] = leftArray[i];
        
        i++;
        k++;
    }

    while (j < n2) {
        teams[k] = rightArray[j];
        
        j++;
        k++;
    }
}

void mergeSort(vector<Team>& teams, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(teams, left, mid);
        mergeSort(teams, mid + 1, right);

        merge(teams, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Team> teams(n);

    for (int i = 0; i < n; i++) {
        teams[i].teamNumber = i + 1;
        
        cin >> teams[i].solvedProblems >> teams[i].penaltyTime;
    }

    mergeSort(teams, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << teams[i].teamNumber << " ";
    }

    return 0;
}