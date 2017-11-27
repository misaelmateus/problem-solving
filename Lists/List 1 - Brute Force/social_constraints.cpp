#include<bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
int v[10];
int M[100][100];
int n, m;
int cont;
vector< pair<ii, int> > lista;
void f(int i, int mask){
	if(i == n){
		
		for(int j = 1; j < n; j++)
			for(int l = 0; l < j; l++){
				M[v[j]][v[l]] = M[v[l]][v[j]] = j - l;
			}
		for(int i = 0; i < lista.size(); i++){
			int c = lista[i].second;
			int a = lista[i].first.first, b = lista[i].first.second;
			if((c > 0 && M[a][b] > c) || ( c < 0 && M[a][b] < -c) ) return;
		}
		cont++;
		return ;
	}
	for(int j = 0; j < n; j++){
		if(!(mask & (1 << j)) ){
			v[i] = j;
			f(i+1, mask | (1 << j));
		}
	}
}
int main(){
	
	while(cin >> n >> m && n){
		cont = 0;
		lista.clear();
		int flag = 1;
		while(m--){
			int a, b, c;
			cin >> a >> b >> c;
			lista.push_back({{a,b}, c});
		}
		f(0, 0);
		cout << cont << "\n";
	}
}