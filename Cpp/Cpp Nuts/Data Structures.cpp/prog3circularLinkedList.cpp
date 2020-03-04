#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node *addToEmpty(struct node *last, int data)
{
    if (last != NULL)
        return last;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // struct node *temp = new node;

    temp->data = data;
    last = temp;
    last->next = last;
    return last;
}

struct node *addEnd(struct node *last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

void traverse(struct node *first)
{
    struct node *tmp = first;

    if (first != NULL)
    {
        do
        {
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        } while (tmp != first);
    }
}

int main()
{
    struct node *last = NULL;
    last = addToEmpty(last, 6);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    traverse(last->next);
    return 0;
}