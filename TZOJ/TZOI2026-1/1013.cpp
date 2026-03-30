#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 20 + 5;

void solve( ){
    int n;

    cin >> n;

    vector<int> a(n+1);

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    int sum=accumulate(a.begin(),a.end(),0ll);
    if( sum % 4 != 0 )
    {
        cout << "no" << '\n';
        return ;
    }
    int len = sum / 4;
    vector<int> vis(n+1);

    sort(a.begin()+1,a.end(),greater<int>());
    
    bool flag=true;

    for (int i=1;i<(1<<n);i++){
        auto tmp=vis;

        int sum=0;
        for (int j=1;j<=n;j++){
            if (sum>len) break;
            if (i&(1<<j-1) && !tmp[j]){
                // cout << a[j] << ' ';
                tmp[j]=1;
                sum+=a[j];
            }
        }
        if (sum==len){
            vis=tmp;
            flag=false;
            // cout << i << "===" << endl;
            break;
        }
        // cout << endl;
    }

    if (flag){
        cout << "no" << '\n';
        return;
    }
    

    flag=true;

    for (int i=1;i<(1<<n);i++){
        auto tmp=vis;

        int sum=0;
        for (int j=1;j<=n;j++){
            if (sum>len) break;
            if (i&(1<<j-1) && !tmp[j]){
                // cout << a[j] << ' ';
                tmp[j]=1;
                sum+=a[j];
            }
        }
        if (sum==len){
            vis=tmp;
            flag=false;
            // cout << i << "===" << endl;
            break;
        }
        // cout << endl;
    }
    if (flag){
        cout << "no" << '\n';
        return;
    }

    flag=true;

    for (int i=1;i<(1<<n);i++){
        auto tmp=vis;

        int sum=0;
        for (int j=1;j<=n;j++){
            if (sum>len) break;
            if (i&(1<<j-1) && !tmp[j]){
                // cout << a[j] << ' ';
                tmp[j]=1;
                sum+=a[j];
            }
        }
        if (sum==len){
            vis=tmp;
            flag=false;
            // cout << i << "===" << endl;
            break;
        }
        // cout << endl;
    }
    if (flag){
        cout << "no" << '\n';
        return;
    }

    cout << "yes" << '\n';


}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}