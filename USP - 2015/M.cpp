#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cont = 0;
		vector<int> seq;
		for(int i = 0; i < n; i++){
			if(s[i] == 'B')
				cont++;
			else{
				cont++;
				for(int l = i; l >= 0 && cont > 0; l--, cont--)
					seq.push_back(l+1);
				if(i < n-1) s[i+1] = 'D' + 'B' - s[i+1];
			}
		}
		if(!cont){
			cout << "Y\n";
			for(int i = 0; i < n; i++)
				cout << seq[i] << " ";
		}
		else cout << "N\n";
	}
}