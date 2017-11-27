//   Author : Misael Mateus 
//   Submission date: 2017-05-05 17:51:11
#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

vector<int> gr[MAXN];
map<int, double > ans[MAXN];
// list with the dist to the more far vertex in each component
vector<int> dist[MAXN];
vector<ll> sufsum[MAXN];
int d[MAXN];
int mx[MAXN], id[MAXN];
int diameter[MAXN];
int parent[MAXN];
int pa[MAXN], mark[MAXN];



int dfs1(int u, int p, int v){
	mark[u] = 1;
	parent[u] = v;
	d[u] = 0;
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		pa[gr[u][i]] = u;
		int d1 = dfs1(gr[u][i], u, v);
		if( 1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(mx[u], d[u]), id[u] = i;
	}

	return d[u];
}
void dfs2(int u, int p){
	if(pa[u]){
		int d1 = d[pa[u]];
		if(id[pa[u]] >= 0 && gr[pa[u]][ id[pa[u]] ] == u ) d1 = mx[pa[u]];
		if(1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(d[u], mx[u]), id[u] = -1;
	}
	diameter[parent[u]] = max(diameter[parent[u]], d[u] + mx[u]);
	dist[parent[u]].push_back(d[u]);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs2(gr[u][i], u);
	}
}

// define the diameter of the tree and the vertex far of each vertex
int f(int u){
	dfs1(u, -1, u);
	dfs2(u, -1);
	sort(dist[u].begin(), dist[u].end());
	sufsum[u] = vector< ll > ( (int)dist[u].size(), 0LL);
	sufsum[u][(int)sufsum[u].size() - 1] = dist[u][(int)sufsum[u].size() - 1];
	for(int i = (int)sufsum[u].size()-2; i >= 0; i--)
		sufsum[u][i] = dist[u][i] + sufsum[u][i+1];
}

double query(int a, int b){
	// resp binary search in x: dist[a] to begin y: dist[b] that x + y > diameter[a/b]
	
	ll ans = 0LL;
	int diam = max(diameter[a], diameter[b]);
	for(int i = 0; i < dist[a].size(); i++){
		int ind = (int)(upper_bound(dist[b].begin(), dist[b].end(), diam - dist[a][i] - 1) - dist[b].begin());
		ans += (ll)(diam)*(ll)(ind);
		ans += (ll)(dist[b].size() - ind)*(dist[a][i] + 1);
		ans += (ll)(sufsum[b][ind]);
	}
	return (double)(ans) / ((ll)(dist[a].size()) * (ll)(dist[b].size())) ;
} 
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	for(int i = 1; i <= n; i++){
		if(!mark[i]) f(i);
	}
	while(q--){
		cin >> a >> b;
		a = parent[a], b = parent[b];
		if(dist[a].size() > dist[b].size()) swap(a, b);
		if(ans[a][b] > 0.00000001){
			cout << ans[a][b] << "\n";
		}
		else if(a == b) cout << -1 << "\n";
		else cout << fixed << setprecision(8) << (double)(ans[a][b] = query(a, b)) << "\n";
	}
}#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

vector<int> gr[MAXN];
map<int, double > ans[MAXN];
// list with the dist to the more far vertex in each component
vector<int> dist[MAXN];
vector<ll> sufsum[MAXN];
int d[MAXN];
int mx[MAXN], id[MAXN];
int diameter[MAXN];
int parent[MAXN];
int pa[MAXN], mark[MAXN];



int dfs1(int u, int p, int v){
	mark[u] = 1;
	parent[u] = v;
	d[u] = 0;
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		pa[gr[u][i]] = u;
		int d1 = dfs1(gr[u][i], u, v);
		if( 1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(mx[u], d[u]), id[u] = i;
	}

	return d[u];
}
void dfs2(int u, int p){
	if(pa[u]){
		int d1 = d[pa[u]];
		if(id[pa[u]] >= 0 && gr[pa[u]][ id[pa[u]] ] == u ) d1 = mx[pa[u]];
		if(1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(d[u], mx[u]), id[u] = -1;
	}
	diameter[parent[u]] = max(diameter[parent[u]], d[u] + mx[u]);
	dist[parent[u]].push_back(d[u]);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs2(gr[u][i], u);
	}
}

