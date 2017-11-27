#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
#define MAXN 300000
vi tree[4*MAXN];

vi v[MAXN];
int p[MAXN], r[MAXN], N;
vector<int> p1, r1;
vi build(int i, int j, int n){
	if(i == j){
		sort(v[i].begin(), v[i].end());
		return tree[n] = v[i];
	}
	vi a, b;
	int middle = (i + j) >> 1;
	a = build(i, middle, n*2);
	b = build(middle+1, j, n*2 + 1);
	vi v1(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), v1.begin());
	return tree[n] = v1;
}

int Query(int e, int f, int g, int h, int i, int j, int n){
	if(i > f || j < e)
		return 0;
	if(i >= e && j <= f){
		auto it1 = lower_bound(tree[n].begin(), tree[n].end(), g);
		auto it2 = upper_bound(tree[n].begin(), tree[n].end(), h);

		return (int)(it2 - it1);
	}
	int middle = (i + j) >> 1;
	return Query(e, f, g, h, i, middle, 2*n) + Query(e, f, g, h, middle+1, j, 2*n + 1);
}

int query(int e, int f, int g, int h){
	int e1, f1, g1, h1;
	e1 = (int)(lower_bound(p1.begin(), p1.end(), e) - p1.begin()) + 1;
	g1 = (int)(lower_bound(r1.begin(), r1.end(), g) - r1.begin()) + 1;
	f1 = (int)(upper_bound(p1.begin(), p1.end(), f) - p1.begin());
	h1 = (int)(upper_bound(r1.begin(), r1.end(), h) - r1.begin());
	if(e1 > f1 || g1 > h1)
		return 0;
	return Query(e1, f1, g1, h1, 1, N, 1);
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> p[i] >> r[i];
		p1.push_back(p[i]);
		r1.push_back(r[i]);
	}

	sort(p1.begin(), p1.end());
	sort(r1.begin(), r1.end());

	for(int i = 0; i < N; i++){
		int a, b;
		a = (int)(lower_bound(p1.begin(), p1.end(), p[i]) - p1.begin()) + 1;
		b = (int)(lower_bound(r1.begin(), r1.end(), r[i]) - r1.begin()) + 1;

		v[a].push_back(b);
	}
	build(1, N, 1);
	int q;
	cin >> q;
	int ans[q+4];
	ans[0] = ans[1] = ans[2] = ans[3] = 0;
	for(int i = 4; i < q+4; i++){
		int e, f, g, h;
		cin >> e >> f >> g >> h;
		e ^= ans[i-4];
		f ^= ans[i-3];
		g ^= ans[i-2];
		h ^= ans[i-1];
		if(e > f) swap(e, f);
		if(g > h) swap(g, h);
		ans[i] = query(e, f, g, h);
		cout << ans[i] << "\n";
	}

	return 0;
}