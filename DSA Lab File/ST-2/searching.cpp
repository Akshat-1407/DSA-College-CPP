// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int linearSearch(vector<int> arr, int key) {
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> arr, int key) {
    int min = 0, max = arr.size() - 1;
    
    while (min <= max) {
        int mid = min + (max - min) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key) // Left Half 
            max = mid - 1;
        else    
            min = mid + 1; // Right Half
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 5, 7, 9, 3, 4, 6};

    cout << "Linear Search Array: ";
    for (int e : arr) cout << e << " ";
    cout << endl;

    int linear_key = 6;
    int linear_idx = linearSearch(arr, linear_key);
    cout << linear_key << " is present at index " << linear_idx << endl;

    sort(arr.begin(), arr.end());

    cout << "\nBinary Search Array: ";
    for (int e : arr) cout << e << " ";
    cout << endl;

    int bin_key = 1;
    int bin_idx = binarySearch(arr, bin_key);
    cout << bin_key << " is present at index " << bin_idx << endl;

    return 0;
}

/*

    OUTPUT - 1

    Linear Search Array: 2 5 7 9 3 4 6 
    3 is present at index 4

    Binary Search Array: 2 3 4 5 6 7 9
    6 is present at index 4

    
    OUTPUT - 2

    Linear Search Array: 2 5 7 9 3 4 6 
    6 is present at index 6

    Binary Search Array: 2 3 4 5 6 7 9
    1 is present at index -1

*/