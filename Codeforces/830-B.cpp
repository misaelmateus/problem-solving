//   Author : Misael Mateus 
//   Submission date: 2017-09-19 01:32:26
#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int tree[MAXN];

void update(int u, int k){
	while(u < MAXN){
		tree[u] += k;
		u += (u & -u);
	}
}

int sum(int u){
	int ans = 0;
	while(u > 0){
		ans += tree[u];
		u -= ( u & -u);
	}
	return ans;
}

int main(){
	int n, x, num;
	scanf("%d", &n);
	set<pair< int, int> > s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		s.insert({num, i});
		update(i, 1);
	}

	long long ans = 0LL;
	int ult = 0, p_ult = 0;
	for(int i = 1; i <= n; i++){
		auto it1 = s.upper_bound({(*(s.begin())).first, p_ult});
		auto it2 = s.begin();
		//cout << i <<" " << (*it1).first <<" " << (*it1).second << " - " << (*it2).first <<" " << (*it2).second << endl;
 		if(it1 == s.end() || (*it1).first > (*it2).first){
			ans += sum(MAXN-1) - sum(p_ult) + sum((*it2).second);
			update((*it2).second, -1);
			p_ult = (*it2).second;
			ult = (*it2).first;
			s.erase(it2);
		}
		else{
			ans += sum((*it1).second) - sum(p_ult);
			update((*it1).second, -1);
			p_ult = (*it1).second;
			ult = (*it1).first;
			s.erase(it1);
		}
	}

	printf("%lld\n", ans);
}#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int tree[MAXN];

void update(int u, int k){
	while(u < MAXN){
		tree[u] += k;
		u += (u & -u);
	}
}

int sum(int u){
	int ans = 0;
	while(u > 0){
		ans += tree[u];
		u -= ( u & -u);
	}
	return ans;
}

int main(){
	int n, x, num;
	scanf("%d", &n);
	set<pair< int, int> > s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		s.insert({num, i});
		update(i, 1);
	}

	long long ans = 0LL;
	int ult = 0, p_ult = 0;
	for(int i = 1; i <= n; i++){
		auto it1 = s.upper_bound({(*(s.begin())).first, p_ult});
		auto it2 = s.begin();
		//cout << i <<" " << (*it1).first <<" " << (*it1).second << " - " << (*it2).first <<" " << (*it2).second << endl;
 		if(it1 == s.end() || (*it1).first > (*it2).first){
			ans += sum(MAXN-1) - sum(p_ult) + sum((*it2).second);
			update((*it2).second, -1);
			p_ult = (*it2).second;
			ult = (*it2).first;
			s.erase(it2);
		}
		else{
			ans += sum((*it1).second) - sum(p_ult);
			update((*it1).second, -1);
			p_ult = (*it1).second;
			ult = (*it1).first;
			s.erase(it1);
		}
	}

	printf("%lld\n", ans);
}#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int tree[MAXN];

void update(int u, int k){
	while(u < MAXN){
		tree[u] += k;
		u += (u & -u);
	}
}

int sum(int u){
	int ans = 0;
	while(u > 0){
		ans += tree[u];
		u -= ( u & -u);
	}
	return ans;
}

int main(){
	int n, x, num;
	scanf("%d", &n);
	set<pair< int, int> > s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		s.insert({num, i});
		update(i, 1);
	}

	long long ans = 0LL;
	int ult = 0, p_ult = 0;
	for(int i = 1; i <= n; i++){
		auto it1 = s.upper_bound({(*(s.begin())).first, p_ult});
		auto it2 = s.begin();
		//cout << i <<" " << (*it1).first <<" " << (*it1).second << " - " << (*it2).first <<" " << (*it2).second << endl;
 		if(it1 == s.end() || (*it1).first > (*it2).first){
			ans += sum(MAXN-1) - sum(p_ult) + sum((*it2).second);
			update((*it2).second, -1);
			p_ult = (*it2).second;
			ult = (*it2).first;
			s.erase(it2);
		}
		else{
			ans += sum((*it1).second) - sum(p_ult);
			update((*it1).second, -1);
			p_ult = (*it1).second;
			ult = (*it1).first;
			s.erase(it1);
		}
	}

	printf("%lld\n", ans);
}#include<bits/stdc++.h>
#define MAXN 200100
using namespace std;

int tree[MAXN];

void update(int u, int k){
	while(u < MAXN){
		tree[u] += k;
		u += (u & -u);
	}
}

int sum(int u){
	int ans = 0;
	while(u > 0){
		ans += tree[u];
		u -= ( u & -u);
	}
	return ans;
}

int main(){
	int n, x, num;
	scanf("%d", &n);
	set<pair< int, int> > s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &num);
		s.insert({num, i});
		update(i, 1);
	}

	long long ans = 0LL;
	int ult = 0, p_ult = 0;
	for(int i = 1; i <= n; i++){
		auto it1 = s.upper_bound({(*(s.begin())).first, p_ult});
		auto it2 = s.begin();
		//cout << i <<" " << (*it1).first <<" " << (*it1).second << " - " << (*it2).first <<" " << (*it2).second << endl;
 		if(it1 == s.end() || (*it1).first > (*it2).first){
			ans += sum(MAXN-1) - sum(p_ult) + sum((*it2).second);
			update((*it2).second, -1);
			p_ult = (*it2).second;
			ult = (*it2).first;
			s.erase(it2);
		}
		else{
			ans += sum((*it1).second) - sum(p_ult);
			update((*it1).second, -1);
			p_ult = (*it1).second;
			ult = (*it1).first;
			s.erase(it1);
		}
	}

	printf("%lld\n", ans);
}