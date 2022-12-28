#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n ;
    int m = n;
    for(int i = 0;i < n/2; i++)
    {
        m--;
        cout<<2*m<<endl;
    }
    m = n/2;
    if(n%2)
    {
        cout<<n/2*2<<endl;
        m++;
    }
    for(int i = 0;i < n/2;i++)
    {
        cout<<2*m<<endl;
        m++;
    }

    return 0;
}