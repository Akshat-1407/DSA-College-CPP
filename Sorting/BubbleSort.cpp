#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int flag = 1;
    for (int i = 0; (i < n-1 && flag == 1); i++) {
        flag = 0;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
    }

}

int main() {

    vector<int> arr = {3, 1, 2, 7, 5, 9, 8, 4, 6, 0};

    bubbleSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}