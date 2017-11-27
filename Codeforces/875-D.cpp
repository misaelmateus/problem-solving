//   Author : Misael Mateus 
//   Submission date: 2017-10-16 19:05:59
#include<bits/stdc++.h>
#define T 450
#define MAXN 200700
using namespace std;


int v1[MAXN/T];

vector<int> v[31];
int val[MAXN];
void decompose(int n, int p){
	for(int i = 0; i < 31; i++){
		if(n & (1 << i))
			v[i].push_back(p);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0LL;
	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		decompose(val[i], i);
		v1[i/T] = max(v1[i/T], val[i]);
	}

	for(int i = 0; i < n; i++){
		
		int p1 = -1, p2 = n;
		for(int j = i+1, l = (i/T + 1)*T; j < l && j < n; j++){
			if(val[j] >= val[i]){
				p2 = min(p2, j);
				break;
			}
		}
		
		for(int j = i/T + 1; j < n/T + 1; j++){
			if(v1[j] >= val[i]){
				for(int l = j*T; l < n && l < (j+1)*T; l++){
					if(val[l] >= val[i]){
						p2 = min(p2, l);
						break;
					}
				}
				break;
			}
		}
		p2--;

		for(int j = i-1, l = (i/T)*T; j >= l; j--){
			if(val[j] > val[i]){
				p1 = max(p1, j);
				break;
			}
		}
		for(int j = i/T - 1; j >= 0; j--){
			if(v1[j] > val[i]){
				for(int l = (j+1)*T - 1; l >= 0 && l >= (j)*T; l--){
					if(val[l] > val[i]){
						p1 = max(p1, l);
				 			break;
					}
				}
				break;
			}
		}
		p1++;
		int a1 = -1, a2 = n;
		for(int l = 0; l < 31; l++){
			if(!(val[i] & (1 << l))){
				auto u = (lower_bound(v[l].begin(), v[l].end(), i));
				int x = n;
				if(u != v[l].end())
					x = *u;
				int y = -1;
				if(u != v[l].begin())
					y = *(--u);
				a1 = max(a1, y);
				a2 = min(a2, x);
			}
		}
		//cout << i << " " << p1 << "-" << a1 << "  " << p2 <<"-" << a2 << endl;
		if(a1 >= p1){
			ans += (long long)(a1 - p1 + 1)*(p2 - i + 1 );
		}
		a2 = max(a2, i+1);
		if(a2 <= p2)
			ans += (long long)(p2 - a2 + 1)*(i - p1 + 1);
		if(a1 >= p1 && a2 <= p2)
			ans -= (long long)(a1 - p1 + 1)*(p2 - a2 + 1);
	}


	cout << ans << endl;
	return 0;
}#include<bits/stdc++.h>
#define T 450
#define MAXN 200700
using namespace std;


int v1[MAXN/T];

vector<int> v[31];
int val[MAXN];
void decompose(int n, int p){
	for(int i = 0; i < 31; i++){
		if(n & (1 << i))
			v[i].push_back(p);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0LL;
	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		decompose(val[i], i);
		v1[i/T] = max(v1[i/T], val[i]);
	}

	for(int i = 0; i < n; i++){
		
		int p1 = -1, p2 = n;
		for(int j = i+1, l = (i/T + 1)*T; j < l && j < n; j++){
			if(val[j] >= val[i]){
				p2 = min(p2, j);
				break;
			}
		}
		
		for(int j = i/T + 1; j < n/T + 1; j++){
			if(v1[j] >= val[i]){
				for(int l = j*T; l < n && l < (j+1)*T; l++){
					if(val[l] >= val[i]){
						p2 = min(p2, l);
						break;
					}
				}
				break;
			}
		}
		p2--;

		for(int j = i-1, l = (i/T)*T; j >= l; j--){
			if(val[j] > val[i]){
				p1 = max(p1, j);
				break;
			}
		}
		for(int j = i/T - 1; j >= 0; j--){
			if(v1[j] > val[i]){
				for(int l = (j+1)*T - 1; l >= 0 && l >= (j)*T; l--){
					if(val[l] > val[i]){
						p1 = max(p1, l);
				 			break;
					}
				}
				break;
			}
		}
		p1++;
		int a1 = -1, a2 = n;
		for(int l = 0; l < 31; l++){
			if(!(val[i] & (1 << l))){
				auto u = (lower_bound(v[l].begin(), v[l].end(), i));
				int x = n;
				if(u != v[l].end())
					x = *u;
				int y = -1;
				if(u != v[l].begin())
					y = *(--u);
				a1 = max(a1, y);
				a2 = min(a2, x);
			}
		}
		//cout << i << " " << p1 << "-" << a1 << "  " << p2 <<"-" << a2 << endl;
		if(a1 >= p1){
			ans += (long long)(a1 - p1 + 1)*(p2 - i + 1 );
		}
		a2 = max(a2, i+1);
		if(a2 <= p2)
			ans += (long long)(p2 - a2 + 1)*(i - p1 + 1);
		if(a1 >= p1 && a2 <= p2)
			ans -= (long long)(a1 - p1 + 1)*(p2 - a2 + 1);
	}


	cout << ans << endl;
	return 0;
}#include<bits/stdc++.h>
#define T 450
#define MAXN 200700
using namespace std;


