//   Author : Misael Mateus 
//   Submission date: 2017-09-06 18:36:48
#include<bits/stdc++.h>
#define MAXN 200010
#define ll long long
#define vi vector<int>
using namespace std;
int p[MAXN];
vi tree[3*MAXN];

void build(int l, int r, int n){
	for(int i = l; i <= r; i++) tree[n].push_back(p[i]);
	sort(tree[n].begin(), tree[n].end());
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, 2*n);
	build(mid+1, r, 2*n + 1);
}

int query(int x1, int y1, int x2, int y2, int l, int r, int n){
	if(l > x2 || r < x1){
		return 0;
	}
	if(l >= x1 && r <= x2){
		return (int)(upper_bound(tree[n].begin(), tree[n].end(), y2) - lower_bound(tree[n].begin(), tree[n].end(), y1));
	}
	int mid = (l + r) >> 1;
	return query(x1, y1, x2, y2, l, mid, 2*n) + query(x1, y1, x2, y2, mid+1, r, 2*n+1);
}
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> aux;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	build(1, n, 1);

	while(q--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int a1 = query(x2+1, y2+1, n+1, n+1, 1, n, 1);
		int a2 = query(x1, y2+1, x2, n+1, 1, n, 1);
		int a3 = n - y2 - a1 - a2;
		int a5 = query(0, y1, x1-1, y2, 1, n, 1);
		int a8 = x1 - 1 - a3 - a5;
		int a4 = query(x2+1, y1, n+1, y2, 1, n, 1);
		int a6 = n - x2 - a1 - a4;
		int a7 = y1 - 1 - a8 - a6;
		int x = n - (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);
 		ll ans = (ll) x * (x-1) / 2 + (ll)a1 * (x + a5 + a7 + a8) + (ll)a2 * (x+ a5 + a4 + a6 + a7 + a8)
				+ (ll) a3 * (x + a4 + a7 + a6) + (ll) a5 * (x + a4 + a7 + a6) + (ll) x * (a8 + a7 + a6) 
				+ (ll) a4 * (x + a8 + a7);

		printf("%lld\n", ans);
	}

	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ll long long
#define vi vector<int>
using namespace std;
int p[MAXN];
vi tree[3*MAXN];

void build(int l, int r, int n){
	for(int i = l; i <= r; i++) tree[n].push_back(p[i]);
	sort(tree[n].begin(), tree[n].end());
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, 2*n);
	build(mid+1, r, 2*n + 1);
}

int query(int x1, int y1, int x2, int y2, int l, int r, int n){
	if(l > x2 || r < x1){
		return 0;
	}
	if(l >= x1 && r <= x2){
		return (int)(upper_bound(tree[n].begin(), tree[n].end(), y2) - lower_bound(tree[n].begin(), tree[n].end(), y1));
	}
	int mid = (l + r) >> 1;
	return query(x1, y1, x2, y2, l, mid, 2*n) + query(x1, y1, x2, y2, mid+1, r, 2*n+1);
}
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> aux;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	build(1, n, 1);

	while(q--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int a1 = query(x2+1, y2+1, n+1, n+1, 1, n, 1);
		int a2 = query(x1, y2+1, x2, n+1, 1, n, 1);
		int a3 = n - y2 - a1 - a2;
		int a5 = query(0, y1, x1-1, y2, 1, n, 1);
		int a8 = x1 - 1 - a3 - a5;
		int a4 = query(x2+1, y1, n+1, y2, 1, n, 1);
		int a6 = n - x2 - a1 - a4;
		int a7 = y1 - 1 - a8 - a6;
		int x = n - (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);
 		ll ans = (ll) x * (x-1) / 2 + (ll)a1 * (x + a5 + a7 + a8) + (ll)a2 * (x+ a5 + a4 + a6 + a7 + a8)
				+ (ll) a3 * (x + a4 + a7 + a6) + (ll) a5 * (x + a4 + a7 + a6) + (ll) x * (a8 + a7 + a6) 
				+ (ll) a4 * (x + a8 + a7);

		printf("%lld\n", ans);
	}

	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ll long long
