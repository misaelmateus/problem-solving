//   Author : Misael Mateus 
//   Submission date: 2017-03-28 21:35:58
#include<bits/stdc++.h>
#define MAXN 200010
#define ll int
using namespace std;

int p[MAXN], pos[MAXN], tree[MAXN][2], val[MAXN], ult[MAXN], f[MAXN];
vector<int> gr[MAXN];

void update( ll id, ll x, ll j ) //update tree in position id with x
{
    while( id <= MAXN )
    {
        tree[id][j] += x;
        id += (id & (-id) ) ;
    }
}
ll sum(ll idx, ll j) //return the sum from 0 to idx
{
    ll ans = (ll)0;
    while( idx )
    {
        ans += tree[idx][j];
        idx -= (idx & (-idx));
    }
    return ans;
}


int cont[] = {1, 1};
int dfs(int a, int j){
	pos[a] = cont[j]++;
	f[a] = j;
	for(int i = 0; i < gr[a].size(); i++){
		int next = gr[a][i];
		if(next != p[a])
			p[next] = a, dfs(next, 1 - j);
	}
	ult[a] = cont[j];
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

	for(int i = 0; i < n-1; i++){
		int ui, vi;
		scanf("%d %d", &ui, &vi );

		gr[ui].push_back(vi);
		gr[vi].push_back(ui);
	}
	
	p[1] = -1;
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		update(pos[i], val[i], f[i]);
		update(pos[i]+1, -val[i], f[i]);
	}	

	int type, x, k;
	while(m--){
		scanf("%d", &type);

		if(type == 2){
			scanf("%d", &x);
			printf("%d\n", sum(pos[x], f[x]));
		}
		else{
			scanf("%d %d", &x, &k);
			update(pos[x], k, f[x]);
			update(ult[x], -k, f[x]);
			int a, b;
			if(gr[x].size() <= 1 && !(gr[x].size() && p[x] == -1))
				continue;
			int A = gr[x][0];
			if(gr[x][0] == p[x])
				A = gr[x][1];
			int B = gr[x][gr[x].size()-1];
			if( B == p[x])
				B = gr[x][gr[x].size()-2];
			a = pos[A], b = ult[B];
			update(a, -k, 1 - f[x]);
			update(b, k, 1 - f[x]);
		}
	}
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ll int
using namespace std;

int p[MAXN], pos[MAXN], tree[MAXN][2], val[MAXN], ult[MAXN], f[MAXN];
vector<int> gr[MAXN];

void update( ll id, ll x, ll j ) //update tree in position id with x
{
    while( id <= MAXN )
    {
        tree[id][j] += x;
        id += (id & (-id) ) ;
    }
}
ll sum(ll idx, ll j) //return the sum from 0 to idx
{
    ll ans = (ll)0;
    while( idx )
    {
        ans += tree[idx][j];
        idx -= (idx & (-idx));
    }
    return ans;
}


int cont[] = {1, 1};
int dfs(int a, int j){
	pos[a] = cont[j]++;
	f[a] = j;
	for(int i = 0; i < gr[a].size(); i++){
		int next = gr[a][i];
		if(next != p[a])
			p[next] = a, dfs(next, 1 - j);
	}
	ult[a] = cont[j];
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

	for(int i = 0; i < n-1; i++){
		int ui, vi;
		scanf("%d %d", &ui, &vi );

		gr[ui].push_back(vi);
		gr[vi].push_back(ui);
	}
	
	p[1] = -1;
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		update(pos[i], val[i], f[i]);
		update(pos[i]+1, -val[i], f[i]);
	}	

	int type, x, k;
	while(m--){
		scanf("%d", &type);

		if(type == 2){
			scanf("%d", &x);
			printf("%d\n", sum(pos[x], f[x]));
		}
		else{
			scanf("%d %d", &x, &k);
			update(pos[x], k, f[x]);
			update(ult[x], -k, f[x]);
			int a, b;
			if(gr[x].size() <= 1 && !(gr[x].size() && p[x] == -1))
				continue;
			int A = gr[x][0];
			if(gr[x][0] == p[x])
				A = gr[x][1];
			int B = gr[x][gr[x].size()-1];
			if( B == p[x])
				B = gr[x][gr[x].size()-2];
			a = pos[A], b = ult[B];
			update(a, -k, 1 - f[x]);
			update(b, k, 1 - f[x]);
		}
	}
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ll int
using namespace std;

