#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n, m, k;
		cin >> n >> m >> k;
		
		string s;
		priority_queue<int> pq;
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin >> s;
			int cont = 0;
			for(int j = 0; j < m; j++) 
				cont += (s[j] == '*');
			ans += cont;
			pq.push(m - 2*cont);
		}

		while(k--){
			int u = pq.top();
			pq.pop();
			ans += u;
			
			int cont = (m - u)/2;
			cont = m - cont;
			pq.push(m - 2*cont);
		}

		cout << ans << "\n";
	}
}