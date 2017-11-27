//   Author : Misael Mateus 
//   Submission date: 2016-12-14 20:07:37
#include<bits/stdc++.h>
#define ll long long
#define MAXN 200010
#define INF 1000000000000000LL
using namespace std;

vector<ll> sum_tree;
vector<ll> a;

vector<int> gr[MAXN];
vector<ll> dp;
int n;

ll dfs_sum(int v, int p){
    
    sum_tree[v] += a[v];
    
    for(int i = 0; i < gr[v].size(); i++){
        if(p != gr[v][i])
            sum_tree[v] += dfs_sum(gr[v][i], v);
    }
    
    return sum_tree[v];
}


ll f(int v, int p, int k){
    
    ll resp = -INF;
    if(k == 0 && dp[v] != INF)
        return dp[v];
    if(k == 0)
        resp = sum_tree[v];
    ll m1 = -INF, m2 = -INF;
    for(int i = 0; i < gr[v].size(); i++){
        if(p != gr[v][i]){
            if(k == 0){
                resp = max(resp, f(gr[v][i], v, 0));
            }
            if(k == 1){
                ll r1 = f(gr[v][i], v, 1), r2 = f(gr[v][i], v, 0);
                resp = max(resp, r1);
                if(r2 > m2)
                    m2 = r2;
                if(m1 < m2)
                    swap(m1, m2);
            }
        }
    }
    if(k == 1 && (m2 == -INF))
        return resp;
    if(k == 1){
        resp = max(resp, m1 + m2);
    }
    if(k == 0)
        dp[v] = resp;
    return resp;
}
int main(){
    cin >> n;
    sum_tree = vector<ll>(n, 0LL);
    a = vector<ll>(n);
    dp = vector<ll>(n, INF);
    
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    for(int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    dfs_sum(0, -1);
    
    
    ll resp = f(0, -1, 1);
    if(resp == -INF)
        cout << "Impossible" << endl;
    else cout << resp;
    
    
    return 0;
}