//   Author : Misael Mateus 
//   Submission date: 2017-09-16 23:18:48
#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); a < (c); a++)
#define rep(a, b) fr(a, 0, b);

using namespace std;
int main(){
	int k;
	scanf("%d", &k);
	int ans = 1e9;
	for(int i = 1; i <= k; i++){
		int j = k/i;
		if(j*i < k) j++;
		ans = min(ans, 2*(i + j));
	}

	printf("%d\n", ans);
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); a < (c); a++)
#define rep(a, b) fr(a, 0, b);

using namespace std;
int main(){
	int k;
	scanf("%d", &k);
	int ans = 1e9;
	for(int i = 1; i <= k; i++){
		int j = k/i;
		if(j*i < k) j++;
		ans = min(ans, 2*(i + j));
	}

	printf("%d\n", ans);
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); a < (c); a++)
#define rep(a, b) fr(a, 0, b);

using namespace std;
int main(){
	int k;
	scanf("%d", &k);
	int ans = 1e9;
	for(int i = 1; i <= k; i++){
		int j = k/i;
		if(j*i < k) j++;
		ans = min(ans, 2*(i + j));
	}

	printf("%d\n", ans);
}#include<bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define fr(a, b, c) for(int a = (b); a < (c); a++)
#define rep(a, b) fr(a, 0, b);

using namespace std;
int main(){
	int k;
	scanf("%d", &k);
	int ans = 1e9;
	for(int i = 1; i <= k; i++){
		int j = k/i;
		if(j*i < k) j++;
		ans = min(ans, 2*(i + j));
	}

	printf("%d\n", ans);
}