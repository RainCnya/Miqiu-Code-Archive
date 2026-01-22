#include<bits/stdc++.h>
using namespace std;

long long calc( vector<int> pos )
{
    int k = pos.size();
    if( k == 0 ) return 0;

    vector<long long> q;
    for( int i = 0; i < k; i ++ )
        q.push_back( pos[i] - i );
    
    sort( q.begin(), q.end() );
    long long mid = q[ k / 2 ];
    long long res = 0;
    for( auto val : q )
        res += abs( val - mid );
    
    return res;
}

int main( )
{
    int t;
    cin>>t;
    while( t -- )
    {
        int len;
        string s;
        cin >> len >> s;
        vector<int> Posa;
        vector<int> Posb;
        for( int i = 0; i < len; i ++ )
        {
            if( s[i] == 'a' ) Posa.push_back(i);
            else Posb.push_back(i);
        }
        long long mina = calc( Posa );
        long long minb = calc( Posb );
        long long ans = min( mina, minb );
        cout << ans << endl;
    }
    return 0;
}