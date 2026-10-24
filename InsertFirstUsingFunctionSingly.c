#include<stdio.h>
#include<stdlib.h>
struct student 
{
    int id;
    char name;
    struct student *next;
};
struct student *start=NULL;
void traverse()
{
    printf("Traverse function called\n");
    struct student *i=start;
    while(i!=NULL)
    {
        printf("%d %c\n", i->id, i->name);
        i=i->next;
    }
}
struct student *createnode()
{
    printf("Createnode function called\n");
    int a;
    char b;
    printf("Enter id: ");
    scanf("%d",&a);
    printf("Enter name: ");
    scanf(" %c",&b);
    struct student *newnode;
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->id=a;
    newnode->name=b;
    newnode->next=NULL;
    return newnode;
}
void insertfirst()
{
    printf("Insertfirst function called\n");
    struct student *newnode=createnode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
int main()
{
    insertfirst();
    insertfirst();
    insertfirst();
    traverse();  
}
