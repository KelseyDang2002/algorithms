#include <iostream>

using namespace std;

void print(string message) {
    cout << message << "\n";
}

int main() {
    print("hello, world");
    print("0 and O\n1 and l\ni and l\nq and g");
    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name