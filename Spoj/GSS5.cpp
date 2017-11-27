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
		ii a = make_pair(-(1LL << 30), -(1LL << 30));
		return make_pair(a, a);
	}
	if(i >= l && j <= r){
		return tree[n];
	}
	int mid = (i + j) >> 1;
	if(mid < l) return query(l, r, mid+1, j, (n << 1) + 1);
	if(mid + 1 > r) return query(l, r, i, mid, n << 1);
	return merge(query(l, r, i, mid, n << 1), query(l, r, mid+1, j, (n << 1) + 1));
}
int main(){
	int T;
	scanf("%d\n", &T);
	while(T--){
		memset(tree, 0, sizeof(tree));

		int n;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++) scanf("%lld", &v[i]);
		build(1, n, 1);
		int m;
		scanf("%d", &m);
		while(m--){
			int l1, r1, l2, r2;
			scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
			ll ans = 0;
			if(r1 == l2 - 1){
				ll a = query(l1, r1, 1, n, 1).ss.ff, b = query(l2, r2, 1, n, 1).ff.ss;
				ans = a+b;
			}
			else if(r1 < l2){
				ans = query(r1+1, l2-1, 1, n, 1).ss.ss + query(l1, r1, 1, n, 1).ss.ff +  query(l2, r2, 1, n, 1).ff.ss;
			}
			else{
				ans = query(l2, r1, 1, n, 1).ff.ff;
				ll a, b;
			
				a = query(l1, r1, 1, n, 1).ss.ff;
				b = query(r1+1, r2, 1, n, 1).ff.ss;
				ans = max(ans, max(a, a+b));

				a = query(l1, l2-1, 1, n, 1).ss.ff;
				b = query(l2, r2, 1, n, 1).ff.ss;
				ans = max(ans, max(b, a+b));
			}
			printf("%lld\n", ans);
		}
	}
}
