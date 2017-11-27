//   Author : Misael Mateus 
//   Submission date: 2017-03-17 16:33:55
#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int p[MAXN];
int root, ans, aux;
vector<int> leafs;

int mark[MAXN];

void dfs_root(int u){
	mark[u] = 1;
	if(p[u] == u)
		root = u;
	if(mark[p[u]] == 0)
		dfs_root(p[u]);
	else if(aux == -1)
		aux = u;
}

void dfs(int u){
	mark[u] = 1;
	if(mark[p[u]] == 0)
		dfs(p[u]);
	else if(mark[p[u]] == 1 && p[u] != root)
		p[u] = root, ans++;

	mark[u] = 2;
}
int main(){
	aux = root = -1;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 1; i <= n && root == -1; i++)
		dfs_root(i);
	if(root == -1)
		root = aux, p[aux] = aux, ans++;

	memset(mark, 0, sizeof(mark));
	for(int i = 1; i <= n; i++)
		dfs(i);

	cout << ans << endl;
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int p[MAXN];
int root, ans, aux;
vector<int> leafs;

int mark[MAXN];

void dfs_root(int u){
	mark[u] = 1;
	if(p[u] == u)
		root = u;
	if(mark[p[u]] == 0)
		dfs_root(p[u]);
	else if(aux == -1)
		aux = u;
}

void dfs(int u){
	mark[u] = 1;
	if(mark[p[u]] == 0)
		dfs(p[u]);
	else if(mark[p[u]] == 1 && p[u] != root)
		p[u] = root, ans++;

	mark[u] = 2;
}
int main(){
	aux = root = -1;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 1; i <= n && root == -1; i++)
		dfs_root(i);
	if(root == -1)
		root = aux, p[aux] = aux, ans++;

	memset(mark, 0, sizeof(mark));
	for(int i = 1; i <= n; i++)
		dfs(i);

	cout << ans << endl;
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int p[MAXN];
int root, ans, aux;
vector<int> leafs;

int mark[MAXN];

void dfs_root(int u){
	mark[u] = 1;
	if(p[u] == u)
		root = u;
	if(mark[p[u]] == 0)
		dfs_root(p[u]);
	else if(aux == -1)
		aux = u;
}

void dfs(int u){
	mark[u] = 1;
	if(mark[p[u]] == 0)
		dfs(p[u]);
	else if(mark[p[u]] == 1 && p[u] != root)
		p[u] = root, ans++;

	mark[u] = 2;
}
int main(){
	aux = root = -1;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 1; i <= n && root == -1; i++)
		dfs_root(i);
	if(root == -1)
		root = aux, p[aux] = aux, ans++;

	memset(mark, 0, sizeof(mark));
	for(int i = 1; i <= n; i++)
		dfs(i);

	cout << ans << endl;
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int p[MAXN];
int root, ans, aux;
vector<int> leafs;

int mark[MAXN];

void dfs_root(int u){
	mark[u] = 1;
	if(p[u] == u)
		root = u;
	if(mark[p[u]] == 0)
		dfs_root(p[u]);
	else if(aux == -1)
		aux = u;
}

void dfs(int u){
	mark[u] = 1;
	if(mark[p[u]] == 0)
		dfs(p[u]);
	else if(mark[p[u]] == 1 && p[u] != root)
		p[u] = root, ans++;

	mark[u] = 2;
}
int main(){
	aux = root = -1;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i];

	for(int i = 1; i <= n && root == -1; i++)
		dfs_root(i);
	if(root == -1)
		root = aux, p[aux] = aux, ans++;

	memset(mark, 0, sizeof(mark));
	for(int i = 1; i <= n; i++)
		dfs(i);

	cout << ans << endl;
	for(int i = 1; i <= n; i++)
		cout << p[i] << " ";
	return 0;
}