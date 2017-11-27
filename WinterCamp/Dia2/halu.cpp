#include<bits/stdc++.h>
#define ii pair<ll, ll>
#define ll long long
using namespace std;
#define ff first
#define ss second
vector< pair<ii, ll> > vx, vy;

ll cont(ll x, vector<pair<ii, ll> > v){
	ll total = 0LL;
	for(int i = 0; i < v.size(); i++){
		if(v[i].ff.ff > x)
			total += v[i].ss*(v[i].ff.ss - v[i].ff.ff + 1) * (v[i].ff.ss + v[i].ff.ff - 2*x) / 2;
		else if (v[i].ff.ss < x)
			total += v[i].ss*(v[i].ff.ss - v[i].ff.ff + 1) * (2*x - v[i].ff.ss - v[i].ff.ff) / 2;
		else{
			total += v[i].ss*((x - v[i].ff.ff)*(x - v[i].ff.ff + 1) / 2);
			total += v[i].ss*((v[i].ff.ss - x)*(v[i].ff.ss - x + 1) / 2);
		}
	}

	return total;
}
pair<ii, ll> calc(ll x, vector<pair<ii, ll> > v){
	ll pre = 0LL, su = 0LL, l = 0LL;
	for(int i = 0; i < v.size(); i++){
		if(v[i].ff.ff > x)
			su += (v[i].ff.ss - v[i].ff.ff + 1) * v[i].ss;
		else if (v[i].ff.ss < x)
			pre += (v[i].ff.ss - v[i].ff.ff + 1) * v[i].ss;
		else{
			pre += (x - v[i].ff.ff) * v[i].ss;
			su += (v[i].ff.ss - x) * v[i].ss;
			l += v[i].ss;
		}
	}

	return {{pre, su}, l};
}


int main(){

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;

		vx.push_back({{x0, x1}, (y1 - y0 + 1LL)});
		vy.push_back({{y0, y1}, (x1 - x0 + 1LL)});
	}

	ll bestX = -1, ans = (1LL << 60);
	ll bestY = -1;
	for(int i = 0; i < vx.size(); i++){
		ll X = -1, Y = -1;
		ll ansX, ansY;
		ll l = vx[i].ff.ff - 1, r = vx[i].ff.ss; // input
		while (r - l > 2) {
		   ll m1 = l + (r - l) / 3,
		      m2 = r - (r - l) / 3;
		   if (cont (m1, vx) < cont (m2, vx)) // f - convex function
		      l = m1;
		   else
		      r = m2;
		}
		X = l+1, ansX = cont(X, vx);
		if(l+1 < vx[i].ff.ss && cont(l+2, vx) < ansX)
			ansX = cont(l+2, vx), X++;

		l = vy[i].ff.ff-1, r = vy[i].ff.ss; // input
		while (r - l > 2) {
		   ll m1 = l + (r - l) / 3,
		      m2 = r - (r - l) / 3;
		   if (cont (m1, vy) < cont (m2, vy)) // f - convex function
		      l = m1;
		   else
		      r = m2;
		}
		Y = l+1, ansY = cont(Y, vy);
		if(l+1 < vy[i].ff.ss && cont(l+2, vx) < ansY)
			ansY = cont(l+2, vy), Y++;
		ll ans1 = ansY + ansX;
		if(ans1 < ans || (ans1 == ans && X < bestX) || (ans1 == ans && X == bestX && Y < bestY)){
			ans = ans1;
			bestX = X;
			bestY = Y;
		}
	}
	cout << ans << endl;
	cout << bestX << " " << bestY << endl;
}