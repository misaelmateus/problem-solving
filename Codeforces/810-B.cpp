//   Author : Misael Mateus 
//   Submission date: 2017-05-20 23:45:05
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 0.000000001
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++);
#define rep(a, b) fr(a, 0, c)
#define fill(v, x) memset(v, x, sizeof(v))
#define RI(x) scanf("%d", &x)
#define RII(x, y) scanf("%d %d", &x, &y)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int n, f;
	cin >> n >> f;
	priority_queue<ll> pq;
	ll tot = 0LL;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		tot += min(a, b);
		if(a < b)
			pq.push( min(a, b - a));
	}
	for(int i = 0; i < f; i++){
		if(pq.empty()) break;
		tot += pq.top();
		pq.pop();
	}

	cout << tot << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 0.000000001
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++);
#define rep(a, b) fr(a, 0, c)
#define fill(v, x) memset(v, x, sizeof(v))
#define RI(x) scanf("%d", &x)
#define RII(x, y) scanf("%d %d", &x, &y)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int n, f;
	cin >> n >> f;
	priority_queue<ll> pq;
	ll tot = 0LL;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		tot += min(a, b);
		if(a < b)
			pq.push( min(a, b - a));
	}
	for(int i = 0; i < f; i++){
		if(pq.empty()) break;
		tot += pq.top();
		pq.pop();
	}

	cout << tot << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 0.000000001
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++);
#define rep(a, b) fr(a, 0, c)
#define fill(v, x) memset(v, x, sizeof(v))
#define RI(x) scanf("%d", &x)
#define RII(x, y) scanf("%d %d", &x, &y)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int n, f;
	cin >> n >> f;
	priority_queue<ll> pq;
	ll tot = 0LL;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		tot += min(a, b);
		if(a < b)
			pq.push( min(a, b - a));
	}
	for(int i = 0; i < f; i++){
		if(pq.empty()) break;
		tot += pq.top();
		pq.pop();
	}

	cout << tot << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define EPS 0.000000001
#define fr(a, b, c) for(int (a) = (b); (a) < (c); (a)++);
#define rep(a, b) fr(a, 0, c)
#define fill(v, x) memset(v, x, sizeof(v))
#define RI(x) scanf("%d", &x)
#define RII(x, y) scanf("%d %d", &x, &y)


using namespace std;

int main(){
	ios::sync_with_stdio( false );
	int n, f;
	cin >> n >> f;
	priority_queue<ll> pq;
	ll tot = 0LL;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		tot += min(a, b);
		if(a < b)
			pq.push( min(a, b - a));
	}
	for(int i = 0; i < f; i++){
		if(pq.empty()) break;
		tot += pq.top();
		pq.pop();
	}

	cout << tot << endl;
}