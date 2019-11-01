#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* create(int );
void insert(struct Node ** ,int );
void show(struct Node * );
void seggregate(struct Node ** );
struct Node* create(int value)
{
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));

if(newnode)
{
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}
else
{
    return NULL;
}
};
void insert(struct Node **root,int value)
{
    if(*root==NULL)
    {
        *root=create(value);
    }
    else
    {
        struct Node *temp=*root;
        while(temp!=NULL&&temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=create(value);
    }
}
void show(struct Node *temp)
{
    if(temp==NULL)
    {
        printf("Empty!");
    }
    else
    {
    while(temp)
    {
    printf("%d",temp->data);
    temp=temp->next;
    }
    }
}
void seggregate(struct Node **root)
{
    if(*root!=NULL)
    {
     struct Node *even=NULL,*odd=NULL,*hold=NULL;
     struct Node *temp=*root;
    *root=NULL;
    while(temp!=NULL){
    if((temp->data%2)!=0)
    {
        if(*root==NULL)
        {
            *root=temp;
        }
       if(odd==NULL)
       {
           odd=temp;
       }
       else
       {
           odd->next=temp;
           temp->prev=odd;
           odd=odd->next;
       }
    }
   else
   {
       if(even==NULL)
       {
           even=temp;
           hold=temp;
       }
       else
       {
           even->next=temp;
           temp->prev=even;
           even=even->next;
       }
   }
   temp=temp->next;
}
if(odd!=NULL)
{
    odd->next=hold;
}
if(*root==NULL)
{
    *root=hold;
}
if(even!=NULL)
{
    even->next=NULL;
}
}
else
{
    printf("empty list!");
}
}
int main()
{
    struct Node *root=NULL;
    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,3);
    insert(&root,4);
    printf("before:\n");
    show(root);
    seggregate(&root);
    printf("after modification:");
    show(root);
}



