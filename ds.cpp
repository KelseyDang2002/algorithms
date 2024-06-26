#include <iostream>
#include <cstdlib>
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

class Set {
    public:
        std::set <int> id;

        void print();
        void setInsert(int value);
        void setErase(int value);
        void setContains(int value);
        void setSize();
};

void Set::print() {
    std::cout << "Set: ";
    for (auto i = id.begin(); i != id.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n\n";
}

void Set::setInsert(int value) {
    std::cout << "Insert " << value << "\n";
    id.insert(value);
}

void Set::setErase(int value) {
    std::cout << "Erase " << value << "\n"; 
    id.erase(value);
}

void Set::setContains(int value) {
    if (id.count(value)) {
        std::cout << "Contains " << value << "\n";
    }
    else {
        std::cout << value << " does not exist\n";
    }
}

void Set::setSize() {
    std::cout << "Set size = " << id.size() << "\n";
}

class Map {
    public:
        std::map <std::string, int> country_codes;

        void print();
        void mapInsert(std::string country, int code);
        void mapErase(std::string country);
        void mapAccess(std::string country);
        void mapEdit(std::string country, int code);
        void mapContains(std::string country);
        void mapSize();
};

void Map::print() {
    std::cout << "Map: ";
    for (auto it: country_codes) {
        std::cout << "\t" << it.first << " -> " << it.second << "\n";
    }
    std::cout << "\n";
}

void Map::mapInsert(std::string country, int code) {
    country_codes.insert({country, code});
    std::cout << "Insert " << country << " " << code << "\n";
}

void Map::mapErase(std::string country) {
    country_codes.erase(country);
    std::cout << "Erase " << country << "\n";
}

void Map::mapAccess(std::string country) {
    std::cout << country << " code = " << country_codes[country] << "\n";
}

void Map::mapEdit(std::string country, int code) {
    country_codes[country] = code;
    std::cout << "Change " << country << " code to " << code << "\n";
}

void Map::mapContains(std::string country) {
    if (country_codes.count(country)) {
        std::cout << "Contains " << country << "\n";
    }
    else {
        std::cout << country << " does not exist\n";
    }
}

void Map::mapSize() {
    std::cout << "Map size = " << country_codes.size() << "\n";
}

struct SLLNode {
    int data;
    struct SLLNode* next;
};

SLLNode* head;

void insertSLL(int value) {
    SLLNode* temp = (SLLNode*)malloc(sizeof(struct SLLNode));
    temp->data = value;
    temp->next = head;
    head = temp;
}

void printSLL() {
    SLLNode* temp = head;
    std::cout << "SLL: ";
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

void prompt() {
    head = NULL; // empty list
    std::cout << "How many numbers? ";
    int n, value;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Enter number: ";
        std::cin >> value;
        insertSLL(value);
        printSLL();
    }
}

// struct DLLNode {
//     int data;
//     struct DLLNode* prev;
//     struct DLLNode* next;
// };

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

    Set set;

    set.setInsert(4060);
    set.setInsert(4070);
    set.setInsert(4080);
    set.setInsert(4090);
    set.setInsert(4060);
    set.setErase(4080);
    set.setContains(4070);
    set.setContains(4080);
    set.setSize();
    set.print();

    Map map;

    map.mapInsert("United States", 840);
    map.mapInsert("Japan", 392);
    map.mapInsert("Korea", 410);
    map.mapInsert("Sweden", 752);
    map.mapErase("Sweden");
    map.mapEdit("Korea", 408);
    map.mapContains("Sweden");
    map.mapInsert("Russia", 643);
    map.mapAccess("Japan");
    map.mapSize();
    map.print();

    prompt();
    
    return 0;
}