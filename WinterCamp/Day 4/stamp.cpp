#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		string s[n], s1[a];
		for(int i = 0; i < n; i++)
			cin >> s[i];

		for(int i = 0; i < a; i++)
			cin >> s1[i];
		int flag = 1;
		for(int i = 0; i < n && flag; i++)
			for(int j = 0; j < m && flag; j++){
				if(s[i][j] != s1[i % a][j % b]){
					cout << "NIE\n";
					flag = 0;
				}
			}
		if(flag)
			cout << "ANO\n";
	}
}