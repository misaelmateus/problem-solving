#include<bits/stdc++.h>
#define MAXN 111
using namespace std;

int N, M;   // N - # of vertexes on X,  M - # of vertexes on Y
vector< int > gr[MAXN];  // gr[u] -- edges from u in X to v in Y
bool seen[MAXN];        
int m[MAXN], m1[MAXN];   // with whom it's matched
 
int dfs( int u ){
    if( u < 0 ) return 1;
    if( seen[u] ) return 0;
    seen[u] = true;
    for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
        if( dfs( m1[ gr[u][i] ] ) ){
            m[u] = gr[u][i];
            m1[ gr[u][i] ] = u;
            return 1;
        }
    }
    return 0;
}
 
int dfsExp( int u ){
    for( int i = 0; i < N; i++ ) seen[i] = false;
    return dfs( u );
}
 
int bipMatch(){
    for( int i = 0; i < N; i++ ) m[i] = -1;
    for( int i = 0; i < M; i++ ) m1[i] = -1;
    int aug, ans = 0;
    do{
        aug = 0;
        bool first = true;
        for( int i = 0; i < N; i++ ) if( m[i] < 0 ){
            if( first ) aug += dfsExp( i );
            else aug += dfs( i );
            first = false;
        }
        ans += aug;
    } while( aug );
    return ans;
}

int main(){
    cin >> N;
    map<pair<string, int>, int> mapa;
    for(int i = 0; i < N; i++)
    {
        int ci;
        cin >> ci;
        ci--;
        int t;
        cin >> t;
        for(int j = 0; j < t; j++)
        {
            string atual;
            cin >> atual;
            mapa[make_pair(atual, i)] = 1;
        }
    }
    
    M = N;
    for(int i = 0; i < M; i++){
        int t;
        cin >> t;
        
        for(int l = 0; l < t; l++){
            string atual;
            cin >> atual;
            for(int j = 0; j < N; j++){
                if(mapa[make_pair(atual, j)])
                    gr[j].push_back(i); 
            }
        }
    }
    int resp = bipMatch();
    cout << resp << endl;
    
}