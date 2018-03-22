#include<bits/stdc++.h>
#define P 4847464544434241LL
#define ll long long
#define REP(i, N) for(int i = 0; i < N; i++)
using namespace std;
#define MAXN 200100
string S;
int STEP, N, SA[MAXN], RA[MAXN], LCP[3*MAXN], *CUR, *OLD;
  
bool comp( int a, int b ){
    if( OLD[a] != OLD[b] ) return OLD[a] < OLD[b];
    if( a+STEP < N && b+STEP < N ) return OLD[a+STEP] < OLD[b+STEP];
    return a > b;
}
 
bool up(){
    int cnt = 0;
    REP( i, N ){
        if( i && comp( SA[i-1], SA[i] ) ) cnt++;
        CUR[ SA[i] ] = cnt;
    }
    if( cnt == N-1 ) return false;
    return true;
}

void buildSA(){
    REP( i, N ) RA[ i ] = S[ SA[i] = i ];
    STEP = 0; OLD = RA, CUR = LCP;
    sort( SA, SA+N, comp );
    if( up() ){
        swap( OLD, CUR );
        for( STEP = 1; STEP < N; STEP *= 2 ){
            sort( SA, SA+N, comp );
            if( !up() ) return;
            swap( OLD, CUR );
        }
    }
}
void buildLCP(){
    REP( i, N ) RA[ SA[i] ] = i;
    LCP[0] = 0;
    for( int i = 0, h = 0; i < N; i++ ){
        if( RA[i] > 0 ){
            int j = SA[ RA[i]-1 ];
            while( ((i + h) < N) && ((j + h) < N) && (S[i+h] == S[j+h]) ) h++;
            LCP[ RA[i] ] = h;
            if( h > 0 ) h--;
        }
    }   
}

int tot[MAXN];
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		memset(LCP, 0, sizeof(LCP));
		string w;
		cin >> w >> S;
		vector<int> countW(26, 0);
		vector<int> countS(26, 0);
		for(auto u : w)
			countW[u - 'a']++;
        for(int i = 0; i < w.size(); i++)
			countS[S[i] - 'a']++;
            
		int ans = 0;
		ll hash = 0;
		ll aux = 1;
		
		N = S.size();
		buildSA();
		buildLCP();
        
        
		set<int> set_i;
		int cont = 1;
        tot[SA[0]] = 1;
		for(int i = 1; i < S.size(); i++){
            //cout << LCP[i] << " " << SA[i] << endl;
            if(LCP[i] >= w.size())
				cont++;
			else cont = 1;
			tot[SA[i]] = cont;
            //cout << SA[i] << " = " << tot[SA[i]] << endl;
		}
		for(int i = 0; i + w.size() <= S.size(); i++){
			if(countW == countS){
				int t = tot[i];
				if(t > ans){
					ans = t;
					set_i.clear();
					set_i.insert(i);
				}
				else if(t == ans) set_i.insert(i);
			}
			if(i + w.size() == S.size()) continue;
			countS[S[i] - 'a']--;
			countS[S[i+w.size()] - 'a']++;
		}
		
		for(int i = 0; i < N; i++)
			if(set_i.count(SA[i])){
				for(int j = 0; j < w.size(); j++)
					cout << S[SA[i]+j];
				cout << "\n";
				break;
			}
		if(ans == 0)
			cout << -1 << "\n";
	}
}