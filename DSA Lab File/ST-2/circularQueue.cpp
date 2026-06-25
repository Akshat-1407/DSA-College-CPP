// AKSHAT RASTOGI       CSE 11      2400320100133

#include<iostream>
#include<stdlib.h>
#define MAXQUEUE 10
using namespace std;
struct CQueue{
    char item[MAXQUEUE];
    int Rear;
    int Front;
};
CQueue CQ;
void Initialize(){
    CQ.Front=MAXQUEUE-1;
    CQ.Rear=MAXQUEUE-1;
}
bool IsEmpty(){
    if(CQ.Rear==CQ.Front){
        return true;
    }
    else{
        return false;   
    }
}
void EnQueue(char x){
    if((CQ.Rear+1)%MAXQUEUE==CQ.Front){
        cout<<"Queue Overflow";
        exit(1);
    }
    else{
        CQ.Rear=(CQ.Rear+1)%MAXQUEUE;
        CQ.item[CQ.Rear]=x;
    }
}
char DeQueue(){
    if(IsEmpty()){
       cout<<"Queue Underflow"; 
       exit(1);
    }
    else{
        CQ.Front=(CQ.Front+1)%MAXQUEUE;
        char x=CQ.item[CQ.Front];
        return x;
    }
}
void Display() {
    if (IsEmpty()) {
        cout << "Queue is Empty\n";
        return;
    }
    cout << "Queue: ";
    int i = (CQ.Front + 1) % MAXQUEUE;
    while (i != (CQ.Rear + 1) % MAXQUEUE) {
        cout << CQ.item[i] << " ";
        i = (i + 1) % MAXQUEUE;
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
/*  OUTPUT
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