#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
int ID1=0,ID2=0;
int main()
{
    scanf("%d",&n);
    n=0;//��������
    while(scanf("%d",&a[++n])!=EOF);
    n--;
    sort(a+1,a+1+n);//��С�������򣬷����������ͳ��
    for(int i=2;i<=n;i++){
        if(a[i]-1!=a[i-1]&&a[i]!=a[i-1])ID1=a[i]-1;//©�ţ�����غ���Ҳ���㣬�������Ƕ��һ���ж�a[i]!=a[i-1]
        if(a[i]==a[i-1])ID2=a[i];//�غ�
    }
    printf("%d %d",ID1,ID2);
}

