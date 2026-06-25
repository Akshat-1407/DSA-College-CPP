#include <iostream>
using namespace std;

int Partition(int arr[], int low, int high) {
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

void QuickSort(int arr[], int low, int high) {

    if (low < high) {
        int j = Partition(arr, low, high);
        QuickSort(arr, low, j - 1); // Left Half
        QuickSort(arr, j + 1, high); // Right Half
    }
}

int main() {

    int arr[] = {3, 1, 2, 7, 5, 9, 8, 4, 6, 0, 5, -1};

    int n = sizeof(arr) / sizeof(arr[0]);

    QuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}