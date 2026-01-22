#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

struct Horse {
    int val, idx;
} a[maxn];
int n;

bool cmp( Horse a, Horse b )
{
    return a.val < b.val;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i].val;
        a[i].idx = i;
    }

    sort( a + 1, a + n + 1, cmp );

    for( int i = 1; i <= 3; ++ i )
    {
        cout << a[i].idx << ' ';
    }

    return 0;
}