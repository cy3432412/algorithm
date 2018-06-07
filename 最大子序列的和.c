#include <stdio.h>
#include <stdlib.h>
int max(int a,int b);//最大值
int dp(int a[],int n);//动态规划求最大子序列和
int divide(int a[],int left,int right);//分治法求解最大子序列和
int main()//
{

    int n;
    int f[1005];
    f[0]=1;
    f[1]=1;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
            f[i]=f[i-1]+f[i/2];
        else
            f[i]=f[i-1];
    }
    printf("%d",f[n]);

    return 0;
}
int divide(int a[],int left,int right)
{
    int mid =(left+right)/2;
    if(right==left)
      return a[left];
    int max_left_sum=divide(a,left,mid);//左字段最大和
    int max_right_sum=divide(a,mid+1,right);//右字段最大和
    //处理端点分别在左半段和右半段的情况
    int sum=0;
    int left_sum=-10001;
    for(int i=mid;i>=left;--i)
    {
        sum+=a[i];
        if(sum>left_sum)
            left_sum=sum;
    }
    sum=0;
    int right_sum=-10001;
    for(int i=mid+1;i<=right;++i)
    {
        sum+=a[i];
        if(sum>right_sum)
           right_sum=sum;
    }
    int max_mid_sum=left_sum+right_sum;
    int max=max_mid_sum;
    if(max<max_left_sum)
        max=max_left_sum;
    if(max<max_right_sum)
        max=max_right_sum;

    return max;
}
int dp(int a[],int n)//状态转移方程 f[i]=max(f[i-1]+a[i],a[i])
/*
**因为若f[i]的值为负数，则f[i+1]的值就是n[i],而n[i]的值不一定比前面的最大字段和数大！
**或者n[i]为负数，则f[i]小于f[i-1]!
**所以，我们还要再用一个数从1到n再查找一次，才能找出最大数.
*/
{
    int ans[200005]={0};
    int sum=-10001;
    for(int i=0;i<n;i++)
    {
        ans[i]=max(ans[i-1]+a[i],a[i]);
        sum=max(sum,ans[i]);
    }
    return sum;
}

int max(int a,int b)
{
    return a>b?a:b;
}








