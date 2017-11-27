//   Author : Misael Mateus 
//   Submission date: 2017-09-25 15:46:57
#include<bits/stdc++.h>
using namespace std;
string s;
int cont[30];

int test(int i, int j){
	if(i > j) return 0;
	memset(cont, 0, sizeof(cont));
	for(int l = i; l <= j; l++){
		cont[s[l] - 'a'] ++;
	}
	int ans = 0;
	for(int l = 0; l < 30; l++)
		ans += (cont[l] != 0);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	int i = 0;
	int ans = 0;
	for(int j = 0; j < n; j++){
		if(s[j] >= 'A' && s[j] <= 'Z'){
			ans = max(ans, test(i, j-1));
			i = j+1;
		}
		else if(j == n-1){
			ans = max(ans, test(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}#include<bits/stdc++.h>
using namespace std;
string s;
int cont[30];

int test(int i, int j){
	if(i > j) return 0;
	memset(cont, 0, sizeof(cont));
	for(int l = i; l <= j; l++){
		cont[s[l] - 'a'] ++;
	}
	int ans = 0;
	for(int l = 0; l < 30; l++)
		ans += (cont[l] != 0);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	int i = 0;
	int ans = 0;
	for(int j = 0; j < n; j++){
		if(s[j] >= 'A' && s[j] <= 'Z'){
			ans = max(ans, test(i, j-1));
			i = j+1;
		}
		else if(j == n-1){
			ans = max(ans, test(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}#include<bits/stdc++.h>
using namespace std;
string s;
int cont[30];

int test(int i, int j){
	if(i > j) return 0;
	memset(cont, 0, sizeof(cont));
	for(int l = i; l <= j; l++){
		cont[s[l] - 'a'] ++;
	}
	int ans = 0;
	for(int l = 0; l < 30; l++)
		ans += (cont[l] != 0);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	int i = 0;
	int ans = 0;
	for(int j = 0; j < n; j++){
		if(s[j] >= 'A' && s[j] <= 'Z'){
			ans = max(ans, test(i, j-1));
			i = j+1;
		}
		else if(j == n-1){
			ans = max(ans, test(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}#include<bits/stdc++.h>
using namespace std;
string s;
int cont[30];

int test(int i, int j){
	if(i > j) return 0;
	memset(cont, 0, sizeof(cont));
	for(int l = i; l <= j; l++){
		cont[s[l] - 'a'] ++;
	}
	int ans = 0;
	for(int l = 0; l < 30; l++)
		ans += (cont[l] != 0);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	int i = 0;
	int ans = 0;
	for(int j = 0; j < n; j++){
		if(s[j] >= 'A' && s[j] <= 'Z'){
			ans = max(ans, test(i, j-1));
			i = j+1;
		}
		else if(j == n-1){
			ans = max(ans, test(i, j));
		}
	}
	cout << ans << "\n";
	return 0;
}