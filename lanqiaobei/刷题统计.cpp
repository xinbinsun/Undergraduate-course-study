#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL a, b, n, ret;
    cin >> a >> b >> n;
    ret = n / (a * 5 + b * 2) * 7;
    n = n - (a * 5 + b * 2) * ret / 7;

    for (int i = 0; i < 5 and n > 0; i ++) ret ++, n -= a;
    for (int i = 0; i < 2 and n > 0; i ++) ret ++, n -= b;

    cout << ret << endl;
    return 0;
}
