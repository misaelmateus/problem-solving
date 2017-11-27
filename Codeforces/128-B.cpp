//   Author : Misael Mateus 
//   Submission date: 2017-02-23 23:08:18
#include<bits/stdc++.h>
#define INF 1000000000
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio( false );

	string s;
	ll k;
	cin >> s >> k;
	int t = s.size();
	string r = "";

	stack<int> p;
	for(int i = 0; i < t; i++)
		p.push(i);

	ll letter[27];
	vector<int> v[27];
	while(k > 0 && !p.empty()){
		memset(letter, 0, sizeof(letter));

		while(!p.empty()){
			int now = p.top();
			p.pop();
			if(now >= t)
				continue;
			letter[s[now] - 'a'] += (t - now);
			v[s[now] - 'a'].push_back(now);
		}

		ll tot = 0;
		int i;
		for(i = 0; i < 27; i++){
			tot += letter[i];
			if(tot >= k){
				tot -= letter[i];
				break;
			}
		}
		if(i == 27){
			cout << "No such line." << endl;
			return 0;
		}
		r += (char)('a' + i);
		for(int j = 0; j < v[i].size(); j++)
			p.push(v[i][j] + 1);

		k -= tot + p.size();


		for(int j = 0; j < 27; j++)
			v[j].clear();
	}

	cout << r << endl;
	return 0;
}#include<bits/stdc++.h>
#define INF 1000000000
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio( false );

	string s;
	ll k;
	cin >> s >> k;
	int t = s.size();
	string r = "";

	stack<int> p;
	for(int i = 0; i < t; i++)
		p.push(i);

	ll letter[27];
	vector<int> v[27];
	while(k > 0 && !p.empty()){
		memset(letter, 0, sizeof(letter));

		while(!p.empty()){
			int now = p.top();
			p.pop();
			if(now >= t)
				continue;
			letter[s[now] - 'a'] += (t - now);
			v[s[now] - 'a'].push_back(now);
		}

		ll tot = 0;
		int i;
		for(i = 0; i < 27; i++){
			tot += letter[i];
			if(tot >= k){
				tot -= letter[i];
				break;
			}
		}
		if(i == 27){
			cout << "No such line." << endl;
			return 0;
		}
		r += (char)('a' + i);
		for(int j = 0; j < v[i].size(); j++)
			p.push(v[i][j] + 1);

		k -= tot + p.size();


		for(int j = 0; j < 27; j++)
			v[j].clear();
	}

	cout << r << endl;
	return 0;
}#include<bits/stdc++.h>
#define INF 1000000000
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio( false );

	string s;
	ll k;
	cin >> s >> k;
	int t = s.size();
	string r = "";

	stack<int> p;
	for(int i = 0; i < t; i++)
		p.push(i);

	ll letter[27];
	vector<int> v[27];
	while(k > 0 && !p.empty()){
		memset(letter, 0, sizeof(letter));

		while(!p.empty()){
			int now = p.top();
			p.pop();
			if(now >= t)
				continue;
			letter[s[now] - 'a'] += (t - now);
			v[s[now] - 'a'].push_back(now);
		}

		ll tot = 0;
		int i;
		for(i = 0; i < 27; i++){
			tot += letter[i];
			if(tot >= k){
				tot -= letter[i];
				break;
			}
		}
		if(i == 27){
			cout << "No such line." << endl;
			return 0;
		}
		r += (char)('a' + i);
		for(int j = 0; j < v[i].size(); j++)
			p.push(v[i][j] + 1);

		k -= tot + p.size();


		for(int j = 0; j < 27; j++)
			v[j].clear();
	}

	cout << r << endl;
	return 0;
}#include<bits/stdc++.h>
#define INF 1000000000
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio( false );

	string s;
	ll k;
	cin >> s >> k;
	int t = s.size();
	string r = "";

	stack<int> p;
	for(int i = 0; i < t; i++)
		p.push(i);

	ll letter[27];
	vector<int> v[27];
	while(k > 0 && !p.empty()){
		memset(letter, 0, sizeof(letter));

		while(!p.empty()){
			int now = p.top();
			p.pop();
			if(now >= t)
				continue;
			letter[s[now] - 'a'] += (t - now);
			v[s[now] - 'a'].push_back(now);
		}

		ll tot = 0;
		int i;
		for(i = 0; i < 27; i++){
			tot += letter[i];
			if(tot >= k){
				tot -= letter[i];
				break;
			}
		}
		if(i == 27){
			cout << "No such line." << endl;
			return 0;
		}
		r += (char)('a' + i);
		for(int j = 0; j < v[i].size(); j++)
			p.push(v[i][j] + 1);

		k -= tot + p.size();


		for(int j = 0; j < 27; j++)
			v[j].clear();
	}

	cout << r << endl;
	return 0;
}