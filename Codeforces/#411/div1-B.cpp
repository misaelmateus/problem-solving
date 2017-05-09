#include<bits/stdc++.h>

#define L 1000000007LL
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	ll t = 0LL;
	int i;
	for(i = s.size() - 1; i >= 0 && s[i] == 'a'; i--);
	ll cont = 0LL;
	for(; i >= 0; i--){
		if(s[i] == 'a')
			t = (t + cont)%L, cont = (cont * 2LL) %L;
		if(s[i] == 'b')
			cont++;
	}
	cout << t << "\n";
	return 0;
}