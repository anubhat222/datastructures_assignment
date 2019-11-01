#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*tail;
void insertAtBeg(int x)
{
     struct node *newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=x;
     newnode->next=NULL;
     if(tail==NULL)
     {
       tail=newnode;
       tail->next=newnode;
       return;
     }

     newnode->next=tail->next;
     tail->next=newnode;

}
void deleteAtBeg()
{
    struct node *temp=tail->next;
    if(tail==NULL)
    {
        printf("\nNO bun is present in carousel\n");
        return;
    }
    else if(tail==temp)
    {
        printf("the bun taken out is one at %d",temp->data);
        tail=0;
        free(temp);
        return;
    }
    else
    {
        printf("the bun taken out is one at %d",temp->data);
        tail->next=temp->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=tail->next;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
}
void cool()
{
    if(tail==NULL)
    {
        printf("\nthis is the first bun to be added to the carousel!\n");
        return;
    }
    struct node *temp=tail->next;
    do
    {
        temp->data-=2;
        temp=temp->next;
    }while(temp!=tail->next);
}
void deleteEnd()
{
    struct node *temp,*prev;
    temp=tail->next;
    if(tail==NULL)
    {
        printf("Sorry buns are not prepared yet!");

    }
    else if(temp->next==temp)
    {
        printf("the bun removed at temperature %d",temp->data);
         tail=0;
        free(temp);

    }
    else
    {
        while(temp->next!=tail->next)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("the coolest bun is about to avail %d",temp->data);
        prev->next=tail->next;
        tail=prev;
        free(temp);
    }

}
int main()
{
    tail=NULL;
    int choice=1,c;

    while(choice)
    {
        printf("\nenter\n1.ADD BUN to carousel\n2.take the hottest bun from carousel at extra cost\n3.take any bun(without add on charges)\n4.to check the carousel\n5.to exit from bakery\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("add the bun which is freshly prepared which is at 40 C\n");

                   cool();
                   insertAtBeg(40);
                   display();
                   break;
            case 2:printf("\nthe bun which is ready to be taken out from carousel\n");
                   deleteAtBeg();
                   break;
            case 3:deleteEnd();
                   break;
            case 4:printf("\nthe buns available on carousel!\n");
                   display();
                   break;
            case 5:printf("\n***thanks!***");
                   exit(0);
            default:printf("please enter a valid choice!");

        }
    }

}

