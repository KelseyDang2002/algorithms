#include <iostream>
#include <cstdlib>
#include <functional>
#include <chrono>

const int ARR_SIZE = 5000; // size of array

class Array {
    public:
        int array[ARR_SIZE];

        void generate_arr();
        void print_arr(std::string text);
        void bubble_sort();
        void bubble_sort_opt();
        void selection_sort();
        void merge_sort();
        void quick_sort();
};

// Function to generate array 
void Array::generate_arr() {
    srand(time(0)); // seed

    for (int i = 0; i < ARR_SIZE; i++) {
        array[i] = (rand() % (100000 + 1)); // random integer between 0 and 100000
    }
}

// Function to print array
void Array::print_arr(std::string text) {
    std::cout << "\n" << text << "\n";
    std::cout << "------------------------------------------------------------------------------------\n";

    for (int i = 0; i < ARR_SIZE; i++) {
        std::cout << "\t" << array[i];

        if ((i + 1) % 10 == 0) {
            std::cout << "\n";
        }
    }
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to do Bubble Sort
void Array::bubble_sort() {
    std::cout << "\nBubble Sort\n";
    
    bool swapped;
    for (int i = 0; i < (ARR_SIZE - 1); i++) {
        swapped = false;

        for (int j = 0; j < (ARR_SIZE - i - 1); j++) {
            // swap if low element in pair > second element in pair
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
void Array::bubble_sort_opt() {
    std::cout << "\nOptimized Bubble Sort\n";
    
    bool swapped = false;
    for (int i = 1; i <= ARR_SIZE; i++) {
        if (i == ARR_SIZE) {
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
void Array::selection_sort() {
    std::cout << "\nSelection Sort\n";

    for (int i = 0; i < ARR_SIZE - 1; i++) {
        int min_value = i;

        for (int j = i + 1; j < ARR_SIZE; j++) {
            if (array[j] < array[min_value]) {
                min_value = j;
            }
        }

        if (min_value != i) {
            swap(&array[min_value], &array[i]);
        }
    }
}

// Function to sort subarrays in Merge Sort
void merge_sorted_subarrays(int array[], int left, int mid, int right) {
    int left_length = mid - left + 1;
    int right_length = right - mid;

    int left_subarray[left_length];
    int right_subarray[right_length];

    int i, j, k;

    for (int i = 0; i < left_length; i++) {
        left_subarray[i] = array[left + i];
    }

    for (int i = 0; i < right_length; i++) {
        right_subarray[i] = array[mid + 1 + i];
    }

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < left_length) && (j >= right_length || left_subarray[i] <= right_subarray[j])) {
            array[k] = left_subarray[i];
            i++;
        }
        
        else {
            array[k] = right_subarray[j];
            j++;
        }
    }
}

// Function to do Merge Sort Recursion
void merge_sort_recursion(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_recursion(array, left, mid);
        merge_sort_recursion(array, mid + 1, right);

        merge_sorted_subarrays(array, left, mid, right); 
    }
    
}

// Function to do Merge Sort
void Array::merge_sort() {
    std::cout << "\nMerge Sort\n";

    merge_sort_recursion(array, 0, ARR_SIZE - 1);
}

// Function that separates values less than and greater than the pivot in Quick Sort
int partition(int array[], int low, int high) {
    // prevent always picking high pivot by swapping high with a random pivot between low and high
    int pivot_index = low + (rand() % (high - low));
    
    if (pivot_index != high) {
        swap(&array[pivot_index], &array[high]);
    }

    int pivot = array[high];
    
    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);

    return i;
}

// Function to do Quick Sort Recursion
void quick_sort_recursion(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);

        quick_sort_recursion(array, low, pivot_index - 1);
        quick_sort_recursion(array, pivot_index + 1, high);
    }
}

// Function to do Quick Sort
void Array::quick_sort() {
    std::cout << "\nQuick Sort\n";

    srand(time(NULL));
    quick_sort_recursion(array, 0, ARR_SIZE - 1);
}

// Main
int main() {
    Array array1, array2, array3, array4, array5;

    array1.generate_arr();
    array2.generate_arr();
    array3.generate_arr();
    array4.generate_arr();
    array5.generate_arr();
    
    array1.print_arr("Unsorted Array:");

    auto start = std::chrono::high_resolution_clock::now(); // time start
    array1.bubble_sort();
    auto stop = std::chrono::high_resolution_clock::now(); // time stop
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // time
    std::cout << "Execution time: " << duration.count() << " microseconds\n"; // print time

    // auto start2 = std::chrono::high_resolution_clock::now(); // time start
    // array2.bubble_sort_opt();
    // auto stop2 = std::chrono::high_resolution_clock::now(); // time stop
    // auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop2 - start2); // time
    // std::cout << "Execution time: " << duration2.count() << " microseconds\n"; // print time

    // auto start3 = std::chrono::high_resolution_clock::now(); // time start
    // array3.selection_sort();
    // auto stop3 = std::chrono::high_resolution_clock::now(); // time stop
    // auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop3 - start3); // time
    // std::cout << "Execution time: " << duration3.count() << " microseconds\n"; // print time

    // auto start4 = std::chrono::high_resolution_clock::now(); // time start
    // array4.merge_sort();
    // auto stop4 = std::chrono::high_resolution_clock::now(); // time stop
    // auto duration4 = std::chrono::duration_cast<std::chrono::microseconds>(stop4 - start4); // time
    // std::cout << "Execution time: " << duration3.count() << " microseconds\n"; // print time

    // auto start5 = std::chrono::high_resolution_clock::now(); // time start
    // array5.quick_sort();
    // auto stop5 = std::chrono::high_resolution_clock::now(); // time stop
    // auto duration5 = std::chrono::duration_cast<std::chrono::microseconds>(stop5 - start5); // time
    // std::cout << "Execution time: " << duration5.count() << " microseconds\n"; // print time
    
    array1.print_arr("Sorted Array:");

    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name