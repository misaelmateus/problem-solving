//   Author : Misael Mateus 
//   Submission date: 2016-05-16 17:39:20
#include<bits/stdc++.h>
#define MAXN 100100
using namespace std;

int n, m;
vector<int> v[MAXN];
int mark[MAXN];
int dfs( int now, int parent)
{
	mark[now] = 1;
	bool teste = true;
	for(int i = 0; i < v[now].size(); i++)
	{
		int other = v[now][i];
		if(other == parent)
			continue;
		if(mark[other] == 1)
			teste = false;
		if(mark[other] == 0)
			if(dfs( other, now) == false)
				teste = false;
	}
	mark[now] = 2;
	return teste;
}
int main()
{

	scanf("%d %d", &n, &m);
	int cont = 0;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
		if(mark[i] == 0 && dfs(i, i) )
			cont++;
			
	printf("%d\n", cont);
	
	return 0;
}
