// In this video we will learn about binary tree data structure.
// NOTES:
// 0. A tree whose nodes can have at most two children is called binary tree.
// 1. As there can only be two children of a node we call them left and right child.

// TYPES OF BINARY TREE:
// 0. FULL BINARY TREE / STRICTLY BINARY TREE
//    Every node must have two children, except the leaf nodes.
// 1. INCOMPLETE BINARY TREE / ALMOST COMPLETE BINARY TREE
//    Every node must have two children's in all levels except second last level and should be filled from left to right.
// 2. COMPLETE BINARY TREE / PERFECT BINARY TREE
//    Every node must have two children's in all the levels (Each level there should be 2^L where L is level)
// 3. LEFT SKEWED BINARY TREE
//    Every node should have only left children.
// 4. RIGHT SKEWED BINARY TREE
//    Every node should have only right children.

// PROGRAM
#include <iostream>
using namespace std;

struct BTnode
{
    int data;
    BTnode *left, *right;
    // Weird Constructor
    BTnode(int data) : data{data}, left{nullptr}, right{nullptr} {}
};

void print_dfs(BTnode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    print_dfs(root->left);
    print_dfs(root->right);
}

int main()
{
    // Nodes Construction
    BTnode *root = new BTnode(1);
    BTnode *left = new BTnode(2);
    BTnode *right = new BTnode(3);
    BTnode *left_left = new BTnode(4);
    BTnode *left_right = new BTnode(5);
    BTnode *right_left = new BTnode(6);
    BTnode *right_right = new BTnode(7);

    // Node connection
    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;
    right->left = right_left;
    right->right = right_right;

    // printing binary tree
    print_dfs(root);

    // delete nodes
    delete root;
    delete left;
    delete right;
    delete left_left;
    delete left_right;
    delete right_left;
    delete right_right;
    return 0;
}
