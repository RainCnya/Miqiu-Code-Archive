#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int maxn = 1e5 + 5;

vector< int > adj[maxn];
int n, m;
ll a[maxn], sum[maxn];

struct State {
    ll val;
    int idx;
    // bool operator < ( const State &o ) const { return val > o.val; }
    bool operator<( const State &o ) const { return val < o.val; }
};

bool del[maxn];
priority_queue< State > pq;
ll summ[maxn];

ll s[maxn], vis[maxn];


int check( ll mid ){
    for(int i = 1; i <= n; i++) s[i] = sum[i], vis[i] = 1, del[i] = 0;
    // cout << mid << "----------------<" << endl;

    vector<State> q;
    for(int i = 1; i <= n; i++) q.push_back({ s[i], i });
    sort( q.begin( ), q.end( ));

    int hh = 0, tt = n;
    while (hh < tt){
        auto [val, u] = q[hh++];
        vis[u] = 0;
        // cout << val << " " << u << endl;
        
        if( del[u] ) continue;
        if( s[u] <= mid ) del[u] = 1;
        else continue;

        for(int v : adj[u]){
            s[v] -= a[u];
            if( del[v] || vis[v] ) continue;
            q.push_back({ s[v], v });
            vis[v] = 1, tt++;
        }
    }

    for(int i = 1; i <= n; i++) if( !del[i] ) return false;
    return true;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i <= m; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j : adj[i] ) sum[i] += a[j];
    }

    
    // int st = 0, mn = inf;
    for( int i = 1; i <= n; ++ i ) 
    {
        pq.push({ sum[i], i });
        // if( sum[i] < mn ) mn = sum[i], st = i;
    }

    ll l = 0, r = 1e18, ans = 0;
    while( l <= r )
    {
        ll mid = ( l + r ) >> 1;
        if( check( mid ) ) r = mid - 1, ans = mid;
        else l = mid + 1;
    }

    cout << ans << '\n';
}

signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}