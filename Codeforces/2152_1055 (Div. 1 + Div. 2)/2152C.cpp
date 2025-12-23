#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, q;
        cin >> n >> q;
        vector<int> a( n + 1, 0 );
        for( int i = 1; i <= n; i ++ )  
            cin >> a[i];
        vector<int> con0( n + 1, 0 );
        vector<int> con1( n + 1, 0 );
        vector<int> sum0( n + 1, 0 );
        vector<int> sum1( n + 1, 0 );
        
        for( int i = 1; i <= n; i ++ )
        {
            if( a[i] == 1 )
            {
                sum1[i] = sum1[ i - 1 ] + 1;
                sum0[i] = sum0[ i - 1 ];
            }
            else
            {
                sum1[i] = sum1[ i - 1 ];
                sum0[i] = sum0[ i - 1 ] + 1;
            }
        }

        for( int i = 2; i <= n; i ++ )
        {
            if( a[i] == 1 && a[ i - 1 ] == 1 )
                con1[i] = con1[ i - 1 ] + 1;
            else
                con1[i] = con1[ i - 1 ];
            
            if( a[i] == 0 && a[ i - 1 ] == 0 )
                con0[i] = con0[ i - 1 ] + 1;
            else
                con0[i] = con0[ i - 1 ];
        }

        while( q -- )
        {
            int l, r;
            cin >> l >> r;
            int cnt0 = sum0[r] - sum0[ l - 1 ];
            int cnt1 = sum1[r] - sum1[ l - 1 ];
            
            bool cont0 = 0, cont1 = 0;
            if( cnt0 % 3 != 0 || cnt1 % 3 != 0 )
                cout << -1 << endl;
            else
            {
                if( cnt0 >= 2 )
                    cont0 = ( con0[r] - con0[l] ) > 0 ;
                if( cnt1 >= 2 )
                    cont1 = ( con1[r] - con1[l] ) > 0 ;
                
                if( cnt0 && cnt1 && !cont0 && !cont1 )
                    cout << ( cnt0 / 3 + cnt1 / 3 ) + 1 << endl;
                else
                    cout << ( cnt0 / 3 + cnt1 / 3 ) << endl;
            }
        }
    }
    return 0;
}