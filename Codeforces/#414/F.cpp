#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 100100
#define readFast ios::sync_with_stdio(false)
using namespace std;

ll tree[MAXN*4][10];
vector<int> lazy[MAXN*4];
ll v[MAXN];
void build(int i, int j, int n){
	xfor(int l = 0; l <= 9; l++)
		lazy[l] = l;
	if(i == j){
		ll pot = 1;
		while(v[i]){
			tree[n][v[i] % 10] += pot;
			v[i] /= 10;
			pot *= 10;
		}
		return;
	}
	int mid = (i + j) >> 1;
	build(i, mid, n << 1);
	build(mid+1, j, n << 1 | 1);

	rep(l, 10) tree[n][l] = tree[n << 1][l] + tree[n << 1 | 1][l];
}

ll aux[10];
void push(int n){
	rep(l, 10)
		aux[l] = tree[n][l];
	rep(l, 10)
		tree[n][l] = aux[lazy[n][l]];

	rep(l, 10)
		aux[l] = lazy[n << 1][l];
	rep(l, 10)
		lazy[n << 1][l] = aux[lazy[n][l]];

	rep(l, 10)
		aux[l] = lazy[n << 1 | 1][l];
	rep(l, 10)
		lazy[n << 1 | 1][l] = aux[lazy[n][l]];

	rep(l, 10)
		lazy[l] = l;
}

void update(int l, int r, int i, int j, int n, int p1, int p2){
	push(n);
	if(i > r || j < l) continue;
	if(i >= l && j <= r){
		lazy[n][p1] = p2;
		push(n);
		return ;
	}
	int mid = (i + j) >> 1;
	update(l, r, i, mid, j, n << 1, p1, p2);
	update(l, r, mid+1, j, n << 1 | 1, p1, p2);
}

ll sum(int l, int r, int i, int j, int n){
	if(i > r || j < l) return 0LL;
	push(n);
	if(i >= l && j <= r){
		ll ans = 0LL;
		rep(k, 10)
			ans += k*tree[n][k];
		return ans;
	}
	int mid = (i + j) >> 1;
	return sum(l, r, i, mid, n << 1) + sum(l, r, mid+1, j, n << 1 | 1);
}
int main(){
	readFast;
	int n, q;
	cin >> n >> q;
	rep(i, n)
		cin >> v[i+1];

	build(1, n, 1);
	while(q--){
		int type, l, r, x, y;
		cin >> type >> l >> r;
		if(type == 1){
			cin >> x >> y;
			update(l, r, 1, n, 1, x, y);
		}
		else {
			ll ans = sum(l, r, 1, n, 1);
			cout << ans << "\n";
		}
	}
	return 0;
}