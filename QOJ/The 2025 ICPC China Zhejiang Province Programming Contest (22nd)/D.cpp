#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;

ll c[maxn], k[maxn];
ll reml[maxn], remr[maxn];
int n;

void solve( )
{
    cin >> n;

    ll sum = 0;
    for( int i = 0; i <= n; ++ i )
    {
        cin >> c[i];
        sum += c[i];
    }

    k[0] = c[0];
    for( int i = 1; i < n; ++ i )
    {
        k[i] = c[i] - k[i - 1];
    }

    for( int i = 0; i < n; ++ i )
    {
        if( k[i] <= 0 ) 
        {
            cout << "Impossible" << '\n';
            return;
        }
        reml[i] = remr[i] = k[i];
    }

    if( k[n - 1] != c[n] )
    {
        cout << "Impossible" << '\n';
        return;
    }

    int cur = 0, nxt = n - 1;
    while( nxt > 0 && remr[nxt] == 0 ) nxt --;

    string res = "";

    for( ll i = 0; i < sum; ++ i )
    {
        bool moved = 0;

        if( cur > 0 && reml[ cur - 1 ] > 0 )
        {
            if( reml[ cur - 1 ] > 1 || nxt < cur )
            {
                res += 'L';
                reml[cur - 1] --;
                cur --;
                moved = 1;
            }
        }

        if( !moved )
        {
            if( cur < n && remr[cur] > 0 )
            {
                res += 'R';
                remr[cur] --;
                cur ++;
                moved = 1;
                while( nxt > 0 && remr[nxt] == 0 ) nxt --;
            }
        }

        if( !moved )
        {
            cout << "Impossible" << '\n';
            return;
        }
    }
    
    cout << res << '\n';
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