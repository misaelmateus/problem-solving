//   Author : Misael Mateus 
//   Submission date: 2017-07-08 22:33:10
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 200010
using namespace std;
vector<int> ans;
vector<int> gr[MAXN];
int mark[MAXN];
void dfs(int u){
	ans.push_back(u);
	mark[u] = 1;
	int flag = 0;
	for(auto &v : gr[u]){
		if(mark[v]) continue;
		if(flag != 0) ans.push_back(u);
		dfs(v);
		flag = 1;
	}
	if(u - 1 && flag) ans.push_back(u);
}


int main(){
	ios::sync_with_stdio(false);	
	int n, m, u, v, k;
	cin >> n >> m >> k;

	rep(i, m){
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs(1);

	int l = (2*n / k ) + ((2*n)%k != 0);
	int j = 0;
	for(int i = 1; i <= k; i++){
		if(j == ans.size()){
			cout << "1 1\n";
			continue;
		}
		cout << min(l, (int)ans.size() - j) << " ";
		for(int cont = 0; j < ans.size() && cont < l; cont++, j++)
			cout << ans[j] << " ";
		cout << "\n";
	}
	return 0;
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 200010
using namespace std;
vector<int> ans;
vector<int> gr[MAXN];
int mark[MAXN];
void dfs(int u){
	ans.push_back(u);
	mark[u] = 1;
	int flag = 0;
	for(auto &v : gr[u]){
		if(mark[v]) continue;
		if(flag != 0) ans.push_back(u);
		dfs(v);
		flag = 1;
	}
	if(u - 1 && flag) ans.push_back(u);
}


int main(){
	ios::sync_with_stdio(false);	
	int n, m, u, v, k;
	cin >> n >> m >> k;

	rep(i, m){
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs(1);

	int l = (2*n / k ) + ((2*n)%k != 0);
	int j = 0;
	for(int i = 1; i <= k; i++){
		if(j == ans.size()){
			cout << "1 1\n";
			continue;
		}
		cout << min(l, (int)ans.size() - j) << " ";
		for(int cont = 0; j < ans.size() && cont < l; cont++, j++)
			cout << ans[j] << " ";
		cout << "\n";
	}
	return 0;
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 200010
using namespace std;
vector<int> ans;
vector<int> gr[MAXN];
int mark[MAXN];
void dfs(int u){
	ans.push_back(u);
	mark[u] = 1;
	int flag = 0;
	for(auto &v : gr[u]){
		if(mark[v]) continue;
		if(flag != 0) ans.push_back(u);
		dfs(v);
		flag = 1;
	}
	if(u - 1 && flag) ans.push_back(u);
}


int main(){
	ios::sync_with_stdio(false);	
	int n, m, u, v, k;
	cin >> n >> m >> k;

	rep(i, m){
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs(1);

	int l = (2*n / k ) + ((2*n)%k != 0);
	int j = 0;
	for(int i = 1; i <= k; i++){
		if(j == ans.size()){
			cout << "1 1\n";
			continue;
		}
		cout << min(l, (int)ans.size() - j) << " ";
		for(int cont = 0; j < ans.size() && cont < l; cont++, j++)
			cout << ans[j] << " ";
		cout << "\n";
	}
	return 0;
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 200010
using namespace std;
vector<int> ans;
vector<int> gr[MAXN];
int mark[MAXN];
void dfs(int u){
	ans.push_back(u);
	mark[u] = 1;
	int flag = 0;
	for(auto &v : gr[u]){
		if(mark[v]) continue;
		if(flag != 0) ans.push_back(u);
		dfs(v);
		flag = 1;
	}
	if(u - 1 && flag) ans.push_back(u);
}


int main(){
	ios::sync_with_stdio(false);	
	int n, m, u, v, k;
	cin >> n >> m >> k;

	rep(i, m){
		cin >> u >> v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	dfs(1);

	int l = (2*n / k ) + ((2*n)%k != 0);
	int j = 0;
	for(int i = 1; i <= k; i++){
		if(j == ans.size()){
			cout << "1 1\n";
			continue;
		}
		cout << min(l, (int)ans.size() - j) << " ";
		for(int cont = 0; j < ans.size() && cont < l; cont++, j++)
			cout << ans[j] << " ";
		cout << "\n";
	}
	return 0;
}