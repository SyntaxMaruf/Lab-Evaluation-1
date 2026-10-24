#include<stdio.h>
#include<stdlib.h>
struct student 
{
    int id;
    char name;
    struct student *next; 
    struct student *previous;
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
    newnode->previous=NULL;
    return newnode;
}
void insertlast()
{
    printf("Insertlast function called\n");
    struct student *newnode=createnode();
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        struct student *i=start;
        while(i->next!=NULL)
        {
            i=i->next;
        }
        i->next=newnode;
        newnode->previous=i;
    }
}
void insertany()
{
    printf("Insertany function called\n");
    struct student *newnode=createnode();
    int search;
    printf("Enter previous node's id: ");
    scanf("%d",&search);
     
        if(start==NULL)
        {
            start=newnode;
        }
        else
        { struct student *i=start; while(i!=NULL)
            {
                if(i->id==search)
                { 
                    newnode ->previous=i;
                    newnode->next=i->next;
                    i->next=newnode;
                    newnode->next->previous=newnode;
                     
                }
                i=i->next;
            }
            
        }
    
     
}
int main()
{
    insertlast();
    insertlast();
    insertlast();
    traverse();
    insertany();
    traverse();
    return 0;
}