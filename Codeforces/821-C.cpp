//   Author : Misael Mateus 
//   Submission date: 2017-07-06 16:00:09
#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	int n, m;
	string str;
	cin >> n;
	stack<int> s;
	priority_queue<int> pq;
	vector<int> v(n+1, 0);
	int cont = 0;
	n *= 2;
	while(n--){
		cin >> str;
		
		if(str[0] == 'a'){
			cin >> m;
			s.push(m), pq.push(-m);
		}
		else{
			while(v[s.top()] == 2) s.pop();
			while(v[-pq.top()] == 2) pq.pop();
			if(s.top() == -pq.top()) {
				int a = s.top();
				s.pop(), pq.pop();
				while(!s.empty() && v[s.top()] == 2) s.pop();
				if(v[a] == 1 && !s.empty()) v[s.top()] = 1;
				v[a] = 2;
			}
			else {
				if(v[s.top()] != 1) cont++;
				v[s.top()] = 1;
				v[-pq.top()] = 2;
				pq.pop();
			}
		}
	}
	cout << cont << "\n";
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	int n, m;
	string str;
	cin >> n;
	stack<int> s;
	priority_queue<int> pq;
	vector<int> v(n+1, 0);
	int cont = 0;
	n *= 2;
	while(n--){
		cin >> str;
		
		if(str[0] == 'a'){
			cin >> m;
			s.push(m), pq.push(-m);
		}
		else{
			while(v[s.top()] == 2) s.pop();
			while(v[-pq.top()] == 2) pq.pop();
			if(s.top() == -pq.top()) {
				int a = s.top();
				s.pop(), pq.pop();
				while(!s.empty() && v[s.top()] == 2) s.pop();
				if(v[a] == 1 && !s.empty()) v[s.top()] = 1;
				v[a] = 2;
			}
			else {
				if(v[s.top()] != 1) cont++;
				v[s.top()] = 1;
				v[-pq.top()] = 2;
				pq.pop();
			}
		}
	}
	cout << cont << "\n";
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	int n, m;
	string str;
	cin >> n;
	stack<int> s;
	priority_queue<int> pq;
	vector<int> v(n+1, 0);
	int cont = 0;
	n *= 2;
	while(n--){
		cin >> str;
		
		if(str[0] == 'a'){
			cin >> m;
			s.push(m), pq.push(-m);
		}
		else{
			while(v[s.top()] == 2) s.pop();
			while(v[-pq.top()] == 2) pq.pop();
			if(s.top() == -pq.top()) {
				int a = s.top();
				s.pop(), pq.pop();
				while(!s.empty() && v[s.top()] == 2) s.pop();
				if(v[a] == 1 && !s.empty()) v[s.top()] = 1;
				v[a] = 2;
			}
			else {
				if(v[s.top()] != 1) cont++;
				v[s.top()] = 1;
				v[-pq.top()] = 2;
				pq.pop();
			}
		}
	}
	cout << cont << "\n";
}#include<bits/stdc++.h>
#define fr(a, b, c) for(int a = b; a < c; a++)
#define rep(a, b) fr(a, 0, b)
#define ii pair<int, int>
#define ll long long
#define ld long double
#define RI(a) scanf("%d", &a)
#define RII(a, b) scanf("%d %d", &a, &b)

using namespace std;

int main(){
	ios::sync_with_stdio(false);	
	int n, m;
	string str;
	cin >> n;
	stack<int> s;
	priority_queue<int> pq;
	vector<int> v(n+1, 0);
	int cont = 0;
	n *= 2;
	while(n--){
		cin >> str;
		
		if(str[0] == 'a'){
			cin >> m;
			s.push(m), pq.push(-m);
		}
		else{
			while(v[s.top()] == 2) s.pop();
			while(v[-pq.top()] == 2) pq.pop();
			if(s.top() == -pq.top()) {
				int a = s.top();
				s.pop(), pq.pop();
				while(!s.empty() && v[s.top()] == 2) s.pop();
				if(v[a] == 1 && !s.empty()) v[s.top()] = 1;
				v[a] = 2;
			}
			else {
				if(v[s.top()] != 1) cont++;
				v[s.top()] = 1;
				v[-pq.top()] = 2;
				pq.pop();
			}
		}
	}
	cout << cont << "\n";
}