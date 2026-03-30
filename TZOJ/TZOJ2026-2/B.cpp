#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
const int N = 2e5 + 5;

int n, k;
int a[N];

void solve( )
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort( a + 1, a + n + 1 );
    int hh = 1, tt = n;
    int sum = 0, cur = 0, ans = 0;

    queue<int> q;
    while(hh <= tt){
        while(hh <= tt && (sum + a[tt]) / k > cur){ //保证只加 a[tt] 不会超过 cur
            sum += a[tt];
            q.push(a[tt]); 
            ans += a[tt];
            cur += 1; 
            tt--;
        }

        while(hh <= tt && (sum + a[hh] + a[tt]) / k <= cur){
            sum += a[hh];
            q.push(a[hh]);
            hh++;
        }

        if(hh <= tt){
            sum += a[hh];
            q.push(a[hh]);
            hh++;
        }
    }
    cout << ans << '\n';
    int flag = 0;
    while(!q.empty()){
        if(flag) cout << " ";
        cout << q.front();
        flag = 1;
        q.pop();
    }
    cout << '\n';
}

signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}