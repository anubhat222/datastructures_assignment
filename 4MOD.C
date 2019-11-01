#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*tail;
void insertend(char x)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
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
tail=newnode;
}
void display()
{
    struct node *temp;
    temp=tail->next;
    do
    {
        printf("%c",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    /*for(int i=0;i<20;i++)
    {
        printf("%c",temp->data);
        temp=temp->next;
    }*/

}
void rearr()
{
    struct node *pri,*high,*temp,*temp1;
    pri=high=tail->next;
    while((int)high->data>=96&&high)
    {
        high=high->next;
    }
    tail->next=pri;
   do
   {
       temp=high->next;
       high->next=pri->next;
       pri->next=high;
       pri=high->next;
       temp1=pri;
       while((temp1->next)!=high)
       {
           temp1=temp1->next;
       }
       temp1->next=temp;
       high=temp;
   }while(high!=tail->next&&pri!=tail->next);


}
int main()
{
    tail=NULL;
    insertend('a');
    insertend('b');
    insertend('c');
    insertend('d');
    insertend('e');
    insertend('A');
    insertend('B');
    insertend('C');
    insertend('D');
    insertend('E');
    display();
    rearr();
    printf("\nAfter principal's opinion\n");
    display();
}
