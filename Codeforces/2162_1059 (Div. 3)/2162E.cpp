#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
int cnt[maxn];
int a[maxn];
int n, k;

void solve( )
{
    cin >> n >> k;

    for( int i = 1; i <= n; ++ i )
    {
        cnt[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        cnt[a[i]] ++;
    } 

    int x = -1;
    for( int i = 1; i <= n; ++ i )
    {
        if( cnt[i] != 0 ) continue;
        x = i;
        break;
    }

    vector< int > res;

    if( x == -1 )
    {
        int tmp[3] = {a[n - 2], a[n - 1], a[n]};
        for( int i = 0; i < k; ++ i )
        {
            res.push_back( tmp[i % 3] );
        }
    }
    else
    {
        int z = a[n];
        int y = -1;

        for( int i = 1; i <= n; ++ i )
        {
            if( i == x || i == z ) continue;
            y = i;
            break;
        }

        int tmp[3] = {x, y, z};
        for( int i = 0; i < k; ++ i )
        {
            res.push_back( tmp[i % 3] );
        }
    }

    for( int x : res )
    {
        cout << x << " ";
    }
    cout << '\n';
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