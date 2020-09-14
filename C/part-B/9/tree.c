#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d", &x);

    if (x == -1)
        return NULL;

    p = (node *)malloc(sizeof(node));
    p->data = x;

    printf("Enter left child of %d:\n", x);
    p->left = create();

    printf("Enter right child of %d:\n", x);
    p->right = create();

    return p;
}

void preorder(node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postOrder(node *t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d ", t->data);
    }
}

void inorder(node *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
int main()
{
    node *root;
    root = create();
    printf("\nThe preorder traversal of tree is:\n");
    preorder(root);
    printf("\n");
    printf("\nThe postorder traversal of tree is:\n");
    postOrder(root);
    printf("\n");
    printf("\nThe inorder traversal of tree is: \n");
    inorder(root);
    printf("\n");
    return 0;
}
