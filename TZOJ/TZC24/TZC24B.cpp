#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

int cnt[maxn];
int n;

int main( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        cnt[x] ++;
    }

    int ans = 0, sum = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( cnt[i] > sum )
        {
            sum = cnt[i];
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}