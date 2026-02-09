#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

int A[maxn];
int cnt[maxn];
int sum[maxn];
int n;

void solve( )
{
    cin >> n;
    
    int maxa = -1;
    for( int i = 1; i <= n; ++ i )
    {
        int a;
        cin >> a;
        maxa = max( maxa, a );
        cnt[a] ++;
    }

    for( int i = maxa; i >= 1; -- i )
    {
        sum[i] = sum[i+1] + cnt[i];
    }

    int len = maxa;
    int carry = 0;
    for( int i = 1; i <= len; ++ i )
    {
        ll cur = sum[i] + carry;
        A[i] = cur % 10;
        carry = cur / 10;
        if( i == len && carry > 0 ) len ++;
    }

    for( int i = len; i >= 1; -- i )
    {
        cout << A[i];
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}