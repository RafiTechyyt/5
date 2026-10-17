
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* insert(struct node *root, int x)
{
    if (root == NULL)
    {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->data = x;
        newnode->left = newnode->right = NULL;

        return newnode;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    else
        printf("Duplicate value not allowed\n");

    return root;
}

struct node* findMin(struct node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node *root, int x)
{
    struct node *temp;

    if (root == NULL)
        return NULL;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int countLeaf(struct node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    int choice, x;

    do
    {
        printf("\n1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Count leaf nodes\n");
        printf("4. Display BST\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &x);

                if (root == NULL)
                    printf("Tree is empty\n");
                else
                {
                    struct node *temp = root;

                    while (temp != NULL && temp->data != x)
                    {
                        if (x < temp->data)
                            temp = temp->left;
                        else
                            temp = temp->right;
                    }

                    if (temp == NULL)
                        printf("Node not found\n");
                    else
                    {
                        root = deleteNode(root, x);
                        printf("Node deleted successfully\n");
                    }
                }
                break;

            case 3:
                printf("Number of leaf nodes: %d\n",
                       countLeaf(root));
                break;

            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Inorder Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}
