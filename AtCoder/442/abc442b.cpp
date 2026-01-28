#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int Q;
    cin >> Q;

    int sound = 0;
    bool open = 0;
    for( int i = 1; i <= Q; ++ i )
    {
        int a;
        cin >> a;
        if( a == 1 )
        {
            sound ++;
        }
        else if( a == 2 )
        {
            if( sound > 0 )
                sound --;
        }
        else
        {
            open = !open;
        }
        if( sound >= 3 && open ) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}