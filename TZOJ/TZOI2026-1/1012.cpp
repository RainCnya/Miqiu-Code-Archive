#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const double eps = 1e-8;

int n;
ll a[maxn];
ll pre[maxn], suf[maxn];

void solve()
{
    suf[n + 1] = 1e9;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--)
        suf[i] = min(suf[i + 1], a[i]);

    double res = 0;
    int k;
    vector<int> v;
    for (int i = 1; i <= n - 2; i++)
    {
        long double tmp = 1.0 * (sum - pre[i] - suf[i + 1]) / (n - i - 1);
        if (res < tmp) // res < tmp
        {
            res = tmp;
            v.clear();
            v.push_back(i);
        }
        else if (res - tmp < eps) // ==
        {
            v.push_back(i);
            res = tmp;
        }
    }
    bool first = 1;
    for (int i : v)
    {
        if (first)
            first = 0;
        else
            cout << ' ';
        cout << i;
    }
    cout << '\n';
    // cout << k << '\n';
    // cout << k << " " << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while (cin >> n)
    {
        solve();
    }
    return 0;
}