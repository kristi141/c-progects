/*RU
Условие:
В цивилизованных странах на железнодорожном вокзале работают k касс, 
однако очередь в них всего одна. Обслуживание происходит следующим образом. 
Изначально, когда все кассы свободны, первые k человек из очереди подходят 
к кассам. Остальные ждут своей очереди. Как только кто-нибудь будет обслужен 
и соответствующая касса освободится, следующий человек из очереди подходит 
к этой кассе. Так продолжается до тех пор, пока не будут 
обслужены все клиенты. 
Определите время, за которое будут обслужены все клиенты. 

Входные данные:
В первой строке находится два целых числа: размер очереди n и количество касс 
k (1 ≤ n ≤ 105, 1 ≤ k ≤ 104). 
Во второй строке задаются n натуральных чисел. i-ое число определяет время 
ti (0 ≤ ti ≤ 105), которое требуется для того, чтобы обслужить i-го клиента 
из очереди. 

Выходные данные:
В выходной файл должно быть выведено единственное значение - время, за 
которое будет обслужена заданная очередь.

ENG
Condition:
In civilized countries, there are cash desks at the railway station,
however, there is only one queue. Service occurs as follows.
Initially, when all the cash registers are free, the first people in the 
queue come up to the box office. The rest are waiting their turn. As soon as 
anyone is served and the corresponding cash register becomes free, the next 
person in line comes up to this cash register. This continues until
all clients are served.
Determine the time during which all customers will be served.

Input data:
The first line contains two integers: queue size n and number of cash 
registers k(1 ≤ n ≤ 105, 1 ≤ k ≤ 104).
The second line contains n natural numbers.The i-th number determines the time
ti(0 ≤ ti ≤ 105), which is required to serve the i-th client
from the queue.

Output:
A single value should be output to the output file - time, for
which the given queue will be served.*/

#include <iostream>
#include <vector>
using namespace std;

struct Queue {
private:
    vector<long long> heap;

    void heapifyUp(long long index) {
        while (index > 0) {
            long long parent = (index - 1) / 2;

            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heapifyDown(long long index) {
        long long leftChild = 2 * index + 1;
        long long rightChild = 2 * index + 2;
        long long smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(long long value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    long long pop() {
        long long top = heap[0];

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return top;
    }

    bool empty() const {
        return heap.empty();
    }
};

int main() {
    long long queueSize, numberOfCashRegisters;
    cin >> queueSize >> numberOfCashRegisters;

    vector<long long> serviceTime(queueSize);

    for (long long i = 0; i < queueSize; i++) {
        cin >> serviceTime[i];
    }

    Queue queue;

    for (long long i = 0; i < numberOfCashRegisters; i++) {
        queue.push(serviceTime[i]);
    }

    for (long long i = numberOfCashRegisters; i < queueSize; i++) {
        long long minTime = queue.pop();
        minTime += serviceTime[i];

        queue.push(minTime);
    }

    long long totalTime = 0;

    while (!queue.empty()) {
        totalTime = queue.pop();
    }

    cout << totalTime << endl;

    return 0;
}