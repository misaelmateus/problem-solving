#include<bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector< pair<ii, ii> > v;
		for(int i = 0; i < n; i++){
			int h1, h2, w1, w2;
			cin >> h1 >> h2 >> w1 >> w2;
			v.push_back({{h1, -h2}, {w1, -w2}});
		}
		sort(v.begin(), v.end());
		int flag = 1;
		for(int i = 1; i < n; i++){
			if(v[i].ff.ff < v[0].ff.ff || -v[i].ff.ss > -v[0].ff.ss || v[i].ss.ff < v[0].ss.ff || -v[i].ss.ss > -v[0].ss.ss){
				cout << "NIE\n";
				flag = 0;
				break;
			}

		}
		if(flag)
			cout << "ANO\n";
	}
}