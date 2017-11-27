#include<bits/stdc++.h>
#define MAXN 100100
#define ff first
#define ss second
#define ii pair<ll, ll>
#define ll long long
using namespace std;

pair<ii, ii> tree[MAXN*3];
ll v[MAXN];
pair<ii, ii> merge(pair<ii, ii> a, pair<ii, ii> b){
	pair<ii, ii> ans;
	ans.ss.ss = a.ss.ss + b.ss.ss;
	ans.ss.ff = max(b.ss.ff, a.ss.ff + b.ss.ss);
	ans.ff.ss = max(a.ff.ss, b.ff.ss + a.ss.ss);
	ans.ff.ff = max(a.ff.ff, max(b.ff.ff, a.ss.ff + b.ff.ss));
	return ans;
}
void build(int i, int j, int n){
	if(i == j){
		tree[n].ff.ff = tree[n].ff.ss = tree[n].ss.ff = tree[n].ss.ss = v[i];
		return;
	}
	int mid = (i + j) >> 1;
	build(i, mid, n << 1);
	build(mid+1, j, (n << 1) + 1);
	tree[n] = merge(tree[n << 1], tree[(n << 1) + 1]);
}


pair<ii, ii> query(int l, int r, int i, int j, int n){
	if(i > r || j < l) {
		ii a = make_pair(-(1LL << 30) + 1, -(1LL << 30) + 1);
		return make_pair(a, a);
	}
	if(i >= l && j <= r){
		return tree[n];
	}
	int mid = (i + j) >> 1;
	return merge(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) + 1));
}

void update	(int l, int i, int j, int n, int k){
	if(i > l || j < l) {
		return ;
	}
	if(i == l && j == l){
		tree[n].ff = tree[n].ss = make_pair((ll)k, (ll)k);
		return ;
	}
	int mid = (i + j) >> 1;
	update(l, i, mid, n << 1, k);
	update(l, mid+1, j, (n << 1) + 1, k);
	tree[n] = merge(tree[n << 1], tree[(n << 1) + 1]);
}
int main(){
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);
	build(1, n, 1);
	int m;
	scanf("%d", &m);
	while(m--){
		int type, l, r;
		scanf("%d %d %d", &type, &l, &r);
		if(!type){
			update(l, 1, n, 1, r);
		}
		else{
			ll ans = query(l, r, 1, n, 1).ff.ff;
			printf("%lld\n", ans);
		}
	}
}