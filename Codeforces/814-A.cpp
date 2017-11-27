//   Author : Misael Mateus 
//   Submission date: 2017-06-09 16:34:31
#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define ld long double
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)

using namespace std;



int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	if(k > 1){
		cout << "Yes\n";
		return 0;
	}
	int p = -1;
	rep(i, n){
		cin >> v[i];
		if(!v[i]) p = i;
	}
	int aux;
	if(k)
		cin >> aux;
	if(p != -1) v[p] = aux;

	fr(i, 1, n) 
		if(v[i] <= v[i-1]){
			cout << "Yes\n";
			return 0;
		}
	cout << "No\n";
	return 0;
}


