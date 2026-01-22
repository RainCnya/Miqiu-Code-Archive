#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y ;
        int tmp;
        
        for( int i = 0; i < n; ++ i )
        {
            cin >> tmp;
        }
        for( int j = 1; j <= m; ++ j )
        {
            cin >> tmp;
        }
        cout << m + n << endl;
    }
    return 0;
}