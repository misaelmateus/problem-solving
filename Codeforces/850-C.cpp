//   Author : Misael Mateus 
//   Submission date: 2017-09-05 16:40:51
#include<bits/stdc++.h>
using namespace std;
int ans = 0;
map<int, int> mapa;
unordered_map<int, int> g;

void fat(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			int cont = 0;
			while(n % i == 0) n /= i, cont++;
			mapa[i] |= (1 << (cont-1));
		}
	}
	if(n > 1){
		mapa[n] |= 1;
	}
}

int grundy(int mask){
	if(g[mask]) return g[mask];
	if(!mask) return 1;
	int mex = 0;
	int j;
	for(j = 31; j >= 0 && !(mask & (1 << j)); j--);
	for(int i = 0; i <= j; i++){
			mex |= 1 << (grundy(mask >> (i+1) | (mask & ((1 << (i)) - 1))) - 1);
	}
	for(int i = 0; i < 31; i++)
		if(!(mex & (1 << i)))
			return g[mask] = i+1;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		fat(x);
	}
	int ans = 0;
	for(auto it = mapa.begin(); it != mapa.end(); it++){
		ans ^= grundy(it->second)-1;
	}
	if(ans)
		printf("Mojtaba\n");
	else printf("Arpa\n");

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int ans = 0;
map<int, int> mapa;
unordered_map<int, int> g;

void fat(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			int cont = 0;
			while(n % i == 0) n /= i, cont++;
			mapa[i] |= (1 << (cont-1));
		}
	}
	if(n > 1){
		mapa[n] |= 1;
	}
}

int grundy(int mask){
	if(g[mask]) return g[mask];
	if(!mask) return 1;
	int mex = 0;
	int j;
	for(j = 31; j >= 0 && !(mask & (1 << j)); j--);
	for(int i = 0; i <= j; i++){
			mex |= 1 << (grundy(mask >> (i+1) | (mask & ((1 << (i)) - 1))) - 1);
	}
	for(int i = 0; i < 31; i++)
		if(!(mex & (1 << i)))
			return g[mask] = i+1;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		fat(x);
	}
	int ans = 0;
	for(auto it = mapa.begin(); it != mapa.end(); it++){
		ans ^= grundy(it->second)-1;
	}
	if(ans)
		printf("Mojtaba\n");
	else printf("Arpa\n");

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int ans = 0;
map<int, int> mapa;
unordered_map<int, int> g;

void fat(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			int cont = 0;
			while(n % i == 0) n /= i, cont++;
			mapa[i] |= (1 << (cont-1));
		}
	}
	if(n > 1){
		mapa[n] |= 1;
	}
}

int grundy(int mask){
	if(g[mask]) return g[mask];
	if(!mask) return 1;
	int mex = 0;
	int j;
	for(j = 31; j >= 0 && !(mask & (1 << j)); j--);
	for(int i = 0; i <= j; i++){
			mex |= 1 << (grundy(mask >> (i+1) | (mask & ((1 << (i)) - 1))) - 1);
	}
	for(int i = 0; i < 31; i++)
		if(!(mex & (1 << i)))
			return g[mask] = i+1;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		fat(x);
	}
	int ans = 0;
	for(auto it = mapa.begin(); it != mapa.end(); it++){
		ans ^= grundy(it->second)-1;
	}
	if(ans)
		printf("Mojtaba\n");
	else printf("Arpa\n");

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int ans = 0;
map<int, int> mapa;
unordered_map<int, int> g;

void fat(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			int cont = 0;
			while(n % i == 0) n /= i, cont++;
			mapa[i] |= (1 << (cont-1));
		}
	}
	if(n > 1){
		mapa[n] |= 1;
	}
}

int grundy(int mask){
	if(g[mask]) return g[mask];
	if(!mask) return 1;
	int mex = 0;
	int j;
	for(j = 31; j >= 0 && !(mask & (1 << j)); j--);
	for(int i = 0; i <= j; i++){
			mex |= 1 << (grundy(mask >> (i+1) | (mask & ((1 << (i)) - 1))) - 1);
	}
	for(int i = 0; i < 31; i++)
		if(!(mex & (1 << i)))
			return g[mask] = i+1;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		fat(x);
	}
	int ans = 0;
	for(auto it = mapa.begin(); it != mapa.end(); it++){
		ans ^= grundy(it->second)-1;
	}
	if(ans)
		printf("Mojtaba\n");
	else printf("Arpa\n");

	return 0;
}