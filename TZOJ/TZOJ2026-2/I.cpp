#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 2e5 + 5;

ll n, d, m;

int a[N], pre[N], pre_p[N]; 

void solve( )
{
    cin >> n >> d >> m;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        a[i] = x;
        // cin >> a[i];
    }

    if(m == 1){
        cout << 1 << '\n';
        return;
    }

    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n;i ++){
        pre[i] = pre[i - 1] + a[i];
        pre_p[i] = pre_p[i - 1] + pre[i];
    }

    int idx = lower_bound( pre + 1, pre + 1 + n, d) - pre - 1;

    int k = 1, res = d * m;
    //cout << idx << endl;
    for(int i = 1; i <= idx; i ++){
        int t = d * (k + i) - pre_p[i];
        //cout << i << " " << t << " " << pre_p[i] << endl;
        if(t >= res){
            cout << (ll)(i + 1) << "\n";
            return;
        }
    }

    cout << -1 << '\n';

}

signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}