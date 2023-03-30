#include<bits/stdc++.h>

using namespace std;

int main()
{
	int w = 0;
	int m = 0;
	int n = 0;
	int x1,x2,y1,y2; 
	cin>>w>>m>>n;
	
	y1 = m / w;	
	if(y1%w == 0)
	{
		x1 = m % w ; 
	}
	else{
		x1 = w - m % w -1;
	}
	
	 y2 = n / w;	
	if(y2%w == 0)
	{
		x2 = n % w ; 
	}
	else{
		x2 = w - n % w -1;
	}
//	cout<<x1<<y1<<endl;
//	cout<<x2<<y2<<endl;
	
	cout<<((abs(x1-x2)+abs(y1-y2)));
	
	return 0;

}
