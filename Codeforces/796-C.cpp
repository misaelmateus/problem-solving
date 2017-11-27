//   Author : Misael Mateus 
//   Submission date: 2017-04-10 22:21:15
#include<bits/stdc++.h>
#define MAXN 300010
using namespace std;
vector<int> gr[MAXN];
int a[MAXN];
int n, s;
int test(int m){
	vector<int> cont(MAXN, 0);
	int contC = 0, center = -1;
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(a[i] == m)
			contC++, center = i;
		else if(a[i] == m-1)
			q.push(i), cont[i] = 1;
	
	if(contC > 1)
		return 0;
	int t = q.size();
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0; i < gr[u].size(); i++){
			cont[gr[u][i]]++;
		}
	}
	if(contC != 0 && cont[center] != t)
		return 0;
	else if(contC != 0)
		return 1;
	for(int i = 1; i <= n; i++)
		if(cont[i] == t)
			return 1;
	return 0;
}
int main(){
	scanf("%d", &n);
	int m = -1000000010;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		m = max(m, a[i]);
	}
	int a, b;
	for(int i = 0; i < n-1; i++){
		scanf("%d %d", &a, &b);
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	if(test(m))
		printf("%d\n", m);
	else if(test(m+1))
		printf("%d\n", m+1);
	else printf("%d\n", m+2);
}
