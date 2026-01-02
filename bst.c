#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node* left;
    struct node* right;
    int data;
};
struct node* root =NULL;
struct node* insert(struct node* ROOT,int data);
int isbst(struct node* ROOT,int min,int max);
void print(struct node* ROOT);
int main()
{
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,6);
    int x=isbst(root,-100,100);
    if(x==1)
    printf("yes");
    else
    printf("np");
    print(root);
}

struct node* insert(struct node* ROOT,int data)
{
    if(ROOT==NULL)
    {
        struct node*temp=(struct node*)malloc(sizeof(struct node));
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        ROOT = temp;
    }
    else if(data<ROOT->data)
    {
        ROOT->left=insert(ROOT->left,data);
    }
    else {
        ROOT->right=insert(ROOT->right,data);
    }
    return ROOT;
}
void print(struct node* ROOT)
{
    if(ROOT==NULL)
    {
        return;
    }
    print(ROOT->left);
    printf("%d",ROOT->data);
    print(ROOT->right);
}


int isbst(struct node* ROOT,int min,int max)
{
    if(ROOT==NULL)
    return 1;
    if((ROOT->data>min)&&(ROOT->data<max)&&isbst(ROOT->left,min,ROOT->data)&&isbst(ROOT->right,ROOT->data,max))
    return 1;
    else
    return 0;
}
