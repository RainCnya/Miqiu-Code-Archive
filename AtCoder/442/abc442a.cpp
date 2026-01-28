#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s;
    cin >> s;
    int ans = 0;
    for( char c : s )
    {
        if( c == 'i' || c == 'j' ) ans ++;
    }

    cout << ans << '\n';
    return 0;
}