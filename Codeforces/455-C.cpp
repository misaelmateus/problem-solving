//   Author : Misael Mateus 
//   Submission date: 2017-03-27 20:41:36
#include<bits/stdc++.h>
#define MAXN 300010
#define ii pair<int, int>
using namespace std;
int parent[MAXN];
int Rank[MAXN];
int lenght[MAXN];
int mark[MAXN];

vector<int> gr[MAXN];
// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (parent[i] != i)
        parent[i] = find(parent[i]);
 
    return parent[i];
}
 
// A function that does union of two sets of x and y
// (uses union by Rank)
void Union(int x, int y)
{
    int xroot = find( x);
    int yroot = find( y);
 	if(xroot == yroot)
 		return;
    // Attach smaller Rank tree under root of high Rank tree
    // (Union by Rank)
    if (Rank[xroot] < Rank[yroot])
        parent[xroot] = yroot;
    else if (Rank[xroot] > Rank[yroot])
        parent[yroot] = xroot;
 
    // If Ranks are same, then make one as root and increment
    // its Rank by one
    else
    {
        parent[yroot] = xroot;
        Rank[xroot]++;
    }
}

ii furthest_distance(int v){
	queue< pair<ii, int> > q;
	q.push({{v, -1}, 0});
	int dist = 0;
	int v_max = 0;
	while(!q.empty()){
		int now = q.front().first.first;
		mark[now] = 1;

		int last = q.front().first.second;
		int d = q.front().second;
		q.pop();
		
		if(d > dist)
			dist = d, v_max = now;

		for(int i = 0; i < gr[now].size(); i++)
			if(gr[now][i] != last)
				q.push({{gr[now][i], now}, d+1}), Union(now, gr[now][i]);
	}

	return (ii){dist, v_max};
}

int calc(int a, int b){
	return a/b + (int)(a % b != 0);
}

int main(){
    for(int i = 0; i <= MAXN; i++)
        parent[i] = i;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	gr[a].push_back(b);
    	gr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
    	if(!mark[i]){
    		int t = furthest_distance(furthest_distance(i).second).first;
    		lenght[find(i)] = t;
    	}
    }

    while(q--){
    	int type, a, b;
    	scanf("%d %d", &type, &a);
    	if(type == 1){
    		printf("%d\n", lenght[find(a)]);
    	}
    	else{
    		scanf("%d", &b);
    		if(find(a) == find(b))
    			continue;
    		int pa = find(a), pb = find(b);
    		lenght[pa] = lenght[pb] = max(lenght[pa], max(lenght[pb], 1 + calc(lenght[pa], 2) + calc(lenght[pb], 2)));
    		Union(pa, pb);
    	}
    }
}
#include<bits/stdc++.h>
#define MAXN 300010
#define ii pair<int, int>
using namespace std;
int parent[MAXN];
int Rank[MAXN];
int lenght[MAXN];
int mark[MAXN];

vector<int> gr[MAXN];
// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (parent[i] != i)
        parent[i] = find(parent[i]);
 
    return parent[i];
}
 
// A function that does union of two sets of x and y
// (uses union by Rank)
void Union(int x, int y)
{
    int xroot = find( x);
    int yroot = find( y);
 	if(xroot == yroot)
 		return;
    // Attach smaller Rank tree under root of high Rank tree
    // (Union by Rank)
    if (Rank[xroot] < Rank[yroot])
        parent[xroot] = yroot;
    else if (Rank[xroot] > Rank[yroot])
        parent[yroot] = xroot;
 
    // If Ranks are same, then make one as root and increment
    // its Rank by one
    else
    {
        parent[yroot] = xroot;
        Rank[xroot]++;
    }
}

ii furthest_distance(int v){
	queue< pair<ii, int> > q;
	q.push({{v, -1}, 0});
	int dist = 0;
	int v_max = 0;
	while(!q.empty()){
		int now = q.front().first.first;
		mark[now] = 1;

		int last = q.front().first.second;
		int d = q.front().second;
		q.pop();
		
		if(d > dist)
			dist = d, v_max = now;

		for(int i = 0; i < gr[now].size(); i++)
			if(gr[now][i] != last)
				q.push({{gr[now][i], now}, d+1}), Union(now, gr[now][i]);
	}

	return (ii){dist, v_max};
}

int calc(int a, int b){
	return a/b + (int)(a % b != 0);
}

int main(){
    for(int i = 0; i <= MAXN; i++)
        parent[i] = i;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	gr[a].push_back(b);
    	gr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
    	if(!mark[i]){
    		int t = furthest_distance(furthest_distance(i).second).first;
    		lenght[find(i)] = t;
    	}
    }

    while(q--){
    	int type, a, b;
    	scanf("%d %d", &type, &a);
    	if(type == 1){
    		printf("%d\n", lenght[find(a)]);
    	}
    	else{
    		scanf("%d", &b);
    		if(find(a) == find(b))
    			continue;
    		int pa = find(a), pb = find(b);
    		lenght[pa] = lenght[pb] = max(lenght[pa], max(lenght[pb], 1 + calc(lenght[pa], 2) + calc(lenght[pb], 2)));
    		Union(pa, pb);
    	}
    }
}
#include<bits/stdc++.h>
#define MAXN 300010
#define ii pair<int, int>
using namespace std;
int parent[MAXN];
int Rank[MAXN];
int lenght[MAXN];
int mark[MAXN];

