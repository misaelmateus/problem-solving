//   Author : Misael Mateus 
//   Submission date: 2017-04-21 19:59:52
#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;

string change(string s){
	string s1 = "";
	fr(i, 1, s.size())
		s1 += s[i];
	s1 += s[0];
	return s1;
}
int main(){
	ios::sync_with_stdio( false );
	int n;
	cin >> n;
	string s[n];
	rp(i, n) cin >> s[i];
	int t = s[0].size();
	int ans = 100000000;
	rp(i, t){
		int temp = i;

		fr(j, 1, n){
			string s1 = s[j];
			int l;
			for(l = 0; l < t && s1 != s[0]; l++)
				s1 = change(s1);
			temp += l;
			if(s1 != s[0]){
				temp = -1;
				break;
			}
		}
		s[0] = change(s[0]);
		if(temp == -1)
			continue;
		else ans = min(ans, temp);
		
	}
	if(ans == 100000000)
		cout <<  -1 << "\n";
	else cout << ans << "\n";
}