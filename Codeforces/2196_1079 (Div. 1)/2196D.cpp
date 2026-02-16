#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

string s;
int n;

void solve( )
{
    cin >> n >> s;

    vector< bool > vis( n, 0 );
    stack< int > st1, st2;

    for( int i = 0; i < n; ++ i )
    {
        if( s[i] == '(' ) st1.push( i );
        else if( s[i] == '[' ) st2.push( i );
        else if( s[i] == ')' )
        {
            if( st1.empty( ) ) continue;
            vis[i] = vis[st1.top( )] = 1;
            st1.pop( );
        }
        else if( s[i] == ']' )
        {
            if( st2.empty( ) ) continue;
            vis[i] = vis[st2.top( )] = 1;
            st2.pop( );
        }
    }

    ll ans = 0;
    int cnt = 0;
    stack< int > st;
    for( int i = 0; i < n; ++ i )
    {
        if( vis[i] ) continue;
        if( s[i] == '(' || s[i] == '[' ) st.push( i );
        else
        {
            if( st.empty( ) ) continue;
            vis[i] = vis[st.top( )] = 1;
            st.pop( );
            ans ++;
            cnt ++;
        }
    }

    int left = 0, right = 0;

    for( int i = 0; i < n; ++ i )
    {
        if( vis[i] ) continue;
        if( s[i] == '(' || s[i] == '[' ) left ++;
        else right ++;
    }

    ans += ( left + right ) / 2;
    if( left % 2 ) ans ++;

    if( left % 2 && cnt ) ans --;
    
    cout << ans << '\n';
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