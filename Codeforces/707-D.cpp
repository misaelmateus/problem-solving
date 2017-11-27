//   Author : Misael Mateus 
//   Submission date: 2016-11-18 01:52:56
#include<bits/stdc++.h>
#define MAXN 1010
#define MAXQ 100010
using namespace std;

struct {
    int type, a, b;
} Q[MAXQ];

vector<int> gr[MAXQ];
int v[MAXN][MAXN];
int ans, n, m, q;
int final[MAXQ];
void inv(int i){
    if(Q[i].type == 1)
        Q[i].type = 2;
    else if(Q[i].type == 2)
        Q[i].type = 1;
}
void change(int i){
    if(Q[i].type == 1){
        if(v[Q[i].a][Q[i].b] == 1){
            Q[i].type = 0;
            return;
        }
        v[Q[i].a][Q[i].b] = 1;
        ans++;
    }
    else if(Q[i].type == 2){
        if(v[Q[i].a][Q[i].b] == 0){
            Q[i].type = 0;
            return;
        }
        v[Q[i].a][Q[i].b] = 0;
        ans--;
    }
    else if(Q[i].type == 3){
        int cont = 0;
        for(int j = 1; j <= m; j++)
            v[Q[i].a][j] ^= 1, cont += v[Q[i].a][j];
        ans += cont - (m - cont);
    }
}

int dfs(int u){
    change(u);
    final[u] = ans;
    for(int i = 0; i < gr[u].size(); i++){
        int next = gr[u][i];
        dfs(next);
    }
    inv(u);
    change(u);
    inv(u);
}
int main(){
    
    cin >> n >> m >> q;
    
    for(int i = 1; i <= q; i++){
        cin >> Q[i].type >> Q[i].a;
        if(Q[i].type <= 2)
            cin >> Q[i].b;
        if(Q[i].type == 4)
            gr[Q[i].a].push_back(i);
        else
            gr[i-1].push_back(i);
    }
    
    dfs(0);
    for(int i = 1; i <= q; i++)
        cout << final[i] << endl;
}