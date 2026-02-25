#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

struct State {
    ll w, h;
    bool operator < ( const State& oth ) const {
        if( w != oth.w ) return w > oth.w;
        return h > oth.h;
    }
};

priority_queue< State > pq;
int n, k;

void solve( )
{
    cin >> n >> k;
    ll ans = 0;
    for( int i = 1; i <= n ; ++ i ) 
    {
        ll wi;
        cin >> wi;
        pq.push({ wi, 1 });
    }

    if( ( n - 1 ) % ( k - 1 ) != 0 )
    {
        for( int i = 1; i <= ( k - 1 ) - ( n - 1 ) % ( k - 1 ); ++ i )
        {
            pq.push({ 0, 1 });
        }
    }

    while( pq.size( ) != 1 )
    {
        State tmp;
        ll sum = 0, maxh = 0;

        for( int i = 1; i <= k; ++ i )
        {
            tmp = pq.top( );
            sum += tmp.w;
            maxh = max( maxh, tmp.h );
            pq.pop( );
        }
        ans += sum;
        pq.push({ sum, maxh + 1 });
    }
    cout << ans << '\n' << pq.top( ).h - 1 << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}