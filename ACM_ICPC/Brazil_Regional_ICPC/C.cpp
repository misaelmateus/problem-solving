#include<bits/stdc++.h>
#define P 1000000007
using namespace std;
map<int, int> mapa;

int C[2000][2000];
int main(){
	std::ios_base::sync_with_stdio(0);
	pot2[0] = 1;
	for(int i = 1; i < 2000; i++) pot2[i] = (pot2[i-1]*2)%P;
	int N;
	cin >> N;
	int a[N];
	for(int i = 0; i < N; i++) cin >> a[i];

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			mapa[(a[i]+a[j])]++;
		}

	int ans = 0;

	for(auto it: mapa){
		ans = (ans +  pot2[it.second/2] - 1) % P;
	}

	cout << ans << "\n";

}