#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void printLinekdList(node *root)
{
    while (root)
    {
        printf(" %d -> ", root->data);
        root = root->next;
    }
}

int main()
{
    node *root, *second, *third;

    root = new node;
    second = new node;
    third = new node;

    root->data = 10;
    root->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printLinekdList(root);
}