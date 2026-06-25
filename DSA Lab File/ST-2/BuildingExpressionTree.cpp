// AKSHAT RASTOGI       CSE 11      2400320100133

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node *left, *right;
};

Node* newNode(char x) {
    Node *p = new Node;
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

Node* createExpressionTree(string postfix) {
    stack<Node*> st;

    for (char c : postfix) {
        if (!isOperator(c)) {
            st.push(newNode(c));
        }
        else {
            Node *right = st.top(); st.pop();
            Node *left  = st.top(); st.pop();

            Node *op = newNode(c);
            op->left = left;
            op->right = right;

            st.push(op);
        }
    }
    return st.top();
}

void preorder(Node *root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    Node *root = createExpressionTree(postfix);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}

/*
    OUTPUT - 1

    Enter postfix expression: ab+
    Preorder: + a b 
    Inorder: a + b 
    Postorder: a b + 

    OUTPUT - 2

    Enter postfix expression: 82/3-
    Preorder: - / 8 2 3 
    Inorder: 8 / 2 - 3 
    Postorder: 8 2 / 3 - 
*/