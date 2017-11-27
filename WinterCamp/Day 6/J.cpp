#include<bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;

	vector< ii > sX;
	set< ii > s;
	vector< pair<ii, ii > > p(n);
	vector< int > parent(n, -1);

	for(int i = 0; i < n; i++){
		cin >> p[i].ff.ff >> p[i].ff.ss >> p[i].ss.ff >> p[i].ss.ss;
		sX.push_back({p[i].ff.ss, i});
		sX.push_back({p[i].ss.ss, i});
	}
	sort(sX.begin(), sX.end());

	for(auto &u : sX){
		if(u.ff == p[u.ss].ff.ss){
			auto it = s.lower_bound({p[u.ss].ss.ff, -1});
			if(it == s.end())
				parent[u.ss] = -1;
			else{
				int v = (*it).ss;
				while(v != -1 && p[v].ff.ff >= p[u.ss].ff.ff) v = parent[v];
				if(v != -1) parent[u.ss] = v;
			}
			s.insert({p[u.ss].ss.ff, u.ss});
		}
		else{
			s.erase({p[u.ss].ss.ff, u.ss});
		}
	}

	for(int i = 0;i < n; i++)
		cout << parent[i] << "\n";
}