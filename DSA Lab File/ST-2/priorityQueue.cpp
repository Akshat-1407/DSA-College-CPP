// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


void ArrayInsertion(vector<int>& arr, int pos, int x) {
    arr.insert(arr.begin() + pos, x);
}

void Traversal(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

void EnQueue(vector<int>& arr, int x) {
    int i = 0;
    while (i < arr.size() && x < arr[i]) {
        i = i + 1;
    }
    ArrayInsertion(arr, i , x);
}

int DeQueue(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Void Deletion" << endl;
        exit(1);
    }
    int x = arr.back();
    arr.pop_back();  
    return x;
}

int main() {
    
    int n;
    cout << "Enter the Size of the array: ";
    cin >> n;

    vector<int>arr(n);
    
    cout << "Enter the elements of the array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<int>());

    EnQueue(arr, 2);

    Traversal(arr);

    return 0;
}

/*
    OUTPUT - 1

    Enter the Size of the array: 5
    Enter the elements of the array: 
    1
    3
    5
    4
    9
    9 5 4 3 2 1 

    OUTPUT - 2

    Enter the Size of the array: 7
    Enter the elements of the array: 
    5
    8
    4
    9
    7
    10
    6
    10 9 8 7 6 5 4 2 
*/