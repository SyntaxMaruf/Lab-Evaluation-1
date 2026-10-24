#include <stdio.h>
#include <stdlib.h>
struct student
{
    int id;
    char name;
    struct student *next;
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
    printf("Crearnode function called.\n");
    int a;
    char b;
    printf("Enter the id: ");
    scanf("%d", &a);
    printf("Enter the name: ");
    scanf(" %c", &b);
    struct student *newnode;
    newnode = (struct student *)malloc(sizeof(struct student));
    newnode->id = a;
    newnode->name = b;
    newnode->next = NULL;
    return newnode;
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
    }
}
void deleteany()
{
    int search;
    printf("Enter the id which you want to delete: ");
    scanf("%d", &search);
    if(start == NULL)
    {
        printf("Underflow.\n");
    }
    else if(start->id == search)
    {
        start = start->next;
    }
    else
    {
        struct student *i = start;
        while(i != NULL)
        {
            if(i->next->id == search)
            {
                if(i->next->next == NULL)
                {
                    i->next = NULL;
                }
                else
                {
                    i->next = i->next->next;
                    break;
                }
            }
            i = i->next;
        }
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