#define vi vector<int>
using namespace std;
int p[MAXN];
vi tree[3*MAXN];

void build(int l, int r, int n){
	for(int i = l; i <= r; i++) tree[n].push_back(p[i]);
	sort(tree[n].begin(), tree[n].end());
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, 2*n);
	build(mid+1, r, 2*n + 1);
}

int query(int x1, int y1, int x2, int y2, int l, int r, int n){
	if(l > x2 || r < x1){
		return 0;
	}
	if(l >= x1 && r <= x2){
		return (int)(upper_bound(tree[n].begin(), tree[n].end(), y2) - lower_bound(tree[n].begin(), tree[n].end(), y1));
	}
	int mid = (l + r) >> 1;
	return query(x1, y1, x2, y2, l, mid, 2*n) + query(x1, y1, x2, y2, mid+1, r, 2*n+1);
}
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> aux;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	build(1, n, 1);

	while(q--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int a1 = query(x2+1, y2+1, n+1, n+1, 1, n, 1);
		int a2 = query(x1, y2+1, x2, n+1, 1, n, 1);
		int a3 = n - y2 - a1 - a2;
		int a5 = query(0, y1, x1-1, y2, 1, n, 1);
		int a8 = x1 - 1 - a3 - a5;
		int a4 = query(x2+1, y1, n+1, y2, 1, n, 1);
		int a6 = n - x2 - a1 - a4;
		int a7 = y1 - 1 - a8 - a6;
		int x = n - (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);
 		ll ans = (ll) x * (x-1) / 2 + (ll)a1 * (x + a5 + a7 + a8) + (ll)a2 * (x+ a5 + a4 + a6 + a7 + a8)
				+ (ll) a3 * (x + a4 + a7 + a6) + (ll) a5 * (x + a4 + a7 + a6) + (ll) x * (a8 + a7 + a6) 
				+ (ll) a4 * (x + a8 + a7);

		printf("%lld\n", ans);
	}

	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ll long long
#define vi vector<int>
using namespace std;
int p[MAXN];
vi tree[3*MAXN];

void build(int l, int r, int n){
	for(int i = l; i <= r; i++) tree[n].push_back(p[i]);
	sort(tree[n].begin(), tree[n].end());
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(l, mid, 2*n);
	build(mid+1, r, 2*n + 1);
}

int query(int x1, int y1, int x2, int y2, int l, int r, int n){
	if(l > x2 || r < x1){
		return 0;
	}
	if(l >= x1 && r <= x2){
		return (int)(upper_bound(tree[n].begin(), tree[n].end(), y2) - lower_bound(tree[n].begin(), tree[n].end(), y1));
	}
	int mid = (l + r) >> 1;
	return query(x1, y1, x2, y2, l, mid, 2*n) + query(x1, y1, x2, y2, mid+1, r, 2*n+1);
}
int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> aux;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}
	build(1, n, 1);

	while(q--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int a1 = query(x2+1, y2+1, n+1, n+1, 1, n, 1);
		int a2 = query(x1, y2+1, x2, n+1, 1, n, 1);
		int a3 = n - y2 - a1 - a2;
		int a5 = query(0, y1, x1-1, y2, 1, n, 1);
		int a8 = x1 - 1 - a3 - a5;
		int a4 = query(x2+1, y1, n+1, y2, 1, n, 1);
		int a6 = n - x2 - a1 - a4;
		int a7 = y1 - 1 - a8 - a6;
		int x = n - (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);
 		ll ans = (ll) x * (x-1) / 2 + (ll)a1 * (x + a5 + a7 + a8) + (ll)a2 * (x+ a5 + a4 + a6 + a7 + a8)
				+ (ll) a3 * (x + a4 + a7 + a6) + (ll) a5 * (x + a4 + a7 + a6) + (ll) x * (a8 + a7 + a6) 
				+ (ll) a4 * (x + a8 + a7);

		printf("%lld\n", ans);
	}

	return 0;
}