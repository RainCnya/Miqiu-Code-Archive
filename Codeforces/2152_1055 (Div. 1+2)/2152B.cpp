#include<bits/stdc++.h>
using namespace std;

long long max( long long a, long long b )
{
    return a > b ? a : b;
}

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        long long n, rK, cK, rD, cD;
        cin >> n >> rK >> cK >> rD >> cD;
        long long ans = 0;
        
        if( rK > rD )
            ans = max( ans, n - rD );
        else if( rK < rD )
            ans = max( ans, rD );
        
        if( cK > cD )
            ans = max( ans, n - cD );
        else if( cK < cD )
            ans = max( ans, cD );
        
        cout << ans << endl;
    }
    return 0;
}