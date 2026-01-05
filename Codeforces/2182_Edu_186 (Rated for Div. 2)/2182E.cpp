#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

struct Node {
    ll x, y, z, cost;
    bool operator < ( const Node &other ) const {
        return cost > other.cost;
    }
} fri[maxn];

int n, m;
ll a[maxn];
ll k;

void solve( )
{
    cin >> n >> m >> k;

    multiset< ll > s;

    for( int i = 1; i <= m; ++ i )
    {
        cin >> a[i];
        s.insert( a[i] );
    }

    ll sum = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> fri[i].x >> fri[i].y >> fri[i].z;
        fri[i].cost = fri[i].z - fri[i].y;
        sum += fri[i].y;
    }

    ll remain = k - sum;
    ll ans = 0;
    vector< ll > remains;

    sort( fri + 1, fri + n + 1 );

    for( int i = 1; i <= n; ++ i )
    {
        auto it = s.lower_bound( fri[i].x );
        if( it != s.end( ) )
        {
            s.erase( it );
            ans ++;
        }
        else
        {
            remains.push_back( fri[i].cost );
        }
    }

    sort( remains.begin( ), remains.end( ) );

    for( ll cost : remains )
    {
        if( remain >= cost )
        {
            remain -= cost;
            ans ++;
        }
        else break;
    }
    
    cout << ans << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
