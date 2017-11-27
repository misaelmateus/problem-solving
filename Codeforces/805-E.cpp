//   Author : Misael Mateus 
//   Submission date: 2017-05-05 21:18:36
#include<bits/stdc++.h>
#define MAXN 300100
using namespace std;
int c[MAXN];
vector<int> s[MAXN];
vector<int> gr[MAXN];
int ans;
void conect(int u){
	vector<int> s1;
	map<int, int> color;
	for(int i = 0; i < s[u].size(); i++){
		if(c[s[u][i]])
			color[c[s[u][i]]] = 1;
		else s1.push_back(s[u][i]);
	}
	int j = 1;
	for(int i = 0; i < s1.size(); i++){
		while(color[j]) j++;
		c[s1[i]] = j;
		j++;
	}
	ans = max(ans, j-1);
}
void dfs(int u, int p){
	conect(u);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs(gr[u][i], u);
	}
}
int main(){
	int n, m;
	int t, aux;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> t;
		while(t--){
			cin >> aux;
			s[i].push_back(aux);
		}
	}

	int a, b;
	for(int i = 0; i < n-1; i++){	
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, -1);
	for(int i = 1; i <= m; i++) if(c[i] == 0) c[i] = 1;
	cout << max(ans, 1) << "\n";
	for(int i = 1; i <= m; i++) cout << c[i] << " ";
	cout << "\n";
	return 0;
}#include<bits/stdc++.h>
#define MAXN 300100
using namespace std;
int c[MAXN];
vector<int> s[MAXN];
vector<int> gr[MAXN];
int ans;
void conect(int u){
	vector<int> s1;
	map<int, int> color;
	for(int i = 0; i < s[u].size(); i++){
		if(c[s[u][i]])
			color[c[s[u][i]]] = 1;
		else s1.push_back(s[u][i]);
	}
	int j = 1;
	for(int i = 0; i < s1.size(); i++){
		while(color[j]) j++;
		c[s1[i]] = j;
		j++;
	}
	ans = max(ans, j-1);
}
void dfs(int u, int p){
	conect(u);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs(gr[u][i], u);
	}
}
int main(){
	int n, m;
	int t, aux;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> t;
		while(t--){
			cin >> aux;
			s[i].push_back(aux);
		}
	}

	int a, b;
	for(int i = 0; i < n-1; i++){	
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, -1);
	for(int i = 1; i <= m; i++) if(c[i] == 0) c[i] = 1;
	cout << max(ans, 1) << "\n";
	for(int i = 1; i <= m; i++) cout << c[i] << " ";
	cout << "\n";
	return 0;
}#include<bits/stdc++.h>
#define MAXN 300100
using namespace std;
int c[MAXN];
vector<int> s[MAXN];
vector<int> gr[MAXN];
int ans;
void conect(int u){
	vector<int> s1;
	map<int, int> color;
	for(int i = 0; i < s[u].size(); i++){
		if(c[s[u][i]])
			color[c[s[u][i]]] = 1;
		else s1.push_back(s[u][i]);
	}
	int j = 1;
	for(int i = 0; i < s1.size(); i++){
		while(color[j]) j++;
		c[s1[i]] = j;
		j++;
	}
	ans = max(ans, j-1);
}
void dfs(int u, int p){
	conect(u);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs(gr[u][i], u);
	}
}
int main(){
	int n, m;
	int t, aux;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> t;
		while(t--){
			cin >> aux;
			s[i].push_back(aux);
		}
	}

	int a, b;
	for(int i = 0; i < n-1; i++){	
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, -1);
	for(int i = 1; i <= m; i++) if(c[i] == 0) c[i] = 1;
	cout << max(ans, 1) << "\n";
	for(int i = 1; i <= m; i++) cout << c[i] << " ";
	cout << "\n";
	return 0;
}#include<bits/stdc++.h>
#define MAXN 300100
using namespace std;
int c[MAXN];
vector<int> s[MAXN];
vector<int> gr[MAXN];
int ans;
void conect(int u){
	vector<int> s1;
	map<int, int> color;
	for(int i = 0; i < s[u].size(); i++){
		if(c[s[u][i]])
			color[c[s[u][i]]] = 1;
		else s1.push_back(s[u][i]);
	}
	int j = 1;
	for(int i = 0; i < s1.size(); i++){
		while(color[j]) j++;
		c[s1[i]] = j;
		j++;
	}
	ans = max(ans, j-1);
}
void dfs(int u, int p){
	conect(u);
	for(int i = 0; i < gr[u].size(); i++){
		if(gr[u][i] == p) continue;
		dfs(gr[u][i], u);
	}
}
int main(){
	int n, m;
	int t, aux;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> t;
		while(t--){
			cin >> aux;
			s[i].push_back(aux);
		}
	}

	int a, b;
	for(int i = 0; i < n-1; i++){	
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1, -1);
	for(int i = 1; i <= m; i++) if(c[i] == 0) c[i] = 1;
	cout << max(ans, 1) << "\n";
	for(int i = 1; i <= m; i++) cout << c[i] << " ";
	cout << "\n";
	return 0;
}