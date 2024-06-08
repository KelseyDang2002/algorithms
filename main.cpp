#include <iostream>
#include <cstdlib>

using namespace std;

void print(string message) {
    cout << message << "\n";
}

void print_arr(int unsorted_arr[], int arr_length, string text) {
    cout << text << "\n";

    for (int i = 0; i < arr_length; i++) {
        cout  << "\t" << unsorted_arr[i];

        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }
}

void bubble_sort(int unsorted_arr[], int arr_length, string text) {
    // TODO
}

void selection_sort(int unsorted_arr[], int arr_length, string text) {
    // TODO
}

void merge_sort(int unsorted_arr[], int arr_length, string text) {
    // TODO
}

int main() {
    int unsorted_arr[] = {
        47, 69, 51, 37, 1, 17, 28, 98, 34, 20,
        74, 31, 11, 4, 55, 64, 25, 56, 3, 8, 
        15, 58, 61, 75, 91, 93, 79, 88, 67, 49,
        2, 73, 38, 89, 36, 68, 99, 32, 50, 39,
        7, 22, 46, 83, 95, 71, 48, 6, 54, 18,
        87, 45, 65, 52, 42, 24, 85, 19, 12, 77,
        44, 29, 90, 62, 10, 27, 16, 80, 100, 40,
        14, 81, 63, 35, 9, 26, 78, 13, 96, 86,
        94, 33, 84, 43, 23, 30, 41, 82, 21, 92,
        53, 59, 60, 76, 5, 70, 66, 72, 57, 97
    };
    
    int arr_length = sizeof(unsorted_arr) / sizeof(unsorted_arr[0]);

    print_arr(unsorted_arr, arr_length, "\nUnsorted Array:");

    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name