int v1[MAXN/T];

vector<int> v[31];
int val[MAXN];
void decompose(int n, int p){
	for(int i = 0; i < 31; i++){
		if(n & (1 << i))
			v[i].push_back(p);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0LL;
	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		decompose(val[i], i);
		v1[i/T] = max(v1[i/T], val[i]);
	}

	for(int i = 0; i < n; i++){
		
		int p1 = -1, p2 = n;
		for(int j = i+1, l = (i/T + 1)*T; j < l && j < n; j++){
			if(val[j] >= val[i]){
				p2 = min(p2, j);
				break;
			}
		}
		
		for(int j = i/T + 1; j < n/T + 1; j++){
			if(v1[j] >= val[i]){
				for(int l = j*T; l < n && l < (j+1)*T; l++){
					if(val[l] >= val[i]){
						p2 = min(p2, l);
						break;
					}
				}
				break;
			}
		}
		p2--;

		for(int j = i-1, l = (i/T)*T; j >= l; j--){
			if(val[j] > val[i]){
				p1 = max(p1, j);
				break;
			}
		}
		for(int j = i/T - 1; j >= 0; j--){
			if(v1[j] > val[i]){
				for(int l = (j+1)*T - 1; l >= 0 && l >= (j)*T; l--){
					if(val[l] > val[i]){
						p1 = max(p1, l);
				 			break;
					}
				}
				break;
			}
		}
		p1++;
		int a1 = -1, a2 = n;
		for(int l = 0; l < 31; l++){
			if(!(val[i] & (1 << l))){
				auto u = (lower_bound(v[l].begin(), v[l].end(), i));
				int x = n;
				if(u != v[l].end())
					x = *u;
				int y = -1;
				if(u != v[l].begin())
					y = *(--u);
				a1 = max(a1, y);
				a2 = min(a2, x);
			}
		}
		//cout << i << " " << p1 << "-" << a1 << "  " << p2 <<"-" << a2 << endl;
		if(a1 >= p1){
			ans += (long long)(a1 - p1 + 1)*(p2 - i + 1 );
		}
		a2 = max(a2, i+1);
		if(a2 <= p2)
			ans += (long long)(p2 - a2 + 1)*(i - p1 + 1);
		if(a1 >= p1 && a2 <= p2)
			ans -= (long long)(a1 - p1 + 1)*(p2 - a2 + 1);
	}


	cout << ans << endl;
	return 0;
}#include<bits/stdc++.h>
#define T 450
#define MAXN 200700
using namespace std;


int v1[MAXN/T];

vector<int> v[31];
int val[MAXN];
void decompose(int n, int p){
	for(int i = 0; i < 31; i++){
		if(n & (1 << i))
			v[i].push_back(p);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	long long ans = 0LL;
	for(int i = 0; i < n; i++){
		scanf("%d", &val[i]);
		decompose(val[i], i);
		v1[i/T] = max(v1[i/T], val[i]);
	}

	for(int i = 0; i < n; i++){
		
		int p1 = -1, p2 = n;
		for(int j = i+1, l = (i/T + 1)*T; j < l && j < n; j++){
			if(val[j] >= val[i]){
				p2 = min(p2, j);
				break;
			}
		}
		
		for(int j = i/T + 1; j < n/T + 1; j++){
			if(v1[j] >= val[i]){
				for(int l = j*T; l < n && l < (j+1)*T; l++){
					if(val[l] >= val[i]){
						p2 = min(p2, l);
						break;
					}
				}
				break;
			}
		}
		p2--;

		for(int j = i-1, l = (i/T)*T; j >= l; j--){
			if(val[j] > val[i]){
				p1 = max(p1, j);
				break;
			}
		}
		for(int j = i/T - 1; j >= 0; j--){
			if(v1[j] > val[i]){
				for(int l = (j+1)*T - 1; l >= 0 && l >= (j)*T; l--){
					if(val[l] > val[i]){
						p1 = max(p1, l);
				 			break;
					}
				}
				break;
			}
		}
		p1++;
		int a1 = -1, a2 = n;
		for(int l = 0; l < 31; l++){
			if(!(val[i] & (1 << l))){
				auto u = (lower_bound(v[l].begin(), v[l].end(), i));
				int x = n;
				if(u != v[l].end())
					x = *u;
				int y = -1;
				if(u != v[l].begin())
					y = *(--u);
				a1 = max(a1, y);
				a2 = min(a2, x);
			}
		}
		//cout << i << " " << p1 << "-" << a1 << "  " << p2 <<"-" << a2 << endl;
		if(a1 >= p1){
			ans += (long long)(a1 - p1 + 1)*(p2 - i + 1 );
		}
		a2 = max(a2, i+1);
		if(a2 <= p2)
			ans += (long long)(p2 - a2 + 1)*(i - p1 + 1);
		if(a1 >= p1 && a2 <= p2)
			ans -= (long long)(a1 - p1 + 1)*(p2 - a2 + 1);
	}


	cout << ans << endl;
	return 0;
}