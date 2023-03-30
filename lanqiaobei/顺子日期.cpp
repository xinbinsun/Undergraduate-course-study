#include<bits/stdc++.h>

using namespace std;

int main()
{
	int num = 14;
	int ans = 0;
	for(int i = 1;i <=12 ; i++)
	{
		for(int j = 1; j<=31; j++)
		{
			int data = i*100 + j;
//			int data = 129;
			int a = data/1000;
			int b = data/100%10;
			int c = data%100/10;
			int d = data%10;
//			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
			if((a+1)==b&&(b+1)==c)
			{
			ans++;
			cout<<data<<endl;
		}
			if((b+1)==c&&(c+1)==d)
			{
			ans++;
			cout<<data<<endl;
		}
		}
	}
	cout<<ans;
//cout<<num;
	return 0;
}
