#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double** GETAMATRIX(int m,int n);
void HANGZUIJIAN();           
void RANK();
void TIMES();
void TEZHENGZHI();
void CHANGEROW(double* a,double* b,int n);
void ADDROW(double* a,double* b,int n,int x);
int DET();
int main()
{
    HANGZUIJIAN();
}

double** GETAMATRIX(int m,int n)
{
    printf("put your matrix : \n");
    double** a=(double**)malloc(m*sizeof(double*));
    for(int i=0;i<m;i++)
    {
        a[i]=(double*)malloc(n*sizeof(double));
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%lf",&a[i][j]);
        }
    }
    return a;
}

void CHANGEROW(double* a,double* b,int n)
{
    for(int i=0;i<n;i++)
    {
        double c=a[i];
        a[i]=b[i];
        b[i]=c;
    }
}
void ADDROW(double* a,double* b,int n,int x)
{
    for(int i=0;i<n;i++)
    {
        b[i]=b[i]+a[i]*x;
    }
}

void HANGZUIJIAN()
{
    int m,n;
    printf("size of matrix : ");
    scanf("%d%d",&m,&n);
    double** a=GETAMATRIX(m,n);
    /*if(a[0][0]==0)
    {
        int none0row=1;
        for(int none0row=1;none0row<m;none0row++)
        {
            if(a[none0row][0]!=0)
            break;
        }
        CHANGEROW(a[0],a[none0row],n);
    }*/
   int rank=0;
    for(int j=0;j<n&&rank<m;j++)
    {
        int pivotrow=rank;
        while(pivotrow<m&&a[pivotrow][j]!=0)
        pivotrow++;
        if(pivotrow==m)
        continue;

        if(pivotrow!=rank)
        CHANGEROW(a[pivotrow],a[rank],n);
        
        
        for(int i=rank+1;i<m;i++)
        {
            if(a[i][j]==0)
            continue;
            int x=a[i][j]/a[rank][j];
            ADDROW(a[rank],a[i],n,-x);
        }
        rank++;
     
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    //
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5.2lf",a[i][j]);
        }
        printf("\n");
    }

}

