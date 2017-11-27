#include<bits/stdc++.h>
#define MAXN 300010
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

int tree[MAXN];

void update(int a){
	while(a < MAXN){
		tree[a] ^= 1;
		a += (a & -a);
	}
}

int query(int a){
	int sum = 0;
	while(a > 0){
		sum ^= tree[a];
		a -= (a & -a);
	}
	return sum;
}

int k;
set<int> aux;
map<int, int> mapa;
int main(){
	k = 1;
	int P, V;
	while(cin >> P >> V){
		aux.clear();
		mapa.clear();
		memset(tree, 0 ,sizeof(tree));
		vector<ii> pl(P);
		vector<ii> fence(V);
		vector<pair<ii, int> > sweep;
		for(int i = 0; i < P; i++){
			cin >> pl[i].first >> pl[i].second;
			aux.insert(pl[i].second);
			sweep.push_back({{pl[i].first, i}, 0});
		}
		for(int i = 0; i < V; i++){
			cin >> fence[i].first >> fence[i].second;
			aux.insert(fence[i].second);
			if(i && fence[i].first == fence[i-1].first)
				sweep.push_back({{fence[i].first, i}, 1});
		}
		if(fence[0].first == fence[V-1].first)
			sweep.push_back({{fence[0].first, 0}, 1});
		for(auto u : aux)
			mapa[u] = ++k;
		
		sort(sweep.begin(), sweep.end());
		long long ans = 0LL;
		for(auto u : sweep){
			if(u.second == 0){
				ans += (long long) (query(mapa[pl[u.ff.ss].ss]) == 0) * (u.ff.ss + 1);
				//cout << mapa[pl[u.ff.ss].ss] << " - " << query(mapa[pl[u.ff.ss].ss]) << endl;
			}
			else{
				int a = mapa[fence[u.ff.ss].ss], b = mapa[fence[(u.ff.ss + V - 1) % V].ss];
				//cout << a << " "<< b << endl;
				if(a < b)
					swap(a, b);
				update(a);
				update(b);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}