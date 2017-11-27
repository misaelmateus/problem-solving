#include<bits/stdc++.h>
#define MAXN 100010
#define ld long double
using namespace std;

vector<int> gr[MAXN];
int mark[MAXN];
ld ans;

void dfs(int u, int ult, int q){
	ans += (ld)q/(q+1);

	if(mark[u]) q++;
	for(auto &v : gr[u]){
		if(v == ult) continue;
		dfs(v, u, q);
	}

}
int main(){
	int T;
	cin >> T;
	while(T--){
		ans = 0;
		int N;
		cin >> N;
		for(int i = 1; i <= N; i++) gr[i].clear();
		memset(mark, 0, sizeof(mark));

		for(int i = 0; i < N-1; i++){
			int u, v;
			cin >> u >> v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		} 

		int q;
		cin >> q;
		while(q--){
			int u;
			cin >> u;
			mark[u] = 1;
		}
		dfs(1, -1, 0);

		cout << fixed << setprecision(10) << ans << endl;
	}
}