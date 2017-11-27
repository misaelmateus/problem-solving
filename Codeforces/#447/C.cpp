#include<bits/stdc++.h>
using namespace std;
#define MAXN 1011
 
vector<int> gr[MAXN];
int v[MAXN];
int mark[MAXN];
vector<int> ans;
void dfs(int i){
	mark[i] = 1;
	ans.push_back(v[i]);
	for(auto u : gr[i]){
		if(mark[u]) continue;
		dfs(u);
		ans.push_back(v[i]);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	set<int> s;
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		s.insert(v[i]);
	}
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
			if(s.count(__gcd( v[i], v[j] ) ) )
				gr[i].push_back(j), gr[j].push_back(i);
	dfs(0);
	for(int i = 1; i < n; i++){
		if(!mark[i]){
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", (int)ans.size());
	for(auto u : ans)
		printf("%d ", u);
}