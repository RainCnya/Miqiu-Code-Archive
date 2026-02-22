#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 5;

struct Enemy { int l, w, use; } e[maxn];

int n, x;
int f[maxn];
// f[i] 表示喝了 i 瓶药最多的经验

void solve( )
{
    cin >> n >> x;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> e[i].l >> e[i].w >> e[i].use;
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = x; j >= 0; -- j )
        {
            if( j >= e[i].use ) f[j] = max( f[j] + e[i].l, f[j - e[i].use] + e[i].w );
            else f[j] += e[i].l;
        }
    }
    cout << 5ll * f[x] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}