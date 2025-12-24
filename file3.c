//BASIC

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE* fp;
    fp=fopen("h.txt","wb+");
    fwrite("123456",1,6,fp);
    fflush(fp);
    fseek(fp,0,SEEK_SET);
    char a[1024]={0};
    fread(a,1,6,fp);
    puts(a);
    fclose(fp);
    
}