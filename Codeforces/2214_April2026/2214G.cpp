#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n; cin >> n;
    string s = "bigchadjeff";
    for( int i = 1; i <= n; ++ i ) {
        int a; cin >> a;
        cout << s[a - 1] << '\n';
    }
}

int main( )
{
    cin.tie( 0 )->sync_with_stdio( 0 );
    solve( );
    return 0;
}