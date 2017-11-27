#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

vector< int > gr[MAXN];

int depth[MAXN], parent[MAXN], treesz[MAXN];
int chain[MAXN], chainpos[MAXN], chainleader[MAXN];
int N, cur_chain, pos;

int treeMin[4*MAXN];
int val[MAXN];


void update(int pos, int i, int j, int n){
	if(i > pos || j < pos)
		return;
	if(i == j){
		if(treeMin[n] == MAXN) treeMin[n] = i;
		else treeMin[n] = MAXN;
		return ;
	}
	int mid = (i + j) >> 1;
	update(pos, i, mid, n << 1);
	update(pos, mid+1, j, n << 1 | 1);
	treeMin[n] = min(treeMin[n << 1], treeMin[(n << 1) | 1]);
}

int query(int l, int r, int i, int j, int n){
	//cout << n <<" " << i <<" " << j <<" " << l <<" " << r << endl;
	if(i > r || j < l) return MAXN;
	if(i >= l && j <= r)
		return treeMin[n];
	int mid = (i + j) >> 1;
	return min(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) | 1) );
}
void explore(int u) {
	int v;
	treesz[u] = 1;
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i];
        if (parent[ v ] == -1) {
			parent[ v ] = u;
			depth[ v ] = depth[ u ]+1;
			explore(v);
			treesz[ u ] += treesz[ v ];
		}
	}
}

void decompose(int u, bool light = true) {
	if (light) {
		++cur_chain;
		chainleader[ cur_chain ] = u;
	}
	
	chain[ u ] = cur_chain;
	chainpos[ u ] = ++pos;
	val[pos] = u;
	
	int v, ind = -1, mx = -1;
	for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
		v = gr[u][i];
        if (parent[ v ] == u && (mx == -1 || treesz[mx] < treesz[v]))
			mx = v, ind = i;
	}
	
	if (mx != -1) {
		decompose(mx, false);
	}
	
	for (size_t i = 0, sz = gr[u].size(); i < sz; ++i) {
		v = gr[u][i];
        if (parent[ v ] == u && v != mx) {
			decompose( v );
		}
	}		
}


int query_up(int u){
	int ans = MAXN;
	while(1){
		//cout << u <<" " << chainleader[chain[u]] << endl;
		//cout << chainpos[1] << " " << chainpos[u] << " " << N << endl;
		if(chain[u] == chain[1]){
			ans = min(ans, query(chainpos[1], chainpos[u], 1, N, 1));
			break;
		}
		int v = chainleader[chain[u]];
		ans = min(ans, query(chainpos[v], chainpos[u], 1, N, 1));
		u = parent[v];
	}


	return ans;
}
int lca(int u, int v) {
	while (chain[u] != chain[v]) {
		if (depth[ chainleader[chain[u]] ] < depth[ chainleader[chain[v]] ])
			v = parent[ chainleader[ chain[v] ] ];
		else
			u = parent[ chainleader[ chain[u] ] ];
	}
	if (depth[u] < depth[v]) return u;
	return v;
}

int main(){
	memset(parent, -1, sizeof(parent));
	int q;
	scanf("%d %d", &N, &q);
	for(int i = 1; i <= N; i++)
		update(i, 1, N, 1);
	for(int i = 0; i < N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);

		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	parent[1] = 0;
	explore(1);
	decompose(1);
	for(int i = 0; i < q; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a){
			int ans = query_up(b);
			if(ans == MAXN) ans = -1;
			else ans = val[ans];
			printf("%d\n", ans);
		}
		else{
			update(chainpos[b], 1, N, 1);
		}
	}

	return 0;
}