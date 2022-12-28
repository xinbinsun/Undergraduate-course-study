#include<iostream>

using namespace std;

int main()
{
    int n = 0,sum = 0 ;
    cin>>n;
    float m = n/2.0;
    // cout<<m<<endl;
    for(int i = 1;i < n;i ++)
    {
        float x = i*i%n;
        if(x < m)
            sum++;
    }
    cout<<sum;
}