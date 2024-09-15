#include <iostream>
#include <vector>

using namespace std;

#define ll long long

// Core binary search function template with lambda for value retrieval
// Template: https://github.com/ehsan18t/C-Programming-Practice/blob/main/Templates/Binary_Search.cpp
template <typename T, typename GetValue>
ll binarySearch(ll low, ll high, T target, GetValue getValue) {
    while (low <= high) {
        ll mid = low + (high - low) / 2; // Avoid overflow
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
ll binarySearch(const Container& arr, ll target, ll start = 0, ll end = -1) {
    if (end == -1) {
        end = arr.size() - 1; // If end is not provided, default to the last index
    }

    // Pass a lambda to extract the value from the container at index 'mid'
    return binarySearch<ll>(start, end, target, [&](ll mid) {
        return arr[mid];
    });
}

// Overload for ranges with optional start
ll binarySearch(ll target, ll start = 1, ll end = 100) {
    // Pass a lambda to treat 'mid' as the value itself for number ranges
    return binarySearch<ll>(start, end, target, [&](ll mid) {
        return mid;
    });
}

// USES
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
