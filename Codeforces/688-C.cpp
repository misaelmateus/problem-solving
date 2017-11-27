//   Author : Misael Mateus 
//   Submission date: 2016-06-29 22:34:15
#include<bits/stdc++.h>
#define MAXN 100100
#define MAXM 100100
using namespace std;
int n, m;
vector<int> v[MAXN];
vector<int> set1, set2;
int mark[MAXN];
int qual[MAXN];
int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue< pair<int, int> > fila;
	for (int i = 1; i <= n; ++i)
	{
		if(mark[i] || !v[i].size())
			continue;
		fila.push(make_pair(i, 1));
		set1.push_back(i);
		qual[i] = 0;
		while(!fila.empty())
		{
			int atual = fila.front().first;
			int set_atual = fila.front().second;
			fila.pop();
			mark[atual] = 1;
			for (int j = 0; j < v[atual].size(); ++j)
			{
				int prox = v[atual][j];
				if(mark[prox] || !v[prox].size())
					continue;	
				if(set_atual == 2){
					fila.push( make_pair(prox, 1));
					set1.push_back(prox);
					qual[prox] = 1;
				}
				else{
					set2.push_back(prox);
					fila.push( make_pair(prox, 2));
					qual[prox] = 2;
				}
				mark[prox] = 1;
			}

		}
	}
	int flag = 1;
	for (int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			if(qual[i] == qual[v[i][j]])
				flag = 0;
		}
	}

	if(!flag)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << set1.size() << endl;
	for(int i = 0; i < set1.size(); i++)
	{
		if(i)
			cout << " ";
		cout << set1[i];
	}

	cout << endl;

	cout << set2.size() << endl;
	for(int i = 0; i < set2.size(); i++)
	{
		if(i)
			cout << " ";
		cout << set2[i];
	}

	cout << endl;
}