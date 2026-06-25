// AKSHAT RASTOGI       CSE 11      2400320100133

#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

node* MakeNode(int x) {
    node* p;
    p = (node*) malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InOrder(node* T){
    if (T != NULL) {
        InOrder(T->left);
        cout << T->data << ", ";
        InOrder(T->right);
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
    return T;
}

node* BST_Delete(node* T, int x) {
    if (T == NULL) {
        return T;
    }
    if (x < T->data) {
        T->left = BST_Delete(T->left, x);
    } 
    else if (x > T->data) {
        T->right = BST_Delete(T->right, x);
    } 
    else {
        // Case 1 & 2: Node with only one child or no child
        if (T->left == NULL) {
            node* temp = T->right;
            free(T);
            return temp;
        } 
        else if (T->right == NULL) {
            node* temp = T->left;
            free(T);
            return temp;
        }

        // Case 3: Node with two children 
        node* temp = BST_Min(T->right);

        T->data = temp->data;
        T->right = BST_Delete(T->right, temp->data);
    }
    return T;
}

void createTree(node **T){
    int choice;
    cout << "Wheather the left of " << (*T)->data << " Exists? (0/1): ";
    cin >> choice;
    if (choice == 1) {
        int x;
        cout << "Enter the left child of " << (*T)->data << ": ";
        cin >> x;
        node *p = MakeNode(x);
        (*T)->left = p;
        createTree(&p);
    }
    cout << "Wheather the right of " << (*T)->data << " Exists? (0/1):  ";
    cin >> choice;
    if (choice == 1) {
        int x;
        cout << "Enter the right child of " << (*T)->data << ": ";
        cin >> x;
        node *p = MakeNode(x);
        (*T)->right = p;
        createTree(&p);
    }
}


int main() {
    node *T = NULL;
    int x;
    
    // Tree Creation 
    cout << "Enter the data of root node: ";
    cin >> x;
    T = MakeNode(x);
    createTree(&T);

    // BST Min and BST Max
    node* minNode = BST_Min(T);
    node* maxNode = BST_Max(T);
    
    cout << "Min: " << minNode->data << endl;
    cout << "Max: " << maxNode->data << endl;

    // Tree Insertin
    T = BST_Insert(T, 99);
    cout << "InOrder Traversal after Insertion: ";
    InOrder(T);
    cout << endl;

    // Tree Deletion
    T = BST_Delete(T, 99);
    cout << "InOrder Traversal after Deletion: ";
    InOrder(T);
    cout << endl;

    return 0;
}

/*
    OUTPUT - 1

    Enter the data of root node: 2
    Wheather the left of 2 Exists? (0/1): 1
    Enter the left child of 2: 1
    Wheather the left of 1 Exists? (0/1): 0
    Wheather the right of 1 Exists? (0/1):  0
    Wheather the right of 2 Exists? (0/1):  1
    Enter the right child of 2: 3
    Wheather the left of 3 Exists? (0/1): 0
    Wheather the right of 3 Exists? (0/1):  0
    Min: 1
    Max: 3
    InOrder Traversal after Insertion: 1, 2, 3, 99,
    InOrder Traversal after Deletion: 1, 2, 3,


    OUTPUT - 2

    
    Enter the data of root node: 5
    Wheather the left of 5 Exists? (0/1): 1
    Enter the left child of 5: 4
    Wheather the left of 4 Exists? (0/1): 1
    Enter the left child of 4: 1
    Wheather the left of 1 Exists? (0/1): 0
    Wheather the right of 1 Exists? (0/1):  0
    Wheather the right of 4 Exists? (0/1):  1
    Enter the right child of 4: 8
    Wheather the left of 8 Exists? (0/1): 0
    Wheather the right of 8 Exists? (0/1):  0
    Wheather the right of 5 Exists? (0/1):  1
    Enter the right child of 5: 10
    Wheather the left of 10 Exists? (0/1): 0
    Wheather the right of 10 Exists? (0/1):  0
    Min: 1
    Max: 10
    InOrder Traversal after Insertion: 1, 4, 8, 5, 10, 99,
    InOrder Traversal after Deletion: 1, 4, 8, 5, 10,
*/