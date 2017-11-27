//   Author : Misael Mateus 
//   Submission date: 2017-02-23 20:36:54
#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
int N, M;
 
int low[MAXN], lbl[MAXN], dfsnum;
vector<int> gr[MAXN];
bool stkd[MAXN];
stack< int > scc;
int flag;

void dfs( int u ){
    lbl[u] = low[u] = dfsnum++;
    scc.push( u );
    stkd[u] = true;
    int v;
    for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
        v = gr[u][i];
        if( lbl[v] == -1 ) dfs( v );
        if( stkd[v] ) low[u] = min( low[u], low[v] );
    }
    if( low[u] == lbl[u] ){  // new component found..
    	set<int> conj;
        while( !scc.empty() && scc.top() != u ){
        	
        	if(conj.count(scc.top() + M) || conj.count(scc.top() - M))
        	{
        		if(!flag)
        			cout << "NO" << endl;
        		flag = 1;
        	}
            conj.insert(scc.top());
            stkd[ scc.top() ] = false;
            scc.pop(); 
        }
        
        if(conj.count(scc.top() + M) || conj.count(scc.top() - M))
    	{
    		if(!flag)
    			cout << "NO" << endl;
    		flag = 1;
    	}
        scc.pop(); stkd[u] = false;
    }
}

int tarjan(){
	dfsnum = 1;
	memset(lbl, -1, sizeof(lbl));
	memset(low, -1, sizeof(low));

	for(int i = 0; i < 2*M; i++)
		if(lbl[i] == -1)
			dfs(i);
}
int main(){
	//
	
	cin >> N >> M;
	int r[N];
	vector<int> R[N];
	
	for(int i = 0; i < N; i++)
		cin >> r[i];


	for(int i = 0; i < M; i++){
		int num;
		cin >> num;
		while(num--){
			int room;
			cin >> room;
			R[room-1].push_back(i);
		}
	}

	for(int i = 0; i < N; i++){
		int a = R[i][0], b = R[i][1];
		int na = R[i][0] + M, nb = R[i][1] + M;
		if(!r[i]){

			gr[a].push_back(nb);
			gr[nb].push_back(a);
			gr[b].push_back(na);
			gr[na].push_back(b);
		}
		else{
			gr[a].push_back(b);
			gr[b].push_back(a);
			gr[nb].push_back(na);
			gr[na].push_back(nb);
		}
	}

	tarjan();
	if(!flag)
		cout << "YES" << endl;
	return 0;
}