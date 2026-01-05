#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    
    int cnt = 0;
    stack<int> stk;
    stk.push( 0 );

    for( int i = 1; i <= n; ++ i )
    {
        int x, y;
        cin >> x >> y;
        while( !stk.empty( ) && stk.top( ) > y )
            stk.pop( );
        if( y != stk.top( ) ) cnt ++;    
        stk.push( y );
    }

    cout << cnt << '\n';
    return 0;
}