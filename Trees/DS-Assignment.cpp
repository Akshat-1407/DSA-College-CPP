// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    char data;
    struct node *left;
    struct node *right;
};

node *makenode(char x)
{
    node *p;
    p = (struct node *)malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preorder(node *t)
{
    if (t != NULL)
    {
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}
void postorder(node *t)
{
    if (t != NULL)
    {
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
        char x;
        cout << "Enter the left child of " << (*T)->data << ": ";
        cin >> x;
        node *p = makenode(x);
        (*T)->left = p;
        createTree(&p);
    }
    cout << "Wheather the right of " << (*T)->data << " Exists? (0/1):  ";
    cin >> choice;
    if (choice == 1) {
        char x;
        cout << "Enter the right child of " << (*T)->data << ": ";
        cin >> x;
        node *p = makenode(x);
        (*T)->right = p;
        createTree(&p);
    }
}

int countnode(node *p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + countnode(p->left) + countnode(p->right);
}

int countleaf(node *p)
{
    if (p == NULL)
        return 0;
    else if (p->left == NULL && p->right == NULL)
        return 1;
    else
        return countleaf(p->left) + countleaf(p->right);
}

int countn2(node *p)
{
    if (p == NULL)
        return 0;
    else if (p->left == NULL && p->right == NULL)
        return 0;
    else if (p->left != NULL && p->right != NULL)
        return 1 + countn2(p->left) + countn2(p->right);
    else
        return countn2(p->left) + countn2(p->right);
}

int countn1(node *p)
{
    if (p == NULL)
        return 0;
    else if (p->left == NULL && p->right == NULL)
        return 0;
    else if (p->left != NULL && p->right != NULL)
        return countn1(p->left) + countn1(p->right);
    else
        return 1 + countn1(p->left) + countn1(p->right);
}

int height(node *p)
{
    if (p == NULL)
        return 0;
    else if (p->left == NULL && p->right == NULL)
        return 0;
    else
        return 1 + max(height(p->left), height(p->right));
}

int main()
{
    node *root = NULL;
    char root_data;

    cout << "Enter the data for the root node: ";
    cin >> root_data;
    root = makenode(root_data);

    createTree(&root);

    cout << "\n--- Traversal  ---" << endl;
    
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "\n--- Tree Properties ---" << endl;
    
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Total Number of Nodes: " << countnode(root) << endl;
    cout << "Number of Leaf Nodes with Zero Child: " << countleaf(root) << endl;
    cout << "Number of Nodes with Two children: " << countn2(root) << endl;
    cout << "Number of Nodes with One child: " << countn1(root) << endl;

    return 0;
}

/*

OUTPUT

Enter the data for the root node: A
Wheather the left of A Exists? (0/1): 1
Enter the left child of A: B
Wheather the left of B Exists? (0/1): 1
Enter the left child of B: C
Wheather the left of C Exists? (0/1): 0
Wheather the right of C Exists? (0/1):  0
Wheather the right of B Exists? (0/1):  1
Enter the right child of B: D
Wheather the left of D Exists? (0/1): 0
Wheather the right of D Exists? (0/1):  0
Wheather the right of A Exists? (0/1):  1
Enter the right child of A: E
Wheather the left of E Exists? (0/1): 0
Wheather the right of E Exists? (0/1):  0

--- Traversal  ---
Preorder Traversal: A B C D E
Inorder Traversal: C B D A E
Postorder Traversal: C D B E A

--- Tree Properties ---
Height of the tree: 2
Total Number of Nodes: 5
Number of Leaf Nodes with Zero Child: 3
Number of Nodes with Two children: 2
Number of Nodes with One child: 0

*/


