#include<bits/stdc++.h>
using namespace std;
string s;
int cont[10];
int find_point(){
	int i;
	for(i = 0; i < s.size(); i++){
		if(++cont[s[i] - '0'] > 2)
				break;
	}
	if(i == s.size()) return i;
	for(; i >= 0; i--){
		--cont[s[i] - '0'];
		for(int j = s[i] - '0' - 1; j >= 0; j--)
			if(cont[j] < 2){
				cont[j]++, s[i] = '0' + j;
				return i+1;
			}
	}
}
int main(){
	ios::sync_with_stdio(false);	
	while(cin >> s){
		memset(cont, 0, sizeof(cont));
		int p = find_point();
		string s1 = s.substr(0, p);
		int j = 9;
		for(int i = p; i < s.size(); i++){
			while(cont[j] > 1) j--;
			s1 += j + '0';
			cont[j]++;
		}
		for(j = 0; j < s1.size() && s1[j] == '0'; j++);
		s1 = s1.substr(j, s1.size()-j);
		cout << s1 << "\n";
	}
}