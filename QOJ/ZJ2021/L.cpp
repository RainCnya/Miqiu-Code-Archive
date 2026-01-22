#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;

    char c = s[0];

    for( int i = 1; i < n; ++ i )
    {
        if( s[i] == c )
        {
            cout << "Wrong Answer" << '\n';
            return 0;
        }
    }

    cout << "Correct" << '\n';
    return 0;
}