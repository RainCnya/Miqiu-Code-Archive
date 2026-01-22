#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;

long long a[maxn];
int pos;
int cnt = 0;
double sum = 0;
int q;

int main() 
{
    cin >> q;

    for( int i = 1; i <= q; ++ i )
    {
        int opt;    
        cin >> opt;
        if( opt == 1 )
        {
            long long x;
            cin >> x;
            a[ ++ pos ] = x;
        }
        else
        {
            long long t = a[pos];
            while( cnt < pos - 1 && ( sum + t ) / ( cnt + 1 ) > a[ cnt + 1 ] )
            {
                cnt ++;
                sum += a[cnt];
            }
            cout << fixed << setprecision(10);
            cout << t - ( sum + t ) / ( cnt + 1 ) << '\n';
        }
    }
    return 0;
}