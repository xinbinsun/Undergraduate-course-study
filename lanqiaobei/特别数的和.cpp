#include<bits/stdc++.h>
#include<string> 
using namespace std;
int main()
{
    int n,sum=0;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        string num = to_string(i);
        for(int j=0;j<num.size();j++)
            if(num[j]=='2' || num[j]=='0' || num[j]=='1' || num[j]=='9')
                {sum+=i;break;}
    }
    cout << sum;
    return 0;
}


