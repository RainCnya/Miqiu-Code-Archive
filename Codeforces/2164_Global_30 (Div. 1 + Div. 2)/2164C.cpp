#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

struct Monster {
    ll h, r;
};  // health, reward;

ll hs[maxn];
ll rs[maxn];

bool cmp( Monster a, Monster b ) {
    return a.h < b.h;
}
 
void solve( )
{
    int n, m;
    cin >> n >> m;

    multiset<ll> swords;
    for( int i = 1; i <= n; ++ i )
    {
        ll x;
        cin >> x;
        swords.insert( x );
    }

    for( int i = 1; i <= m; ++ i )
        cin >> hs[i];
    
    for( int i = 1; i <= m; ++ i )
        cin >> rs[i];

    vector<Monster> m1;
    vector<Monster> m2;

    for( int i = 1; i <= m; ++ i )
    {
        if( rs[i] ) m1.push_back({ hs[i], rs[i] });
        else m2.push_back({ hs[i], rs[i] });
    }

    sort( m1.begin( ), m1.end( ), cmp );
    sort( m2.begin( ), m2.end( ), cmp );

    int cnt = 0;

    for( auto [heal, reward] : m1 )
    {
        auto it = swords.lower_bound( heal );
        if( it != swords.end( ) )
        {
            cnt ++;
            ll tmp = *it;
            swords.erase( it );
            swords.insert( max( tmp, reward ) );
        }
    }

    for( auto [heal, reward] : m2 )
    {
        auto it = swords.lower_bound( heal );
        if( it != swords.end( ) )
        {
            cnt ++;
            swords.erase( it );
        }
    }

    cout << cnt << '\n';
    return ;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;    
    cin >> t;
    while( t -- )
    {
        solve( );
    }
    return 0;
}