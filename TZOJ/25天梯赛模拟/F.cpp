#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

string s, s1, s2;
char c1, c2, c4;
int n, opt;

void solve( )
{
    cin >> n >> s;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> opt;

        if( opt == 1 ) 
        {
            cin >> s1;
            size_t p = s.find( s1 );
            if( p == string::npos ) cout << -1 << '\n';
            else cout << p << '\n';
        }
        else if( opt == 2 )
        {
            cin >> s1 >> s2;
            size_t p = s.find( s1 );
            if( p != string::npos ) s.replace( p, s1.length( ), s2 );
            cout << s << '\n';
        }
        else
        {
            cin >> c1 >> c2 >> s1;
            string ts = "";
            int len = s.length( );
            for( int i = 0; i < len; ++ i )
            {
                ts += s[i];
                if( i + 1 < len && s[i] == c1 && s[i + 1] == c2 ) ts += s1;
            }
            s = ts;
            cout << s << '\n';
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}