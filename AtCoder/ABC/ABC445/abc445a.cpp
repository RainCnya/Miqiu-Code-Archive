#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

void solve( )
{
    string s;
    cin >> s;
    int n = s.length( );
    if( s[0] == s[n - 1] ) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}