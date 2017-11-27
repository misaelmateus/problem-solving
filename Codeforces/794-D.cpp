//   Author : Misael Mateus 
//   Submission date: 2017-11-06 15:24:06
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 300010
#define readFast ios::sync_with_stdio(false)
using namespace std;

map<set<int>, int> mapa;
set<int> gr[MAXN];
int ans[MAXN];
int parent[MAXN];
int t;

int main(){
	readFast;
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		gr[i].insert(i);
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		gr[u].insert(v);
		gr[v].insert(u);
	}
	for(int i = 1; i <= n; i++){
		if(!mapa[gr[i]])
			mapa[gr[i]] = ++t, parent[i] = t;
		else parent[i] = mapa[gr[i]];
	}
	if(t == 1){
		cout << "YES\n";
		rep(i, n) cout << "1 ";
		cout << "\n";
		return 0;
	}
	int ini = -1;
	for(int i = 1; i <= n; i++){
		set<int> aux;
		for(auto u : gr[i])
			if( parent[u] != parent[i]) aux.insert(parent[u]);
		if(aux.size() == 1){
			ini = i; 
			break;
		}
	}
	if(ini == -1){
		cout << "NO\n";
		return 0;
	}
	queue<int> q;
	q.push(ini);
	ans[parent[ini]] = 1;
 	while(!q.empty()){
 		int u = q.front();
 		q.pop();
 		for(auto v : gr[u]){
 			if(ans[parent[v]] && abs(ans[parent[v]] - ans[parent[u]]) > 1){
 				cout << "NO\n";
 				return 0;
 			}
			if(!ans[parent[v]]){
 				ans[parent[v]] = ans[parent[u]]+1, q.push(v);
 				break;
			}
 		}
	}
	rep(i, n){
		if(!ans[parent[i+1]]){
			cout << "NO\n";
			return 0;		
		}
	}
	cout << "YES\n";
	rep(i, n){
		cout << ans[parent[i+1]] << " ";
	}
	cout << "\n";
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 300010
#define readFast ios::sync_with_stdio(false)
using namespace std;

map<set<int>, int> mapa;
set<int> gr[MAXN];
int ans[MAXN];
int parent[MAXN];
int t;

int main(){
	readFast;
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		gr[i].insert(i);
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		gr[u].insert(v);
		gr[v].insert(u);
	}
	for(int i = 1; i <= n; i++){
		if(!mapa[gr[i]])
			mapa[gr[i]] = ++t, parent[i] = t;
		else parent[i] = mapa[gr[i]];
	}
	if(t == 1){
		cout << "YES\n";
		rep(i, n) cout << "1 ";
		cout << "\n";
		return 0;
	}
	int ini = -1;
	for(int i = 1; i <= n; i++){
		set<int> aux;
		for(auto u : gr[i])
			if( parent[u] != parent[i]) aux.insert(parent[u]);
		if(aux.size() == 1){
			ini = i; 
			break;
		}
	}
	if(ini == -1){
		cout << "NO\n";
		return 0;
	}
	queue<int> q;
	q.push(ini);
	ans[parent[ini]] = 1;
 	while(!q.empty()){
 		int u = q.front();
 		q.pop();
 		for(auto v : gr[u]){
 			if(ans[parent[v]] && abs(ans[parent[v]] - ans[parent[u]]) > 1){
 				cout << "NO\n";
 				return 0;
 			}
			if(!ans[parent[v]]){
 				ans[parent[v]] = ans[parent[u]]+1, q.push(v);
 				break;
			}
 		}
	}
	rep(i, n){
		if(!ans[parent[i+1]]){
			cout << "NO\n";
			return 0;		
		}
	}
	cout << "YES\n";
	rep(i, n){
		cout << ans[parent[i+1]] << " ";
	}
	cout << "\n";
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 300010
#define readFast ios::sync_with_stdio(false)
using namespace std;

map<set<int>, int> mapa;
set<int> gr[MAXN];
int ans[MAXN];
int parent[MAXN];
int t;

int main(){
	readFast;
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		gr[i].insert(i);
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		gr[u].insert(v);
		gr[v].insert(u);
	}
	for(int i = 1; i <= n; i++){
		if(!mapa[gr[i]])
			mapa[gr[i]] = ++t, parent[i] = t;
		else parent[i] = mapa[gr[i]];
	}
	if(t == 1){
		cout << "YES\n";
		rep(i, n) cout << "1 ";
		cout << "\n";
		return 0;
	}
	int ini = -1;
	for(int i = 1; i <= n; i++){
		set<int> aux;
		for(auto u : gr[i])
			if( parent[u] != parent[i]) aux.insert(parent[u]);
		if(aux.size() == 1){
			ini = i; 
			break;
		}
	}
	if(ini == -1){
		cout << "NO\n";
		return 0;
	}
	queue<int> q;
	q.push(ini);
	ans[parent[ini]] = 1;
 	while(!q.empty()){
 		int u = q.front();
 		q.pop();
 		for(auto v : gr[u]){
 			if(ans[parent[v]] && abs(ans[parent[v]] - ans[parent[u]]) > 1){
 				cout << "NO\n";
 				return 0;
 			}
			if(!ans[parent[v]]){
 				ans[parent[v]] = ans[parent[u]]+1, q.push(v);
 				break;
			}
 		}
	}
	rep(i, n){
		if(!ans[parent[i+1]]){
			cout << "NO\n";
			return 0;		
		}
	}
	cout << "YES\n";
	rep(i, n){
		cout << ans[parent[i+1]] << " ";
	}
	cout << "\n";
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 300010
#define readFast ios::sync_with_stdio(false)
using namespace std;

map<set<int>, int> mapa;
set<int> gr[MAXN];
int ans[MAXN];
int parent[MAXN];
int t;

int main(){
	readFast;
	int n, m, u, v;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		gr[i].insert(i);
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		gr[u].insert(v);
		gr[v].insert(u);
	}
	for(int i = 1; i <= n; i++){
		if(!mapa[gr[i]])
			mapa[gr[i]] = ++t, parent[i] = t;
		else parent[i] = mapa[gr[i]];
	}
	if(t == 1){
		cout << "YES\n";
		rep(i, n) cout << "1 ";
		cout << "\n";
		return 0;
	}
	int ini = -1;
	for(int i = 1; i <= n; i++){
		set<int> aux;
		for(auto u : gr[i])
			if( parent[u] != parent[i]) aux.insert(parent[u]);
		if(aux.size() == 1){
			ini = i; 
			break;
		}
	}
	if(ini == -1){
		cout << "NO\n";
		return 0;
	}
	queue<int> q;
	q.push(ini);
	ans[parent[ini]] = 1;
 	while(!q.empty()){
 		int u = q.front();
 		q.pop();
 		for(auto v : gr[u]){
 			if(ans[parent[v]] && abs(ans[parent[v]] - ans[parent[u]]) > 1){
 				cout << "NO\n";
 				return 0;
 			}
			if(!ans[parent[v]]){
 				ans[parent[v]] = ans[parent[u]]+1, q.push(v);
 				break;
			}
 		}
	}
	rep(i, n){
		if(!ans[parent[i+1]]){
			cout << "NO\n";
			return 0;		
		}
	}
	cout << "YES\n";
	rep(i, n){
		cout << ans[parent[i+1]] << " ";
	}
	cout << "\n";
}