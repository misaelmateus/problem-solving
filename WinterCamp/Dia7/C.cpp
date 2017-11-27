#include<bits/stdc++.h>
#define MAXN 50
#define ld long double
#define EPS (ld)0.000000001
using namespace std;
ld x[MAXN], y[MAXN];
int v[MAXN];
int n;
ld dist(ld dx, ld dy, ld vi){
	return sqrt(dx*dx + dy*dy)/vi;
}
ld calc(ld x1, ld y1){
	ld ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dist(x1 - x[i], y1 - y[i], v[i]));
	}
	return ans;
}

ld f1(ld x1){
	ld l = -1001000.0, r = 1001000.0;
	for(int i = 0; i < 80; i++) {
	   ld m1 = l + (r - l) / 3,
	      m2 = r - (r - l) / 3;
	   if (calc (x1, m1) - calc (x1, m2) > EPS) 
	      l = m1;
	   else
	      r = m2;
	}
	return r;
}

ld f(){
	ld l = -1001000.0, r = 1001000.0;
	for(int i = 0; i < 80; i++) {
	   ld m1 = l + (r - l) / 3,
	      m2 = r - (r - l) / 3;

	   ld y1 = f1(m1), y2 = f1(m2);
	   if (calc (m1, y1) - calc(m2, y2) > EPS) 
	      l = m1;
	   else
	      r = m2;
	}
	return calc(r, f1(r));
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> v[i];
		cout << fixed << setprecision(11) << f() << endl;
	}
}