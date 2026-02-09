#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    
    vector< int > s, ans;
    size_t max_stack = 0;

    for( int i = 1; i <= n; ++ i ) 
    {
        int x;
        cin >> x;
        while( !s.empty( ) && x > s.back( ) ) s.pop_back( );
        s.push_back( x );

        if( s.size( ) > max_stack ) 
        {
            max_stack = s.size( );
            ans = s;
        }
    }

    cout << max_stack << '\n';
    for( int i = max_stack - 1; i >= 0; -- i )
    {
        cout << ans[i];
        if( i != 0 ) cout << ' ';
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}