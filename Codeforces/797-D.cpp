//   Author : Misael Mateus 
//   Submission date: 2017-04-16 22:50:39
#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;
vector<int> V;
vector<int> R;
int l[MAXN];
int r[MAXN];
int value[MAXN];
int p[MAXN];
void fill1(int i, int j){
	auto it = lower_bound(V.begin(), V.end(), i);
	if(it == V.end())
		return;
	
	for(; it != V.end() && *it <= j; it++)
		R[(int)(it - V.begin())] = 1;
}
void fill2(int i, int j){
	auto it = lower_bound(V.begin(), V.end(), i);
	if(it == V.end())
		return;
	for(; it != V.end() && *it <= j; it++)
		R[(int)(it - V.begin())] = 0;
}
void query(int v, int i, int j){
	
	if(v == -1){
		fill2(i, j);
		return;
	}
	if(value[v] >= i && value[v] <= j){
		fill1(value[v], value[v]);
		query(l[v], i, value[v]-1);
		query(r[v], value[v]+1, j);
	}
	else if(value[v] < i){
		query(r[v], i, j);
	}
	else
		query(l[v], i, j);
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int val, le, ri;
		scanf("%d %d %d", &val, &le, &ri);
		l[i] = le;
		r[i] = ri;
		value[i] = val;
		if(le > 0)
			p[le] = i;
		if(ri > 0)
			p[ri] = i;
		V.push_back(val);
	}
	R = vector<int>(n);
	sort(V.begin(), V.end());
	int root;
	for(int i = 1; i <= n; i++)
		if(!p[i])
			root = i;

	query(root, 0, 1000000100);

	int ans = 0;
	for(int i = 0; i < n; i++)
		if(!R[i])
			ans++;

	printf("%d\n", ans);
	return 0;
}