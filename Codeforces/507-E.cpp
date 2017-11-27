//   Author : Misael Mateus 
//   Submission date: 2017-03-16 17:19:58
#include<bits/stdc++.h>
#define MAXN 100010
#define ii pair<int, int>
using namespace std;

int dist[MAXN], n;
vector< ii > gr[MAXN];

void dfs(){
	memset(dist, -1, sizeof(dist));
	dist[1] = 0;

	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int i = 0; i < gr[u].size(); i++){
			int next = gr[u][i].first;
			if(dist[next] == -1){
				dist[next] = dist[u] + 1;
				q.push(next);
			}
		}
	}
}

vector< pair<int, ii> > ans;
int v_ans = 0;
int dp[MAXN];
map<pair<int, int>, int> mark;

int calc_dp(int u){
	if(dp[u] != -1)
		return dp[u];
	if(u == 1)
		return dp[u] = 0;
	for(int i = 0; i < gr[u].size(); i++){
		int next = gr[u][i].first;
		if(dist[next] == dist[u] - 1)
			dp[u] = max(dp[u], calc_dp(next) + gr[u][i].second);
	}	
	
	return dp[u];
}	

void calc_ans(int u){
	if(u == 1){
		return;
	}
	for(int i = 0; i < gr[u].size(); i++){
		int next = gr[u][i].first;
		
		if(dist[next] == dist[u] - 1 && dp[next] == dp[u] - gr[u][i].second){
			calc_ans(next);
			mark[{min(next, u), max(next, u)}] = 1;
			break;
		}
	}
}
int main(){
	ios::sync_with_stdio( false );
	memset(dp, -1, sizeof(dp));

	int m;
	cin >> n >> m;
	int cont = 0;
	vector<pair<int, ii> > edges;
	for(int i = 0; i < m; i++){
		int a, b, z;
		cin >> a >> b >> z;
		cont += z;
		gr[a].push_back({b, z});
		gr[b].push_back({a, z});

		edges.push_back({z, {min(a, b), max(a, b)}} );
	}
	dfs();
	int v = calc_dp(n);
	
	cout << (cont - v) + (dist[n] - v) << endl;
	calc_ans(n);
	for(int i = 0; i < m; i++){
		if(edges[i].first == 1 && !mark[edges[i].second])
			cout << edges[i].second.first << " " << edges[i].second.second << " 0\n";
		if(edges[i].first == 0 && mark[edges[i].second])
			cout << edges[i].second.first << " " << edges[i].second.second << " 1\n";
	}
	return 0;
}