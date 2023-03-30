#include<bits/stdc++.h>

using namespace std;

int mt[510][510];

int main()
{
	int n=0,m=0,k=0;
	
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++)
	{
		for(int j=1; j <=m;j++)
		{
			int a = 0;
			cin>>a;
			mt[i][j] = mt[i-1][j] + a;
		}
	 } 
	 
	 for(int i = 1;i<=n;i++)
	{
		for(int j=1; j <=m;j++)
		{
			cout<<mt[i][j]<<" ";
		}
		cout<<endl;
	 } 
	 
	 long long res = 0;
	 
	 for(int i=1; i<=n; i++)
	 {
	 	for(int j = i; j<=n; j++)
	 	{
	 		for(int l=1,r=1,sum=0;r<=m;r++)
	 		{
	 			sum = sum + mt[j][r] - mt[i-1][r];
				 while(sum>k)
				 {
				 	sum = sum - (mt[j][l] - mt[i-1][l]);
				 	l++;
				  } 
				  res = res + r-l+1;
			 }
		 }
	  } 
	  cout<<res;
	  
	  return 0;
	 
 } 
