#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Array Should be sorted for this search
int indexSequentialSearch(vector<int> A, int key) {
    int N = A.size();
    int high = N - 1;
    int low = 0;
    int gs = sqrt(N); // Group size should be sqrt(N), for optimal time

    if (key > A[high] || key < A[low]) {
        return -1;
    }

    int i = low;
    while (key > A[i] && i < high) {
        i = i + gs;
    }

    if (key == A[i]) {
        return i;
    }
    else {
        int li = i-1;
        int fi = i-gs+1;

        for (int j = fi; j <= li; j++) {
            if (A[j] == key) {
                return j;
            }
        }
    }

    return -1;
}



int main() {

    vector<int> arr = {2, 4, 5, 9, 14, 16, 19, 20};

    sort(arr.begin(), arr.end());

    int key = 5;

    int index = indexSequentialSearch(arr, key);

    cout << key << " is present at index " << index << endl;

    return 0;
}