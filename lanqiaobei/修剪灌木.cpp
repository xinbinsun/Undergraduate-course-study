#include<bits/stdc++.h>

using namespace std;

int a[10010];

int main()
{
	int n;
	cin>>n;
	if(n%2 == 0)
	{
	
	for(int i = 1; i <= n/2; i++)
	{
		a[i] = (n - i)*2;
		a[n-i+1] = a[i];
	}
}
if(n%2 == 1)
	{
	
	for(int i = 1; i <= n/2; i++)
	{
		a[i] = (n - i)*2;
		a[n-i+1] = a[i];
	}
	a[n/2+1] = a[n/2] - 2;
}

for(int i = 1; i<=n; i++)
{
	cout<<a[i]<<endl;
}

return 0;
	
}
