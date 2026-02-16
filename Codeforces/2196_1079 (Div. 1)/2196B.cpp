#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
vector< int > pos[maxn];
int a[maxn];
int n;

void solve( )
{
    cin >> n;

    vector< int > nums;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( a[i] >= n ) continue;
        if( pos[a[i]].empty( ) ) nums.push_back( a[i] );
        pos[a[i]].push_back( i );
    }
    sort( nums.begin( ), nums.end( ) );

    ll ans = 0;
    for( int a1 : nums )
    {
        for( int a2 : nums )
        {
            ll prod = 1ll * a1 * a2;
            if( prod >= n ) continue;

            for( int i : pos[a1] )
            {
                int j = i + prod;
                if( j <= n && a[j] == a2 ) ans ++;
            }
        } 
    }
    cout << ans << '\n';

    for( int x : nums ) pos[x].clear( );
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