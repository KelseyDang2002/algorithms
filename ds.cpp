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
        std::cout << "\t" << it.first << ", " << it.second << "\n";
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
    SLLNode* next;
};

void headInsertSLL(SLLNode** ptrToHead, int value) {
    // SLLNode* temp = (SLLNode*)malloc(sizeof(struct SLLNode)); // C
    SLLNode* temp = new SLLNode(); // C++
    temp->data = value;
    temp->next = NULL;
    
    if (*ptrToHead != NULL) temp->next = *ptrToHead;
    *ptrToHead = temp;
}

void positionInsertSLL(SLLNode** ptrToHead, int value, int position) {
    SLLNode* temp1 = new SLLNode();
    temp1->data = value;
    temp1->next = NULL;

    if (position == 1) {
        temp1->next = *ptrToHead;
        *ptrToHead = temp1;
        return;
    }

    SLLNode* temp2 = *ptrToHead;
    for (int i = 0; i < position - 2; i++) {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void positionDeleteSLL(SLLNode** ptrToHead, int position) {
    SLLNode* temp1 = *ptrToHead;

    if (position == 1) {
        *ptrToHead = temp1->next; // head now points to second node
        // free(temp1); // C
        delete temp1; // C++
        return;
    }

    for (int i = 0; i < position - 2; i++)
        temp1 = temp1->next; // temp1 points to (n-1)th Node
    
    SLLNode* temp2 = temp1->next; // nth Node
    temp1->next = temp2->next; // (n+1)th Node
    delete temp2;
}

void printSLL(SLLNode* head) {
    std::cout << "SLL: ";

    while(head != NULL) {
        std::cout << head->data << " -> ";
        head = head->next;
    }

    std::cout << "NULL\n";
}

void callSLL() {
    SLLNode* head = NULL; // empty list
    positionInsertSLL(&head, 2, 1); // 2
    positionInsertSLL(&head, 3, 2); // 2, 3
    positionInsertSLL(&head, 4, 1); // 4, 2, 3
    positionInsertSLL(&head, 5, 2); // 4, 5, 2, 3
    headInsertSLL(&head, 7); // 7, 4, 5, 2, 3
    positionDeleteSLL(&head, 3); // 7, 4, 2, 3
    printSLL(head);
}

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
};

DLLNode* head;

DLLNode* getNewNode(int value) {
    DLLNode* newNode = new DLLNode();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void headInsertDLL(int value) {
    DLLNode* newNode = getNewNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }

    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void tailInsertDLL() {}

void reversePrintDLL() {
    DLLNode* temp = head;
    if (temp == NULL) return; // empty list, exit

    // going to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // traversing backward using prev pointer
    std::cout << "DLL Reversed: NULL <-> ";
    while (temp != NULL) {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }

    std::cout << "NULL\n";
}

void printDLL() {
    DLLNode* temp = head;
    std::cout << "DLL: NULL <-> ";

    while (temp != NULL) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }

    std::cout << "NULL\n";
}

void callDLL() {
    head = NULL;
    headInsertDLL(2);
    printDLL();
    reversePrintDLL();
    headInsertDLL(4);
    printDLL();
    reversePrintDLL();
    headInsertDLL(6);
    printDLL();
    reversePrintDLL();
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

    callSLL();
    
    callDLL();
    
    return 0;
}