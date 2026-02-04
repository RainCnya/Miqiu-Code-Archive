#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e3 + 5;
unordered_map< string, int > dict;
char g[maxn][maxn];
int n, m;

bool check( string s, ll &ans )
{
    s += '#';
    string cur = "";

    for( char c : s )
    {
        if( c != '#' )
        {
            cur += c;
            continue;
        }

        if( !cur.empty( ) )
        {
            auto it = dict.find( cur );
            if( it == dict.end( ) ) return 0;
            ans += it->second;
        }
        cur = "";
    }
    return 1;
}

void solve( )
{
    dict.clear( );
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            cin >> g[i][j];
        }
    }

    for( int i = 1; i <= m; ++ i )
    {
        string s;
        int score;
        cin >> s >> score;
        dict[s] += score;
    }

    ll ans = 0;
    bool ok = 1;

    for( int i = 1; i <= n; ++ i )
    {
        string word = "";
        for( int j = 1; j <= n; ++ j ) word += g[i][j];
        if( check( word, ans ) ) continue;
        ok = 0;
        break;
    }

    if( ok == 0 ) 
    {
        cout << "-1" << '\n';
        return ;
    }

    for( int j = 1; j <= n; ++ j )
    {
        string word = "";
        for( int i = 1; i <= n; ++ i ) word += g[i][j];
        if( check( word, ans ) ) continue;
        ok = 0;
        break;
    }

    if( ok == 0 )
    {
        cout << "-1" << '\n';
        return ;
    }

    cout << ans << '\n';
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