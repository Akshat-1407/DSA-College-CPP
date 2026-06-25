// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <cmath>
using namespace std;

int nearest_prime (int ts) {
    int i=0, j=0;
    int flag=0;
    
    for (i = ts; i >= 2; i--) {
        for (j=2; j <= sqrt(i); j++) {
            if (i%j==0)
                break;
        }
        if (j > sqrt(i))
            return i;
    }
}

int DigitsCount(int N) {
    int count = 0;    
    while (N != 0) {
        N /= 10;
        count++;
    }
    return count;
}

int Reverse(int R) {
    int reversed_R = 0;
    while (R > 0) {
        reversed_R = reversed_R * 10 + (R % 10);
        R /= 10;
    }
    return reversed_R;
}

int DivisionHash(int ts, int key) {
    int np = 0;
    int l = 0;
    np = nearest_prime(ts);
    l = key % np;
    return l;
}

int Midsquare (int TS, long long N) {
    int d = DigitsCount(TS-1);
    int l = DigitsCount(N); 
    int e = (2 * l - d)/2;
    int r = pow(10, e);
    N = (N*N) / r; 
    int mod = pow(10, d);
    return N % mod; 
}

int FoldingHash(int TS, long long N) {
    int d = DigitsCount(TS - 1);
    int mod = pow(10, d);
    int sum = 0;

    while (N != 0) {
        sum = sum + N % mod;
        N = N / mod;
    }
    return sum % TS;
}

int ReverseFoldingHash(int TS, long long N) {
    int d = DigitsCount(TS - 1);
    long long M = (long long)pow(10, d);
    long long S = 0;
    int flag = 0;
    while (N != 0) {
        long long r = N % M;
        if (flag == 1) {
            r = Reverse(r);
            flag = 0;
        }
        else {
            flag = 1;
        }
        S = S + r;
        N = N / M;
    }
    return S % TS;
}
int main() {
    const int TS = 100;
    const long long KEY = 54678LL;

    cout << "TS = " << TS << ", Key = " << KEY << endl;
    cout << "Division: " << DivisionHash(TS, KEY) << endl;
    cout << "Midsquare: " << Midsquare(TS, KEY) << endl;
    cout << "Folding: " << FoldingHash(TS, KEY) << endl;
    cout << "Reverse Folding: " << ReverseFoldingHash(TS, KEY) << endl;
    
    return 0;
}

/*

    OUTPUT - 1

    TS = 100, Key = 54678
    Division: 67
    Midsquare: 18
    Folding: 92
    Reverse Folding: 10

    OUTPUT - 2

    TS = 100, Key = 896541
    Division: 67
    Midsquare: 47
    Folding: 33
    Reverse Folding: 51

*/
