#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
int ID1=0,ID2=0;
int main()
{
    scanf("%d",&n);
    n=0;//你无意义
    while(scanf("%d",&a[++n])!=EOF);
    n--;
    sort(a+1,a+1+n);//由小到大排序，方便接下来的统计
    for(int i=2;i<=n;i++){
        if(a[i]-1!=a[i-1]&&a[i]!=a[i-1])ID1=a[i]-1;//漏号，如果重号它也会算，所以我们多加一个判断a[i]!=a[i-1]
        if(a[i]==a[i-1])ID2=a[i];//重号
    }
    printf("%d %d",ID1,ID2);
}

