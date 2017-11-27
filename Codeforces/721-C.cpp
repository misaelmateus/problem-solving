//   Author : Misael Mateus 
//   Submission date: 2016-10-04 00:31:56
#include<bits/stdc++.h>
#define MAXN 5100
#define ll long long
using namespace std;

ll dp[MAXN][MAXN];

vector< pair<ll, int> > arestas[MAXN];

ll calc(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == 0 && j != 1)
        return (1LL << 59);
    if(i == 0 && j == 1)
        return dp[i][j] = 0LL;
    dp[i][j] = (1LL << 59);
    for(int l = 0; l < arestas[i].size(); l++){
        int prox = arestas[i][l].second;
        ll c = arestas[i][l].first;
        dp[i][j] = min(dp[i][j], c + calc(prox, j-1));
    }
    return dp[i][j];
}

void imprimi(int i, int j){
    if(i == 0){
        cout << i+1 << " ";
        return ;
    }
    for(int l = 0; l < arestas[i].size(); l++){
        int prox = arestas[i][l].second;
        ll c = arestas[i][l].first;
        
        if(calc(i, j) == c + calc(prox, j-1) )
        {
            imprimi(prox, j-1);
            break;
        }
    }
    cout << i+1 << " ";
}
int main(){
    int n, m, T;
    cin >> n >> m >> T;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        arestas[b].push_back({c, a});
    }
    
    int resp = -1;
    for(int i = n; i > 0; i--){
        if(calc(n-1, i) <= T)
        {
            resp = i;
            break;
        }
    }
    cout << resp << endl;
    imprimi(n-1, resp);
}