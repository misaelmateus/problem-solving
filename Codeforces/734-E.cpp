//   Author : Misael Mateus 
//   Submission date: 2016-11-18 14:51:18
#include<bits/stdc++.h>
#define MAXN 2000001
using namespace std;
vector<int> gr[MAXN], gr1[MAXN];
int n, n1;
int color[MAXN];
int ans;

int dfs(int i){
    int val1 = 0, val2 = 0;

    for(int j = 0; j < gr1[i].size(); j++){
        int next = gr1[i][j];
        val1 = max(val1, 1 + dfs(next));
        if(val1 > val2){ int aux = val1; val1 = val2, val2 = aux; }
    }
    
    ans = max(ans, val1 + val2);
    return val2;
}
int dfs0(int i, int p = -1, int actual = 1){
    for(int j = 0; j < gr[i].size(); j++){
        int next = gr[i][j];
        if(next == p)
            continue;
        if(color[next] == color[i])
            dfs0(next, i, actual);
        else{
            n1++; 
            gr1[actual].push_back(n1);
            dfs0(next, i, n1);
        }
    }
    
    return 0;
}
int main(){
    cin >> n;
    n1 = 1;
    for(int i = 1; i <= n; i++)
        cin >> color[i];
        
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs0(1);
    dfs(1);
    
    cout << (ans+1)/2 << endl;
    
    return 0;
}