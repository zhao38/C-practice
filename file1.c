//file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE* fp;
    char word[50];
    if((fp=fopen("wordy","a+"))==NULL)
    {
        fprintf(stdout,"cant open");
        exit(1);
    }
    puts("enter the word");
    while((fscanf(stdin,"%s",word)==1)&&(word[0]!='#'))
    fprintf(fp,"%s",word);
    rewind(fp);                          //return to the start

    while(fscanf(fp,"%s",word)==1)        //read the file
    puts(word);                           //print the file
    if(fclose(fp)!=0)
    fprintf(stderr,"erroe");

    
}