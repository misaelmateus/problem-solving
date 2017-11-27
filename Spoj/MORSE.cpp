#include<bits/stdc++.h>
#define MAXN 10100
using namespace std;
int dp[MAXN];
string alphabet[] = {".-", "-...", "-.-.", "-..", 
					 ".", "..-.", "--.",  "....",
					 "..", ".---", "-.-", ".-..",
					 "--", "-.", "---", ".--.",
					 "--.-", ".-.", "...", "-", 
					 "..-",  "...-", ".--", "-..-",
					 "-.--", "--.."};

string code(string s){
	string s1 = "";
	for(int i = 0; i < s.size(); i++)
		s1 += alphabet[s[i] - 'A'];
	return s1;
}
int main(){
	ios::sync_with_stdio(false);
	int tests;
	cin >> tests;
	while(tests--){
		memset(dp, 0, sizeof(dp));
		string s;
		int n;
		map<string, int> count;
		cin >> s >> n;
		for(int i = 0; i < n; i++){
			string s1;
			cin >> s1;
			s1 = code(s1);
			count[s1]++;
		}
		dp[s.size()] = 1;
		for(int i = s.size()-1; i >= 0; i--){
			string s1 = "";
			for(int j = 0; j + i < s.size() && j <= 82; j++){
				s1 += s[i+j];
				if(count[s1])
					dp[i] += count[s1] * dp[i+j+1];
			}
		}


		cout << dp[0] << endl;
	}
}