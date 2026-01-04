#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int get_SG( int x, int y )
{
    int v = ( x - 1 ) | ( y - 1 );
    int cnt = 0;
    while( v & 1 )
    {
        cnt ++;
        v >>= 1;    
    }
    return cnt;
}

void solve( )
{
    int n;
    cin >> n;

    int xor_sum = 0;

    for( int i = 1; i <= n / 2; ++ i )
    {
        int a, b;
        cin >> a >> b;
        xor_sum ^= get_SG( a, b );
    }
    
    if( xor_sum == 0 ) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
