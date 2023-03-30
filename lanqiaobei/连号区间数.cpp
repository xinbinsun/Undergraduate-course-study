#include<bits/stdc++.h>

using namespace std;

int a[11000];
int main()
{
	int ans = 0,n = 0, i = 0;
	cin >> n ;
	for(int i = 1; i <= n;i++)
	{
		cin>>a[i];
	}
	
	for(int i = 1; i <= n;i++)
	{
		int max_ = 0;
		int min_ = 10011;
		for(int j = i; j <= n; j++)
		{
			
			max_ = max(a[j], max_);
			min_ = min(a[j], min_);
//			cout<<(max_ - min_);
			if((max_ - min_) == (j - i))
			{
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
	
}
