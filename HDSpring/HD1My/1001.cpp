#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int maxn = 1e5 + 5;

int n;
int a[maxn];
int lm[maxn], rm[maxn];
map< int, vector<int> > mp;

ll calc( int val, int l, int r )
{
    auto it = mp.find( val );
    if( it == mp.end( ) ) return 0;
    auto &v = it->second;
    auto itl = lower_bound( v.begin( ), v.end( ), l );
    auto itr = upper_bound( v.begin( ), v.end( ), r );
    return distance( itl, itr );
}

void solve( )
{
    cin >> n;
    mp.clear( );
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
        mp[a[i]].push_back( i );
    }

    stack< int > st;
    for( int i = 1; i <= n; ++ i )
    {
        while( !st.empty( ) && a[st.top()] < a[i] ) st.pop( );
        lm[i] = st.empty( ) ? 0 : st.top( );
        st.push( i );
    }

    while( !st.empty( ) ) st.pop( );
    for( int i = n; i >= 1; -- i )
    {
        while( !st.empty( ) && a[st.top()] <= a[i] ) st.pop( );
        rm[i] = st.empty( ) ? n + 1 : st.top( );
        st.push( i );
    }

    ll ans = 1ll * n * n;
    for( int p = 1; p <= n; ++ p )
    {
        if( a[p] % 2 == 0 ) continue;
        int l = lm[p] + 1, r = rm[p] - 1;
        int tar = a[p] + 1;
        if( p - l < r - p )
        {
            for( int i = l; i < p; ++ i )
            {
                int val = tar - a[i];
                if( val >= 2 ) ans -= calc( val, p + 1, r ) * 2;
            }
        }
        else
        {
            for( int i = p + 1; i <= r; ++ i )
            {
                int val = tar - a[i];
                if( val >= 2 ) ans -= calc( val, l, p - 1 ) * 2;
            }
        }
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}