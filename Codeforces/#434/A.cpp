#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 0.000000001
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++);
#define rep(a, b) fr(a, 0, b)
#define fill(v, x) memset(v, x, sizeof(v))
#define RI(x) scanf("%d", &x)
#define RII(x, y) scanf("%d %d", &x, &y)


using namespace std;
string s;


int main(){
	map<int, int> mapa;
	mapa['a'] = 1;
	mapa['e'] = 1;
	mapa['i'] = 1;
	mapa['o'] = 1;
	mapa['u'] = 1;
	ios::sync_with_stdio( false );
	cin >> s;
	int count = 0, diff = 0;
	for(int i = 0; i < s.size(); i++){
		if(mapa[s[i]]){
			printf("%c", s[i]);
			count = 0, diff = 0;
			continue;
		}
		count++;
		if(count > 1 && s[i-1] != s[i])
			diff = 1;
		if(count >= 3 && diff){
			printf(" %c", s[i]);
			count = 1, diff = 0;
		}
		else printf("%c", s[i]);
	}
	printf("\n");
}