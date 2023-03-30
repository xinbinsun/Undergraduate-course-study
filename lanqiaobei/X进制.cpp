#include<bits/stdc++.h>

using namespace std;

int a[100010];
int b[100010];
int c[100010];
int main()
{
	int n;
	long int ma,mb,mma=0,mmb=0;
	
	long long int suma = 0;
	long long int sumb = 0;
	int weishu;
	cin>>n;
	cin>>ma;
	for(int i = 0; i < ma; i++)
	{
		cin>>a[i];
	}
	cin>>mb;
	for(int i = 0; i < mb; i++)
	{
		cin>>b[i];
	}
	if(ma>mb)
	{
		weishu = ma;
	}
	else{
		weishu = mb;
	}
	for(int i = 0; i < weishu; i++)
	{
		c[i] = max(a[i],b[i])+1;
		c[i] = max(c[i],2);
//		cout<<c[i]<<endl;
	}
	for(int i = 0;i<ma ;i++)
	{
		
		suma = suma + a[ma -i-1]*pow(c[i],mma++);
	}
//	cout<<suma<<endl;
	for(int i = 0;i<mb ;i++)
	{
		
		sumb = sumb + b[mb-i-1]*pow(c[i],mmb++);
//		cout<<"1:"<<sumb<<" "<<b[mb-i-1]<<" "<<pow(c[i],mmb++)<<endl;
	}
//	cout<<sumb<<endl;
	long long int sub = (suma - sumb)%1000000007;
	cout<<sub;
	return 0;

	
}
