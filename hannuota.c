#include<stdio.h>
void hannuota(int n,char start,char end,char transition);
int main()
{
    int n;
    scanf("%d",&n);
    
    hannuota(n,'a','b','c');
}

void hannuota(int n,char start,char end,char transition)
{
    if(n==1)
    {
        printf("%c -> %c\n",start,end);
        return;
    }
    hannuota(n-1,start,transition,end);
    printf("%c -> %c\n",start,end);
    hannuota(n-1,transition,end,start);

}