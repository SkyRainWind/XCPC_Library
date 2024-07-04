#include<stdio.h>
int a[1005][8];
int main(void)
{
    int n,x[8];
    int b[8]={0,0,0,0,0,0,0};
    scanf("%d",&n);
    for(int i=1;i<=7;i++)
    {
        scanf("%d",&x[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=7;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int s=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=7;j++)
        {
            for(int k=1;k<=7;k++)
            {
                if(x[k]==a[i][j])
                s++;
            }
        }
        if(s!=0)
        {
            b[8-s]+=1;
            s=0;
        }
    }
    for(int i=1;i<=7;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}
