#include<bits/stdc++.h>
using namespace std;

long long count(int k, int n, int l, int r, vector<int> &a)
{
    if( k < 0 ) return 0;
    map<int, int> cnt;
    int now = 0;
    int left = 0;
    long long ans = 0;

    for( int right = 0; right < n; ++ right )
    {
        int num = a[right];
        if( cnt[num] == 0 )
            now ++;
        cnt[num] ++;

        while( now > k && left <= right )
        {
            int del = a[left];
            cnt[del] --;
            if( cnt[del] == 0 )
                now --;
            left ++;
        }
        int L = max( left, right - r + 1 );
        int R = right - l + 1;
        if( R >= L )
            ans += (R - L + 1);
    }
    return ans;
}

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; i ++ )
            cin >> a[i];
        long long ans = count(k, n, l, r, a) - count(k - 1, n, l, r, a);
        cout << ans << endl;
    }
    return 0;
}