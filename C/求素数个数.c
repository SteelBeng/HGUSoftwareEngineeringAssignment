#include <stdio.h>

int main()
{
    int n,j,i,k=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        j=IsPrime(i);
        if(j==1) k++;
    }
    printf("count=%d",k);
    return 0;
}
int IsPrime(int n)
{
    int i;
    for(i=2;i<n;i++)
    {
         if(n%i==0) return 0;
    }
    return 1;
}
