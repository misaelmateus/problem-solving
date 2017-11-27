#include<bits/stdc++.h>
#define MAXN 100110
#define ii pair<int, int>
#define ff first
#define ss second

using namespace std;
// ----------- Seg Tree ----------//
pair<ii, ii> tree[MAXN*4];
int lazy[MAXN*4];
pair<ii, ii> merge(pair<ii, ii> a, pair<ii, ii> b){
	pair<ii, ii> ans;
	ans.ss.ss = a.ss.ss + b.ss.ss;
	ans.ss.ff = max(b.ss.ff, a.ss.ff + b.ss.ss);
	ans.ff.ss = max(a.ff.ss, b.ff.ss + a.ss.ss);
	ans.ff.ff = max(a.ff.ff, max(b.ff.ff, a.ss.ff + b.ff.ss));
	return ans;
}

void inv(pair<ii, ii> &a){
	swap(a.ss.ff, a.ff.ss);
}
void propagate(int l, int r, int n){
	if(lazy[n] == (1 << 30)) return;
	int num = max(lazy[n]*(r - l + 1), lazy[n]);
	tree[n] = {{num, num}, {num, lazy[n]*(r - l + 1)} };
	lazy[n << 1] = lazy[n];
	lazy[(n << 1) | 1] = lazy[n];
	lazy[n] = 1 << 30;
}

pair<ii, ii> query(int l, int r, int i, int j, int n){
	if(l > r) {
		ii a = make_pair(-(1 << 30) + 10, -(1 << 30) + 10);
		return make_pair(a, a);
	}
	//cout << l << " " << r << " " << i <<" " << j <<" " << n << endl;
	propagate(i, j, n);
	if(i >= l && j <= r){
		return tree[n];
	}
	int mid = (i + j) >> 1;
	if(mid+1 > r)
		return query(l, r, i, mid, n << 1);
	if(mid < l)
		return query(l, r, mid+1, j, (n << 1) + 1);
	return merge(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) + 1));
}
void update	(int i, int j, int n, int l, int r, int k){
	propagate(i, j, n);
	if(l > r || i > r || j < l) {
		return ;
	}
	if(i >= l && j <= r){
		lazy[n] = k;
		propagate(i, j, n);
		return ;
	}
	int mid = (i + j) >> 1;
	update(i, mid, n << 1, l, r, k);
	update(mid+1, j, (n << 1) + 1, l, r, k);
	tree[n] = merge(tree[n << 1], tree[(n << 1) + 1]);
}

// ---------------HLD------------------//

vector<int> gr[MAXN];
int count_no[MAXN], head_chain[MAXN], belong_chain[MAXN], pos_no[MAXN], val[MAXN];
int p[MAXN], level[MAXN], k, n;

int dfs1(int u){
	count_no[u] = 1;
	for(auto v : gr[u]){
		if(v == p[u]) continue;
		p[v] = u;
		level[v] = level[u] + 1;
		count_no[u] += dfs1(v);
	}
	return count_no[u];
}

void dfs(int u, int &chain, int is_head = 1){
	if(is_head)
		head_chain[chain] = u;
	belong_chain[u] = chain;
	pos_no[u] = ++k;
	update(1, n, 1, pos_no[u], pos_no[u], val[u]);

	int ma = -1, ind = -1;

	for(auto v : gr[u]){
		if(v == p[u]) continue;
		if(count_no[v] > ma)
			ma = count_no[v], ind = v;
	}

	if(ind != -1){
		dfs(ind, chain, 0);
	}

	for(auto v: gr[u]){
		if(v == ind || v == p[u]) continue;
		dfs(v, ++chain);
	}
}

pair<ii, ii> query_up(int u, int v, int flag = 0){
	int flag1 = 0;
	pair<ii, ii> ans = {{0, 0}, {0, 0}};
	if(u == v)
		return ans;
	while(1){
		if(belong_chain[u] == belong_chain[v]){
			if(pos_no[v] + flag > pos_no[u]) break;
			pair<ii, ii> now = query(pos_no[v] + flag, pos_no[u], 1, n, 1);
			if(flag1)
				ans = merge(now, ans);
			else ans = now;
			break;
		}
		int chain = belong_chain[u];
		pair<ii, ii> now = query(pos_no[head_chain[chain]], pos_no[u], 1, n, 1);
		if(flag1)
			ans = merge(now, ans);
		else ans = now;
		flag1 = 1;
		u = p[head_chain[chain]];
		//cout << "ans : " << ans.ff.ff << " " << ans.ff.ss << " " << ans.ss.ff <<" " << ans.ss.ss << endl;
	}
	//cout << "ans : " << ans.ff.ff << " " << ans.ff.ss << " " << ans.ss.ff <<" " << ans.ss.ss << endl;

	return ans;
}

void update_up(int u, int v, int k){
	while(1){
		//cout << u << endl;
		if(belong_chain[u] == belong_chain[v]){
			update(1, n, 1, pos_no[v], pos_no[u], k);
			break;
		}
		int chain = belong_chain[u];
		update(1, n, 1, pos_no[head_chain[chain]], pos_no[u], k);
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


//-------------------------------------------//
void clean(){
	memset(tree, 0, sizeof(tree));
	memset(count_no, 0, sizeof(count_no));
	memset(head_chain, 0, sizeof(head_chain));
	memset(pos_no, 0, sizeof(pos_no));
	for(int i =0; i < 4*MAXN; i++) lazy[i] = (1 << 30);
	for(int i = 0; i < MAXN; i++) gr[i].clear();
	k = 0;
}
int main(){
	while(scanf("%d", &n) != EOF){
		clean();
		int a, b, c;
		for(int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		for(int i = 0; i < n-1; i++){
			scanf("%d %d", &a, &b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}

		int chain = 1;
		dfs1(1);
		dfs(1, chain);
		pre_calc_lca(n);

		int q, type;
		scanf("%d", &q);
		while(q--){
			scanf("%d %d %d", &type, &a, &b);
			if(type == 1){
				int u = lca(a, b);
				pair<ii, ii> ans1 = query_up(a, u);
				pair<ii, ii> ans2 = query_up(b, u, 1);
				inv(ans1);
				ans1 = merge(ans1, ans2);
				printf("%d\n", max(ans1.ff.ff, 0));

			}
			else{
				scanf("%d", &c);
				int u = lca(a, b);
				update_up(a, u, c);
				update_up(b, u, c);
				
			}
			//cout << "-->" <<  query( pos_no[1], pos_no[2], 1, n, 1).ff.ff << endl;;
		}
	}
}