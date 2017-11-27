//   Author : Misael Mateus 
//   Submission date: 2017-10-26 20:13:16
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;

int main(){
	readFast;
	int N;
	cin >> N;
	vector<pair<char, int> > v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i].first >> v[i].second;
	}
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 10; i++){
		int ans0 = 0, ans1 = 1 << i;
		for(int j = 0; j < N; j++){
			if(v[j].first == '|'){
				ans0 |= v[j].second;
				ans1 |= v[j].second;
			}
			else if(v[j].first == '^'){
				ans0 ^= v[j].second;
				ans1 ^= v[j].second;
			}
			else{
				ans0 &= v[j].second;
				ans1 &= v[j].second;
			}
		}
		ans0 >>= i;
		ans1 >>= i;
		ans0 &= 1;
		ans1 &= 1;
		if(!ans1){
			if(!ans0){
				a |= (1 << i);
				b |= (1 << i);
				c |= (1 << i);
			}
			else{
				b |= (1 << i);
				c |= (1 << i);
			}
		}
		else{
			if(!ans0){
				b |= (1 << i);
			}
			else{
				a |= (1 << i);
				b |= (1 << i);
			}	
		}
	}
	cout << "3\n";
	cout << "| " << a << "\n";
	cout << "& " << b << "\n";
	cout << "^ " << c << "\n";	
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;

int main(){
	readFast;
	int N;
	cin >> N;
	vector<pair<char, int> > v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i].first >> v[i].second;
	}
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 10; i++){
		int ans0 = 0, ans1 = 1 << i;
		for(int j = 0; j < N; j++){
			if(v[j].first == '|'){
				ans0 |= v[j].second;
				ans1 |= v[j].second;
			}
			else if(v[j].first == '^'){
				ans0 ^= v[j].second;
				ans1 ^= v[j].second;
			}
			else{
				ans0 &= v[j].second;
				ans1 &= v[j].second;
			}
		}
		ans0 >>= i;
		ans1 >>= i;
		ans0 &= 1;
		ans1 &= 1;
		if(!ans1){
			if(!ans0){
				a |= (1 << i);
				b |= (1 << i);
				c |= (1 << i);
			}
			else{
				b |= (1 << i);
				c |= (1 << i);
			}
		}
		else{
			if(!ans0){
				b |= (1 << i);
			}
			else{
				a |= (1 << i);
				b |= (1 << i);
			}	
		}
	}
	cout << "3\n";
	cout << "| " << a << "\n";
	cout << "& " << b << "\n";
	cout << "^ " << c << "\n";	
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;

int main(){
	readFast;
	int N;
	cin >> N;
	vector<pair<char, int> > v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i].first >> v[i].second;
	}
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 10; i++){
		int ans0 = 0, ans1 = 1 << i;
		for(int j = 0; j < N; j++){
			if(v[j].first == '|'){
				ans0 |= v[j].second;
				ans1 |= v[j].second;
			}
			else if(v[j].first == '^'){
				ans0 ^= v[j].second;
				ans1 ^= v[j].second;
			}
			else{
				ans0 &= v[j].second;
				ans1 &= v[j].second;
			}
		}
		ans0 >>= i;
		ans1 >>= i;
		ans0 &= 1;
		ans1 &= 1;
		if(!ans1){
			if(!ans0){
				a |= (1 << i);
				b |= (1 << i);
				c |= (1 << i);
			}
			else{
				b |= (1 << i);
				c |= (1 << i);
			}
		}
		else{
			if(!ans0){
				b |= (1 << i);
			}
			else{
				a |= (1 << i);
				b |= (1 << i);
			}	
		}
	}
	cout << "3\n";
	cout << "| " << a << "\n";
	cout << "& " << b << "\n";
	cout << "^ " << c << "\n";	
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)
#define vi vector<int>
#define MAXN 111
#define readFast ios::sync_with_stdio(false)
using namespace std;

int main(){
	readFast;
	int N;
	cin >> N;
	vector<pair<char, int> > v(N);
	for(int i = 0; i < N; i++){
		cin >> v[i].first >> v[i].second;
	}
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < 10; i++){
		int ans0 = 0, ans1 = 1 << i;
		for(int j = 0; j < N; j++){
			if(v[j].first == '|'){
				ans0 |= v[j].second;
				ans1 |= v[j].second;
			}
			else if(v[j].first == '^'){
				ans0 ^= v[j].second;
				ans1 ^= v[j].second;
			}
			else{
				ans0 &= v[j].second;
				ans1 &= v[j].second;
			}
		}
		ans0 >>= i;
		ans1 >>= i;
		ans0 &= 1;
		ans1 &= 1;
		if(!ans1){
			if(!ans0){
				a |= (1 << i);
				b |= (1 << i);
				c |= (1 << i);
			}
			else{
				b |= (1 << i);
				c |= (1 << i);
			}
		}
		else{
			if(!ans0){
				b |= (1 << i);
			}
			else{
				a |= (1 << i);
				b |= (1 << i);
			}	
		}
	}
	cout << "3\n";
	cout << "| " << a << "\n";
	cout << "& " << b << "\n";
	cout << "^ " << c << "\n";	
}