//   Author : Misael Mateus 
//   Submission date: 2017-03-21 20:37:30
#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
int q[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		q[aux]++;
	}
	for(int i = 1; i < MAX; i++)
		q[i] += q[i-1];

	for(int i = MAX-1; i > 0; i--){
		int cont = 0;
		for(int j = i; j < MAX; j+= i){
			cont += q[j+min(MAX-j-1, min(i-1, k))] - q[j-1];
		}
		if(cont == n){
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
int q[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		q[aux]++;
	}
	for(int i = 1; i < MAX; i++)
		q[i] += q[i-1];

	for(int i = MAX-1; i > 0; i--){
		int cont = 0;
		for(int j = i; j < MAX; j+= i){
			cont += q[j+min(MAX-j-1, min(i-1, k))] - q[j-1];
		}
		if(cont == n){
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
int q[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		q[aux]++;
	}
	for(int i = 1; i < MAX; i++)
		q[i] += q[i-1];

	for(int i = MAX-1; i > 0; i--){
		int cont = 0;
		for(int j = i; j < MAX; j+= i){
			cont += q[j+min(MAX-j-1, min(i-1, k))] - q[j-1];
		}
		if(cont == n){
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
int q[MAX];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int aux;
		scanf("%d", &aux);
		q[aux]++;
	}
	for(int i = 1; i < MAX; i++)
		q[i] += q[i-1];

	for(int i = MAX-1; i > 0; i--){
		int cont = 0;
		for(int j = i; j < MAX; j+= i){
			cont += q[j+min(MAX-j-1, min(i-1, k))] - q[j-1];
		}
		if(cont == n){
			printf("%d\n", i);
			return 0;
		}
	}

	return 0;
}