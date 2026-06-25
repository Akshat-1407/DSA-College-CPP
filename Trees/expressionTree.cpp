// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>

// using namespace std;

// struct node {
//     char data;
//     struct node* left;
//     struct node* right;
//     struct node* next;
// };

// struct node* start = NULL;
// char op_stack[20];
// int top = -1;

// struct node* makeNode(char x) {
//     struct node* p = (struct node*)malloc(sizeof(struct node));
//     if (p == NULL) {
//         cerr << "Memory allocation failed!\n";
//         exit(EXIT_FAILURE);
//     }
//     p->data = x;
//     p->left = NULL;
//     p->right = NULL;
//     p->next = NULL;
//     return p;
// }

// void push_opnd_stack(struct node* y) {
//     y->next = start;
//     start = y;
// }

// struct node* pop_opnd_stack() {
//     struct node* p = start;
//     if (start != NULL) {
//         start = start->next;
//     }
//     return p;
// }

// void push_op_stack(char symb) {
//     if (top < 19) {
//         op_stack[++top] = symb;
//     }
// }

// char pop_op_stack() {
//     if (top >= 0) {
//         return op_stack[top--];
//     }
//     return '\0';
// }

// int is_empty_op_stack() {
//     return top == -1;
// }

// char top_op_stack() {
//     if (top >= 0) {
//         return op_stack[top];
//     }
//     return '\0';
// }

// int precedence(char a, char b) {
//     if (a == '^') {
//         if (b == '^') {
//             return 0;
//         } else {
//             return 1;
//         }
//     }
//     if (a == '*' || a == '/' || a == '%') {
//         if (b == '+' || b == '-' || b == '*' || b == '/' || b == '%') {
//             return 1;
//         } else {
//             return 0;
//         }
//     }
//     if (a == '+' || a == '-') {
//         if (b == '+' || b == '-') {
//             return 1;
//         } else {
//             return 0;
//         }
//     }
//     return 0;
// }

// struct node* buildExpressionTree(char* exp) {
//     int i = 0;
//     char symb;
//     struct node *x, *y, *p, *q;
//     char op;

//     while (exp[i] != '\0') {
//         symb = exp[i];
//         i++;

//         if ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z') || (symb >= '0' && symb <= '9')) {
//             x = makeNode(symb);
//             push_opnd_stack(x);
//         } else {
//             while (!is_empty_op_stack() && precedence(top_op_stack(), symb)) {
//                 op = pop_op_stack();
//                 y = makeNode(op);

//                 p = pop_opnd_stack();
//                 q = pop_opnd_stack();

//                 y->right = p;
//                 y->left = q;

//                 push_opnd_stack(y);
//             }
//             push_op_stack(symb);
//         }
//     }

//     while (!is_empty_op_stack()) {
//         op = pop_op_stack();
//         y = makeNode(op);

//         p = pop_opnd_stack();
//         q = pop_opnd_stack();

//         y->right = p;
//         y->left = q;

//         push_opnd_stack(y);
//     }

//     return start;
// }

// void preOrderTraversal(struct node* T) {
//     if (T != NULL) {
//         cout << T->data;
//         preOrderTraversal(T->left);
//         preOrderTraversal(T->right);
//     }
// }

// void inOrderTraversal(struct node* T) {
//     if (T != NULL) {
//         inOrderTraversal(T->left);
//         cout << T->data;
//         inOrderTraversal(T->right);
//     }
// }

// void postOrderTraversal(struct node* T) {
//     if (T != NULL) {
//         postOrderTraversal(T->left);
//         postOrderTraversal(T->right);
//         cout << T->data;
//     }
// }

// int main() {
//     char expression[20];
//     struct node* T;

//     cout << "Input the expression: ";
//     cin >> expression;

//     T = buildExpressionTree(expression);

//     cout << "Prefix expression: ";
//     preOrderTraversal(T);
//     cout << "\n";

//     cout << "Infix expression: ";
//     inOrderTraversal(T);
//     cout << "\n";

//     cout << "Postfix expression: ";
//     postOrderTraversal(T);
//     cout << "\n";

//     return 0;
// }

