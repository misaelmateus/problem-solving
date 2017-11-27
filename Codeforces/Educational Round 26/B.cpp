#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	string s[n];
	map<char, int> cont;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		int flag = 1;
		for(int j = 1; j < m; j++){
			if(s[i][j] != s[i][j-1]){
				flag = 0;
				break;
			}
		}
		if(flag) cont[s[i][0]]++;
	}
	int flag = (n % 3 == 0);
	for(int i = 1; flag && i < n; i++){
		if(i != n/3  && i != 2 * n / 3  && s[i][0] != s[i-1][0]) flag = 0;
	}

	if(flag && cont['R'] == n/3 && cont['G'] == n/3  && cont['B'] == n/3 ){
		cout << "YES\n";
		return 0;
	}
	cont.clear();
	for(int i = 0; i < m; i++){
		flag = 1;
		for(int j = 1; j < n; j++){
			if(s[j][i] != s[j-1][i]){
				flag = 0;
				break;
			}
		}
		if(flag) cont[s[0][i]]++;
	}
	flag = (m % 3 == 0);
	for(int i = 1; flag && i < m; i++){
		if(i != m/3  && i != 2 * m / 3  && s[0][i] != s[0][i-1]) flag = 0;
	}

	if(flag && cont['R'] == m/3 && cont['G'] == m/3  && cont['B'] == m/3 )
		cout << "YES\n";
	else cout << "NO\n";
}