#include<bits/stdc++.h>
#define MAXN 300010
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

set<int> gr[MAXN];
vector<ii> a;
int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	a = vector<ii>(m);
	for(int i = 0; i < m; i++){
		cin >> a[i].ff >> a[i].ss;
		gr[a[i].ff].insert(a[i].ss);
		gr[a[i].ss].insert(a[i].ff);
	}
	long long ans = 0;
	map< set<int>, int > cont;
	map< ii, int > mark;
	for(int i = 1; i <= n; i++){
		ans += (long long)cont[gr[i]];
		cont[gr[i]]++;
	}

	for(int i = 0; i < m; i++){
		if(a[i].ff > a[i].ss)
			swap(a[i].ff, a[i].ss);
		if(mark[{a[i].ff, a[i].ss}])
			continue;
		mark[{a[i].ff, a[i].ss}]++;

		gr[a[i].ff].erase(a[i].ss);
		gr[a[i].ss].erase(a[i].ff);
		if(gr[a[i].ff] == gr[a[i].ss])
			ans++;
		gr[a[i].ff].insert(a[i].ss);
		gr[a[i].ss].insert(a[i].ff);
	}

	cout << ans << "\n";
	return 0;
}