#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 4e5 + 50;

ll cost[maxn];
ll cnt[maxn];
ll n, w;

void solve( )
{
    // 输入部分
    cin >> n >> w;
    for( int i = 1; i <= n; ++ i )
        cin >> cost[i];

    // 此处是多组数组初始化
    ll remain = w * 2;
    for( int i = 0; i < remain; ++ i ) 
        cnt[i] = 0;
    
    // 按余数分组
    for( int i = 1; i <= n; ++ i ) 
        cnt[i % remain] += cost[i];

    // 滑动窗口初始化
    ll sum = 0;
    for( int i = 0; i < w; ++ i )
        sum += cnt[i];

    // 标准滑动窗口
    ll ans = sum;
    for( int i = 0; i < remain; ++ i )
    {
        // 滑动窗口移动
        sum -= cnt[i]; 
        sum += cnt[(i + w) % remain];
        // 更新答案
        ans = min( ans, sum );
    }
    cout << ans << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}