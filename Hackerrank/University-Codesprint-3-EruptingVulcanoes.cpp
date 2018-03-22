#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int x[m], y[m];
	for(int i = 0; i < m; i++)
		cin >> x[i] >> y[i];
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			int val = 0;
			for(int l = 0; l < m; l++)
				val += min(abs(i - x[l]), abs(j - y[l]));
			ans = max(val, ans);
		}
	cout << ans << endl;
}