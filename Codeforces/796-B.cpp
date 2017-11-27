//   Author : Misael Mateus 
//   Submission date: 2017-04-10 22:15:28
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int v[n+1], aux;

	for(int i = 0; i <= n; i++)
		v[i] = 0;

	for(int i = 0; i < m; i++){
		scanf("%d", &aux);
		v[aux] = 1;
	}
	int p = 1;
	if(v[1] == 1){
		printf("%d\n", p);
		return 0;
	}
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(p == a)
			p = b;
		else if(p == b)
			p = a;
		if(v[p] == 1){
			printf("%d\n", p);
			return 0;
		}

	}
	printf("%d\n", p);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int v[n+1], aux;

	for(int i = 0; i <= n; i++)
		v[i] = 0;

	for(int i = 0; i < m; i++){
		scanf("%d", &aux);
		v[aux] = 1;
	}
	int p = 1;
	if(v[1] == 1){
		printf("%d\n", p);
		return 0;
	}
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(p == a)
			p = b;
		else if(p == b)
			p = a;
		if(v[p] == 1){
			printf("%d\n", p);
			return 0;
		}

	}
	printf("%d\n", p);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int v[n+1], aux;

	for(int i = 0; i <= n; i++)
		v[i] = 0;

	for(int i = 0; i < m; i++){
		scanf("%d", &aux);
		v[aux] = 1;
	}
	int p = 1;
	if(v[1] == 1){
		printf("%d\n", p);
		return 0;
	}
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(p == a)
			p = b;
		else if(p == b)
			p = a;
		if(v[p] == 1){
			printf("%d\n", p);
			return 0;
		}

	}
	printf("%d\n", p);
	return 0;
}#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int v[n+1], aux;

	for(int i = 0; i <= n; i++)
		v[i] = 0;

	for(int i = 0; i < m; i++){
		scanf("%d", &aux);
		v[aux] = 1;
	}
	int p = 1;
	if(v[1] == 1){
		printf("%d\n", p);
		return 0;
	}
	while(k--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(p == a)
			p = b;
		else if(p == b)
			p = a;
		if(v[p] == 1){
			printf("%d\n", p);
			return 0;
		}

	}
	printf("%d\n", p);
	return 0;
}