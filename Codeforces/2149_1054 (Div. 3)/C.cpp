#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, k;
        cin >> n >> k;
        set<int> vis;
        int remove = 0;
        for( int i = 0; i < n; ++ i )
        {
            int x; cin >> x;
            if( 0 <= x && x < k ) {
                vis.insert( x );
            } else if( x == k ) {
                remove ++;
            }           
        }
        int need = k - vis.size( );
        cout << max( need, remove ) << endl;
    }
    return 0;
}