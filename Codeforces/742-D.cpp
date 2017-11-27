//   Author : Misael Mateus 
//   Submission date: 2016-12-06 19:53:39
#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
vector<int> gr[MAXN];
vector<int> w, beauty;
vector<int> mark;

vector< set<int> > group;
void dfs(int i, set<int>& g){
    mark[i] = 1;
    g.insert(i);
    for(int j = 0; j < gr[i].size(); j++)
    {
        int prox = gr[i][j];
        if(!mark[prox])
            dfs(prox, g);
    }
}

int main(){
    int n, m, W;
    cin >> n >> m >> W;
    w = vector<int>(n);
    beauty = vector<int>(n);
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
        cin >> beauty[i];
        
    mark = vector<int>(n, 0);
    set<int> aux;
    group.push_back(aux);
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        if(!mark[i]){
            set<int> g;
            dfs(i, g);
            group.push_back(g);
        }
    }
    
    int t = group.size();
    
    int dp[t][W+1];
    int sum_w[t], sum_b[t];
    
    for(int i = 1; i < t; i++){
        sum_w[i] = sum_b[i] = 0;
        set<int>::iterator it = group[i].begin();
        for(; it != group[i].end(); it++)
            sum_w[i] += w[*it], sum_b[i] += beauty[*it];
    }
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < t; i++){
        for(int j = 1; j <= W; j++){
            dp[i][j] = dp[i-1][j];
            if(sum_w[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i-1][j - sum_w[i]] + sum_b[i] );
            
            set<int>::iterator it = group[i].begin();
            for(; it != group[i].end(); it++)
                if(w[*it] <= j)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-w[*it]] + beauty[*it]);
            }
    }
    
    cout << dp[t-1][W] << endl;
    return 0;
}