#include <stdio.h>
#include <stdlib.h>
#define null NULL
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = null;
void insert(int data)
{
    Node *link = malloc(sizeof(Node));
    link->data = data;
    if (head == null)
    {
        head = link;
    }
    else
    {
        if (data > head->data)
        {
            link->next = head;
            head = link;
        }

        else
        {
            Node *temp = head;
            while (temp->next && temp->next->data > data)
                temp = temp->next;
            link->next = temp->next;
            temp->next = link;
        }
    }
}

void display()
{
    Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(40);
    insert(30);
    display();
    return 0;
}
