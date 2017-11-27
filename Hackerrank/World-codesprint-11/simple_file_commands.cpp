#include<bits/stdc++.h>
using namespace std;

map<string, int> tam;
map<string, set<int> > rest;

void add(string s, int flag){
	if(!tam[s]){
		if(flag)
			cout << "+ " ;
		cout << s << "\n";
		tam[s]++;
		return;
	}
	if(rest[s].size() == 0){
		if(flag)
			cout << "+ ";
		cout << s << "(" << tam[s] << ")" << "\n";
		tam[s]++;
		return;
	}
	else{
		int i = (*rest[s].begin());
		rest[s].erase(i);
		if(flag)
			cout << "+ ";
		cout << s;
		if(i) cout << "(" << i << ")";
		cout << "\n";
	}
}

void del(string s, int i, int flag){
	if(i == tam[s]-1)
		tam[s]--;
	else rest[s].insert(i);
	if(!flag) return;
	cout << "- " << s;
	if(i) cout << "(" << i << ")";
	cout << "\n";
}

void divide(string &s, int &n){
	n = 0;
	int i;
	for(i = s.size()-1; i >= 0 && s[i] != ')'; i--);
	if(i < 0)
		return;
	i--;
	int mult = 1;
	for(; s[i] != '('; i--){
		n += mult*(int)(s[i] - '0');
		mult *= 10;	
	}
	int t = s.size();
	for(; i < t; i++) s.pop_back();
}

int main(){
	int T;
	cin >> T;
	while(T--){
		string type;
		string s, s1;
		cin >> type >> s;
		if(type[0] == 'c'){
			add(s, 1);
		}
		else if(type[0] == 'd'){
			int n;
			divide(s, n);
			del(s, n, 1);
		}
		else{
			cin >> s1;
			cout << "r " << s << " -> ";
			int n;
			divide(s, n);
			del(s, n, 0);
			add(s1, 0);
		}
	}
}