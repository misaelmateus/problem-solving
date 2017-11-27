#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int v[n];
	int A = 0;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		v[i] = a - b;
		if(v[i] > 0)
			A++;
	}
	vector<pair<int, int> > ans;
	vector<int> mark(n, 0);
	int N = n;
	for(int i = 0; i < n-1 && 2*A <= N; i++){
		if((v[i] + v[i+1] > 0 && (v[i+1] <= 0 || v[i] <= 0)) || (v[i] <= 0 && v[i+1] <= 0)){
			ans.push_back({i+1, i+2});
			N--;
			i++;
		}
	}
	if(2*A <= N)
		cout << -1 << endl;
	else{ 
		cout << ans.size() << "\n";
		for(int i =0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << "\n";
	}

	return 0;
}