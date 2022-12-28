#include<iostream>

using namespace std;

int main()
{
    int a, b, n;
    int m = 0;
    int sum = 0, tsum = 0;
    cin>>a>>b>>n;
    while(sum < n)
    {
        if(m < 5)
        {
            sum = sum + a;
            m = m + 1;
            tsum = tsum + 1;
        }
        
        if(m >= 5)
        {
            if(m > 7)
            m = 0;
            sum = sum + b;
            tsum = tsum + 1;
        }
    }
    cout<<tsum;


    return 0;
}