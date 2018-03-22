#include<bits/stdc++.h>
using namespace std;
#define MAXN 50010
#define ii pair<int, int>
 
int N, M;
int low[MAXN], lbl[MAXN], dfsnum;
bool stkd[MAXN];
stack< int > scc;

int num[MAXN];
vector<int> gr[MAXN];
vector<int> gr1[MAXN];
vector<ii> query[MAXN];
bitset<MAXN> bit[MAXN];

int parent[MAXN];
int cont;
void dfs( int u ){
    lbl[u] = low[u] = dfsnum++;
    scc.push( u );
    stkd[u] = true;
    int v;

    for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
        v = gr[u][i];
        if( lbl[v] == -1 ) dfs( v );
        if( stkd[v] ) low[u] = min( low[u], low[v] );
    }
    if( low[u] == lbl[u] ){  // new component found..
        while( !scc.empty() && scc.top() != u ){
        	parent[scc.top()] = cont;
            stkd[ scc.top() ] = false;
            scc.pop(); 
        }
        if(scc.size())
        	parent[scc.top()] = cont;
        cont++;
        scc.pop(); stkd[u] = false;
    }
}

int main()
{
	memset(lbl, -1, sizeof(lbl));
	dfsnum = 1;
	scanf("%d %d", &N, &M);
	int a, b;
	while(M--){
		int a, b;
		scanf("%d %d", &a, &b);
		gr[a].push_back(b);
	}
	for(int i = 1; i <= N; i++){
		if(lbl[i]==-1) dfs(i);
	}

	map<ii, int> mapa;
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < gr[i].size(); j++){
			int u = gr[i][j];
			if(!mapa[{parent[i], parent[u]}] && parent[u] != parent[i])
				gr1[parent[i]].push_back(parent[u]);
		}
	}
	for(int i = 0; i < cont; i++)
		gr[i] = gr1[i], gr1[i].clear();
	for(int i = 0; i < cont; i++){
		for(int j = 0; j < gr[i].size(); j++){
			int u = gr[i][j];
			if(u != i)
				gr1[u].push_back(i);
		}
	}
	for(int i = cont; i <= N; i++) gr[i].clear(), gr1[i].clear();
	int Q;
	vector<ii> query_ord;
	scanf("%d", &Q);
	while(Q--){
		int type, a, b;
		cin >> type >> a >> b;
		if(type == 1){
			if(!b) gr[parent[a]].push_back(cont), gr1[cont++].push_back(parent[a]);
			else gr[cont].push_back(parent[a]), gr1[parent[a]].push_back(cont++);
			parent[++N] = cont-1;
		}
		else{
			query[parent[b]].push_back({parent[a], 0});
			query_ord.push_back({parent[a], parent[b]});
		}
	}
	queue<int> q;
	for(int i = 0; i < cont; i++){
		if(!gr1[i].size()) {
			q.push(i);
			num[i] = 1;
		}
		
	}

	while(!q.empty()){
		int i = q.front();
		bit[i][i] = 1;
		q.pop();
		for(int j = 0; j < query[i].size(); j++){
			int u = query[i][j].first;
			if(bit[i][u]) query[i][j].second = 1;
		}
		for(int j = 0; j < gr[i].size(); j++){
			num[gr[i][j]]++;
			bit[gr[i][j]] |= bit[i];
			if(num[gr[i][j]] == gr1[gr[i][j]].size())
				q.push(gr[i][j]);
		}
	}

	for(int i = 0; i < cont; i++)
		sort(query[i].begin(), query[i].end());
	for(int i = 0; i < query_ord.size(); i++){
		int a = query_ord[i].first, b = query_ord[i].second;
		int ans = (*lower_bound(query[b].begin(), query[b].end(), (ii){a, -1})).second;
		if(ans == 1)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}