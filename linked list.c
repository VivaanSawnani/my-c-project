#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    if(!head||!second||!third)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

    temp=head;
    while(temp!=NULL)
    {
        struct Node *next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;

};