int p[MAXN], pos[MAXN], tree[MAXN][2], val[MAXN], ult[MAXN], f[MAXN];
vector<int> gr[MAXN];

void update( ll id, ll x, ll j ) //update tree in position id with x
{
    while( id <= MAXN )
    {
        tree[id][j] += x;
        id += (id & (-id) ) ;
    }
}
ll sum(ll idx, ll j) //return the sum from 0 to idx
{
    ll ans = (ll)0;
    while( idx )
    {
        ans += tree[idx][j];
        idx -= (idx & (-idx));
    }
    return ans;
}


int cont[] = {1, 1};
int dfs(int a, int j){
	pos[a] = cont[j]++;
	f[a] = j;
	for(int i = 0; i < gr[a].size(); i++){
		int next = gr[a][i];
		if(next != p[a])
			p[next] = a, dfs(next, 1 - j);
	}
	ult[a] = cont[j];
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

	for(int i = 0; i < n-1; i++){
		int ui, vi;
		scanf("%d %d", &ui, &vi );

		gr[ui].push_back(vi);
		gr[vi].push_back(ui);
	}
	
	p[1] = -1;
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		update(pos[i], val[i], f[i]);
		update(pos[i]+1, -val[i], f[i]);
	}	

	int type, x, k;
	while(m--){
		scanf("%d", &type);

		if(type == 2){
			scanf("%d", &x);
			printf("%d\n", sum(pos[x], f[x]));
		}
		else{
			scanf("%d %d", &x, &k);
			update(pos[x], k, f[x]);
			update(ult[x], -k, f[x]);
			int a, b;
			if(gr[x].size() <= 1 && !(gr[x].size() && p[x] == -1))
				continue;
			int A = gr[x][0];
			if(gr[x][0] == p[x])
				A = gr[x][1];
			int B = gr[x][gr[x].size()-1];
			if( B == p[x])
				B = gr[x][gr[x].size()-2];
			a = pos[A], b = ult[B];
			update(a, -k, 1 - f[x]);
			update(b, k, 1 - f[x]);
		}
	}
	return 0;
}#include<bits/stdc++.h>
#define MAXN 200010
#define ll int
using namespace std;

int p[MAXN], pos[MAXN], tree[MAXN][2], val[MAXN], ult[MAXN], f[MAXN];
vector<int> gr[MAXN];

void update( ll id, ll x, ll j ) //update tree in position id with x
{
    while( id <= MAXN )
    {
        tree[id][j] += x;
        id += (id & (-id) ) ;
    }
}
ll sum(ll idx, ll j) //return the sum from 0 to idx
{
    ll ans = (ll)0;
    while( idx )
    {
        ans += tree[idx][j];
        idx -= (idx & (-idx));
    }
    return ans;
}


int cont[] = {1, 1};
int dfs(int a, int j){
	pos[a] = cont[j]++;
	f[a] = j;
	for(int i = 0; i < gr[a].size(); i++){
		int next = gr[a][i];
		if(next != p[a])
			p[next] = a, dfs(next, 1 - j);
	}
	ult[a] = cont[j];
}


int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; i++)
		scanf("%d", &val[i]);

	for(int i = 0; i < n-1; i++){
		int ui, vi;
		scanf("%d %d", &ui, &vi );

		gr[ui].push_back(vi);
		gr[vi].push_back(ui);
	}
	
	p[1] = -1;
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		update(pos[i], val[i], f[i]);
		update(pos[i]+1, -val[i], f[i]);
	}	

	int type, x, k;
	while(m--){
		scanf("%d", &type);

		if(type == 2){
			scanf("%d", &x);
			printf("%d\n", sum(pos[x], f[x]));
		}
		else{
			scanf("%d %d", &x, &k);
			update(pos[x], k, f[x]);
			update(ult[x], -k, f[x]);
			int a, b;
			if(gr[x].size() <= 1 && !(gr[x].size() && p[x] == -1))
				continue;
			int A = gr[x][0];
			if(gr[x][0] == p[x])
				A = gr[x][1];
			int B = gr[x][gr[x].size()-1];
			if( B == p[x])
				B = gr[x][gr[x].size()-2];
			a = pos[A], b = ult[B];
			update(a, -k, 1 - f[x]);
			update(b, k, 1 - f[x]);
		}
	}
	return 0;
}