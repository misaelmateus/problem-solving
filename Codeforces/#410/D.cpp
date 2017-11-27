#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
using namespace std;

ll sum1, sum2;

int test(vector<pair<ii, int> > v){
	ll a = 0LL, b = 0LL;
	for(int i = 0; i < v.size()/2 + 1; i++)
		a += v[i].first.first, b += v[i].first.second;
	if(2*a > sum1 && 2*b > sum2)
		return true;
	return false;
}
int main(){
	int n;
	cin >> n;
	vector<pair<ii, int> > v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i].first.first >> v[i].first.second;
		sum1 += v[i].first.first;
		sum2 += v[i].first.second;
		v[i].second = i+1;
	}

	while(!test(v)){
		random_shuffle(v.begin(), v.end());
	}

	cout << n/2+1 << endl;
	for(int i = 0; i < n/2+1; i++){
		cout << v[i].second << " ";
	}
}