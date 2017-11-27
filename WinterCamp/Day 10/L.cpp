#include<bits/stdc++.h>
#define MAXV 200100
#define LG_MAXV 16
using namespace std;

int root,V;
vector<int> L[MAXV],Lrev[MAXV];
int parent[MAXV],height[MAXV],dfsNum[MAXV],dfsPath[MAXV],cont;
int sdom[MAXV],idom[MAXV];

void init(int _V, int _root){
    V = _V; root = _root;

    for(int i = 0;i < V;++i){
        L[i].clear();
        Lrev[i].clear();
    }
}

void dfs(int cur){
    dfsNum[cur] = cont;
    dfsPath[cont] = cur;
    ++cont;

    for(int i = (int)L[cur].size() - 1;i >= 0;--i){
        int to = L[cur][i];

        if(dfsNum[to] == -1){
            parent[to] = cur;
            height[to] = height[cur] + 1;
            sdom[to] = dfsNum[cur];
            dfs(to);
        }else if(dfsNum[cur] < dfsNum[to]){
            sdom[to] = min(sdom[to],dfsNum[cur]);
        }else if(to != cur){
            Lrev[to].push_back(cur);
        }
    }
}

int uf_parent[MAXV],min_sdom[MAXV];

int Find(int x){
    if(uf_parent[x] != x){
        int p = uf_parent[x];
        uf_parent[x] = Find(uf_parent[x]);
        min_sdom[x] = min(min_sdom[x],min_sdom[p]);
    }

    return uf_parent[x];
}

void Union(int x, int y){
    uf_parent[x] = y;
    min_sdom[x] = min(min_sdom[x],min_sdom[y]);
}

int parent2[LG_MAXV + 1][MAXV],sdom2[LG_MAXV + 1][MAXV];

int up_sdom(int x, int up){
    int ret = x;

    for(int i = 0;i <= LG_MAXV;++i){
        if(up >> i & 1){
            if(sdom[ sdom2[i][x] ] < sdom[ret])
                ret = sdom2[i][x];
            
            x = parent2[i][x];
        }
    }

    return ret;
}

void dominator_tree(){
    memset(dfsNum,-1,sizeof(dfsNum));
    parent[root] = root;
    height[root] = 0;
    cont = 0;
    dfs(root);

    for(int i = 0;i < V;++i)
        uf_parent[i] = i;

    vector<int> sdomOrder[V];

    for(int i = cont - 1;i > 0;--i){
        int cur = dfsPath[i];

        for(int j = (int)Lrev[cur].size() - 1;j >= 0;--j){
            int to = Lrev[cur][j];
            Find(to);
            sdom[cur] = min(sdom[cur],min_sdom[to]);
        }

        min_sdom[cur] = sdom[cur];

        for(int j = (int)L[cur].size() - 1;j >= 0;--j){
            int to = L[cur][j];

            if(parent[to] == cur)
                Union(to,cur);
        }

        sdomOrder[ sdom[cur] ].push_back(cur);
    }

    for(int i = 0;i < V;++i){
        parent2[0][i] = parent[i];
        sdom2[0][i] = i;
    }

    for(int j = 1;j <= LG_MAXV;++j){
        for(int i = 0;i < V;++i){
            parent2[j][i] = parent2[j - 1][ parent2[j - 1][i] ];
            int x = sdom2[j - 1][i],y = sdom2[j - 1][ parent2[j - 1][i] ];
            sdom2[j][i] = (sdom[x] < sdom[y]? x : y);
        }
    }

    for(int i = 0;i < V;++i){
        for(int j = (int)sdomOrder[i].size() - 1;j >= 0;--j){
            int cur = sdomOrder[i][j];
            int aux = up_sdom(cur,height[cur] - height[ dfsPath[ sdom[cur] ] ]);
            idom[cur] = (sdom[aux] == sdom[cur]? dfsPath[ sdom[cur] ] : idom[aux]);
        }
    }
}

int main(){
	int n, m;
	cin >> n >> m;
	init(n+1, 1);
	vector<pair<int, int> > q;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		L[u].push_back(v);
		Lrev[v].push_back(u);
	}
	dominator_tree();
	for(int i =1 ; i <= n; i++)
		cout << idom[i] << endl;

	return 0;
}