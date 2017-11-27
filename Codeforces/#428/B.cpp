
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



int main(){
	ios::sync_with_stdio(false);	
	int n, k;
	cin >> n >> k;
	vi v(k);
	int c2 = 0, c1 = 0;	
	int a = 2*n;
	int b = n;
	rep(i, k) {
		cin >> v[i];
		while(v[i] >= 4 && b > 0)
			v[i] -= 4, b--;
		while(v[i] >= 2 && a > 0)
			v[i] -= 2, a--;
		if(v[i] == 3)
			c2++, c1++;
		else if(v[i] == 2) c2++;
		else if(v[i] == 1) c1++;
		else if(v[i] != 0)b = -1;
	}
	if(b >= 0){
		int x = min(c2, b);
		c2 -= x, b -= x, c1 -= x;
		c1 -= a + 2*b;
	}
	if(b >= 0 && c1 <= 0 && c2 <= 0)
			cout << "YES\n";
	else cout << "NO\n";
	return 0;

}