#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int tree[MAXN];
int sum(int u){
    u++;
    int sum = 0;
    while( u > 0 )
        sum = (sum + tree[u]) % (int)(1e9), u -= (u & -u);
    return sum;
}

void update(int u, int k){
    u++;
    while( u < MAXN ){
        tree[u] = (tree[u] + k) % (int)(1e9);
        if(tree[u] < 0)
            tree[u] += (int)(1e9);
        u += (u & -u);
       
    }
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> A(n);
    set< int > no_zero;
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    int fat[41];
    fat[0] = 1;
    for(int i = 1; i <= 40; i++){
        fat[i] = ((long)fat[i-1]*i) % (int)(1e9);
    }
    for(int i = 0; i < n; i++){
        if(fat[min(40, A[i])] != 0)
            no_zero.insert(i), update(i, fat[A[i]]);
    }
    
    for(int a0 = 0; a0 < m; a0++){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1){
            r--, l--;
            vector<int> er;
            for(auto u = lower_bound(no_zero.begin(), no_zero.end(), l); u != no_zero.end() && *u <= r; u++){
                update(*u, -fat[A[*u]]);
                A[*u]++;
                update(*u, +fat[A[*u]]);
                if(A[*u] >= 40)
                    er.push_back(*u);
            }
            for(auto u : er)
                no_zero.erase(u);
        }
        else if(type == 2){
            r--, l--;
            int ans = (sum(r) - sum(l-1) + (int)(1e9))%(int)(1e9);
            cout << ans << "\n";
        }
        else{
            l--;
            auto u = no_zero.find(l);
            if(u != no_zero.end())
            {
                update(l, -fat[A[l]]);
                no_zero.erase(u);
            }
            A[l] = 40;
            if(r < 40){
                update(l, fat[r]);
                A[l] = r;
                no_zero.insert(l);
            }
        }
    }
    return 0;
}
