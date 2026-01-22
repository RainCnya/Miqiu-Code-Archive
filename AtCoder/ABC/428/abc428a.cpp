#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int len = 0;
    int k = x / ( a + b );
    int remain = x % ( a + b );
    remain = min( remain, a );
    len += k * a * s;
    len += remain * s;
    cout << len;
    return 0;
}