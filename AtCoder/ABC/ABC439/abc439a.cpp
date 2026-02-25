#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int n;
    cin >> n;
    int ans = (1 << n) - 2 * n;
    cout << ans << '\n';
    return 0;
}