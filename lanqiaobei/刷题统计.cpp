#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long int a= 0 ;
	long long int b = 0;
	long long int n = 0;
	long long int num = 0;
	long long int days = 0;
	cin >> a>>b>>n;
	
	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			num = num + a;
			days++;
			if(num >= n)
			break;
		}
		if(num>=n)
			break;
		for(int i = 0; i < 2; i++)
		{
			num = num + b;
			days++;
			if(num>=n)
			break;
		}
		if(num>=n)
			break;
	}
	cout<<days;
	
	return 0;
}
