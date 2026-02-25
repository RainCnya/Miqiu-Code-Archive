#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    
    for( int i = 1; i <= n; i ++ ) cin >> a[i];

    int cnt = 0;
    vector< int > st;
    for( int i = 1; i <= n; ++ i )
    {
        while( !st.empty( ) && st.back( ) >= a[i] ) st.pop_back( );

        if( st.empty( ) || st.back( ) != a[i] - 1 )
        {
            cnt ++;
            st.clear( );
        }
        st.push_back( a[i] );
    }
    
    cout << cnt << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}