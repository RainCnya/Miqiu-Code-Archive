#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int p, q, x, y;


int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> p >> q >> x >> y;

    if( p <= x && x < p + 100 && q <= y && y < q + 100 )
    {
        cout << "Yes" << '\n';
    }
    else
    {
        cout << "No" << '\n';
    }
    return 0;
}