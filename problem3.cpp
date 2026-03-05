// Compile with:
// g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3

#include <iostream>

// 1. Linear Search
int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// 2. Binary Search (iterative)
int binarySearch(int* arr, int n, int target) {
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return -1;
}

// 3. Generate sorted array of distinct integers
int* generateSortedArray(int n) {
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = 2 * i;   // {0, 2, 4, ..., 2(n-1)}
    }

    return arr;  // caller must delete[]
}

int main() {
    int sizes[] = {10, 100, 1000};

    for (int s = 0; s < 3; ++s) {
        int n = sizes[s];
        std::cout << "===== n = " << n << " =====\n";

        int* arr = generateSortedArray(n);

        // Existing value (element at midpoint)
        int midIndex = n / 2;
        int existingValue = arr[midIndex];

        // Non-existing value (odd number, array only has even numbers)
        int nonExistingValue = -1;

        // Search existing value
        int linIndex1 = linearSearch(arr, n, existingValue);
        int binIndex1 = binarySearch(arr, n, existingValue);

        std::cout << "Search existing value (" << existingValue << ")\n";
        std::cout << "Linear Search index: " << linIndex1 << "\n";
        std::cout << "Binary Search index: " << binIndex1 << "\n";

        if (linIndex1 == binIndex1) {
            std::cout << "Result: MATCH\n";
        } else {
            std::cout << "Result: MISMATCH\n";
        }

        // Search non-existing value
        int linIndex2 = linearSearch(arr, n, nonExistingValue);
        int binIndex2 = binarySearch(arr, n, nonExistingValue);

        std::cout << "\nSearch non-existing value (" << nonExistingValue << ")\n";
        std::cout << "Linear Search index: " << linIndex2 << "\n";
        std::cout << "Binary Search index: " << binIndex2 << "\n";

        if (linIndex2 == binIndex2) {
            std::cout << "Result: MATCH\n";
        } else {
            std::cout << "Result: MISMATCH\n";
        }

        std::cout << "\n";

        delete[] arr;  // free memory
    }

    return 0;
}