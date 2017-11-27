//   Author : Misael Mateus 
//   Submission date: 2017-10-26 20:16:18
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;

vector<pair<int, int> > v;
vector<pair<int, int> > ini, fim;
ll ans;

ll n, m, k;
void f(int i, int j){
	if(i > j) return;
	//cout << i <<" " << j << endl;
	if(i == j){
		ans += (((ll)m * v[i].second) / (ll)k)*(ll)k;
		if((m*v[i].second) % k != 0) ini.clear(), fim.clear();
		return ;
	}
	if( v[i].first == v[j].first && (v[i].second + v[j].second) % k == 0){
		ans += ((ll)(v[i].second + v[j].second) * (ll)(m-1));
		ini.push_back(v[i]);
		fim.push_back(v[j]);
		f(i+1, j-1);
		return ;
	}
	else if(v[i].first == v[j].first){
		ans += (((ll)(v[i].second + v[j].second) / (ll)k) * (ll)k)*(ll)(m-1);
		ini.clear();
		fim.clear();
		return ;
	}
	else{
		ini.clear();
		fim.clear();
		return ;
	}
}
int main(){
	readFast;
	ans = 0LL;
	cin >> n >> k >> m;
	int ai;
	for(int i = 0; i < n; i++){
		cin >> ai;
		if(!v.size() || v.back().first != ai) v.push_back({ai, 1});
		else{
			v.back().second++;
			if(v.back().second == k)
				ans+=k, v.pop_back();
		}
	}
	
	
	ans *= (ll)m;
	
	if(m == 1){
		cout << ((ll)n - ans) << "\n";
		return 0;
	}
	f(0, v.size()-1);
	while(ini.size() && fim.size()){
		if(ini.back().first == fim.back().first){
			ans += ((ll)(ini.back().second + fim.back().second)/(ll)k )* (ll)k;
			if( (ini.back().second + fim.back().second) % k != 0)
				break;
			ini.pop_back();
			fim.pop_back();
		}
		else break;
	}

	cout << ((ll)n * m - ans) << "\n";
	return 0;
}