#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    int opt;
    int cnt = 0;
    queue< int > q;
    while( cin >> opt )
    {
        if( opt == 3 ) break;
        if( opt == 1 )
        {
            cout << "A" << cnt << " " << q.size( ) << '\n';
            q.push( cnt ++ );   
        }
        else 
        {
            if( q.empty( ) )
            {
                cout << "not exist" << '\n';
                continue;
            }
            cout << "A" << q.front( ) << '\n';
            q.pop( );
        }
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}