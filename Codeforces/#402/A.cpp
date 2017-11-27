#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
using namespace std;


string a, b;

int test(string s){
	int i = 0, j = 0;
	while(i < b.size() && j < s.size()){
		while(j < s.size() && s[j] != b[i]) j++;
		if(j == s.size()) break;
		i++, j++;
	}
	if(i == b.size())
		return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> a >> b;
	int t = a.size();
	int v[t];
	rep(i, t) cin >> v[i];

	int i = 0, j = t+1;
	while(j - i > 1){
		string c = a;
		int mid = (i + j)/2;
		rep(l, mid) c[v[l]-1] = '-';
		string d = "";
		rep(l, t) if(c[l] != '-') d += c[l];
		if(test(d))
			i = mid;
		else j = mid;
	}
	cout << i << "\n";

	return 0;
}