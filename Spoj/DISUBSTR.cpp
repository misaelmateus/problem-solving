#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define P 31
int main(){
	ios::sync_with_stdio(false);


	int t;
	cin >> t;
	while(t--){
		unordered_set<ll> c;
		string s;
		cin >> s;

		for(int i = 0; i < s.size(); i++){
			ll hash = 0;
			for(int j = i; j < s.size(); j++){
				hash *= P;
				hash += (ll)s[j];
				c.insert(hash);
			}

		}
		cout << c.size() << endl;
	}
}