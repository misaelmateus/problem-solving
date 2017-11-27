#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;

	int a = 1, b = s.size()+1;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '<')
			cout << a++ << " ";
		else cout << b-- << " ";
	}

	cout << a << "\n";
}