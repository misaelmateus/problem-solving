#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define MAXN 1010

using namespace std;

struct PT { 
  int x, y; 
  int i;
} ;

int x0, y0;
vector<int> gr[MAXN];
int ans[MAXN];
int t[MAXN];

bool comp1(const PT &a, const PT &b){
	return a.x < b.x;
}
bool comp2(const PT &a, const PT &b){

	return (bool)((ll)(a.y - y0)*(ll)(b.x - x0) > (ll)(b.y - y0)*(ll)(a.x - x0));
}

int dfs1(int v, int p){
	t[v] = 1;
	for(int i = 0; i < gr[v].size(); i++){
		int u = gr[v][i];
		if(u == p) continue;

		t[v] += dfs1(u, v);
	}
	return t[v];
}
void dfs2(int v, int p, vector<PT> pt){
	
	sort(pt.begin(), pt.end(), comp1);
	
	x0 = pt[0].x;
	y0 = pt[0].y;
	ans[v] = pt[0].i;
	sort(pt.begin()+1, pt.end(), comp2);
	
	vector<PT> pt_next;
	int j = 1;
	for(int i = 0; i < gr[v].size(); i++){
		int u = gr[v][i];
		if(u == p) continue;

		pt_next.clear();
		for(int l = 0; l < t[u]; l++, j++){
			pt_next.push_back(pt[j]);
		}
		dfs2(u, v, pt_next);
	}

}

int main(){
	int n;
	cin >> n;
	vector<PT> pt(n);
	for(int i = 0; i < n-1;i++){
		int a, b;
		cin >> a >>  b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}	
	for(int i = 0; i < n; i++){
		cin >> pt[i].x >> pt[i].y;
		pt[i].i = i+1;
	}	
	dfs1(1, -1);
	dfs2(1, -1, pt);

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}