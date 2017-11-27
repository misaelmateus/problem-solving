//   Author : Misael Mateus 
//   Submission date: 2016-08-29 18:10:26
#include<bits/stdc++.h>
#define ll long long 
#define ii pair<int, int>
#define L 10000000000000LL
using namespace std;
int main(){
    int n, m, K;
    cin >> n >> m >> K;
    int cor[n];
    ll p[n][m];
    ll dp[n][m+1][K+1];
    ll men[n][m+1];
    ll cont[n][m+1];
    ll seg[n][m+1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= m; j++)
            for(int l = 0; l <= K; l++)
                dp[i][j][l] = L;
                
    for(int i = 0; i < n; i++)
        cin >> cor[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> p[i][j];
    
    if(cor[0] == 0){
        for(int l = 1; l <= m; l++)
            dp[0][l][1] = p[0][l-1];
    }
    else{
        dp[0][cor[0]][1] = 0LL;
    }
    
    for(int i = 1; i < n; i++){
        for(int k = 1; k <= K; k++){
            for(int j = 1; j <= m; j++){
            
                if(cor[i] && cor[i] != j)
                    continue;
                dp[i][j][k] = dp[i-1][j][k] + ((cor[i] == 0) ? p[i][j-1] : 0LL);
                for(int o = 1; o <= m; o++)
                    if(o != j)
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][o][k-1] + ((cor[i] == 0) ? p[i][j-1] : 0LL));
            }
        }
        
    }
    ll resp = L*10LL;
    for(int i = 1; i <= m; i++)
        resp = min(resp, dp[n-1][i][K]);
    if(resp >= L)
        cout << "-1" << endl;
    else
        cout << resp << endl;
        
    return 0;
}