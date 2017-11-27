#include<bits/stdc++.h>
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define mp make_pair
#define MAXN 60

using namespace std;
int main(){
	ios::sync_with_stdio( false );
	int T;
	cin >> T;
	for(int l = 1; l <= T; l++){
		string s;
		cin >> s;
		int t = s.size();
		stack<int> p;
		int ans = 1;
		for(int i = 0; i < t; i+=2){
			int m = (int)(s[i+1] == '1');

			if(s[i] == 'P') p.push(m);
			else {
				if(p.empty() || p.top() != 1 - m){
					ans = 0;
					break;
				}
				p.pop();
			}
		}
		if(!p.empty()) ans = 0;

		if(ans) cout << "Caso " << l << ": Sim" << "\n";
		else cout << "Caso " << l << ": Nao" << "\n";
	} 
}