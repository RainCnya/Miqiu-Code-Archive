#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int T;
    cin >> T;
    while( T -- )
    {
        int n, tmp;
        cin >> n;
        int zero = 0, negtive = 0; 
        for( int i = 0; i < n; ++ i )
        {
            cin >> tmp;
            if( tmp < 0 ) negtive ++;
            else if( tmp == 0 ) zero ++;
        }

        int ans = zero;

        if( negtive % 2 == 1 )
            ans += 2;
        
        cout << ans << endl;
    }
    return 0;
}