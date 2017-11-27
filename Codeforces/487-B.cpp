//   Author : Misael Mateus 
//   Submission date: 2017-03-13 17:17:13
#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>
#define MAX 800000
#define INF 1000010000
#define ll long long
using namespace std;
 
ll tree[MAX][3];


void update(ll i, ll j, ll l, ll r, ll n, ll k, int p)
{
    if(l >= i && r <= j)
    {
    	if(p == 0)
        	tree[n][p] = max(tree[n][p], k); // update current
        else 
        	tree[n][p] = min(tree[n][p], k); // update current
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k, p);
    update(i, j, middle + 1, r, 2*n + 1, k, p);
    if(p == 0)
    	tree[n][p] = max(tree[2*n][p] , tree[2*n + 1][p]); // update current
    else
    	tree[n][p] = min(tree[2*n][p] , tree[2*n + 1][p]); // update current
    
 
}
ll query(ll i, ll j, ll l, ll r, ll n, ll p)
{
    if(r < i || l > j){
        if(p == 0)
        	return -INF;
        else return INF;
    }
    if(l >= i && r <= j)
        return (ll) tree[n][p];

    ll middle = (l + r) / 2;
    if(p == 0)
    	return max(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
    else
    	return min(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
}


int main(){
	ios::sync_with_stdio( false );
	for(int i = 0; i < MAX; i++)
		tree[i][1] = tree[i][2] = INF, tree[i][0] = -INF;
	int n, s, l;
	cin >> n >> s >> l;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		update(i, i, 1, n, 1, num, 0);
		update(i, i, 1, n, 1, num, 1);
	}

	int i = n, j = n;
	while(i > 0 && j > 0){
		
		if(j - i  + 1 < l){
			i--;
			continue;
		}
		if(query(i, j, 1, n, 1, 0) - query(i, j, 1, n, 1, 1) > s)
			j--;
		else{
			if(j + 1 > n)
				update(i, i, 1, n, 1, 1, 2);
			else{
				int	ans1 = query(i+l, j+1, 1, n, 1, 2);
				if(ans1 == INF){
					i--;
					continue;
				}
				else
					update(i, i, 1, n, 1, ans1+1, 2);
			}
			
			i--;
		}
	}
	int ans = query(1, 1, 1, n, 1, 2);
	if(ans == INF)
		ans = -1;
	cout << ans << endl;
}#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>
#define MAX 800000
#define INF 1000010000
#define ll long long
using namespace std;
 
ll tree[MAX][3];


void update(ll i, ll j, ll l, ll r, ll n, ll k, int p)
{
    if(l >= i && r <= j)
    {
    	if(p == 0)
        	tree[n][p] = max(tree[n][p], k); // update current
        else 
        	tree[n][p] = min(tree[n][p], k); // update current
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k, p);
    update(i, j, middle + 1, r, 2*n + 1, k, p);
    if(p == 0)
    	tree[n][p] = max(tree[2*n][p] , tree[2*n + 1][p]); // update current
    else
    	tree[n][p] = min(tree[2*n][p] , tree[2*n + 1][p]); // update current
    
 
}
ll query(ll i, ll j, ll l, ll r, ll n, ll p)
{
    if(r < i || l > j){
        if(p == 0)
        	return -INF;
        else return INF;
    }
    if(l >= i && r <= j)
        return (ll) tree[n][p];

    ll middle = (l + r) / 2;
    if(p == 0)
    	return max(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
    else
    	return min(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
}


int main(){
	ios::sync_with_stdio( false );
	for(int i = 0; i < MAX; i++)
		tree[i][1] = tree[i][2] = INF, tree[i][0] = -INF;
	int n, s, l;
	cin >> n >> s >> l;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		update(i, i, 1, n, 1, num, 0);
		update(i, i, 1, n, 1, num, 1);
	}

	int i = n, j = n;
	while(i > 0 && j > 0){
		
		if(j - i  + 1 < l){
			i--;
			continue;
		}
		if(query(i, j, 1, n, 1, 0) - query(i, j, 1, n, 1, 1) > s)
			j--;
		else{
			if(j + 1 > n)
				update(i, i, 1, n, 1, 1, 2);
			else{
				int	ans1 = query(i+l, j+1, 1, n, 1, 2);
				if(ans1 == INF){
					i--;
					continue;
				}
				else
					update(i, i, 1, n, 1, ans1+1, 2);
			}
			
			i--;
		}
	}
	int ans = query(1, 1, 1, n, 1, 2);
	if(ans == INF)
		ans = -1;
	cout << ans << endl;
}#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>
#define MAX 800000
#define INF 1000010000
#define ll long long
using namespace std;
 
ll tree[MAX][3];


void update(ll i, ll j, ll l, ll r, ll n, ll k, int p)
{
    if(l >= i && r <= j)
    {
    	if(p == 0)
        	tree[n][p] = max(tree[n][p], k); // update current
        else 
        	tree[n][p] = min(tree[n][p], k); // update current
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k, p);
    update(i, j, middle + 1, r, 2*n + 1, k, p);
    if(p == 0)
    	tree[n][p] = max(tree[2*n][p] , tree[2*n + 1][p]); // update current
    else
    	tree[n][p] = min(tree[2*n][p] , tree[2*n + 1][p]); // update current
    
 
}
ll query(ll i, ll j, ll l, ll r, ll n, ll p)
{
    if(r < i || l > j){
        if(p == 0)
        	return -INF;
        else return INF;
    }
    if(l >= i && r <= j)
        return (ll) tree[n][p];

    ll middle = (l + r) / 2;
    if(p == 0)
    	return max(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
    else
    	return min(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
}


int main(){
	ios::sync_with_stdio( false );
	for(int i = 0; i < MAX; i++)
		tree[i][1] = tree[i][2] = INF, tree[i][0] = -INF;
	int n, s, l;
	cin >> n >> s >> l;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		update(i, i, 1, n, 1, num, 0);
		update(i, i, 1, n, 1, num, 1);
	}

	int i = n, j = n;
	while(i > 0 && j > 0){
		
		if(j - i  + 1 < l){
			i--;
			continue;
		}
		if(query(i, j, 1, n, 1, 0) - query(i, j, 1, n, 1, 1) > s)
			j--;
		else{
			if(j + 1 > n)
				update(i, i, 1, n, 1, 1, 2);
			else{
				int	ans1 = query(i+l, j+1, 1, n, 1, 2);
				if(ans1 == INF){
					i--;
					continue;
				}
				else
					update(i, i, 1, n, 1, ans1+1, 2);
			}
			
			i--;
		}
	}
	int ans = query(1, 1, 1, n, 1, 2);
	if(ans == INF)
		ans = -1;
	cout << ans << endl;
}#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>
#define MAX 800000
#define INF 1000010000
#define ll long long
using namespace std;
 
ll tree[MAX][3];


void update(ll i, ll j, ll l, ll r, ll n, ll k, int p)
{
    if(l >= i && r <= j)
    {
    	if(p == 0)
        	tree[n][p] = max(tree[n][p], k); // update current
        else 
        	tree[n][p] = min(tree[n][p], k); // update current
        return ;
    }
    if(r < i || l > j)
        return ;
    
    ll middle = (l + r) / 2;
    update(i, j, l, middle, 2*n, k, p);
    update(i, j, middle + 1, r, 2*n + 1, k, p);
    if(p == 0)
    	tree[n][p] = max(tree[2*n][p] , tree[2*n + 1][p]); // update current
    else
    	tree[n][p] = min(tree[2*n][p] , tree[2*n + 1][p]); // update current
    
 
}
ll query(ll i, ll j, ll l, ll r, ll n, ll p)
{
    if(r < i || l > j){
        if(p == 0)
        	return -INF;
        else return INF;
    }
    if(l >= i && r <= j)
        return (ll) tree[n][p];

    ll middle = (l + r) / 2;
    if(p == 0)
    	return max(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
    else
    	return min(query(i, j, l, middle, 2*n, p), query(i, j, middle + 1, r, 2*n + 1, p) ); // return according to the sons
}


int main(){
	ios::sync_with_stdio( false );
	for(int i = 0; i < MAX; i++)
		tree[i][1] = tree[i][2] = INF, tree[i][0] = -INF;
	int n, s, l;
	cin >> n >> s >> l;
	for(int i = 1; i <= n; i++){
		int num;
		cin >> num;
		update(i, i, 1, n, 1, num, 0);
		update(i, i, 1, n, 1, num, 1);
	}

	int i = n, j = n;
	while(i > 0 && j > 0){
		
		if(j - i  + 1 < l){
			i--;
			continue;
		}
		if(query(i, j, 1, n, 1, 0) - query(i, j, 1, n, 1, 1) > s)
			j--;
		else{
			if(j + 1 > n)
				update(i, i, 1, n, 1, 1, 2);
			else{
				int	ans1 = query(i+l, j+1, 1, n, 1, 2);
				if(ans1 == INF){
					i--;
					continue;
				}
				else
					update(i, i, 1, n, 1, ans1+1, 2);
			}
			
			i--;
		}
	}
	int ans = query(1, 1, 1, n, 1, 2);
	if(ans == INF)
		ans = -1;
	cout << ans << endl;
}