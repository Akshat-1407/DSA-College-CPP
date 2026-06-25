// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int flag = 1;
  
    for (int i = 0; i < n - 1; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void shellSort(vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];  
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}


void print(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
}

int main() {
    vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };

    cout << "Original Array: ";
    print(arr);

    shellSort(arr);
    cout << "\nSorted Array: ";
    print(arr);

    return 0;
}/*
    OUTPUT - 1

    Original Array: 64 34 25 12 22 11 90 
    Sorted Array: 11 12 22 25 34 64 90

    OUTPUT - 2

    Original Array: 170 45 75 90 24 2 66
    Sorted Array: 2 24 45 66 75 90 170
*/