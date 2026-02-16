#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 3e5 + 5;
const ld inf = 1e18;

ll a[maxn];
ll s[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }

    int pos = -1;
    for( int i = 2; i < n; ++ i ) 
    {
        if( a[i-1] > a[i] && a[i] < a[i+1] )
        {
            pos = i;
            break;
        }
    }

    ld ans = 0;

    ld res1 = (ld)( s[n] ) / n;
    ld res2 = (ld)( s[pos+1] ) / (pos + 1);
    ld res3 = (ld)( s[n] - s[pos-2] ) / (n - pos + 2);
    ld res4 = (ld)( s[pos+1] - s[pos-2] ) / 3;
    ans = max({ res1, res2, res3, res4 });

    cout << fixed << setprecision(20) << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}