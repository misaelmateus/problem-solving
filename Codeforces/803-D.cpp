//   Author : Misael Mateus 
//   Submission date: 2017-04-30 02:58:04
#include<bits/stdc++.h>
#define ll long long
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;
int main(){
	int k;
	cin >> k;
	vector<int> v;
	
	string s;
	cin.ignore();
	getline(cin, s);
	int t = s.size();
	
	int cont = 0;
	rep(i, t){
		if(s[i] == ' ' || s[i] == '-')
			v.push_back(cont+1), cont = 0;
		else cont++;
	}
	v.push_back(cont);
	int i = 0, j = s.size()+1;
	int n = v.size();
	while(j - i > 1){
		int middle = (i+j) >> 1;
		cont = 1;
		int tot = 0;
		rep(l, n){
			if(tot + v[l] > middle){
				cont++, tot = v[l];
				if(tot > middle){
					cont = 10000000;
					break;
				}
			}
			else 
				tot += v[l];
		}
		if(cont <= k)
			j = middle;
		else
			i = middle;
	}

	cout << j << endl;
	return 0;
}
