#include <iostream>
#include <vector>
using namespace std;

// Core binary search function template with lambda for value retrieval
template <typename T, typename GetValue>
int binarySearch(int low, int high, T target, GetValue getValue) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        T midValue = getValue(mid); // Get the value at the current mid index
        if (midValue == target) {
            return mid; // Target found
        } else if (midValue < target) {
            low = mid + 1; // Search right
        } else {
            high = mid - 1; // Search left
        }
    }
    return -1; // Target not found
}

// Overload for containers with optional start and end
template <typename Container>
int binarySearch(const Container& arr, int target, int start = 0, int end = -1) {
    if (end == -1) {
        end = arr.size() - 1; // If end is not provided, default to the last index
    }

    // Pass a lambda to extract the value from the container at index 'mid'
    return binarySearch<int>(start, end, target, [&](int mid) {
        return arr[mid];
    });
}

// Overload for ranges with optional start
int binarySearch(int target, int start = 1, int end = 100) {
    // Pass a lambda to treat 'mid' as the value itself for number ranges
    return binarySearch<int>(start, end, target, [&](int mid) {
        return mid;
    });
}

int main() {
    // Test with an array (start and end are optional)
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target1 = 7;

    // Searching with default start and end
    int result1 = binarySearch(arr, target1);
    if (result1 != -1) {
        cout << "Element found at index " << result1 << " in array" << endl;
    } else {
        cout << "Element not found in array" << endl;
    }

    // Test with a range (start is optional)
    int target2 = 75;

    // Searching with default range (1 to 100)
    int result2 = binarySearch(target2);
    if (result2 != -1) {
        cout << "Element found at " << result2 << " in range" << endl;
    } else {
        cout << "Element not found in range" << endl;
    }

    return 0;
}
