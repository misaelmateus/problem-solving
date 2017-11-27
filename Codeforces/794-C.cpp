//   Author : Misael Mateus 
//   Submission date: 2017-11-06 14:49:27
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;




int main(){
	readFast;
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	reverse(s2.begin(), s2.end());
	int n = s1.size();
	int i2 = 0, j2 = n/2 - 1;
	int i1 = 0, j1 = n - j2 - 2;
	string ans = "";
	for(int i = 0; i < n; i++) ans += " ";

	int player = 0;
	int l = 0, r = n-1;
	for(int i = 0; i < n; i++){
		if(!player){
			if(s2[i2] <= s1[i1]){
				ans[r--] = s1[j1--];
			}
			else ans[l++] = s1[i1++];
		}
		else{	
			if(s1[i1] >= s2[i2]){
				ans[r--] = s2[j2--];
			}
			else ans[l++] = s2[i2++];
		}
		player ^= 1;
	}
	cout << ans << "\n";
	cout << "\n";
}