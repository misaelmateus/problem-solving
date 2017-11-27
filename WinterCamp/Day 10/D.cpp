#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector< pair<ll, int> > v(n);
	int type[n];
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> type[i];
		v[i].second = i;
	}

	sort(v.begin(), v.end());

	int i = n-1;
	ll sum = 0LL;
	set<pair<ll, int> > s0;
	set<int> s1;
	while(sum < m){
		sum += (ll)v[i].first;
		if(!type[v[i].second]) s0.insert({v[i].first, v[i].second});
		else s1.insert(v[i].second);
		i--;
	}

	cout << n-1-i << " ";
	sum -= m;
	for(; i >= 0 && s0.size(); i--){
		if(type[v[i].second]){
			auto it = s0.begin();
			if((*it).first <= v[i].first + sum){
				sum = sum + (ll)v[i].first - (*it).first;
				s0.erase(it);
				s1.insert(v[i].second);
			}
		}
	}
	cout << s1.size() << "\n";

	for(auto it = s0.begin(); it != s0.end(); it++)
		cout << (*it).second + 1 << " ";
	for(auto it = s1.begin(); it != s1.end(); it++)
		cout << (*it) + 1 << " ";
	cout << "\n";


	return 0;
}