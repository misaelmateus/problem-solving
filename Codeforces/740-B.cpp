//   Author : Misael Mateus 
//   Submission date: 2016-11-23 22:02:29
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int sum[n+1];
    sum[0] = 0;
    for(int i = 1; i <= n; i++){
        int aux;
        cin >> aux;
        sum[i] = aux + sum[i-1];
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int s = sum[b] - sum[a-1];
        if(s > 0)
            ans += s;
    }
    
    cout << ans << endl;
}