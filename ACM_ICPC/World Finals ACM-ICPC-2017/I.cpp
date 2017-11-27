#include<bits/stdc++.h>
using namespace std;
int main(){
	map<pair<char, char>, int> mapa;
	int m, n;
	cin >> m >> n;
	while(m--){
		char a, b;
		cin >> a >> b;
		mapa[a][b] = 1;
		for(auto it = )
	}

	for(int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		int ans = 1;
		if(a.size() != b.size()){
			cout << "no\n";
			continue;
		}
		for(int i = 0; i < a.size(); i++){
			while(a[i] != b[i] && mapa[])
				ans = 0;
		}
		if(ans)
			cout << "yes\n";
		else cout << "no\n"; 
	}


	return 0;
}