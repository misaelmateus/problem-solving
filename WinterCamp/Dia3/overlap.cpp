#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, d;
	cin >> n >> d;
	vector<pair<int, int> > beg[d+1], en[d+1];
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		beg[c].push_back({a, i+1});
		en[c].push_back({b, i+1});
	}

	for(int i = 1; i <= d; i++){
		sort(beg[i].begin(), beg[i].end());
		sort(en[i].begin(), en[i].end());

		if(beg[i].size() > 1 && beg[i][beg[i].size() - 1].first > en[i][0].first){
			cout << "ANO " << en[i][0].second << " " << beg[i][beg[i].size() - 1].second << "\n" ;
		}
		else cout << "NIE\n";
	}


	return 0;

}