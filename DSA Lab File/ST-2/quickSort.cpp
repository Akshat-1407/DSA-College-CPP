// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int Partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high + 1;

    do {
        do {
            i = i + 1;
        }
        while (arr[i] < pivot);
        
        do {
            j = j - 1;
        }
        while (arr[j] > pivot);

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    while (i < j);

    swap(arr[low], arr[j]);
    
    return j;
}

void QuickSort(vector<int>& arr, int low, int high) {

    if (low < high) {
        int j = Partition(arr, low, high);
        QuickSort(arr, low, j); // Left Half
        QuickSort(arr, j + 1, high); // Right Half
    }
}

int main() {

    vector<int> arr = {3, 1, 2, 7, 5, 9, 8, 4, 6, 0};

    QuickSort(arr, 0, arr.size()-1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    OUTPUT - 1
    0 1 2 3 4 5 6 7 8 9 

    OUTPUT - 2
    2 24 45 66 75 90 170
*/