/*Write a program to implement a specialized queue data structure capable of deleting the smallest element within its contents. The program should also handle standard enqueue and dequeue operations.*/
#include <iostream>
#include <vector>
#include <algorithm>

class SpecialQueue {
private:
    std::vector<double> queue;

public:
    void enqueue(double value) {
        queue.push_back(value);
    }

    void dequeueSmallest() {
        if (queue.empty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        auto minElement = std::min_element(queue.begin(), queue.end());
        queue.erase(minElement);
    }

    void displayQueue() {
        if (queue.empty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        for (const double& element : queue) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int N;
    std::cin >> N;
    SpecialQueue specialQueue;

    for (int i = 0; i < N; ++i) {
        double element;
        std::cin >> element;
        specialQueue.enqueue(element);
    }

    specialQueue.dequeueSmallest();
    specialQueue.displayQueue();

    return 0;
}
