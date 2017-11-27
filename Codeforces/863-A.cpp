//   Author : Misael Mateus 
//   Submission date: 2017-09-22 20:20:13
#include<bits/stdc++.h>
using namespace std;

bool check(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] != s[s.size() - i - 1])
			return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);	
	string s;
	cin >> s;
	string s1 = "";
	for(int i = 0; i < s.size()+1; i++, s1+= '0'){
		if(check(s1 + s)){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}