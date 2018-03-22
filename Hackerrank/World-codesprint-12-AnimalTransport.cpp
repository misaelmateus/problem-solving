#include <bits/stdc++.h>

#define MAXN 100010
using namespace std;
int tree[4*MAXN][2];
int lazy[4*MAXN][2];

void push(int n, int l){
    if(!lazy[n][l])
        return;
    tree[n][l] += lazy[n][l];
    lazy[n << 1][l] += lazy[n][l];
    lazy[n << 1 | 1][l] += lazy[n][l];
    lazy[n][l] = 0;
}
void change(int p, int i, int j, int n, int k, int l){
    push(n, l);
    if(i == j){
        tree[n][l] = k;
        return ;
    }
    int mid = (i + j) >> 1;
    if(mid >= p)
        change(p, i, mid, n << 1, k, l);
    else change(p, mid+1, j, n << 1 | 1, k, l);
    tree[n][l] = max(tree[n << 1][l], tree[n << 1 | 1][l]);
}

void sum_1(int l, int r, int i, int j, int n, int k){
    push(n, k);
    if(l > j || r < i)
        return ;
    if(i >= l && j <= r)
    {
        lazy[n][k] ++;
        push(n, k);
        return ;
    }
    int mid = (i+j) >> 1;
    sum_1(l, r, i, mid, n << 1,k);
    sum_1(l, r, mid+1, j, n << 1 | 1, k);
    tree[n][k] = max(tree[n << 1][k], tree[n << 1 | 1][k]);
}

int get_max(int l, int r, int i, int j, int n, int k){
    push(n, k);
    if(l > j || r < i)
        return 0;
    if(i >= l && j <= r)
    {
        return tree[n][k];
    }
    int mid = (i + j) >> 1;
    return max(get_max(l, r, i, mid, n << 1, k),
    get_max(l, r, mid+1, j, n << 1 | 1, k));
}

int main() {
    int cases;
    cin >> cases;
    for(int a0 = 0; a0 < cases; a0++){
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        int m;
        int n;
        cin >> m >> n;
        vector<char> t(n);
        vector<int> type(n);
        for(int t_i = 0; t_i < n; t_i++){
           cin >> t[t_i];
           if(t[t_i] == 'E' || t[t_i] == 'C')
               type[t_i] = 0;
           else type[t_i] = 1;
        }
        vector<int> a(n);
        for(int s_i = 0; s_i < n; s_i++){
           cin >> a[s_i];
        }
        vector<int> b(n);
        vector<int> en[m+1][2];
        for(int d_i = 0; d_i < n; d_i++){
           cin >> b[d_i];
            if(b[d_i] < a[d_i]) continue;
           en[b[d_i]][type[d_i]].push_back(a[d_i]);
        }
        
        vector<int> dp(m+1, 0);
        int best = 0;
        for(int i = 1; i <= m; i++){
            for(int l = 0; l <= 1; l++){
                for(auto u : en[i][l]){
                    sum_1(1, u, 1, m, 1, l);
                    //cout << i << " " << l << " " << u << endl;
                }
            }
            dp[i] = max(get_max(1, i, 1, m, 1, 0), get_max(1, i, 1, m, 1, 1));
            change(i, 1, m, 1, dp[i], 0);
            change(i, 1, m, 1, dp[i], 1);
        }
        
        vector<int> ans(n+1, -1);
        for(int i = 1; i <= m; i++)
            if(ans[dp[i]] == -1) ans[dp[i]] = i;
        for(int i = n-1; i >= 1; i--)
            if(ans[i] == -1)
                ans[i] = ans[i+1];
            
        for(int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}



