#include<bits/stdc++.h>
#define ld long double
#define ii pair<ld, ld>
using namespace std;

ld f(vector<ii> p){
	int t = p.size()/2;
	for(int i = 0; i < p.size(); i++){
		int j = (i + t) % p.size();
		vector<int> v1, v2;
		for(int l = i; l != j+1; l++){
			if(l == p.size()) l = 0;


		}
	}
}
int main(){
	int N;
	scanf("%d", &N);
	vector<ii> p(N);
	scanf("%ld", &p[i].first, &p[i].second);
	

}