//   Author : Misael Mateus 
//   Submission date: 2017-04-16 22:32:53
#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
char best[MAXN];
int main()
{
	std::ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	best[s.size()-1] = s[s.size() - 1];

	for(int i = s.size()-2; i >= 0; i--)
		best[i] = (char)min((int)(s[i]), (int)(best[i+1]));
	best[s.size()] = (char)('z' + 1);
	string ans = "";
	stack<char> p;
	int i = 1;
	p.push(s[0]);
	while(!p.empty() || i < s.size()){
		if(!p.empty() && p.top() <= best[i])
			ans += p.top(), p.pop();
		else
			p.push(s[i]), i++;

	}

	cout << ans << "\n";
}