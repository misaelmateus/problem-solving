#include<bits/stdc++.h>
using namespace std;
int main(){
	string s, t;
	int a, b;
	cin >> a >> b >> s >> t;
	int pos = -1, tam = 100000;
	for(int i = 0; i <= b - a; i++){
		int cont = 0;
		for(int j = 0; j < a; j++){
			if(s[j] != t[j+i]) cont++;
		}
		if(cont < tam) tam = cont, pos = i;
	}
	cout << tam << endl;
	for(int j = 0; j < a; j++){
		if(s[j] != t[j + pos]) cout << j+1 << " ";
	}
	cout << endl;
}