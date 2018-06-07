#include <stdlib.h>
#include <stdio.h>
int lis(int a[],int f[],int n);//最长上升子序列
int lds(int a[],int f[],int n,int i);//最长下降子序列

int max(int a,int b);
int main()
{
    int n;
    int f[105],a[105],b[105],c[105];
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        b[i]=lis(a,f,i);
        c[i]=lds(a,f,n,i);
        sum=max(b[i]+c[i]-1,sum);
    }
    printf("%d",n-sum);
    return 0;
}

int lis(int a[],int f[],int n)//最长上升子序列
{
    f[0]=-1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(f[ans]<a[i])
        {
            f[++ans]=a[i];
        }
        else
        {
            int l=0,r=ans;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(f[mid]>=a[i])
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            f[l]=a[i];
        }
    }
    return ans;
}

int  lds(int a[],int f[],int n,int i)//最长下降子序列
{
    f[0]=999999999;
    int ans=0;
    for(;i<=n;i++)
    {
        if(f[ans]>a[i])
        {
            f[++ans]=a[i];
        }
        else
        {
            int l=0,r=ans;
            while(l<r)
            {
                int mid=(l+r)/2;
                if(f[mid]>a[i])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid;
                }
            }
            if(l!=0)
            {
                f[l]=a[i];
            }
        }
    }
    return ans;
}

int max(int a,int b)
{
    return a>b?a:b;
}






