#include<iostream>

using namespace std;

int main()
{
    int x,sum=0;
    int n = 5;
    while(n)
    {
        n--;
        cin>>x;
        int a = x/1000, b = x/100%10,c = x/10%10,d = x%10;
        if(a == c and (d - b) == 1)
        sum ++;
    }
    cout<<sum;
}