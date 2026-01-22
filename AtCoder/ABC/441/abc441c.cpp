#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 3e5 + 50;

int k, n;
ll a[maxn];
ll s[maxn];
ll x;


int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> x;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1, greater<ll>() );

    ll sum = 0;
    int st = n - k + 1;
    if( st < 0 ) st = 0;

    for( int m = st; m <= n; ++ m )
    {
        sum += a[m];
        if( sum >= x )
        {
            cout << m << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}