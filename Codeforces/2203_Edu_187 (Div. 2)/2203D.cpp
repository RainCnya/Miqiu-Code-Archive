#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e6 + 5;

bool vis[maxn];
int a[maxn], b[maxn];
int n, m;

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= m; ++ i ) cin >> b[i];

    int maxv = n + m;
    for( int i = 1; i <= maxv; ++ i ) vis[i] = 0;

    sort( a + 1, a + n + 1 );
    int k = unique( a + 1, a + n + 1 ) - ( a + 1 );

    for( int i = 1; i <= k; ++ i ) 
    {
        for( int j = a[i]; j <= maxv; j += a[i] ) vis[j] = 1;
    }

    ll lcm = a[1];
    bool byd = ( lcm > maxv );   // beyond maxv
    for( int i = 2; i <= k; ++ i )
    {
        ll g = __gcd( lcm, (ll)a[i] );
        if( lcm > (ll)maxv * g / a[i] ) 
        {
            byd = 1;
            break;
        }
        lcm = lcm / g * a[i];
    }

    // Alice / Bob / Other
    int cntA = 0, cntB = 0, cntO = 0;
    for( int j = 1; j <= m; ++ j )
    {
        bool alice = ( byd == 0 && b[j] % lcm == 0 );
        bool bob = ( vis[ b[j] ] == 0 );
        
        if( alice ) cntA ++;
        else if( bob ) cntB ++;
        else cntO ++;
    }

    if( cntO % 2 == 1 && cntA >= cntB ) cout << "Alice" << '\n';
    else if( cntO % 2 == 0 && cntA > cntB ) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
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