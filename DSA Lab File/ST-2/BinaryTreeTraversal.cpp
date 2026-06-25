// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

node *makenode(int x) {
    node *p;
    p = (struct node *)malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preorder(node *t) {
    if (t != NULL) {
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t) {
    if (t != NULL) {
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}
void postorder(node *t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }
}

void createTree(node **T){
    int choice;
    cout << "Wheather the left of " << (*T)->data << " Exists? (0/1): ";
    cin >> choice;
    if (choice == 1) {
        int x;
        cout << "Enter the left child of " << (*T)->data << ": ";
        cin >> x;
        node *p = makenode(x);
        (*T)->left = p;
        createTree(&p);
    }
    cout << "Wheather the right of " << (*T)->data << " Exists? (0/1):  ";
    cin >> choice;
    if (choice == 1) {
        int x;
        cout << "Enter the right child of " << (*T)->data << ": ";
        cin >> x;
        node *p = makenode(x);
        (*T)->right = p;
        createTree(&p);
    }
}

int main() {
    node *root = NULL;
    int root_data;

    cout << "Enter the data for the Root node: ";
    cin >> root_data;
    root = makenode(root_data);

    createTree(&root);
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
}

/*
    OUTPUT - 1

    Enter the data for the Root node: 5
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
    Preorder: 5 4 1 8 10
    Inorder: 1 4 8 5 10
    Postorder: 1 8 4 10 5

    OUTPUT - 2

    Enter the data for the Root node: 1
    Wheather the left of 1 Exists? (0/1): 1
    Enter the left child of 1: 2
    Wheather the left of 2 Exists? (0/1): 0
    Wheather the right of 2 Exists? (0/1):  0
    Wheather the right of 1 Exists? (0/1):  1
    Enter the right child of 1: 3
    Wheather the left of 3 Exists? (0/1): 0
    Wheather the right of 3 Exists? (0/1):  0
    Preorder: 1 2 3 
    Inorder: 2 1 3 
    Postorder: 2 3 1 
*/