#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

void solve( )
{
    int n;
    cin >> n;
    int a = n / 100;
    int b = n / 10 % 10;
    int c = n % 10;
    if( a == b && b == c) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}