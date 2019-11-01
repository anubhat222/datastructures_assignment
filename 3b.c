#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void insert(char x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;

    if(head==NULL)
    {
       head=temp;
       return;
    }
    struct node *a;
    a=head;
    while(a->next!=NULL)
        a=a->next;
    a->next=temp;
}
void print()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%c\t",temp->data);
        temp=temp->next;
    }

}
void sort()
{
    int i;
do{

       i=0;
      char temp;
       struct node *cur=head,*abc=NULL;

        while(cur->next!=abc)
        {
            if((cur->data)>(cur->next->data))
            {
                  temp=cur->data;
                  cur->data=cur->next->data;
                  cur->next->data=temp;
                  i=1;

            }
            cur=cur->next;
        }
     abc=cur;

}while(i);
}
void main()
{
    head=NULL;
    insert('G');
    insert('A');
    insert('N');
    insert('D');
    insert('H');
    insert('I');
    print();
    sort();
    printf("\n");
    print();
}
