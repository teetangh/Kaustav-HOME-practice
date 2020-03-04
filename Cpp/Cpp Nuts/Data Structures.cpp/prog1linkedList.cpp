#include <iostream>
using namespace std;

struct LinkedList
{
    int data;
    LinkedList *next;
};

void printLinekdList(LinkedList *root)
{
    while (root)
    {
        printf(" %d -> ", root->data);
        root = root->next;
    }
}

int main()
{
    LinkedList *root, *second, *third;

    root = new LinkedList;
    second = new LinkedList;
    third = new LinkedList;

    root->data = 10;
    root->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printLinekdList(root);
}