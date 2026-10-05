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

struct node* create()
{
    struct node *head = NULL;
    int n, i, c, e;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        head = insertSorted(head, c, e);
    }

    return head;
}

void append(int c, int e)
{
    struct node *n = makeNode(c, e);
    struct node *temp;

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

void add()
{
    struct node *t1 = p1;
    struct node *t2 = p2;

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
}

void display()
{
    struct node *temp = p3;

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
    printf("Enter first polynomial\n");
    p1 = create();

    printf("Enter second polynomial\n");
    p2 = create();

    add();

    printf("Sum of polynomials: ");
    display();

    return 0;
}
