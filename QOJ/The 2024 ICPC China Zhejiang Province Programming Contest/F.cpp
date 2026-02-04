#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e3 + 5;

struct Setter {
    string name;
    int solved;
    int rank;
} setters[maxn];

int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> setters[i].name >> setters[i].solved;
    }

    for( int i = 1; i <= n; ++ i )
    {
        int cnt = 0;
        for( int j = 1; j <= n; ++ j )
        {
            if( setters[j].solved > setters[i].solved ) cnt ++;
        }
        setters[i].rank = 1 + cnt;
    }

    string t = "";
    for( int i = 1; i <= n; ++ i )
    {
        int l = setters[i].name.length( );
        int r = setters[i].rank;
        if( l > r ) t += setters[i].name.substr( 0, l - r );
    }

    t[0] = toupper( t[0] );

    cout << "Stage: " << t << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}