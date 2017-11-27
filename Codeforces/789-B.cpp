//   Author : Misael Mateus 
//   Submission date: 2017-03-29 22:01:36
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ABS(ll a){
	if(a >= 0)
		return a;
	return -a;
}
int main(){
	ios::sync_with_stdio( false );

	ll b1, q, l, m;
	cin >> b1 >> q >> l >> m;
	set<ll> s;
	ll aux;
	while(m--){
		cin >> aux;
		s.insert(aux);
	}
	if(b1 == 0){
		if(!s.count(0))
			cout << "inf\n";
		else cout << "0\n";
		return 0;
	}
	if(q == 0){
		if(ABS(b1) > l)
			cout << "0\n";
		else if(!s.count(0))
			cout << "inf\n";
		else if(!s.count(b1))
			cout << "1\n";
		else cout << "0\n";
		return 0;
	}
	if(q == -1){
		if(ABS(b1) > l)
			cout << "0\n";
		else if( (!s.count(b1) || !s.count(-b1)))
			cout << "inf\n";
		else cout << "0\n";
			
		return 0;

	}
	if(q == 1){
		if(ABS(b1) <= l && !s.count(b1))
			cout << "inf\n";
		else
			cout << "0\n";
		return 0;

	}


	ll now = b1;
	int ans = 0;
	while(ABS(now) <= l){
		if(s.count(now) == 0)
			ans++;
		now *= q;
	}

	cout << ans << "\n";
	return 0;
}