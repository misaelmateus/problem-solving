#include<bits/stdc++.h>
#define MAXN 100100
#define ff first
#define ss second
#define ii pair<int, int>
#define esq ss.ff
#define dir ss.ss
#define mx ff
#define node(a) make_pair(a, make_pair(a, a))
using namespace std;

typedef pair<int, ii> node;
node tree[MAXN*3];
int v[MAXN];
node merge(node a, node b, int i1, int j1, int i2, int j2){
	node ans;
	if(v[j1] == v[j2])
		ans.dir = a.dir + b.dir;
	else ans.dir = b.dir;
	if(v[i1] == v[i2])
		ans.esq = a.esq + b.esq;
	else ans.esq = a.esq;
	ans.mx = max(a.mx, b.mx);
	if(v[j1] == v[i2]) ans.mx = max(ans.mx, a.dir + b.esq);
	return ans;
}
void build(int i, int j, int n){
	if(i == j){
		tree[n] = node(1);
		return;
	}
	int mid = (i + j) >> 1;
	build(i, mid, n << 1);
	build(mid+1, j, (n << 1) + 1);
	tree[n] = merge(tree[n << 1], tree[(n << 1) + 1], i, mid, mid+1, j);
	//cout << i << " " << j <<" = " << tree[n].mx << endl;
}

node query(int l, int r, int i, int j, int n){
	if(i > r || j < l) {
		return node(0);
	}
	if(i >= l && j <= r){
		return tree[n];
	}
	int mid = (i + j) >> 1;
	if(mid < l) return query(l, r, mid+1, j, (n << 1) + 1);
	if(mid+1 > r) return query(l, r, i, mid, n << 1); 
	return merge(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) + 1), max(l, i), mid, mid+1, min(r, j));
}
int main(){
	int n, m;
	while(scanf("%d", &n) && n){
		scanf("%d", &m);
		for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
		build(1, n, 1);
		while(m--){
			int l, r;
			scanf("%d %d", &l, &r);
			int ans = query(l, r, 1, n, 1).mx;
			printf("%d\n", ans);
		}
	}
}