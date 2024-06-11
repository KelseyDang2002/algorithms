#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to print array
void print_arr(int unsorted_arr[], int arr_length, string text) {
    cout << "\n" << text << "\n";

    for (int i = 0; i < arr_length; i++) {
        cout  << "\t" << unsorted_arr[i];

        if ((i + 1) % 10 == 0) {
            cout << "\n";
        }
    }
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Function to do Bubble Sort
void bubble_sort(int unsorted_arr[], int arr_length, string text) {
    cout << "\n" << text << "\n";
    
    bool swapped;
    for (int i = 0; i < (arr_length - 1); i++) {
        swapped = false;

        for (int j = 0; j < (arr_length - i - 1); j++) {
            // swap if first element in pair > second element in pair
            if (unsorted_arr[j] > unsorted_arr[j + 1]) {
                swap(&unsorted_arr[j], &unsorted_arr[j + 1]);
                swapped = true;
            }
        }

        // no pairs of elements were swapped by inner for loop
        if (swapped == false) {
            break;
        }
    }
}

// Function to do Optimized Bubble Sort
void bubble_sort_opt(int unsorted_arr[], int arr_length, string text) {
    cout << "\n" << text << "\n";
    
    bool swapped = false;
    for (int i = 1; i <= arr_length; i++) {
        if (i == arr_length) {
            if (!swapped) {
                break;
            }

            swapped = false;
            i = 1;
        }

        if (unsorted_arr[i - 1] > unsorted_arr[i]) {
            swap(&unsorted_arr[i - 1], &unsorted_arr[i]);
            swapped = true;
        }
    }
}

// Function to do Selection Sort
void selection_sort(int unsorted_arr[], int arr_length, string text) {
    cout << "\n" << text << "\n";

    for (int i = 0; i < arr_length - 1; i++) {
        int min_value = i;

        for (int j = i + 1; j < arr_length; j++) {
            if (unsorted_arr[j] < unsorted_arr[min_value]) {
                min_value = j;
            }
        }

        if (min_value != i) {
            swap(&unsorted_arr[min_value], &unsorted_arr[i]);
        }
    }
}

// Function to do Merge Sort TODO
void merge_sort(int unsorted_arr[], int arr_length, string text) {
    cout << "\n" << text << "\n";
}

// Main
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
    cout << arr_length << "\n";

    print_arr(unsorted_arr, arr_length, "Unsorted Array:");

    auto start = high_resolution_clock::now();

    // bubble_sort(unsorted_arr, arr_length, "Bubble Sort");
    // bubble_sort_opt(unsorted_arr, arr_length, "Optimized Bubble Sort");
    selection_sort(unsorted_arr, arr_length, "Selection Sort");

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";

    print_arr(unsorted_arr, arr_length, "Sorted Array:");

    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name