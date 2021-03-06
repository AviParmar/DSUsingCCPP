#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};
struct Node *head = NULL;
void insert(int coeff, int pow)
{
    struct Node *link = (struct Node *)(malloc(sizeof(struct Node)));
    link->coeff = coeff;
    link->pow = pow;
    if (head == NULL)
    {
        link->next = NULL;
        head = link;
    }
    else
    {
        if (pow > head->pow)
        {
            link->next = head;
            head = link;
        }
        else
        {
            struct Node *temp = head;
            while (temp->next && (temp->next->pow > pow))
                temp = temp->next;
            link->next = temp->next;
            temp->next = link;
        }
    }
}
void print()
{
    struct Node *temp = head;
    while (temp->next)
    {
        printf("%dx^%d+", temp->coeff, temp->pow);
        temp = temp->next;
    }
    printf("%dx^%d=0", temp->coeff, temp->pow);
}
int main()
{
    insert(70, 7);
    insert(50, 5);
    insert(20, 2);
    insert(10, 1);
    insert(80, 8);
    insert(60, 6);
    insert(30, 3);
    insert(40, 4);
    print();
    return 0;
}
