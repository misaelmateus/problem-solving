//   Author : Misael Mateus 
//   Submission date: 2017-08-29 22:58:14
#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

vector<int> gr[MAXN];
int ans[MAXN], v[MAXN];
int dfs(int u, int p, int gcd, set<int> s){
	set<int> s1;
	for(auto it = s.begin(); it != s.end(); it++)
		s1.insert(__gcd(*it, v[u]));
	s1.insert(gcd);
	gcd = __gcd(gcd, v[u]);
	auto it = s1.end(); it--;
	ans[u] = *it;
	for(auto next: gr[u]){
		if(next == p) continue;
		dfs(next, u, gcd, s1);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1, -1, 0, {0});

	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

vector<int> gr[MAXN];
int ans[MAXN], v[MAXN];
int dfs(int u, int p, int gcd, set<int> s){
	set<int> s1;
	for(auto it = s.begin(); it != s.end(); it++)
		s1.insert(__gcd(*it, v[u]));
	s1.insert(gcd);
	gcd = __gcd(gcd, v[u]);
	auto it = s1.end(); it--;
	ans[u] = *it;
	for(auto next: gr[u]){
		if(next == p) continue;
		dfs(next, u, gcd, s1);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1, -1, 0, {0});

	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

vector<int> gr[MAXN];
int ans[MAXN], v[MAXN];
int dfs(int u, int p, int gcd, set<int> s){
	set<int> s1;
	for(auto it = s.begin(); it != s.end(); it++)
		s1.insert(__gcd(*it, v[u]));
	s1.insert(gcd);
	gcd = __gcd(gcd, v[u]);
	auto it = s1.end(); it--;
	ans[u] = *it;
	for(auto next: gr[u]){
		if(next == p) continue;
		dfs(next, u, gcd, s1);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1, -1, 0, {0});

	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

vector<int> gr[MAXN];
int ans[MAXN], v[MAXN];
int dfs(int u, int p, int gcd, set<int> s){
	set<int> s1;
	for(auto it = s.begin(); it != s.end(); it++)
		s1.insert(__gcd(*it, v[u]));
	s1.insert(gcd);
	gcd = __gcd(gcd, v[u]);
	auto it = s1.end(); it--;
	ans[u] = *it;
	for(auto next: gr[u]){
		if(next == p) continue;
		dfs(next, u, gcd, s1);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);

	for(int i = 0; i < n-1; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1, -1, 0, {0});

	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}