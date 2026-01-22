#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 50 + 5;

struct State 
{
    ll cost;
    int idx;
    int cnt;
    bool operator < ( const State &oth ) {
        return cost > oth.cost;
    }
};

ll a[maxn];
ll d[maxn];
ll n, k, x;

bool cmp( ll a, ll b ) {
    return a > b;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k >> x;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    sort( a + 1, a + n + 1, cmp );
    for( int i = 2; i <= n; ++ i ) d[i] = a[1] - a[i];

    ll res = a[1] * k;
    cout << res << "\n";

    priority_queue<State> pq;
    pq.push({ d[2], 2, 1 });

    for( int i = 2; i <= x; ++ i )
    {
        auto [cost, idx, cnt] = pq.top();
        pq.pop();
        
        cout << res - cost << "\n";
        
        if( cnt + 1 <= k ) pq.push({ cost + d[idx], idx, cnt + 1 });
        if( idx + 1 <= n ) pq.push({ cost + ( d[idx + 1] - d[idx] ), idx + 1, cnt });
    }

    return 0;
}