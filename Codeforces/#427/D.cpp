#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;
string s, s1;
int lcs[MAXN][MAXN];
int lcs1[MAXN][MAXN];
void LCS(int a){
	for(int i = 0; i < s.size(); i++)
		for(int j = 0; j < s1.size(); j++)
			if((a == 0 && s[i] == s[j]) || (a == 1 && s[i] == s1[j])) {
				lcs[i][j] = 1 + (i > 0 && j > 0 ? lcs[i-1][j-1] : 0);
			}
			else lcs[i][j] = max( (i > 0 ? lcs[i-1][j] : 0 ), (j > 0 ? lcs[i][j-1] : 0));
}

int main(){
	cin >> s;
	LCS();
}