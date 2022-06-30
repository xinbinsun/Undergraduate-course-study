#include <iostream>
using namespace std;
int n;
void f(int* a, int* b, int m)
{
    int sum = 0;
    int x = 1;
    int h = 2;
    for (int i = 1, j = 1; i <= m && j <= m;)
    {
        if (a[i] <= b[j])
        {
            sum -= 200;
            j++; 
        }
        else
        {
            sum += 200;
            i++;
            j++;
        }
        x = x + 1;
        h = h + 2;
    }
    cout << sum << endl;
}
bool  cmp(int& x, int& y) 
{
    return x > y;
}
void in()
{
    cin >> n;
}

int main() 
{
    in();
    while (n--)
    {
        int m = 0;
        cin >> m;
        int a[m], b[m];
        for (int i = 1; i <= m; i++)
            cin >> a[i];
        sort(a + 1, a + m + 1, cmp);
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        sort(b + 1, b + m + 1, cmp);
        f(a, b, m);
    }
}
