#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;

vector<int> gr[MAXN];

int ans[MAXN];
int x[MAXN];

void dfs(int i, int p = -1){
	ans[i] = (x[i] ? 1 : -1);
	for(auto u : gr[i]){
		if(u == p) continue;
		dfs(u, i);
		if(ans[u] > 0) ans[i] += ans[u];
	}
}

void calc_ans(int i, vector<int> &v_ans, int p = -1){
	v_ans.push_back(i);
	for(auto u : gr[i]){
		if(u != p && ans[u] > 0){
			calc_ans(u, v_ans, i);
		}
	}	
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &x[i]);

	for(int i = 0; i < n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	dfs(1);
	vector<int> v_ans;
	int answer = -(1e8);
	int i_max;
	for(int i = 1; i <= n; i++) {
		if(answer < ans[i]){
			answer = ans[i];
			i_max = i;
		}
		x[i] ^= 1;
	}
	calc_ans(i_max, v_ans);
	int answer1 = -(1e9);
	dfs(1);
	for(int i = 1; i <= n; i++) {
		if(answer1 < ans[i]){
			answer1 = ans[i];
			i_max = i;
		}
	}
	if(answer1 > answer)
		answer = answer1, v_ans.clear(), calc_ans(i_max, v_ans);
	printf("%d\n", answer);
	printf("%d\n", (int)v_ans.size());
	for(auto u : v_ans) printf("%d ", u);
	printf("\n");
	return 0;
}