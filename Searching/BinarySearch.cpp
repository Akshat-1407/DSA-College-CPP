#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int BsRecursive(vector<int> arr, int key, int min, int max) {
    if (min <= max) {
        int mid = min + (max - min) / 2;

        if (arr[mid] > key)
            return BsRecursive(arr, key, min, mid-1); // Left Half
        else if (arr[mid] < key)
            return BsRecursive(arr, key, mid + 1, max); // Right Half
        else
            return mid;
    }
    return -1; 
}


int main() {
    vector<int> arr = {2, 5, 7, 9, 3, 4, 6};

    sort(arr.begin(), arr.end());

    int key = 3;

    int index = binarySearch(arr, key);

    cout << key << " is present at index " << index << endl;

    return 0;
}