// define the diameter of the tree and the vertex far of each vertex
int f(int u){
	dfs1(u, -1, u);
	dfs2(u, -1);
	sort(dist[u].begin(), dist[u].end());
	sufsum[u] = vector< ll > ( (int)dist[u].size(), 0LL);
	sufsum[u][(int)sufsum[u].size() - 1] = dist[u][(int)sufsum[u].size() - 1];
	for(int i = (int)sufsum[u].size()-2; i >= 0; i--)
		sufsum[u][i] = dist[u][i] + sufsum[u][i+1];
}

double query(int a, int b){
	// resp binary search in x: dist[a] to begin y: dist[b] that x + y > diameter[a/b]
	
	ll ans = 0LL;
	int diam = max(diameter[a], diameter[b]);
	for(int i = 0; i < dist[a].size(); i++){
		int ind = (int)(upper_bound(dist[b].begin(), dist[b].end(), diam - dist[a][i] - 1) - dist[b].begin());
		ans += (ll)(diam)*(ll)(ind);
		ans += (ll)(dist[b].size() - ind)*(dist[a][i] + 1);
		ans += (ll)(sufsum[b][ind]);
	}
	return (double)(ans) / ((ll)(dist[a].size()) * (ll)(dist[b].size())) ;
} 
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	for(int i = 1; i <= n; i++){
		if(!mark[i]) f(i);
	}
	while(q--){
		cin >> a >> b;
		a = parent[a], b = parent[b];
		if(dist[a].size() > dist[b].size()) swap(a, b);
		if(ans[a][b] > 0.00000001){
			cout << ans[a][b] << "\n";
		}
		else if(a == b) cout << -1 << "\n";
		else cout << fixed << setprecision(8) << (double)(ans[a][b] = query(a, b)) << "\n";
	}
}#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

vector<int> gr[MAXN];
map<int, double > ans[MAXN];
// list with the dist to the more far vertex in each component
vector<int> dist[MAXN];
vector<ll> sufsum[MAXN];
int d[MAXN];
int mx[MAXN], id[MAXN];
int diameter[MAXN];
int parent[MAXN];
int pa[MAXN], mark[MAXN];



int dfs1(int u, int p, int v){
	mark[u] = 1;
	parent[u] = v;
	d[u] = 0;
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		pa[gr[u][i]] = u;
		int d1 = dfs1(gr[u][i], u, v);
		if( 1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(mx[u], d[u]), id[u] = i;
	}

	return d[u];
}
void dfs2(int u, int p){
	if(pa[u]){
		int d1 = d[pa[u]];
		if(id[pa[u]] >= 0 && gr[pa[u]][ id[pa[u]] ] == u ) d1 = mx[pa[u]];
		if(1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(d[u], mx[u]), id[u] = -1;
	}
	diameter[parent[u]] = max(diameter[parent[u]], d[u] + mx[u]);
	dist[parent[u]].push_back(d[u]);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs2(gr[u][i], u);
	}
}

// define the diameter of the tree and the vertex far of each vertex
int f(int u){
	dfs1(u, -1, u);
	dfs2(u, -1);
	sort(dist[u].begin(), dist[u].end());
	sufsum[u] = vector< ll > ( (int)dist[u].size(), 0LL);
	sufsum[u][(int)sufsum[u].size() - 1] = dist[u][(int)sufsum[u].size() - 1];
	for(int i = (int)sufsum[u].size()-2; i >= 0; i--)
		sufsum[u][i] = dist[u][i] + sufsum[u][i+1];
}

