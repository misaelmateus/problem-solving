//   Author : Misael Mateus 
//   Submission date: 2017-09-22 20:27:44
#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
using namespace std;

map<pair<ii, ii>, pair<ll, ii> > mapa; 
int A[4][4], B[4][4];
int main(){
	ios::sync_with_stdio(false);	
	ll k, a, b;
	cin >> k >> a >> b;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> A[i][j];
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> B[i][j];
	ll pa = (a == (b % 3) + 1), pb = (b == (a % 3) +1);
	ll rod = 1;
	for(rod++; rod <= k; rod++){
		pair<ll, ii> aux = mapa[{{a, b}, {A[a][b], B[a][b]}}];
		if(aux.first){
			ll dif = rod - aux.first;
			ll dif_a = pa - aux.second.first;
			ll dif_b = pb - aux.second.second;
			ll num = (k - rod) / dif;
			//cout << rod << " " << dif_a <<" " << dif_b << " " << dif <<" " << aux.first << endl;
			pa += dif_a*num;
			pb += dif_b*num;
			rod += num*dif;
		}
		mapa[{{a, b}, {A[a][b], B[a][b]}}] = {rod, {pa, pb}};
		pa += (A[a][b] == (B[a][b]%3) + 1);
		pb += (B[a][b] == (A[a][b]%3) + 1);
		int a1 = a, b1 = b;
		a = A[a1][b1];
		b = B[a1][b1];
		//cout << a << " " << b << " " << pa <<" " << pb << endl;
	}
	cout << pa << " " << pb << "\n"; 
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
using namespace std;

map<pair<ii, ii>, pair<ll, ii> > mapa; 
int A[4][4], B[4][4];
int main(){
	ios::sync_with_stdio(false);	
	ll k, a, b;
	cin >> k >> a >> b;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> A[i][j];
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> B[i][j];
	ll pa = (a == (b % 3) + 1), pb = (b == (a % 3) +1);
	ll rod = 1;
	for(rod++; rod <= k; rod++){
		pair<ll, ii> aux = mapa[{{a, b}, {A[a][b], B[a][b]}}];
		if(aux.first){
			ll dif = rod - aux.first;
			ll dif_a = pa - aux.second.first;
			ll dif_b = pb - aux.second.second;
			ll num = (k - rod) / dif;
			//cout << rod << " " << dif_a <<" " << dif_b << " " << dif <<" " << aux.first << endl;
			pa += dif_a*num;
			pb += dif_b*num;
			rod += num*dif;
		}
		mapa[{{a, b}, {A[a][b], B[a][b]}}] = {rod, {pa, pb}};
		pa += (A[a][b] == (B[a][b]%3) + 1);
		pb += (B[a][b] == (A[a][b]%3) + 1);
		int a1 = a, b1 = b;
		a = A[a1][b1];
		b = B[a1][b1];
		//cout << a << " " << b << " " << pa <<" " << pb << endl;
	}
	cout << pa << " " << pb << "\n"; 
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
using namespace std;

map<pair<ii, ii>, pair<ll, ii> > mapa; 
int A[4][4], B[4][4];
int main(){
	ios::sync_with_stdio(false);	
	ll k, a, b;
	cin >> k >> a >> b;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> A[i][j];
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> B[i][j];
	ll pa = (a == (b % 3) + 1), pb = (b == (a % 3) +1);
	ll rod = 1;
	for(rod++; rod <= k; rod++){
		pair<ll, ii> aux = mapa[{{a, b}, {A[a][b], B[a][b]}}];
		if(aux.first){
			ll dif = rod - aux.first;
			ll dif_a = pa - aux.second.first;
			ll dif_b = pb - aux.second.second;
			ll num = (k - rod) / dif;
			//cout << rod << " " << dif_a <<" " << dif_b << " " << dif <<" " << aux.first << endl;
			pa += dif_a*num;
			pb += dif_b*num;
			rod += num*dif;
		}
		mapa[{{a, b}, {A[a][b], B[a][b]}}] = {rod, {pa, pb}};
		pa += (A[a][b] == (B[a][b]%3) + 1);
		pb += (B[a][b] == (A[a][b]%3) + 1);
		int a1 = a, b1 = b;
		a = A[a1][b1];
		b = B[a1][b1];
		//cout << a << " " << b << " " << pa <<" " << pb << endl;
	}
	cout << pa << " " << pb << "\n"; 
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
using namespace std;

map<pair<ii, ii>, pair<ll, ii> > mapa; 
int A[4][4], B[4][4];
int main(){
	ios::sync_with_stdio(false);	
	ll k, a, b;
	cin >> k >> a >> b;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> A[i][j];
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			cin >> B[i][j];
	ll pa = (a == (b % 3) + 1), pb = (b == (a % 3) +1);
	ll rod = 1;
	for(rod++; rod <= k; rod++){
		pair<ll, ii> aux = mapa[{{a, b}, {A[a][b], B[a][b]}}];
		if(aux.first){
			ll dif = rod - aux.first;
			ll dif_a = pa - aux.second.first;
			ll dif_b = pb - aux.second.second;
			ll num = (k - rod) / dif;
			//cout << rod << " " << dif_a <<" " << dif_b << " " << dif <<" " << aux.first << endl;
			pa += dif_a*num;
			pb += dif_b*num;
			rod += num*dif;
		}
		mapa[{{a, b}, {A[a][b], B[a][b]}}] = {rod, {pa, pb}};
		pa += (A[a][b] == (B[a][b]%3) + 1);
		pb += (B[a][b] == (A[a][b]%3) + 1);
		int a1 = a, b1 = b;
		a = A[a1][b1];
		b = B[a1][b1];
		//cout << a << " " << b << " " << pa <<" " << pb << endl;
	}
	cout << pa << " " << pb << "\n"; 
}