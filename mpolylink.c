#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *link;
};

struct node *p1 = NULL, *p2 = NULL, *p3 = NULL;

struct node* makeNode(int c, int e)
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->coeff = c;
    n->exp = e;
    n->link = NULL;
    return n;
}

struct node* insertSorted(struct node *head, int c, int e)
{
    struct node *temp = NULL, *curr = head, *n;

    while (curr != NULL && curr->exp > e)
    {
        temp = curr;
        curr = curr->link;
    }

    if (curr != NULL && curr->exp == e)
    {
        curr->coeff += c;
        return head;
    }

    n = makeNode(c, e);
    n->link = curr;

    if (temp == NULL)
        return n;

    temp->link = n;
    return head;
}

void append(int c, int e)
{
    struct node *n = makeNode(c, e), *temp;

    if (p3 == NULL)
        p3 = n;
    else
    {
        temp = p3;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = n;
    }
}

struct node* create()
{
    struct node *head = NULL;
    int n, i, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter coefficient and exponent of term %d: ", i);
        scanf("%d %d", &c, &e);
        head = insertSorted(head, c, e);
    }

    printf("Polynomial created successfully\n");
    return head;
}

void add()
{
    struct node *t1 = p1, *t2 = p2;

    if (p1 == NULL || p2 == NULL)
    {
        printf("Please create both polynomials first\n");
        return;
    }

    p3 = NULL;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp == t2->exp)
        {
            append(t1->coeff + t2->coeff, t1->exp);
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->exp > t2->exp)
        {
            append(t1->coeff, t1->exp);
            t1 = t1->link;
        }
        else
        {
            append(t2->coeff, t2->exp);
            t2 = t2->link;
        }
    }

    while (t1 != NULL)
    {
        append(t1->coeff, t1->exp);
        t1 = t1->link;
    }

    while (t2 != NULL)
    {
        append(t2->coeff, t2->exp);
        t2 = t2->link;
    }

    printf("Polynomial addition completed\n");
}

void display()
{
    struct node *temp = p3;

    if (temp == NULL)
    {
        printf("Result is empty\n");
        return;
    }

    printf("Resultant Polynomial: ");

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->link != NULL)
            printf(" + ");

        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Add Polynomials\n");
        printf("4. Display Result\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            p1 = create();
        else if (choice == 2)
            p2 = create();
        else if (choice == 3)
            add();
        else if (choice == 4)
            display();
        else if (choice == 5)
            printf("Program terminated\n");
        else
            printf("Invalid choice\n");

    } while (choice != 5);

    return 0;
}
