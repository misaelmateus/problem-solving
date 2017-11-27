#include<bits/stdc++.h>
using namespace std;
vector<string> word;
int dist[2][1010];
int n;

int dif(int a, int b){
	int cont = 0;
	for(int i = 0; i < word[a].size(); i++)
		if(word[a][i] != word[b][i])
			cont++;
	return cont;
}
int bfs(int p){
	dist[p][p] = 0;

	queue<int> q;
	q.push(p);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < n; i++){
			if(i == u || dist[p][i] != -1 || dif(u, i) != 1) continue;
			q.push(i);
			dist[p][i] = dist[p][u] + 1;
 		}
	}
}

string new_word(int a, int b){
	string s = word[a];
	int flag = 0;
	for(int i = 0; i < word[0].size(); i++){
		if(s[i] != word[b][i] && (flag || word[b][i] < s[i])){
			s[i] = word[b][i];
			break;
		}
		else if(s[i] != word[b][i]) flag = 1;
	}
	return s;
}
int main(){
	while(cin >> n){
		memset(dist, -1, sizeof(dist));
		word = vector<string>(n);
		for(int i = 0; i < n; i++)
			cin >> word[i];

		bfs(0);
		bfs(1);
		int ans = (1 << 30);
		string s_ans = "0";
		if(word[0] == word[1])
			ans = 0;
		if(dist[0][1] != -1)
			ans = dist[0][1];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(dif(i, j) == 2 && dist[0][i] != -1 && dist[1][j] != -1 ){
					int d = dist[0][i] + dist[1][j] + 2;
					if(d < ans || (d == ans && new_word(i, j) < s_ans))
						ans = d, s_ans = new_word(i, j);
				}
			}
		if(ans == (1 << 30)) ans = -1;
		cout << s_ans << "\n" << ans << "\n";
	}
}