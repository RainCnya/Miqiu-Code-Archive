#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n;
string s;

void solve( )
{
    cin >> n >> s;
    s = ' ' + s;
    vector< int > pos;

    for( int i = 1; i <= n; i ++ )
    {
        if( s[ i ] == '1' ) pos.push_back( i );
    }

    if( pos.empty( ) )
    {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    int minn = 0, maxx = 0;
    int m = pos.size( );
    
    for( int i = 0; i < m; )
    {
        int st = i;
        while( i + 1 < m && pos[i + 1] - pos[i] <= 2 ) ++ i;

        int l = pos[st];
        int r = pos[i];

        int cnt = r - l + 1;
        
        maxx += cnt;
        minn += ( cnt / 2 ) + 1;
        i ++;
    }
    cout << minn << ' ' << maxx << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}