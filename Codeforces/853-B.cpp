//   Author : Misael Mateus 
//   Submission date: 2017-09-07 00:06:56
#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define MAXV 1000100
using namespace std;
ll ans[MAXV];
ll ans1[MAXV];
int mark[MAXV/10];
vector<pair<ii, int> > fl[MAXV];
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int di, fi, ti, ci;
		scanf("%d %d %d %d", &di, &fi, &ti, &ci);
		fl[di].push_back({{fi, ti}, ci});
	}
	int cont = 0;
	ll temp = 0LL;
	for(int i = 0; i < MAXV; i++){
		ans[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.first == 0) continue;
			if(!mark[fl[i][j].first.first]) 
				mark[fl[i][j].first.first] = fl[i][j].second, temp += fl[i][j].second, cont++;
			
			else if(mark[fl[i][j].first.first] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.first];
				mark[fl[i][j].first.first] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans[i] = temp;
	}
	
	cont = 0;
	temp = 0LL;
	memset(mark, 0, sizeof(mark));
	for(int i = MAXV-1; i >= 0; i--){
		ans1[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.second == 0) continue;
			if(!mark[fl[i][j].first.second]) 
				mark[fl[i][j].first.second] = fl[i][j].second, temp += fl[i][j].second, cont++;
			else if(mark[fl[i][j].first.second] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.second];
				mark[fl[i][j].first.second] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans1[i] = temp;
	}

	ll val = (1LL << 60);
	for(int i = 1; i+k+1 < MAXV; i++){
		val = min(val, ans[i] + ans1[i+k+1]);
	}

	if(val == (1LL << 60))
		val = -1;
	printf("%lld\n", val);
}#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define MAXV 1000100
using namespace std;
ll ans[MAXV];
ll ans1[MAXV];
int mark[MAXV/10];
vector<pair<ii, int> > fl[MAXV];
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int di, fi, ti, ci;
		scanf("%d %d %d %d", &di, &fi, &ti, &ci);
		fl[di].push_back({{fi, ti}, ci});
	}
	int cont = 0;
	ll temp = 0LL;
	for(int i = 0; i < MAXV; i++){
		ans[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.first == 0) continue;
			if(!mark[fl[i][j].first.first]) 
				mark[fl[i][j].first.first] = fl[i][j].second, temp += fl[i][j].second, cont++;
			
			else if(mark[fl[i][j].first.first] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.first];
				mark[fl[i][j].first.first] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans[i] = temp;
	}
	
	cont = 0;
	temp = 0LL;
	memset(mark, 0, sizeof(mark));
	for(int i = MAXV-1; i >= 0; i--){
		ans1[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.second == 0) continue;
			if(!mark[fl[i][j].first.second]) 
				mark[fl[i][j].first.second] = fl[i][j].second, temp += fl[i][j].second, cont++;
			else if(mark[fl[i][j].first.second] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.second];
				mark[fl[i][j].first.second] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans1[i] = temp;
	}

	ll val = (1LL << 60);
	for(int i = 1; i+k+1 < MAXV; i++){
		val = min(val, ans[i] + ans1[i+k+1]);
	}

	if(val == (1LL << 60))
		val = -1;
	printf("%lld\n", val);
}#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define MAXV 1000100
using namespace std;
ll ans[MAXV];
ll ans1[MAXV];
int mark[MAXV/10];
vector<pair<ii, int> > fl[MAXV];
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int di, fi, ti, ci;
		scanf("%d %d %d %d", &di, &fi, &ti, &ci);
		fl[di].push_back({{fi, ti}, ci});
	}
	int cont = 0;
	ll temp = 0LL;
	for(int i = 0; i < MAXV; i++){
		ans[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.first == 0) continue;
			if(!mark[fl[i][j].first.first]) 
				mark[fl[i][j].first.first] = fl[i][j].second, temp += fl[i][j].second, cont++;
			
			else if(mark[fl[i][j].first.first] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.first];
				mark[fl[i][j].first.first] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans[i] = temp;
	}
	
	cont = 0;
	temp = 0LL;
	memset(mark, 0, sizeof(mark));
	for(int i = MAXV-1; i >= 0; i--){
		ans1[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.second == 0) continue;
			if(!mark[fl[i][j].first.second]) 
				mark[fl[i][j].first.second] = fl[i][j].second, temp += fl[i][j].second, cont++;
			else if(mark[fl[i][j].first.second] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.second];
				mark[fl[i][j].first.second] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans1[i] = temp;
	}

	ll val = (1LL << 60);
	for(int i = 1; i+k+1 < MAXV; i++){
		val = min(val, ans[i] + ans1[i+k+1]);
	}

	if(val == (1LL << 60))
		val = -1;
	printf("%lld\n", val);
}#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll long long
#define MAXV 1000100
using namespace std;
ll ans[MAXV];
ll ans1[MAXV];
int mark[MAXV/10];
vector<pair<ii, int> > fl[MAXV];
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < m; i++){
		int di, fi, ti, ci;
		scanf("%d %d %d %d", &di, &fi, &ti, &ci);
		fl[di].push_back({{fi, ti}, ci});
	}
	int cont = 0;
	ll temp = 0LL;
	for(int i = 0; i < MAXV; i++){
		ans[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.first == 0) continue;
			if(!mark[fl[i][j].first.first]) 
				mark[fl[i][j].first.first] = fl[i][j].second, temp += fl[i][j].second, cont++;
			
			else if(mark[fl[i][j].first.first] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.first];
				mark[fl[i][j].first.first] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans[i] = temp;
	}
	
	cont = 0;
	temp = 0LL;
	memset(mark, 0, sizeof(mark));
	for(int i = MAXV-1; i >= 0; i--){
		ans1[i] = (1LL << 60);
		for(int j = 0; j < fl[i].size(); j++){
			if(fl[i][j].first.second == 0) continue;
			if(!mark[fl[i][j].first.second]) 
				mark[fl[i][j].first.second] = fl[i][j].second, temp += fl[i][j].second, cont++;
			else if(mark[fl[i][j].first.second] > fl[i][j].second){
				temp += fl[i][j].second - mark[fl[i][j].first.second];
				mark[fl[i][j].first.second] = fl[i][j].second;
			}
		}
		if(cont == n) 
			ans1[i] = temp;
	}

	ll val = (1LL << 60);
	for(int i = 1; i+k+1 < MAXV; i++){
		val = min(val, ans[i] + ans1[i+k+1]);
	}

	if(val == (1LL << 60))
		val = -1;
	printf("%lld\n", val);
}