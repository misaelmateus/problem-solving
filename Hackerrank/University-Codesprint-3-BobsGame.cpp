#include<bits/stdc++.h>
using namespace std;
int mex(int a, int b, int c){
	for(int i = 0; i <5; i++){
		if(i != a && i != b && i != c)
			return i;
	}
    return 0;
}

int x[] = {-1, -1, 0};
int y[] = {-1, 0, -1};
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s[n];
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		int grundy[n][n];
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s[i][j] == 'X'){
					grundy[i][j] = 0;
					continue;
				}
				int v[3];
				for(int l = 0; l < 3; l++){
					int i1 = i + x[l], j1 = j + y[l];
					if(i1 < 0 || j1 < 0 || s[i1][j1] == 'X') v[l] = -1;
					else v[l] = grundy[i1][j1];
				}
				grundy[i][j] = mex(v[0], v[1], v[2]);
				if(s[i][j] == 'K')
					ans ^= grundy[i][j];
			}
		}
        int cont = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(s[i][j] == 'K'){
					for(int l = 0; l < 3; l++){
						int i1 = i + x[l], j1 = j + y[l];
						if(i1 < 0 || j1 < 0 || s[i1][j1] == 'X') continue;
						if(!(ans ^ grundy[i][j] ^ grundy[i1][j1]))
							cont++;
					}
				}
			}
		}
        if(!cont) cout << "LOSE\n";
		else cout <<"WIN " << cont << "\n";

	}
}