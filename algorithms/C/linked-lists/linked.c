#include <stdio.h>
#include <stdlib.h>



//most of the operations in linked list
struct node
{
    int data;
    struct node *next;
} *head = NULL, *head2 = NULL, *third = NULL;

//creating linkedList
void create(int a[], int n)
{
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void create2(int b[], int n)
{
    struct node *t, *last;
    head2 = (struct node *)malloc(sizeof(struct node));
    head2->data = b[0];
    head2->next = NULL;
    last = head2;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = b[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

//displaying linked list by loop
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

//displaying linked list by recursion
void rdisplay(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

//displaying linked list in reverse by recursion
void reversedisplay(struct node *p)
{
    if (p != NULL)
    {
        reversedisplay(p->next);
        printf("%d ", p->data);
    }
}

//counting nodes
int node_count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//counting nodes by recursion
int rnode_count(struct node *p)
{
    if (p == NULL)
        return 0;
    return rnode_count(p->next) + 1;
}

//sum of elements in a linked list
int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//sum of elements using recursion
int rsum(struct node *p)
{
    if (p == 0)
        return 0;
    return rsum(p->next) + p->data;
}

//mult of elements
int mult(struct node *p)
{
    int mult = 1;
    while (p != NULL)
    {
        mult *= p->data;
        p = p->next;
    }
    return mult;
}

//max element in linked list
int max(struct node *p)
{
    int max = -65536;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

//max element by recursion
int rmax(struct node *p)
{
    int x;

    if (p == NULL)
        return 0;
    x = rmax(p->next);
    return x > p->data ? x : p->data;
}

//linear search in linked list
struct node *linear(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

//linear search by recursion
struct node *rlinear(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return rlinear(p->next, key);
}

//linear search by moving head
struct node *linear_move(struct node *p, int key)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

//inserting elements to linked list
void insert(struct node *p, int index, int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index < 0 || index > node_count(p))
        return;
    if (index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

//deleting an element
int delete_node(struct node *p, int index)
{
    struct node *q = NULL;
    int x = -1;

    if (index < 1 || index > node_count(p))
        return -1;
    if (index == 1)
    {
        q = head;
        x = head->data;
        head = head->next;
        free(q);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

//checking if linked list is sorted or not
//only for sorted linked list
int ifsorted(struct node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

//deleting duplicate elemnts in sorted linked list
void delete_duplicate(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

//deleting duplicates in unsorted linked List
int unsort_deleting(struct node *f)
{
    struct node *p = f;
    while (p != NULL)
    {
        struct node *q = p->next;
        struct node *t = p;
        while (q != NULL)
        {
            if (p->data == q->data)
            {
                t->next = q->next;
                free(q);
                q = t->next;
            }
            else
            {
                q = q->next;
                t = t->next;
            }
        }
        p = p->next;
    }
}

//reversing a linked list

//reversing using swapping of elements
void reverse_element(struct node *p)
{
    int *a, i;
    a = (int *)malloc(node_count(p) * sizeof(int));
    while (p != NULL)
    {
        a[i++] = p->data;
        p = p->next;
    }
    p = head;
    i--;
    while (p != NULL)
    {
        p->data = a[i--];
        p = p->next;
    }
}

//reversing by changing links
void reverse_link(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

//reversing by recursion
void reverse_recursion(struct node *q, struct node *p)
{
    if (p != NULL)
    {
        reverse_recursion(p, p->next);
        p->next = q;
    }
    else
    {
        head = q;
    }
}

//concatinating linked list
void concat(struct node *p, struct node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

//merging two sorted linked list

int merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = q;
    else
        last->next = q;
}

//checking wheather linked list contains a loop
int if_loop(struct node *f)
{
    struct node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : q;
    } while (p != NULL && q != NULL && p != q);

    if (p == q)
        return 1;
    else
        return 0;
}

//checking the lenght of loop in linked List

int looplenght(struct node *q)
{
    struct node *temp = q;
    int rev = 1;
    while (temp->next != q)
    {
        rev++;
        temp = temp->next;
    }
    return rev;
}

int if_loop_2(struct node *f)
{
    struct node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
            q = q->next;
    } while (p && q && p != q);
    if (p == q)
        return looplenght(p);
    return 0;
}

int main()
{
    struct node *t1, *t2;
    int a[4] = {3, 4, 5, 6};
    int n = sizeof(a);
    create2(a, n);

    /*  making loop in linked list
    t1 = head->next;
    t2 = head->next->next->next;
    t2->next = t1; */

    display(head);
}
