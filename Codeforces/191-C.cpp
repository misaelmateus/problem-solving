//   Author : Misael Mateus 
//   Submission date: 2017-09-15 17:41:19
#include<bits/stdc++.h>
#define MAXN 100110
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
// ----------- Data Structure ----------//
int tree[MAXN];

int update(int i, int val){
	while(i < MAXN){
		tree[i] += val;
		i += (i & -i);
	}
}
int update(int i, int j, int val){
	update(j+1, -val);
	update(i, val);
}

int query(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
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

int update_up(int u, int v){
	if(u == v)
		return 0;
	int ans = -(1 << 30); // depends on the query
	while(1){
		if(belong_chain[u] == belong_chain[v]){
			update(pos_no[v]+1, pos_no[u], 1);
			break;
		}
		int chain = belong_chain[u];
		update(pos_no[head_chain[chain]], pos_no[u], 1);
		u = p[head_chain[chain]];
		
	}

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
		scanf("%d %d", &a, &b);
		int u = lca(a, b);
		update_up(a, u);
		update_up(b, u);
	}

	for(int i = 0; i < n-1; i++){
		if(p[A[i]] != B[i])
			swap(A[i], B[i]);
		printf("%d ", query( pos_no[A[i]]));
	}
}#include<bits/stdc++.h>
#define MAXN 100110
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
// ----------- Data Structure ----------//
int tree[MAXN];

int update(int i, int val){
	while(i < MAXN){
		tree[i] += val;
		i += (i & -i);
	}
}
int update(int i, int j, int val){
	update(j+1, -val);
	update(i, val);
}

int query(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
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

int update_up(int u, int v){
	if(u == v)
		return 0;
	int ans = -(1 << 30); // depends on the query
	while(1){
		if(belong_chain[u] == belong_chain[v]){
			update(pos_no[v]+1, pos_no[u], 1);
			break;
		}
		int chain = belong_chain[u];
		update(pos_no[head_chain[chain]], pos_no[u], 1);
		u = p[head_chain[chain]];
		
	}

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
		scanf("%d %d", &a, &b);
		int u = lca(a, b);
		update_up(a, u);
		update_up(b, u);
	}

	for(int i = 0; i < n-1; i++){
		if(p[A[i]] != B[i])
			swap(A[i], B[i]);
		printf("%d ", query( pos_no[A[i]]));
	}
}#include<bits/stdc++.h>
#define MAXN 100110
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
// ----------- Data Structure ----------//
int tree[MAXN];

int update(int i, int val){
	while(i < MAXN){
		tree[i] += val;
		i += (i & -i);
	}
}
int update(int i, int j, int val){
	update(j+1, -val);
	update(i, val);
}

int query(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
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

int update_up(int u, int v){
	if(u == v)
		return 0;
	int ans = -(1 << 30); // depends on the query
	while(1){
		if(belong_chain[u] == belong_chain[v]){
			update(pos_no[v]+1, pos_no[u], 1);
			break;
		}
		int chain = belong_chain[u];
		update(pos_no[head_chain[chain]], pos_no[u], 1);
		u = p[head_chain[chain]];
		
	}

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
		scanf("%d %d", &a, &b);
		int u = lca(a, b);
		update_up(a, u);
		update_up(b, u);
	}

	for(int i = 0; i < n-1; i++){
		if(p[A[i]] != B[i])
			swap(A[i], B[i]);
		printf("%d ", query( pos_no[A[i]]));
	}
}#include<bits/stdc++.h>
#define MAXN 100110
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
// ----------- Data Structure ----------//
int tree[MAXN];

int update(int i, int val){
	while(i < MAXN){
		tree[i] += val;
		i += (i & -i);
	}
}
int update(int i, int j, int val){
	update(j+1, -val);
	update(i, val);
}

int query(int i){
	int ans = 0;
	while(i > 0){
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
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

int update_up(int u, int v){
	if(u == v)
		return 0;
	int ans = -(1 << 30); // depends on the query
	while(1){
		if(belong_chain[u] == belong_chain[v]){
			update(pos_no[v]+1, pos_no[u], 1);
			break;
		}
		int chain = belong_chain[u];
		update(pos_no[head_chain[chain]], pos_no[u], 1);
		u = p[head_chain[chain]];
		
	}

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
		scanf("%d %d", &a, &b);
		int u = lca(a, b);
		update_up(a, u);
		update_up(b, u);
	}

	for(int i = 0; i < n-1; i++){
		if(p[A[i]] != B[i])
			swap(A[i], B[i]);
		printf("%d ", query( pos_no[A[i]]));
	}
}