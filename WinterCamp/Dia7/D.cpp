#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		int ans = 1;
		for(int i = 0; i < s.size(); i++)
			if(s[i] != s[s.size() - 1 - i]) ans = 0;
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
}