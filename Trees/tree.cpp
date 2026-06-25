#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    char data;
    struct node* left;
    struct node* right;
};

node* MakeNode(char x) {
    node* p;
    p = (node*) malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void PreOrder(node* T){
    if (T != NULL) {
        cout << T->data << ", ";
        PreOrder(T->left);
        PreOrder(T->right);
    }
}

void InOrder(node* T){
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
    }
}

void PostOrder(node* T){
    if (T != NULL) {
        PostOrder(T->left);
        PostOrder(T->right);
        cout << T->data << ", ";
    }
}

node* BST_Insert(node* T, int x) {
    node* P = T;
    node* Q = NULL;

    while (P != NULL) {
        Q = P;

        if (x < P->data) 
            P = P->left;
        else 
            P = P->right;
    }

    if (T == NULL) {
        MakeNode(x);
    }
    else {
        if (x < Q->data) 
            Q->left = MakeNode(x);
        else   
            Q->right = MakeNode(x);
    }
}

node* BST_Min(node* T) {
    while (T->left != NULL) {
        T = T->left;
    }
    return T;
}

node* BST_Max(node* T) {
    while (T->right != NULL) {
        T = T->right;
    }
    return T;
}

void createTree(node **T){
    int choice;
    cout << "Wheather the left of " << (*T)->data << " Exists? (0/1): ";
    cin >> choice;
    if (choice == 1) {
        char x;
        cout << "Enter the left child of " << (*T)->data << ": ";
        cin >> x;
        node *p = MakeNode(x);
        (*T)->left = p;
        createTree(&p);
    }
    cout << "Wheather the right of " << (*T)->data << " Exists? (0/1):  ";
    cin >> choice;
    if (choice == 1) {
        char x;
        cout << "Enter the right child of " << (*T)->data << ": ";
        cin >> x;
        node *p = MakeNode(x);
        (*T)->right = p;
        createTree(&p);
    }
}


int main() {
    node *T;
    char x;
    cout<<"Enter the data of root node: ";
    cin>>x;
    T = MakeNode(x);
    createTree(&T);

    cout << "PreOrder Traversal: ";
    PreOrder(T);

    cout << "\nInOrder Traversal: ";
    InOrder(T);

    cout << "\nPostOrder Traversal: ";
    PostOrder(T);

    return 0;
}