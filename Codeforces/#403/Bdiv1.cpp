#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 1010
using namespace std;

map<string, queue<int>  > name1, name2;

int choose[MAXN];

int main(){
	ios::sync_with_stdio(false);	
	int n;
	cin >> n;

	string s1[n], s2[n];

	queue<string> q;
	rep(i, n){
		string a, b;
		cin >> a >> b;
		s1[i] = s2[i] = "";
		s1[i] += a[0]; s1[i] += a[1]; s1[i] += a[2];
		s2[i] += a[0]; s2[i] += a[1]; s2[i] += b[0];

		if(name1[s1[i]].size()) 
			q.push(s1[i]);
		name1[s1[i]].push(i);
	}

	while(!q.empty()){
		string s = q.front();
		q.pop();

		while(!name1[s].empty()){
			int i = name1[s].front();
			name1[s].pop();
			choose[i] = 1;
			if(!name2[s2[i]].empty()){
				cout << "NO\n";
				return 0;
			}

			name2[s2[i]].push(i);
			if(name1[s2[i]].size() )
				q.push(s2[i]);
		}
	}
	cout << "YES\n";
	fr(i, 0, n){
		if(choose[i]) cout << s2[i] << "\n";
		else cout << s1[i] << "\n";
	}
	return 0;
}