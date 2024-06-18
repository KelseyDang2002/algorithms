#include <iostream>
#include <cstdlib>
#include <chrono>

const int ARR_SIZE = 5000; // size of array

// Function to generate array 
void generate_arr(int array[], int size) {
    srand(time(0)); // seed

    for (int i = 0; i < size; i++) {
        array[i] = (rand() % 1001); // random integer between 0 and 1000
    }
}

// Function to print array
void print_arr(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";
    std::cout << "------------------------------------------------------------------------------------\n";

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

// Args: array, leftmost index, rightmost index
void merge_sort_recursion(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_recursion(array, left, mid);
        merge_sort_recursion(array, mid + 1, right);

        merge_sorted_subarrays(array, left, mid, right); 
    }
    
}

// Function to do Merge Sort
void merge_sort(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";

    merge_sort_recursion(array, 0, ARR_SIZE - 1);
}

// Function to do Quick Sort TODO
void quick_sort(int array[], int size, std::string text) {
    std::cout << "\n" << text << "\n";
}

// Main
int main() {
    // int array[ARR_SIZE]; // array
    // int array2[ARR_SIZE];
    // int array3[ARR_SIZE];
    int array4[ARR_SIZE];
    // int array5[ARR_SIZE];

    // generate_arr(array, ARR_SIZE);
    // generate_arr(array2, ARR_SIZE);
    // generate_arr(array3, ARR_SIZE);
    generate_arr(array4, ARR_SIZE);
    // generate_arr(array5, ARR_SIZE);

    // print_arr(array, ARR_SIZE, "Unsorted Array:");
    // print_arr(array2, ARR_SIZE, "Unsorted Array2:");
    // print_arr(array3, ARR_SIZE, "Unsorted Array3:");
    print_arr(array4, ARR_SIZE, "Unsorted Array4:");
    // print_arr(array5, ARR_SIZE, "Unsorted Array5:");

    auto start = std::chrono::high_resolution_clock::now(); // time start

    // bubble_sort(array, ARR_SIZE, "Bubble Sort");
    // bubble_sort_opt(array2, ARR_SIZE, "Optimized Bubble Sort");
    // selection_sort(array3, ARR_SIZE, "Selection Sort");
    merge_sort(array4, ARR_SIZE, "Merge Sort");
    // quick_sort(array5, ARR_SIZE, "Quick Sort");

    auto stop = std::chrono::high_resolution_clock::now(); // time stop
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // time
    std::cout << "Execution time: " << duration.count() << " microseconds\n"; // print time

    // print_arr(array, ARR_SIZE, "Sorted Array:");
    // print_arr(array2, ARR_SIZE, "Sorted Array2:");
    // print_arr(array3, ARR_SIZE, "Sorted Array3:");
    print_arr(array4, ARR_SIZE, "Sorted Array4:");
    // print_arr(array5, ARR_SIZE, "Sorted Array5:");

    return 0;
}

// Compile: g++ -o some_name filename.cpp
// Run: ./some_name