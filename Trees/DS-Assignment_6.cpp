// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};

node *makenode(int x)
{
    node *p;
    p = (struct node *)malloc(sizeof(node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void inorder(node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        cout << t->data << ",";
        inorder(t->right);
    }
}

node *BSTinsertion(node *t, int x)
{
    node *p = t, *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (x < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    if (q == NULL)
    {
        t = makenode(x);
    }
    else
    {
        if (x < q->data)
        {
            q->left = makenode(x);
        }
        else
        {
            q->right = makenode(x);
        }
    }
}

node *BSTmin(node *t)
{
    while (t->left != NULL)
    {
        t = t->left;
    }
    cout << t->data;
}
node *BSTmax(node *t)
{
    while (t->right != NULL)
    {
        t = t->right;
    }
    cout << t->data;
}

node *BSTsuccessor(node *p)
{
    node *q;
    if (p->right != NULL)
        return BSTmin(p->right);
    else
    {
        q = p->father;
        while (q != NULL && q->right == p)
        {
            p = q;
            q = q->father;
        }
    }
    cout << q << " ";
}

node *BSTpredecessor(node *p)
{
    node *q;
    if (p->left != NULL)
        return BSTmin(p->left);
    else
    {
        q = p->father;
        while (q != NULL && q->left == p)
        {
            p = q;
            q = q->father;
        }
    }
    cout << q << " ";
}

bool Isleft(node *p)
{
    if (p->father->left == p)
        return true;
    else
        return false;
}

bool Isright(node *p)
{
    if (p->father->right == p)
        return true;
    else
        return false;
}

int BSTdeletion(node *p)
{
    node *q;
    int y = p->data;
    if (p->left == NULL && p->right == NULL)
    {
        if (Isleft(p))
            p->father->left = NULL;
        else
            p->father->right = NULL;
    }
    else if (p->left == NULL || p->right == NULL)
    {
        if (p->left == NULL)
            q = p->right;
        else
            q = p->left;
        node *r = p->father;
        if (Isleft(p))
            p->father->left = q;
        else
            p->father->right = q;
        q->father = r;
    }
    else
    {
        q = BSTsuccessor(p);
        int x = BSTdeletion(q);
        p->data = x;
        p = q;
    }
    delete (p);
    return y;
}


int main()
{
    node *root = NULL;
    root = BSTinsertion(root, 100);
    BSTinsertion(root, 150);
    BSTinsertion(root, 120);
    BSTinsertion(root, 200);
    BSTinsertion(root, 300);
    BSTinsertion(root, 175);
    BSTinsertion(root, 160);
    BSTinsertion(root, 70);
    BSTinsertion(root, 20);
    BSTinsertion(root, 10);
    BSTinsertion(root, 60);
    BSTinsertion(root, 15);
    BSTinsertion(root, 45);
    cout << "Traversal of nodes :" << endl;
    inorder(root);
    cout << endl;
    cout << "Min :  ";
    BSTmin(root);
    cout << endl;
    cout << "Max : ";
    BSTmax(root);
    cout << endl;
    cout << "Successor: ";
    BSTsuccessor(root->left->left);
    cout << endl;
    cout << "Predecessor: ";
    BSTpredecessor(root->left->left);
    cout << endl;
    cout << "Delete Node : ";
    BSTdeletion(root->left->left);
}

/*

OUTPUT

Traversal of nodes :
10,15,20,45,60,70,100,120,150,160,175,200,300,
Min :  10
Max : 300
Successor: 45
Predecessor: 10
Delete Node : 45

*/
