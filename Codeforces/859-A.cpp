//   Author : Misael Mateus 
//   Submission date: 2017-09-16 23:17:33
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); a < (c); a++)
#define rep(a, b) fr(a, 0, b);

using namespace std;
int main(){
	int k;
	scanf("%d", &k);
	int ma = -1;
	for(int i = 0; i < k; i++){
		int aux;
		scanf("%d", &aux);
		ma = max(aux, ma);
	}

	printf("%d\n", max(0, ma-25));
}