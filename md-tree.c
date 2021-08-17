// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
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

void leftv(Node *root, int *val, int level) {

    if(!root) return;

    if(*val <= level){
        //printf("%d:%d:%d ", root->data, *val, level);
        printf("%d->\n", root->data);
        *val +=1;
    }
    leftv(root->right, val, level+1);
    leftv(root->left, val, level+1);
}

map<int, int> mp;

void topv(Node *root, int level) {
    
    if (!root) return;

    topv(root->left, level - 1);
    mp[level] = root->data;
    printf("%d:%d->", root->data, level);
    topv(root->right, level + 1);
}

void topv1(Node *root) {

    if(!root) return;
    topv (root, 0);

}

void moris(Node *root) {

    stack<Node *> st;
    Node *cur;
    
    while (root || !st.empty()) {
        
        while(root) {
            st.push(root);
            root = root->left;
        }
        
        root = st.top();
        st.pop();
        printf("%d-> \n", root->data);
        
        root = root->right;

    }
}
int findmin(Node *root) {
    while(root->left) root = root->left;
    return root->data;
}

void root_to_leaf_sum(Node* root, int sum, int *v1, int idx) {
    if(!root) return;

    v1[idx] = root->data;
    sum -= root->data;
    if(sum==0 && !root->left && !root->right) {
        for (int i=0; i<= idx; i++ ) printf("%d -> ", v1[i]);
        printf("\n");
        return;
    }

    root_to_leaf_sum(root->left, sum, v1, idx+1);
    root_to_leaf_sum(root->right, sum, v1, idx+1);

}
void find_ancsuc (Node *root, int *anc, int *suc, int key) {

    if(!root) return;

    if(root->data == key) {
        if (root->left) {
            *anc = findmin (root->left);
        }

        if(root->right) {
            *suc = findmin(root->right);
        }
        return;
    }
    
    if(key < root->data) {
        *suc = root->data;
        find_ancsuc(root->left, anc, suc, key);
    }
    if(key > root->data) {
        *anc = root->data;
        find_ancsuc(root->right, anc, suc, key);
    }

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
    int val = 0, level = 0;

    printf("left view \n");
    leftv(root, &val, level);

    printf("top view \n");
    topv1(root);

    printf("\nFake Moris \n");
    moris(root);
    
    int n = 16;
    printf("\n find ancister and successor %d\n", n );
    int anc = 0, suc = 0;
    find_ancsuc(root, &anc, &suc, n);
    printf("%d: %d : %d \n", anc, n, suc);
    n=41;
    printf("root to leaf sum %d \n", n);
    int v1[10];
    root_to_leaf_sum(root, n, v1, 0);
    return 0;
}

