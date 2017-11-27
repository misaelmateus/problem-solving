	#include<bits/stdc++.h>
	#define ii pair<int, int>
	using namespace std;
	int main(){
		map<int, vector<pair<int, ii> > > m1;
		vector< pair<int, ii> > v;
		int n, x, l, r, c;
		cin >> n >> x;

		for(int i = 0; i < n; i++){
			cin >> l >> r >> c;
			int d = (r - l + 1);
			m1[d].push_back({r, {c, 0}});
			v.push_back({c, {l, r}});
		}

		for(auto it = m1.begin(); it != m1.end(); it++){
			int best = (1 << 30);
			sort((it->second).begin(), (it->second).end());
			for(auto& p : (it->second)){
				best = min(best, (p.second).first);
				p.second.second = best;
			}
		}
		int ans = 2000000001;
		for(auto &p: v){
			c = p.first, l = p.second.first, r = p.second.second;
			int d = x -(r - l + 1);
			if(d < 0 || m1[d].size() == 0) continue;
			auto it = lower_bound(m1[d].begin(), m1[d].end(), (pair<int, ii>){l, {-(1 << 30), -(1 << 30)}} );
			if(it != m1[d].begin()){
				it--;
				ans = min(ans, c + (*it).second.second);
			}
		}
		if(ans == 2000000001) ans = -1;
		cout << ans << endl;
	}