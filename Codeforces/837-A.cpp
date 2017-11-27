//   Author : Misael Mateus 
//   Submission date: 2017-08-07 07:05:12
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin.ignore();
	getline(cin, s);
	int cont = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == ' ')
			ans = max(ans, cont), cont = 0;
		else if(s[i] < 'a')
			cont++;
	}
	ans = max(ans, cont);
	cout << ans << endl;
}