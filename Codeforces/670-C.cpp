//   Author : Misael Mateus 
//   Submission date: 2016-05-05 23:12:52
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int idioma[n];
	map<int, int> mapa;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &idioma[i]);
		mapa[idioma[i]]++;
	}
	int m;
	scanf("%d", &m);
	map<int, int> filmes;
	int max = -1;
	int f[m];
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &f[i]);
		if(mapa[f[i]] == max)
			filmes[i] = 1;
		if(mapa[f[i]]> max)
		{
			max = mapa[f[i]];
			filmes.clear();
			filmes[i] = 1;
		}
	}
	max = -1;
	int escolha = 0;
	for(int i = 0; i < m; i++)
	{
		int aux;
		scanf("%d", &aux);
		if(filmes[i])
		{
			if(mapa[aux] > max)
				max = mapa[aux], escolha = i+1;
		} 
	}
	cout << escolha << endl;
	
	return 0;
}
