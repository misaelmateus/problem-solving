//   Author : Misael Mateus 
//   Submission date: 2017-05-11 21:15:50
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	int x;
	set<int> f[4];

	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		f[x].insert(p[i]);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		f[x].insert(p[i]);
	}

	int m;
	cin >> m;
	while(m--){
		cin >> x;
		int price = -1;
		if(f[x].size()){
			price = *(f[x].begin());
			for(int i = 1; i <= 3; i++)
				f[i].erase(price);
		}
		if(price + 1)
			printf("%d ", price);
		else printf("-1 ");
	}
	printf("\n");

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	int x;
	set<int> f[4];

	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		f[x].insert(p[i]);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		f[x].insert(p[i]);
	}

	int m;
	cin >> m;
	while(m--){
		cin >> x;
		int price = -1;
		if(f[x].size()){
			price = *(f[x].begin());
			for(int i = 1; i <= 3; i++)
				f[i].erase(price);
		}
		if(price + 1)
			printf("%d ", price);
		else printf("-1 ");
	}
	printf("\n");

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	int x;
	set<int> f[4];

	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		f[x].insert(p[i]);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		f[x].insert(p[i]);
	}

	int m;
	cin >> m;
	while(m--){
		cin >> x;
		int price = -1;
		if(f[x].size()){
			price = *(f[x].begin());
			for(int i = 1; i <= 3; i++)
				f[i].erase(price);
		}
		if(price + 1)
			printf("%d ", price);
		else printf("-1 ");
	}
	printf("\n");

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int p[n];
	int x;
	set<int> f[4];

	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		f[x].insert(p[i]);
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		f[x].insert(p[i]);
	}

	int m;
	cin >> m;
	while(m--){
		cin >> x;
		int price = -1;
		if(f[x].size()){
			price = *(f[x].begin());
			for(int i = 1; i <= 3; i++)
				f[i].erase(price);
		}
		if(price + 1)
			printf("%d ", price);
		else printf("-1 ");
	}
	printf("\n");

	return 0;
}

