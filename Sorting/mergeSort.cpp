#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> C(arr.size());
    
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            C[k] = arr[i];
            k++; i++;
        }
        else {
            C[k] = arr[j];
            k++; j++;
        }
    }

    while (i <= mid) {
        C[k] = arr[i];
        k++; i++;
    }

    while (j <= right) {
        C[k] = arr[j];
        k++; j++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = C[i];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {    
    int mid = left + (right - left) / 2;

    if (left < right) {
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    
    vector<int> arr = {38, 27, 43, 10};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}