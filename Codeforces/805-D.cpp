//   Author : Misael Mateus 
//   Submission date: 2017-05-04 20:32:13
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = (b); (b) < (c); c++)
#define rep(a, b) fr(a, 0, c)
#define ll long long
#define ld long double
#define fill(v, x) memset(v, x, sizeof(v))
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