vector<int> gr[MAXN];
// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (parent[i] != i)
        parent[i] = find(parent[i]);
 
    return parent[i];
}
 
// A function that does union of two sets of x and y
// (uses union by Rank)
void Union(int x, int y)
{
    int xroot = find( x);
    int yroot = find( y);
 	if(xroot == yroot)
 		return;
    // Attach smaller Rank tree under root of high Rank tree
    // (Union by Rank)
    if (Rank[xroot] < Rank[yroot])
        parent[xroot] = yroot;
    else if (Rank[xroot] > Rank[yroot])
        parent[yroot] = xroot;
 
    // If Ranks are same, then make one as root and increment
    // its Rank by one
    else
    {
        parent[yroot] = xroot;
        Rank[xroot]++;
    }
}

ii furthest_distance(int v){
	queue< pair<ii, int> > q;
	q.push({{v, -1}, 0});
	int dist = 0;
	int v_max = 0;
	while(!q.empty()){
		int now = q.front().first.first;
		mark[now] = 1;

		int last = q.front().first.second;
		int d = q.front().second;
		q.pop();
		
		if(d > dist)
			dist = d, v_max = now;

		for(int i = 0; i < gr[now].size(); i++)
			if(gr[now][i] != last)
				q.push({{gr[now][i], now}, d+1}), Union(now, gr[now][i]);
	}

	return (ii){dist, v_max};
}

int calc(int a, int b){
	return a/b + (int)(a % b != 0);
}

int main(){
    for(int i = 0; i <= MAXN; i++)
        parent[i] = i;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	gr[a].push_back(b);
    	gr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
    	if(!mark[i]){
    		int t = furthest_distance(furthest_distance(i).second).first;
    		lenght[find(i)] = t;
    	}
    }

    while(q--){
    	int type, a, b;
    	scanf("%d %d", &type, &a);
    	if(type == 1){
    		printf("%d\n", lenght[find(a)]);
    	}
    	else{
    		scanf("%d", &b);
    		if(find(a) == find(b))
    			continue;
    		int pa = find(a), pb = find(b);
    		lenght[pa] = lenght[pb] = max(lenght[pa], max(lenght[pb], 1 + calc(lenght[pa], 2) + calc(lenght[pb], 2)));
    		Union(pa, pb);
    	}
    }
}
#include<bits/stdc++.h>
#define MAXN 300010
#define ii pair<int, int>
using namespace std;
int parent[MAXN];
int Rank[MAXN];
int lenght[MAXN];
int mark[MAXN];

vector<int> gr[MAXN];
// A utility function to find set of an element i
// (uses path compression technique)
int find(int i)
{
    // find root and make root as parent of i (path compression)
    if (parent[i] != i)
        parent[i] = find(parent[i]);
 
    return parent[i];
}
 
// A function that does union of two sets of x and y
// (uses union by Rank)
void Union(int x, int y)
{
    int xroot = find( x);
    int yroot = find( y);
 	if(xroot == yroot)
 		return;
    // Attach smaller Rank tree under root of high Rank tree
    // (Union by Rank)
    if (Rank[xroot] < Rank[yroot])
        parent[xroot] = yroot;
    else if (Rank[xroot] > Rank[yroot])
        parent[yroot] = xroot;
 
    // If Ranks are same, then make one as root and increment
    // its Rank by one
    else
    {
        parent[yroot] = xroot;
        Rank[xroot]++;
    }
}

ii furthest_distance(int v){
	queue< pair<ii, int> > q;
	q.push({{v, -1}, 0});
	int dist = 0;
	int v_max = 0;
	while(!q.empty()){
		int now = q.front().first.first;
		mark[now] = 1;

		int last = q.front().first.second;
		int d = q.front().second;
		q.pop();
		
		if(d > dist)
			dist = d, v_max = now;

		for(int i = 0; i < gr[now].size(); i++)
			if(gr[now][i] != last)
				q.push({{gr[now][i], now}, d+1}), Union(now, gr[now][i]);
	}

	return (ii){dist, v_max};
}

int calc(int a, int b){
	return a/b + (int)(a % b != 0);
}

int main(){
    for(int i = 0; i <= MAXN; i++)
        parent[i] = i;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	gr[a].push_back(b);
    	gr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
    	if(!mark[i]){
    		int t = furthest_distance(furthest_distance(i).second).first;
    		lenght[find(i)] = t;
    	}
    }

    while(q--){
    	int type, a, b;
    	scanf("%d %d", &type, &a);
    	if(type == 1){
    		printf("%d\n", lenght[find(a)]);
    	}
    	else{
    		scanf("%d", &b);
    		if(find(a) == find(b))
    			continue;
    		int pa = find(a), pb = find(b);
    		lenght[pa] = lenght[pb] = max(lenght[pa], max(lenght[pb], 1 + calc(lenght[pa], 2) + calc(lenght[pb], 2)));
    		Union(pa, pb);
    	}
    }
}
