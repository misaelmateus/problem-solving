#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n, m, k, x, s;
		scanf("%d %d %d %d %d", &n, &m, &k, &x, &s);
		vector<pair<int, int> > talent(m);
		vector<pair<int, int> > hero(k);

		vector<pair<int, int> > v1;
		vector<pair<int, int> > v2;
		ll ans = (1LL << 62);
		for(int i = 0; i < m; i++)
			scanf("%d", &talent[i].second);
		for(int i = 0; i < m; i++)
			scanf("%d", &talent[i].first);
		for(int i = 0; i < k; i++){
			scanf("%d", &hero[i].second);
			hero[i].second *= -1;
		}
		for(int i = 0; i < k; i++){
			scanf("%d", &hero[i].first);
		}

		talent.push_back({0, x});
		sort(talent.begin(), talent.end());
		sort(hero.begin(), hero.end());
		
			v1.push_back(talent[0]);
		for(int i = 1; i <= m; i++){
			if(talent[i].second >= v1.back().second) continue;
			v1.push_back(talent[i]);
		}
		
		v2.push_back(hero[0]);
		v2[0].second *= -1;
		for(int j = 1; j < k; j++){
			if(-hero[j].second <= v2.back().second) continue;
			v2.push_back(hero[j]);
			v2[v2.size()-1].second *= -1;
		}

		for(int i = 0; i < v1.size(); i++){
			int t = v1[i].second, p = s - v1[i].first;
			if(p < 0) break;
			int q = 0;
			auto it = upper_bound(v2.begin(), v2.end(),(pair<int, int>){p, 2*(1e9)});
			if(it != v2.begin()){
				it--;
				q = (*it).second;
			}
			ans = min(ans, (ll)t * (ll)max(0, (n - q)));
		}

		printf("%lld\n", ans);
	}
	return 0;
}