double query(int a, int b){
	// resp binary search in x: dist[a] to begin y: dist[b] that x + y > diameter[a/b]
	
	ll ans = 0LL;
	int diam = max(diameter[a], diameter[b]);
	for(int i = 0; i < dist[a].size(); i++){
		int ind = (int)(upper_bound(dist[b].begin(), dist[b].end(), diam - dist[a][i] - 1) - dist[b].begin());
		ans += (ll)(diam)*(ll)(ind);
		ans += (ll)(dist[b].size() - ind)*(dist[a][i] + 1);
		ans += (ll)(sufsum[b][ind]);
	}
	return (double)(ans) / ((ll)(dist[a].size()) * (ll)(dist[b].size())) ;
} 
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	for(int i = 1; i <= n; i++){
		if(!mark[i]) f(i);
	}
	while(q--){
		cin >> a >> b;
		a = parent[a], b = parent[b];
		if(dist[a].size() > dist[b].size()) swap(a, b);
		if(ans[a][b] > 0.00000001){
			cout << ans[a][b] << "\n";
		}
		else if(a == b) cout << -1 << "\n";
		else cout << fixed << setprecision(8) << (double)(ans[a][b] = query(a, b)) << "\n";
	}
}#include<bits/stdc++.h>
#define MAXN 100010
#define ll long long
using namespace std;

vector<int> gr[MAXN];
map<int, double > ans[MAXN];
// list with the dist to the more far vertex in each component
vector<int> dist[MAXN];
vector<ll> sufsum[MAXN];
int d[MAXN];
int mx[MAXN], id[MAXN];
int diameter[MAXN];
int parent[MAXN];
int pa[MAXN], mark[MAXN];



int dfs1(int u, int p, int v){
	mark[u] = 1;
	parent[u] = v;
	d[u] = 0;
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		pa[gr[u][i]] = u;
		int d1 = dfs1(gr[u][i], u, v);
		if( 1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(mx[u], d[u]), id[u] = i;
	}

	return d[u];
}
void dfs2(int u, int p){
	if(pa[u]){
		int d1 = d[pa[u]];
		if(id[pa[u]] >= 0 && gr[pa[u]][ id[pa[u]] ] == u ) d1 = mx[pa[u]];
		if(1 + d1 > mx[u]) mx[u] = 1 + d1;
		if(mx[u] > d[u]) swap(d[u], mx[u]), id[u] = -1;
	}
	diameter[parent[u]] = max(diameter[parent[u]], d[u] + mx[u]);
	dist[parent[u]].push_back(d[u]);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs2(gr[u][i], u);
	}
}

// define the diameter of the tree and the vertex far of each vertex
int f(int u){
	dfs1(u, -1, u);
	dfs2(u, -1);
	sort(dist[u].begin(), dist[u].end());
	sufsum[u] = vector< ll > ( (int)dist[u].size(), 0LL);
	sufsum[u][(int)sufsum[u].size() - 1] = dist[u][(int)sufsum[u].size() - 1];
	for(int i = (int)sufsum[u].size()-2; i >= 0; i--)
		sufsum[u][i] = dist[u][i] + sufsum[u][i+1];
}

double query(int a, int b){
	// resp binary search in x: dist[a] to begin y: dist[b] that x + y > diameter[a/b]
	
	ll ans = 0LL;
	int diam = max(diameter[a], diameter[b]);
	for(int i = 0; i < dist[a].size(); i++){
		int ind = (int)(upper_bound(dist[b].begin(), dist[b].end(), diam - dist[a][i] - 1) - dist[b].begin());
		ans += (ll)(diam)*(ll)(ind);
		ans += (ll)(dist[b].size() - ind)*(dist[a][i] + 1);
		ans += (ll)(sufsum[b][ind]);
	}
	return (double)(ans) / ((ll)(dist[a].size()) * (ll)(dist[b].size())) ;
} 
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q, a, b;
	cin >> n >> m >> q;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	for(int i = 1; i <= n; i++){
		if(!mark[i]) f(i);
	}
	while(q--){
		cin >> a >> b;
		a = parent[a], b = parent[b];
		if(dist[a].size() > dist[b].size()) swap(a, b);
		if(ans[a][b] > 0.00000001){
			cout << ans[a][b] << "\n";
		}
		else if(a == b) cout << -1 << "\n";
		else cout << fixed << setprecision(8) << (double)(ans[a][b] = query(a, b)) << "\n";
	}
}