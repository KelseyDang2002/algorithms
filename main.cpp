#include <iostream>
#include <cstdlib>
#include <chrono>

// Function to generate array 
void generate_arr(int array[], int size) {
    srand(time(0)); // seed

    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 1001); // 0 - 100
    }
}

// Function to print array
void print_arr(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";

    for (int i = 0; i < size; i++) {
        std::cout  << "\t" << array[i];

        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

// Function to do Bubble Sort
void bubble_sort(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";
    
    bool swapped;
    for (int i = 0; i < (size - 1); i++) {
        swapped = false;

        for (int j = 0; j < (size - i - 1); j++) {
            // swap if first element in pair > second element in pair
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
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
void bubble_sort_opt(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";
    
    bool swapped = false;
    for (int i = 1; i <= size; i++) {
        if (i == size) {
            if (!swapped) {
                break;
            }

            swapped = false;
            i = 1;
        }

        if (array[i - 1] > array[i]) {
            swap(&array[i - 1], &array[i]);
            swapped = true;
        }
    }
}

// Function to do Selection Sort
void selection_sort(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";

    for (int i = 0; i < size - 1; i++) {
        int min_value = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min_value]) {
                min_value = j;
            }
        }

        if (min_value != i) {
            swap(&array[min_value], &array[i]);
        }
    }
}

// Function to do Merge Sort TODO
void merge_sort(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";
}

// Main
int main() {
    const int ARR_SIZE = 5000;
    int array[ARR_SIZE];

    generate_arr(array, ARR_SIZE);

    print_arr(array, ARR_SIZE, "Unsorted Array:");

    auto start = std::chrono::high_resolution_clock::now(); // time start

    // bubble_sort(array, ARR_SIZE, "Bubble Sort");
    // bubble_sort_opt(array, ARR_SIZE, "Optimized Bubble Sort");
    selection_sort(array, ARR_SIZE, "Selection Sort");

    auto stop = std::chrono::high_resolution_clock::now(); // time stop
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // time
    std::cout << duration.count() << " microseconds\n"; // print time

    print_arr(array, ARR_SIZE, "Sorted Array:");

    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name