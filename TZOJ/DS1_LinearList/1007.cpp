#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p;

void solve( )
{
    cin >> n;
    vector< int > list;
    for( int i = 1; i <= n; ++ i )
    {
        int val; cin >> val;
        list.push_back( val );
    }

    cin >> p;
    for( int i = 1; i <= p; ++ i )
    {
        string s;
        cin >> s;
        if( s == "insert" )
        {
            int pos, m; cin >> pos >> m;
            vector< int > tmp( m );
            for( int j = 0; j < m; ++ j ) cin >> tmp[j];
            int idx = max( 0, pos - 1 );
            list.insert( list.begin( ) + idx, tmp.begin( ), tmp.end( ) );
        }
        else if( s == "delete" )
        {
            int pos, m; cin >> pos >> m;
            if( list.empty( ) ) continue;
            int idx = pos - 1;
            int mm = min( m, (int)list.size( ) - idx );
            list.erase( list.begin( ) + idx, list.begin( ) + idx + mm );
        }
    }
    for( int i = 0; i < list.size( ); ++ i )
    {
        if( i ) cout << " ";
        cout << list[i];
    }
    cout << "\n";
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}