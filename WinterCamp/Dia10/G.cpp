#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	set<int> s;
	vector<int> v(n);
	int me = 1e9;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		me = min(v[i], me);
	}
	ll sum = 0LL;
	ll tot = 0LL;
	for(int i = 0; i < k-1; i++){
		sum += (ll)v[i];
		if(v[i] > me)
			s.insert(-i);
	}
	for(int j = k-1; j < n; j++){
		sum += v[j];
		if(v[j] > me)
			s.insert(-j);
		while(sum >= 0){
			int i = -(*s.begin());
			if(i < j-(k-1)){
				s.erase(-i);
				continue;
			}
			int val = min((ll)v[i] - me, sum+1);
			tot += val;
			sum -= val;
			v[i] -= val;
			if(v[i] == me)
				s.erase(-i);
		}
		sum -= v[j-(k-1)];
	}
	cout << tot << "\n";
	for(int i = 0; i < n; i++)
		cout << v[i] << " ";
	cout << "\n";
}