#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> elements;

public:
    void enqueue(int value) {
        elements.push_back(value);
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
        } else {
            elements.erase(elements.begin());
        }
    }

    bool isEmpty() {
        return elements.empty();
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return -1; // Return a default value or throw an exception as needed
        }
        return elements.front();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Queue elements: ";
            for (int i : elements) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);

    myQueue.display(); // Display queue elements

    cout << "Front element: " << myQueue.front() << endl;

    myQueue.dequeue();
    myQueue.display(); // Display queue elements after dequeue operation

    return 0;
}
