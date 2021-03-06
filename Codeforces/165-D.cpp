//   Author : Misael Mateus 
//   Submission date: 2017-09-15 16:58:46
#include<bits/stdc++.h>
#define MAXN 100110
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
// ----------- Seg Tree ----------//
int tree[MAXN*4];

void update(int i, int j, int n, int pos, int val){
	if(i > pos || j < pos) return;
	if(i == pos && j == pos){
		tree[n] = val;
		return ;
	}
	int mid = (i + j) >> 1;
	update(i, mid, n << 1, pos , val);
	update(mid+1, j, (n << 1) | 1, pos, val);
	tree[n] = max(tree[n << 1], tree[(n << 1) | 1]);
}

int query(int l, int r, int i, int j, int n){
	if(l > r || i > r || j < l) return (int)-(1 << 30);
	if(i >= l && j <= r){
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return max(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) | 1) );
}

// ---------------HLD------------------//

vector<ii> gr[MAXN];
int count_no[MAXN], head_chain[MAXN], belong_chain[MAXN], pos_no[MAXN], val[MAXN];
int p[MAXN], level[MAXN], k, n;

int dfs1(int u){
	count_no[u] = 1;
	for(auto v : gr[u]){
		if(v.ff == p[u]) continue;
		p[v.ff] = u;
		val[v.ff] = v.ss;
		level[v.ff] = level[u] + 1;
		count_no[u] += dfs1(v.ff);
	}
	return count_no[u];
}

void dfs(int u, int &chain, int is_head = 1){
	if(is_head)
		head_chain[chain] = u;
	belong_chain[u] = chain;
	pos_no[u] = ++k;

	int ma = -1, ind = -1;

	for(auto v : gr[u]){
		if(v.ff == p[u]) continue;
		if(count_no[v.ff] > ma)
			ma = count_no[v.ff], ind = v.ff;
	}

	if(ind != -1){
		dfs(ind, chain, 0);
	}

	for(auto v: gr[u]){
		if(v.ff == ind || v.ff == p[u]) continue;
		dfs(v.ff, ++chain);
	}
}

int query_up(int u, int v){
	if(u == v)
		return 0;
	int ans = -(1 << 30); // depends on the query
	while(1){
		if(belong_chain[u] == belong_chain[v]){
			int num = query(pos_no[v]+1, pos_no[u], 1, n, 1);
			if(num > ans) ans = num;
			break;
		}
		int chain = belong_chain[u];
		int num = query(pos_no[head_chain[chain]], pos_no[u], 1, n, 1);
		if(num > ans) ans = num;
		u = p[head_chain[chain]];
		
	}

	return ans;
}

// ------------------ LCA --------------------//

int anc[MAXN][18];

int pre_calc_lca(int n){
	for(int i = 1; i <= n; i++){
		anc[i][0] = p[i];
	}
	for(int j = 1; j < 18; j++){
		for(int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j-1]][j-1];
	}
}


int lca(int a, int b){
	if(level[a] < level[b]) swap(a, b);
	for(int l = 17; l >= 0; l--)
		if(level[a] - (1 << l) >= level[b]) 
			a = anc[a][l];
	if(a == b) return a;
	for(int l = 17; l >= 0; l--)
		if(anc[a][l] != anc[b][l]) 
			a = anc[a][l], b = anc[b][l];
	return p[a];
}


int main(){
	int a, b, type;
	scanf("%d", &n);

	int A[n-1], B[n-1];
	for(int i = 0; i < n-1; i++){
		scanf("%d %d", &A[i], &B[i]);
		gr[A[i]].push_back({B[i], 0});
		gr[B[i]].push_back({A[i], 0});
	}

	int chain = 1;
	dfs1(1);
	dfs(1, chain);
	pre_calc_lca(n);
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &type, &a);
		if(type == 3){
			scanf("%d", &b);

			int u = lca(a, b);

			int ans = max(query_up(a, u), query_up(b, u));
			if(ans == 0)
				printf("%d\n", level[a] + level[b] - 2*level[u]);
			else printf("-1\n");
		}
		else if(type == 2){
			if(p[A[a-1]] != B[a-1])
				swap(A[a-1], B[a-1]);

			update(1, n, 1, pos_no[A[a-1]], 1);
		}
		else{
				if(p[A[a-1]] != B[a-1])
					swap(A[a-1], B[a-1]);
				update(1, n, 1, pos_no[A[a-1]], 0);

		} 
	}
}