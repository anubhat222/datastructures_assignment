#include<stdio.h>
char p[6]= {"GANDHI"};
void main()
{

sort();
}
void sort()
{
    int i,j;
    char temp;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i;j++)
        {
            if(p[j]>p[j+1])
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=0;i<6;i++)
    {
      printf("%c\t\t%d\n\n",p[i],(int)p[i]);
    }
}
