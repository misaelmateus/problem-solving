//   Author : Misael Mateus 
//   Submission date: 2017-10-26 20:08:41
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
	ll K;
	cin >> N >> K;
	K = min((ll)(N-1), K);
	int aux;
	deque<int> q;
	for(int i = 0; i < N; i++){
		cin >> aux;
		q.push_back(aux);
	}

	ll cont = 0;
	while(cont < K){
		int first = q.front(); q.pop_front();
		int second = q.front(); q.pop_front();
		if(first > second)
			cont++, q.push_back(second), q.push_front(first);
		else cont = 1, q.push_back(first), q.push_front(second);
	}

	cout << q.front() << "\n";
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
	ll K;
	cin >> N >> K;
	K = min((ll)(N-1), K);
	int aux;
	deque<int> q;
	for(int i = 0; i < N; i++){
		cin >> aux;
		q.push_back(aux);
	}

	ll cont = 0;
	while(cont < K){
		int first = q.front(); q.pop_front();
		int second = q.front(); q.pop_front();
		if(first > second)
			cont++, q.push_back(second), q.push_front(first);
		else cont = 1, q.push_back(first), q.push_front(second);
	}

	cout << q.front() << "\n";
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
	ll K;
	cin >> N >> K;
	K = min((ll)(N-1), K);
	int aux;
	deque<int> q;
	for(int i = 0; i < N; i++){
		cin >> aux;
		q.push_back(aux);
	}

	ll cont = 0;
	while(cont < K){
		int first = q.front(); q.pop_front();
		int second = q.front(); q.pop_front();
		if(first > second)
			cont++, q.push_back(second), q.push_front(first);
		else cont = 1, q.push_back(first), q.push_front(second);
	}

	cout << q.front() << "\n";
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
	ll K;
	cin >> N >> K;
	K = min((ll)(N-1), K);
	int aux;
	deque<int> q;
	for(int i = 0; i < N; i++){
		cin >> aux;
		q.push_back(aux);
	}

	ll cont = 0;
	while(cont < K){
		int first = q.front(); q.pop_front();
		int second = q.front(); q.pop_front();
		if(first > second)
			cont++, q.push_back(second), q.push_front(first);
		else cont = 1, q.push_back(first), q.push_front(second);
	}

	cout << q.front() << "\n";
}