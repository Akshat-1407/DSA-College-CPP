// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <stdlib.h>
#define MAXQUEUE 10
using namespace std;

struct Deque {
    char item[MAXQUEUE];
    int Rear;
    int Front;
};
Deque DQ;

void Initialize() {
    DQ.Front = MAXQUEUE - 1;
    DQ.Rear  = MAXQUEUE - 1;
}

bool IsEmpty() {
    return (DQ.Rear == DQ.Front);
}

bool IsFull() {
    return ((DQ.Rear + 1) % MAXQUEUE == DQ.Front);
}

void insertRear(char x) {
    if (IsFull()) {
        cout << "Deque Overflow\n";
        exit(1);
    } else {
        DQ.Rear = (DQ.Rear + 1) % MAXQUEUE;
        DQ.item[DQ.Rear] = x;
    }
}

void insertFront(char x) {
    if (IsFull()) {
        cout << "Deque Overflow\n";
        exit(1);
    } else {
        DQ.Front = (DQ.Front - 1 + MAXQUEUE) % MAXQUEUE;
        DQ.item[DQ.Front] = x;
    }
}

char deleteFront() {
    if (IsEmpty()) {
        cout << "Deque Underflow\n";
        exit(1);
    } else {
        DQ.Front = (DQ.Front + 1) % MAXQUEUE;
        return DQ.item[DQ.Front];
    }
}

char deleteRear() {
    if (IsEmpty()) {
        cout << "Deque Underflow\n";
        exit(1);
    } else {
        char x = DQ.item[DQ.Rear];
        DQ.Rear = (DQ.Rear - 1 + MAXQUEUE) % MAXQUEUE;
        return x;
    }
}

void Display() {
    if (IsEmpty()) {
        cout << "Deque is Empty\n";
        return;
    }

    cout << "Deque: ";
    int i = (DQ.Front + 1) % MAXQUEUE;
    while (i != (DQ.Rear + 1) % MAXQUEUE) {
        cout << DQ.item[i] << " ";
        i = (i + 1) % MAXQUEUE;
    }
    cout << endl;
}

int main() {
    Initialize();

    insertRear('P');
    insertRear('Q');
    insertRear('R');
    cout << "After insertRear :\n";
    Display();
    insertFront('X');
    insertFront('Y');
    cout << "After insertFront :\n";
    Display();
    cout << "deleteFront : " << deleteFront() << endl;
    Display();
    cout << "deleteRear : " << deleteRear() << endl;
    Display();
    insertRear('D');
    insertFront('Z');
    cout << "After insertRear D and insertFront Z:\n";
    Display();
    cout << "Emptying deque (deleteFront): ";
    cout << deleteFront() << " ";
    cout << endl;
    Display();
    return 0;
}

/*

    OUTPUT - 1

    After insertRear :
    Deque: A B C 
    After insertFront :
    Deque: X  A B C 
    deleteFront : X
    Deque:  A B C 
    deleteRear : C
    Deque:  A B 
    After insertRear D and insertFront Z:
    Deque: X  A B D
    Emptying deque (deleteFront): X
    Deque:  A B D

    OUTPUT - 2

    After insertRear :
    Deque: P Q R
    After insertFront :
    Deque: X  P Q R
    deleteFront : X
    Deque:  P Q R
    deleteRear : R
    Deque:  P Q
    After insertRear D and insertFront Z:
    Deque: X  P Q D
    Emptying deque (deleteFront): X
    Deque:  P Q D

*/