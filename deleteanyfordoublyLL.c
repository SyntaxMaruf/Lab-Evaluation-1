#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    char name;
    struct student *next;
    struct student *previous;
};
struct student *start = NULL;
void traverse()
{
    printf("Traverse function called.\n");
    struct student *i = start;
    while (i != NULL)
    {
        printf("%d %c\n", i->id, i->name);
        i = i->next;
    }
}
struct student *createnode()
{
    printf("Createnode function called.\n");
    int a;
    char b;
    printf("Enter id: ");
    scanf("%d", &a);
    printf("Enter name: ");
    scanf(" %c", &b);
    struct student *newnode;
    newnode = (struct student *)malloc(sizeof(struct student));
    newnode->id = a;
    newnode->name = b;
    newnode->next = NULL;
    newnode->previous = NULL;
    return newnode;
}
void insertfirst()
{
    printf("Insertfirst function called.\n");
    struct student *newnode = createnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start->previous = newnode;
        start = newnode;
    }
}
void insertany()
{
    printf("Insertany function called.\n");
    struct student *newnode = createnode();
    int search;
    printf("Enter id after which you want to insert: ");
    scanf("%d", &search);
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        struct student *i = start;
        while (i != NULL)
        {
            if (i->id == search)
            {
                newnode->previous = i;
                newnode->next = i->next;
                i->next = newnode;
                newnode->next->previous = newnode;
            }
            i = i->next;
        }
    }
}
void insertlast()
{
    printf("Insertlast function called.\n");
    struct student *newnode = createnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        struct student *i = start;
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = newnode;
        newnode->previous = i;
    }
}
void deletefirst()
{
    if (start == NULL)
    {
        printf("Underflow.\n");
    }
    else
    {
        start = start->next;
        start->previous = NULL;
    }
}
void deleteany()
{
    int search;
    printf("Enter the id which you want to delete: ");
    scanf("%d", &search);
    if (start == NULL)
    {
        printf("Underflow.\n");
    }
    else if (start->id == search)
    {
        start = start->next;
        start->previous = NULL;
    }
    else
    {
        struct student *i = start;
        while (i != NULL)
        {
            if (i->next->id == search)
            {
                if (i->next->next == NULL)
                {
                    i->next = NULL;
                }
                else
                {
                    i->next->next->previous = i;
                    i->next = i->next->next;
                    break;
                }
            }
            i = i->next;
        }
    }
}
void deletelast()
{
    if (start == NULL)
    {
        printf("Underflow.\n");
    }
    else if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        struct student *i = start;
        while (i->next->next != NULL)
        {
            i = i->next;
        }
        i->next = NULL;
    }
}
int main()
{
    insertlast();
    insertlast();
    insertlast();
    traverse();
    deleteany();
    traverse();
    return 0;
}
