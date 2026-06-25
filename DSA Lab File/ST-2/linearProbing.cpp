// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
using namespace std;

int LinearProbing(int Table[], int ts, int x)
{
    int m = x % ts;
    int flag = 1;
    
    if (Table[m] == 0)
        Table[m] = x;
    else {
        flag = 0;
        for (int i = 1; i < ts; i++) {
            int newPos = (m + i) % ts;
            if (Table[newPos] == 0) {
                Table[newPos] = x;
                flag = 1;
                break;
            }
        }
    }
    
    return flag;
}

int main() {
    int key, ts=15;
    int n,x;
    int TableLP[15]={0};
    
    cout<<"Enter No of elements to store: ";
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>x;
        LinearProbing(TableLP,ts,x);
        
    }
    for(int i=0; i<=ts-1; i++) {
        cout<<i;
        cout<<" ";
    }
    cout<<"\n\n";

    for (int i=0; i<=ts-1; i++) {
        cout << TableLP[i] << " ";
    }
    return 0;
}

/*

    OUTPUT - 1

    Enter No of elements to store: 5
    50
    65
    80
    100
    55
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 

    0 0 0 0 0 50 65 80 0 0 100 55 0 0 0


    OUTPUT - 2

    Enter No of elements to store: 6
    15
    90
    80
    65
    100
    120
    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 

    15 90 120 0 0 80 65 0 0 0 100 0 0 0 0

*/