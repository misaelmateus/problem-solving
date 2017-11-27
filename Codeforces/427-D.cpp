//   Author : Misael Mateus 
//   Submission date: 2017-03-15 16:37:54
#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;

int lcp[MAXN][MAXN], lcp1[MAXN][MAXN], lcp2[MAXN][MAXN];
int mark1[MAXN], mark2[MAXN];

void calc_lcp(string &s1, string &s2, int m[][MAXN]){
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(s1[i] == s2[j])
				m[i][j] = 1 + m[i+1][j+1];
}
int main(){
	ios::sync_with_stdio( false );
	
	string s1, s2;
	cin >> s1 >> s2;

	calc_lcp(s1, s2, lcp);
	calc_lcp(s1, s1, lcp1);
	calc_lcp(s2, s2, lcp2);

	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s1.size() - 1; j >= 0; j--)
			if(i != j) mark1[i] = max(mark1[i], lcp1[i][j]);

	for(int i = s2.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(i != j) mark2[i] = max(mark2[i], lcp2[i][j]);

		
	int ans = s1.size() + s2.size();
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(lcp[i][j] > mark1[i] && lcp[i][j] > mark2[j])
				ans = min(ans, 1 + max(mark1[i], mark2[j]));


	if(ans == s1.size() + s2.size())
		ans = -1;

	cout << ans << endl;
}#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;

int lcp[MAXN][MAXN], lcp1[MAXN][MAXN], lcp2[MAXN][MAXN];
int mark1[MAXN], mark2[MAXN];

void calc_lcp(string &s1, string &s2, int m[][MAXN]){
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(s1[i] == s2[j])
				m[i][j] = 1 + m[i+1][j+1];
}
int main(){
	ios::sync_with_stdio( false );
	
	string s1, s2;
	cin >> s1 >> s2;

	calc_lcp(s1, s2, lcp);
	calc_lcp(s1, s1, lcp1);
	calc_lcp(s2, s2, lcp2);

	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s1.size() - 1; j >= 0; j--)
			if(i != j) mark1[i] = max(mark1[i], lcp1[i][j]);

	for(int i = s2.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(i != j) mark2[i] = max(mark2[i], lcp2[i][j]);

		
	int ans = s1.size() + s2.size();
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(lcp[i][j] > mark1[i] && lcp[i][j] > mark2[j])
				ans = min(ans, 1 + max(mark1[i], mark2[j]));


	if(ans == s1.size() + s2.size())
		ans = -1;

	cout << ans << endl;
}#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;

int lcp[MAXN][MAXN], lcp1[MAXN][MAXN], lcp2[MAXN][MAXN];
int mark1[MAXN], mark2[MAXN];

void calc_lcp(string &s1, string &s2, int m[][MAXN]){
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(s1[i] == s2[j])
				m[i][j] = 1 + m[i+1][j+1];
}
int main(){
	ios::sync_with_stdio( false );
	
	string s1, s2;
	cin >> s1 >> s2;

	calc_lcp(s1, s2, lcp);
	calc_lcp(s1, s1, lcp1);
	calc_lcp(s2, s2, lcp2);

	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s1.size() - 1; j >= 0; j--)
			if(i != j) mark1[i] = max(mark1[i], lcp1[i][j]);

	for(int i = s2.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(i != j) mark2[i] = max(mark2[i], lcp2[i][j]);

		
	int ans = s1.size() + s2.size();
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(lcp[i][j] > mark1[i] && lcp[i][j] > mark2[j])
				ans = min(ans, 1 + max(mark1[i], mark2[j]));


	if(ans == s1.size() + s2.size())
		ans = -1;

	cout << ans << endl;
}#include<bits/stdc++.h>
#define MAXN 5010
using namespace std;

int lcp[MAXN][MAXN], lcp1[MAXN][MAXN], lcp2[MAXN][MAXN];
int mark1[MAXN], mark2[MAXN];

void calc_lcp(string &s1, string &s2, int m[][MAXN]){
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(s1[i] == s2[j])
				m[i][j] = 1 + m[i+1][j+1];
}
int main(){
	ios::sync_with_stdio( false );
	
	string s1, s2;
	cin >> s1 >> s2;

	calc_lcp(s1, s2, lcp);
	calc_lcp(s1, s1, lcp1);
	calc_lcp(s2, s2, lcp2);

	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s1.size() - 1; j >= 0; j--)
			if(i != j) mark1[i] = max(mark1[i], lcp1[i][j]);

	for(int i = s2.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(i != j) mark2[i] = max(mark2[i], lcp2[i][j]);

		
	int ans = s1.size() + s2.size();
	for(int i = s1.size() - 1; i >= 0; i--)
		for(int j = s2.size() - 1; j >= 0; j--)
			if(lcp[i][j] > mark1[i] && lcp[i][j] > mark2[j])
				ans = min(ans, 1 + max(mark1[i], mark2[j]));


	if(ans == s1.size() + s2.size())
		ans = -1;

	cout << ans << endl;
}