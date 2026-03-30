#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a, b, c;

int calc(int x, int k){ //数字 x k进制
    int res = 0, cnt = 1;
    while(x){
        res += (x % 10) * cnt; 
        cnt *= k;
        x /= 10;
    }
    return res;
}

int check(int x){
    int maxx = -1;
    while( x ) 
    {
        maxx = max( maxx, x % 10 );
        x /= 10;
    }
    return maxx + 1;
}

void solve( )
{
    cin >> a >> b >> c;
    
    int st1 = check(a);
    int st2 = check(b);

    for(int i = st1; i <= 10; i++){
        for(int j = st2; j <= 10; j++){
            if(calc(a, i) + calc(b, j) == c){
                cout << i << " " << j << endl;
                return;
            }
        }
    }
    
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}