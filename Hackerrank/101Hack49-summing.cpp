#include <bits/stdc++.h>
#define MAXN 100010
#define ll long long
#define ii pair<int, int>
using namespace std;

vector<ii > gr[MAXN];
int c[MAXN];
int cont[MAXN];
ll S[MAXN], S1[MAXN];
ll ans = 0LL;
void dfs(int u, int p){
    cont[u] += c[u];
    for(int i = 0; i < gr[u].size(); i++){
        int v = gr[u][i].first;
        if(v == p) continue;
        dfs(v, u);
        cont[u] += cont[v];
        S[u] += S[v] + (ll)cont[v]*gr[u][i].second;
    }
}

void dfs2(int u, int p, int w){
    if(!u)
        S1[u] = S[u];
    else S1[u] = S1[p] + (ll)(w)*(cont[0] - 2*cont[u]);
    
    
    if(!c[u]) 
        ans += S1[u];
    for(int i = 0; i < gr[u].size(); i++){
        int v = gr[u][i].first;
        if(v == p) continue;
        dfs2(v, u, gr[u][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        int w;
        cin >> u >> v >> w;
        u--, v--;
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
        // Write Your Code Here
    }
    dfs(0, -1);
    dfs2(0, -1, -1);
    cout << ans << "\n";
    return 0;
}
