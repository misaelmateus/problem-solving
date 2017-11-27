#include<bits/stdc++.h>
#define MAXN 250010
#define iiv pair<int, vector<int> >
using namespace std;
iiv tree[4*MAXN];
int v[MAXN], N;

iiv Merge(iiv a, iiv b){
	if(a.first < b.first)
		return a;
	if(a.first > b.first)
		return b;
	vector<int> v1(a.second.size() + b.second.size());
	merge(a.second.begin(), a.second.end(), b.second.begin(), b.second.end(), v1.begin());
	return {a.first, v1};
}
iiv build(int i, int j, int n){
	if(i == j)
		return tree[n] = {v[i], {i}};
	int middle = (i + j) >> 1;
	iiv a = build(i, middle, 2*n);
	iiv b = build(middle+1, j,  2*n+1);
	
	return tree[n] = Merge(a, b);
}

iiv query(int i, int j, int ini, int fim, int n){
	if(i > fim || j < ini) return {(1 << 30), {} };
	if(i >= ini && j <= fim) return tree[n];
	int middle = (i + j) >> 1;
	return Merge(query(i, middle, ini, fim, 2*n), query(middle+1, j, ini, fim, 2*n+1));	
}
int f(int i, int j){
	if(i > j)
		return 0;
	if(i == j)
		return 1;
	iiv x = query(1, N, i, j, 1);
	vector<int> p = x.second;
	int l = x.first;

	int ult = i-1;
	int ans = 1;
	for(int i = 0; i < p.size(); i++){
		ans += f(ult+1, p[i] - 1);
		ult = p[i];
	}
	ans += f(ult+1, j);
	return ans;
}
int main(){
	int aux;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> aux >> v[i];
	}
	build(1, N, 1);
	cout << f(1, N) << endl;
}