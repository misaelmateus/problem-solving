//   Author : Misael Mateus 
//   Submission date: 2016-06-17 23:31:53
#include<bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;
vector< pair<int, ll> > v[MAXN];
int n;
ll a[MAXN];
int cont = 0;
int mark[MAXN];
void dfs(int atual, ll dist, int flag)
{
	if(flag == 0)
	{
		if(dist > a[atual]){
			cont++;
			flag = 1;
		}
	}
	else
	{
		cont++;
	}
	mark[atual] = 1;
	if(dist < 0LL)
		dist = 0LL;
	for(int i = 0; i < v[atual].size(); i++)
	{
		int prox = v[atual][i].first;
		ll c = v[atual][i].second;
		if(!mark[prox])
		{
			dfs(prox, dist+c, flag);
		} 
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = 0; i < n-1; ++i){
		int pi;
		ll ci;
		cin >> pi >> ci;
		v[i+1].push_back(make_pair(pi-1, ci));
		v[pi-1].push_back(make_pair(i+1, ci));
	}

	dfs(0, 0LL, 0);
	cout << cont;

	return 0;
}