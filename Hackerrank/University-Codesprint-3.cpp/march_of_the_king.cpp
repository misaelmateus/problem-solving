#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

string m[10];
string s;
int x[] = {1, -1, 0, 0, 1, 1, -1, -1};
int y[] = {0, 0, 1, -1, 1, -1, 1, -1};

int f(int i, int j, ll mask, int p){
	if(p >= s.size()) return 1;
	if(m[i][j] != s[p])
		return 0;
	if(p == s.size() - 1)
		return 1;
	int ans = 0;
	for(int l = 0; l < 8; l++){
		int i1 = i + x[l];
		int j1 = j + y[l];

		if(i1 < 0 || j1 < 0 || i1 >= 8 || j1 >= 8 || mask & (1ULL << (i1*8 + j1)))
			continue;
		ans += f(i1, j1, mask | (1ULL << (i1*8 + j1)), p+1);
	}
	return ans;
}
int main(){
	int k;
	cin >> k;
	cin >> s;
	for(int i = 0; i < 8; i++)
		cin >> m[i];
	int ans = 0;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++){
			ans += f(i, j, 0ULL | (1ULL << (i * 8 + j)), 0);
		}

	cout << ans << endl;
}