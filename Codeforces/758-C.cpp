//   Author : Misael Mateus 
//   Submission date: 2017-01-19 21:01:00
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll r[111][111];
int main(){
    ll n, m, x, y;
    ll k;
    cin >> n >> m >> k >> x >> y;
    ll a;
    if(n == 1){
        a = k / (ll) m;
        k %= (ll)(m);
    }
    else{
        a = k / (ll)((2*n - 2)*m);
        
        k %= (ll)((2*n - 2)*m);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            r[i][j] = a*2;
            if(i == 1 || i == n)
                r[i][j] -= a;
            
        }
    }
    
    for(int i = 1; i <= n && k > 0; i++){
        for(int j = 1; j <= m && k > 0; j++){
            r[i][j] += 1LL;
            k--;
        }
    }
    for(int i = n-1; i > 0 && k > 0; i--){
        for(int j = 1; j <= m && k > 0; j++){
            r[i][j] += 1LL;
            k--;
        }
    }
    
    ll me = 1000000000000000000LL, ma = 0LL;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            me = min(me, r[i][j]);
            ma = max(ma, r[i][j]);
            
        }
        
    cout << ma << " " << me << " " << r[x][y] << "\n";
    return 0;
}