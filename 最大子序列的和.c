#include <stdio.h>
#include <stdlib.h>
int max(int a,int b);//���ֵ
int dp(int a[],int n);//��̬�滮����������к�
int divide(int a[],int left,int right);//���η������������к�
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
    int max_left_sum=divide(a,left,mid);//���ֶ�����
    int max_right_sum=divide(a,mid+1,right);//���ֶ�����
    //����˵�ֱ������κ��Ұ�ε����
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
int dp(int a[],int n)//״̬ת�Ʒ��� f[i]=max(f[i-1]+a[i],a[i])
/*
**��Ϊ��f[i]��ֵΪ��������f[i+1]��ֵ����n[i],��n[i]��ֵ��һ����ǰ�������ֶκ�����
**����n[i]Ϊ��������f[i]С��f[i-1]!
**���ԣ����ǻ�Ҫ����һ������1��n�ٲ���һ�Σ������ҳ������.
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








