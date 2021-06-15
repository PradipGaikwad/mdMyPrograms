// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node {
    int data;
    Node* left;
    Node* right;
};

#define SPACE 10


void print2D(Node * r, int space);
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int height(Node *root) 
{
    if(!root) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return std::max(lh,rh) + 1;
}
/* Function to insert element in binary tree */
Node *left_rotate(Node *root) {
    Node *newroot = root->right;
    Node *newroot_left = newroot->left;
    newroot->left = root;
    root->right = newroot_left;
    return newroot;
}
Node *right_rotate(Node *root) {
    Node *newroot = root->left;
    Node *newroot_right = newroot->right;
    newroot->right = root;
    root->left = newroot_right;
    return newroot;
}
Node* _InsertNode(Node* root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }

    if(root->data > data) root->left = _InsertNode(root->left, data);
    else if(root->data < data) root->right =  _InsertNode(root->right, data);
    else 
        return root;
   
    int bal = height(root->left) - height(root->right);
   
    //right right inb
    if (bal < -1 && data > root->right->data) {
        return left_rotate(root);
    }
    // right left inb
    if(bal < -1 && data < root->right->data) {
          root->right =  right_rotate(root->right);
          return left_rotate(root);

    }

    //left left inb
    if(bal > 1 && data < root->left->data) {
        return right_rotate(root);
    }
    //Left right inb
    if(bal > 1 && data > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    return root;

}
Node* InsertNode(Node* root, int data) {
    printf("============= INSERTING %d =================\n", data);
    print2D(root, 5);
    printf("---------------");
    Node *tmp = _InsertNode(root, data);
    print2D(tmp, 5);
    return tmp;
}
/* Inorder traversal of a binary tree */

void inorder(Node* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}


/* Function to create a new node */
void _print2D(Node * r, int space) {
    if (r == NULL) // Base case  1
        return;
    space += SPACE; // Increase distance between levels   2
    _print2D(r->right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
        cout << " "; // 5.1  
    cout << r->data << "\n"; // 6
    _print2D(r->left, space); // Process left child  7
}
void print2D(Node * r, int space) {
    _print2D(r, space);
}
// Driver code
int main()
{
    Node* root = CreateNode(10);

    root = InsertNode(root, 5);
    root = InsertNode(root, 8);
    root = InsertNode(root, 9);
    root = InsertNode(root, 7);
    root = InsertNode(root, 11);
    root = InsertNode(root, 12);
    root = InsertNode(root, 13);
    root = InsertNode(root, 14);
    root = InsertNode(root, 15);
    root = InsertNode(root, 16);
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;


    print2D(root, 5);
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
    return 0;
}

