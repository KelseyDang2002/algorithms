#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

class Vector {
    public:
        std::vector <int> v = {};

        void print();
        void add(int value);
        void remove();
};

void Vector::print() {
    std::cout << "Vector: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";
}

void Vector::add(int value) {
    std::cout << "Add " << value << "\n";
    v.push_back(value);
}

void Vector::remove() {
    std::cout << "Remove last element\n";
    v.pop_back();
}

class Stack {
    public:
        std::stack <int> s;

        void printAndEmpty();
        void addToTop(int value);
        void removeTop();
};

void Stack::printAndEmpty() {
    std::cout << "Stack (top to bottom): ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n\n";
}

void Stack::addToTop(int value) {
    std::cout << "Push " << value << " to top\n";
    s.push(value);
}

void Stack::removeTop() {
    std::cout << "Remove top element\n";
    s.pop();
}

class Queue {
    public:
        std::queue <int> q;

        void printAndEmpty();
        void addToFront(int value);
        void removeFront();
};

void Queue::printAndEmpty() {
    std::cout << "Queue: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n\n";
}

void Queue::addToFront(int value) {
    std::cout << "Push " << value << " to front\n";
    q.push(value);
}

void Queue::removeFront() {
    std::cout << "Remove first element\n";
    q.pop();
}

int main() {
    Vector vector;

    vector.add(1);
    vector.add(2);
    vector.add(4);
    vector.add(8);
    vector.add(16);
    vector.add(32);
    vector.add(64);
    vector.print();
    vector.remove();
    vector.remove();
    vector.remove();
    vector.print();

    Stack stack;

    stack.addToTop(5);
    stack.addToTop(10);
    stack.addToTop(15);
    stack.removeTop();
    stack.printAndEmpty();

    Queue queue;

    queue.addToFront(100);
    queue.addToFront(101);
    queue.addToFront(102);
    queue.addToFront(103);
    queue.removeFront();
    queue.removeFront();
    queue.printAndEmpty();
    queue.addToFront(104);
    queue.addToFront(105);
    queue.printAndEmpty();
    
    return 0;
}