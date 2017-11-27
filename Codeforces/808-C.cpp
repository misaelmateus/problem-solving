//   Author : Misael Mateus 
//   Submission date: 2017-05-16 22:42:23
#include<bits/stdc++.h>
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;

bool comp(pair<ii, int> a, pair<ii, int> b){
	return a.second < b.second;
}
int main(){
	int n, w;
	cin >> n >> w;
	pair<ii, int> a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i].ff.ff;
		a[i].ff.ss = (a[i].ff.ff + 1)/2;
		a[i].ss = i;
		w -= a[i].ff.ss;
	}
	if(w < 0){
		cout << -1 << endl;
		return 0;
	}
	sort(a, a+n);
	while(w > 0)
		for(int i = n-1; i >= 0 && w > 0; i--){
			if(a[i].ff.ss < a[i].ff.ff)
				a[i].ff.ss++, w--;
		}
	sort(a, a+n, comp);
	for(int i = 0; i < n; i++) cout << a[i].ff.ss << " ";
	cout << endl;
}