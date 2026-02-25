#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

bool vis1[26];
bool vis2[26];

int n, m, q;
string s1, s2;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    cin >> s1 >> s2;

    for( int i = 0; i < n; ++ i )
    {
        vis1[ s1[i] - 'a' ] = 1;
    }

    for( int i = 0; i < m; ++ i )
    {
        vis2[ s2[i] - 'a' ] = 1;
    }


    cin >> q;

    while( q -- )
    {
        string w;
        cin >> w;

        bool ok1 = 1, ok2 = 1;
        for( char c : w )
        {
            if( !vis1[ c - 'a' ] ) ok1 = 0;
            if( !vis2[ c - 'a' ] ) ok2 = 0;
        }

        if( ok1 && ok2 ) cout << "Unknown" << '\n';
        else if( ok1 ) cout << "Takahashi" << '\n';
        else cout << "Aoki" << '\n';

    }

    return 0;
}