#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void insect(int data);
void printlinklist();
struct node* HEAD =NULL;
int main()
{
    insect(3);
    insect(5);
    insect(6);
    insect(9);
    printlinklist();
}

void insect(int data)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=data;
    if(HEAD==NULL)
    {
        HEAD=temp;
        return;
    }
    struct node* track =HEAD;
    while(track->next!=NULL)
    {
        track=track->next;
    }
    track->next=temp;
}

void printlinklist()
{
    struct node* track=HEAD;
    while(track!=NULL)
    {
        printf("%d ",track->data);
        track=track->next;
    }
}
