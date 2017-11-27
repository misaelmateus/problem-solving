//   Author : Misael Mateus 
//   Submission date: 2017-04-21 20:18:59
#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;



int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){

	int cont = 0;
	int n;
	scanf("%d", &n);
	int j = 0, x[n];
	rp(i, n){
		scanf("%d", &x[i]);
	}
	rp(i, n-1){
		if(i != j)
			continue;
		if(x[i] % 2 == 0)
			j++;
		else{
			cont++;
			j+=2;
			if(x[i+1] % 2 == 0)
				cont++;
		}
	}
	if(x[n-1] % 2 && j < n)
		cont += 2;
	int l = x[0];
	fr(i, 1, n)
		l = gcd(l, x[i]);
	if(l != 1)
	{
		printf("YES\n%d\n", 0);
		return 0;
	}
	else
		printf("YES\n%d\n", cont);

	return 0;
}#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;



int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){

	int cont = 0;
	int n;
	scanf("%d", &n);
	int j = 0, x[n];
	rp(i, n){
		scanf("%d", &x[i]);
	}
	rp(i, n-1){
		if(i != j)
			continue;
		if(x[i] % 2 == 0)
			j++;
		else{
			cont++;
			j+=2;
			if(x[i+1] % 2 == 0)
				cont++;
		}
	}
	if(x[n-1] % 2 && j < n)
		cont += 2;
	int l = x[0];
	fr(i, 1, n)
		l = gcd(l, x[i]);
	if(l != 1)
	{
		printf("YES\n%d\n", 0);
		return 0;
	}
	else
		printf("YES\n%d\n", cont);

	return 0;
}#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;



int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){

	int cont = 0;
	int n;
	scanf("%d", &n);
	int j = 0, x[n];
	rp(i, n){
		scanf("%d", &x[i]);
	}
	rp(i, n-1){
		if(i != j)
			continue;
		if(x[i] % 2 == 0)
			j++;
		else{
			cont++;
			j+=2;
			if(x[i+1] % 2 == 0)
				cont++;
		}
	}
	if(x[n-1] % 2 && j < n)
		cont += 2;
	int l = x[0];
	fr(i, 1, n)
		l = gcd(l, x[i]);
	if(l != 1)
	{
		printf("YES\n%d\n", 0);
		return 0;
	}
	else
		printf("YES\n%d\n", cont);

	return 0;
}#include<bits/stdc++.h>
#define MAXN 110
#define MAXS 50010
#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)


using namespace std;



int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main(){

	int cont = 0;
	int n;
	scanf("%d", &n);
	int j = 0, x[n];
	rp(i, n){
		scanf("%d", &x[i]);
	}
	rp(i, n-1){
		if(i != j)
			continue;
		if(x[i] % 2 == 0)
			j++;
		else{
			cont++;
			j+=2;
			if(x[i+1] % 2 == 0)
				cont++;
		}
	}
	if(x[n-1] % 2 && j < n)
		cont += 2;
	int l = x[0];
	fr(i, 1, n)
		l = gcd(l, x[i]);
	if(l != 1)
	{
		printf("YES\n%d\n", 0);
		return 0;
	}
	else
		printf("YES\n%d\n", cont);

	return 0;
}