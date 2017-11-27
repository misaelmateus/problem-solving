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
using namespace std;



vector<int> var;

vector< pair<int, pair<string, string> > > op;

unordered_map<string, int> mapa;
int main(){
	ios::sync_with_stdio(false);	
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	
	var = vector<int> (n+1, 0);
	string name, aux, a, b, c;
	for(int i = 0; i < n; i++){
		cin >> name >> aux >> a;
		mapa[name] = i+1;
		if(a[0] > '9' || a[0] < '0'){
			cin >> b >> c;
			int type = 1;
			if(b[0] == 'A') type = 2;
			if(b[0] == 'X') type = 3;
			op.push_back({type, {a, c}});
		}
		else op.push_back({0, {a, ""}});
	}
	string ans1 = "", ans2 = "";
	for(int i = 0; i < m; i++){
		int ans_now1 = 1e9, ans_now2 = -1;
		char c_ans1, c_ans2;
		for(int l = 0; l <= 1; l++){
			var[0] = l;
			int k = 1;
			for(auto &u : op){
				if(u.first == 0) var[k++] = (int)(u.second.first[i] - '0');
				else if(u.first == 1){
					var[k++] = (int)(var[mapa[u.second.first]] | var[mapa[u.second.second]]) ;
				}
				else if(u.first == 2)
					var[k++] = (int)(var[mapa[u.second.first]] & var[mapa[u.second.second]]);
				else {
					var[k++] = (int)(var[mapa[u.second.first]] ^ var[mapa[u.second.second]]);
				}
			}
			int cont = 0;
			for(auto &u : var){
				cont += u;
			}
			cont -= l;
			if(cont < ans_now1)
				ans_now1 = cont, c_ans1 = '0' + l;
			if(cont > ans_now2)
				ans_now2 = cont, c_ans2 = '0' + l;
		}
		ans1 += c_ans1, ans2 += c_ans2;
	}

	cout << ans1 << "\n" << ans2 << "\n";
}