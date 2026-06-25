// AKSHAT RASTOGI       CSE 11      2400320100133

#include<iostream>
#include<stdlib.h>
#define MAXQUEUE 10
using namespace std;
struct Queue{
    char item[MAXQUEUE];
    int Rear;
    int Front;
};
Queue Q;
void Initialize(){
    Q.Front=0;
    Q.Rear=-1;
}
bool IsEmpty(){
    if(Q.Rear-Q.Front+1==0){
        return true;
    }
    else{
        return false;   
    }
}
void EnQueue(char x){
    if(Q.Rear==MAXQUEUE-1){
        cout<<"Queue Overflow";
        exit(1);
    }
    else{
        Q.Rear=Q.Rear+1;
        Q.item[Q.Rear]=x;
    }
}
char DeQueue(){
    if(IsEmpty()){
       cout<<"Queue Underflow"; 
       exit(1);
    }
    else{
        char x=Q.item[Q.Front];
        Q.Front=Q.Front+1;
        return x;
    }
}
void Display() {
    if (IsEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = Q.Front; i <= Q.Rear; i++) {
        cout << Q.item[i] << " ";
    }
    cout << endl;
}
int main() {
    Initialize();
    EnQueue('A');
    EnQueue('B');
    EnQueue('C');
    EnQueue('D');
    EnQueue('E');
    EnQueue('F');
    cout << "Initial Queue:\n";
    Display();
    cout << "Deleted item: " << DeQueue() << endl;
    Display();
    cout << "Deleted item: " << DeQueue() << endl;
    Display();
    cout << "Deleted item: " << DeQueue() << endl;
    Display();
    cout << "Deleted item: " << DeQueue() << endl;
    Display();
    cout << "Deleted item: " << DeQueue() << endl;
    Display();
    cout << "Deleted item: " << DeQueue() << endl;
    Display();
    return 0;
}

/*
OUTPUT
    Initial Queue:
    Queue: A B C D E F 
    Deleted item: A
    Queue: B C D E F
    Deleted item: B
    Queue: C D E F
    Deleted item: C
    Queue: D E F
    Deleted item: D
    Queue: E F 
    Deleted item: E
    Queue: F
    Deleted item: F
    Queue is Empty
*/