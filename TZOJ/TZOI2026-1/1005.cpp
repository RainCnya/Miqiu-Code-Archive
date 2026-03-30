#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ff(ll x)
{

    vector<int> v;
    while (x)
    {
        v.push_back(x % 2);
        x /= 2;
    }

    // reverse(v.begin(), v.end());
    int st = 0;
    while (v[st] == 0)
        st++;

    int len = v.size();
    if (st == len - 1)
        return 0;
    int cnt = 0;
    for (int i = st; i < len; ++i)
    {
        if (v[i] != v[len - (i - st) - 1])
            return 0;
        if (v[i] == 1)
        {
            cnt++;
        }
    }
    if (cnt % 2)
        return 0;
    return 1;
}
// Program exited with code: 3221225477

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << ff(4);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            cout << "YES" << '\n';
            continue;
        }
        if (ff(x))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}