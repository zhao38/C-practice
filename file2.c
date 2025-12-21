//fseek,ftell
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE* fp;
    char word[50];
    char ch;
    long last;
    if((fp=fopen("wordy","a+"))==0)
    exit(1);
    while(fscanf(stdin,"%s",word)==1&&word[0]!='#')
    fprintf(fp,"%s",word);
    fseek(fp,0L,SEEK_END);
    last=ftell(fp);//number of words
    for(int count=1;count<=last;count++)
    {
        fseek(fp,-count,SEEK_END);
        ch=getc(fp);
        putchar(ch);
    }
    fclose(fp);

}