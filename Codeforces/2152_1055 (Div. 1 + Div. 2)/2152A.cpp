#include<bits/stdc++.h>
using namespace std;

const int N = 100+5;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, tmp;
        cin >> n;
        set<int> vis;
        for( int i = 1; i <= n; ++ i )
        {
            cin >> tmp;
            vis.insert(tmp);
        }
        int ans = vis.size();
        cout << ans * 2 - 1 << endl;
    }
    return 0;
}