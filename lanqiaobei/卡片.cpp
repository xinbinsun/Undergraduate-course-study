#include<bits/stdc++.h>

using namespace std;
int a[11];
int main()
{
	int x = 0;
	int i = 1; 
	int flag = 0;
	for(;flag==0;i++)
	{
		int ans = i;
		while(ans>0)
		{
			x = ans%10;
			ans = ans/10;
			a[x]++;
			if(a[x]==2021)
			{
				flag=1;
				cout<<i;
				break;
			}
		}
	}
 } 
