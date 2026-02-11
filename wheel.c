#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* cy(char source[],char key[]);
void de(char c[],char key[]);


char* cy(char source[],char key[])
{
    do
    {
        printf("enter your con: ");
    scanf("%s",source);
    printf("enter your key: ");
    scanf("%s",key);
    printf("the length of your con is : %ld\n",strlen(source));
    printf("the length of your key is : %ld\n",strlen(key));
    }while(strlen(source)>strlen(key));

    char* c =(char*)malloc(sizeof(char)*strlen(source));
    for(int i=0;i<strlen(source);i++)
    {
        if((source[i]+key[i])>127)
        {
            c[i]=source[i]+key[i]-127;
        }
        else
        {
            c[i]=source[i]+key[i];
        }
    }
    printf("the con is: %s\n",c);
    return c;
}


void de(char c[],char key[])
{
    do
    {
        printf("enter your key: ");
        scanf("%s",key);
    }while(strlen(key)<strlen(c));
    char* source =(char*)malloc(sizeof(char)*strlen(c));
    for(int j=0;j<strlen(c);j++)
    {
        if((c[j]-key[j])<0)
        {
            source[j]=c[j]-key[j]+127;
        }
        else
        {
            source[j]=c[j]-key[j];
        }
    }
    printf("%s\n",source);
}


int main()
{
    char source[100];
    char key [100];
    de(cy(source,key),key);
}