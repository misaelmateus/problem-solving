//   Author : Misael Mateus 
//   Submission date: 2017-05-21 16:50:49
#include<bits/stdc++.h>
using namespace std;
int n, k;
int search(int i, int j){
	if(i == j)
		return i;
	int middle = (i+j)/2;

	cout << "1 " << middle << " " << middle +1 << "\n";
	fflush(stdout);
	string s;
	cin >> s;
	if(s[0] == 'T'){
		return search(i, middle);
	}
	else
		return search(middle+1, j);
}
int first;
bool teste(int x){
	cout << "1 " << x << " " << first << "\n";
	fflush(stdout);
	string s;
	cin >> s;
	if(s[0] == 'T')
		return true;
	return false;

}
int main(){
	cin >> n >> k;

	first = search(1, n);
	if(first + 1 <= n){
		if(teste(first+1)){
			cout << "2 " << first << " " << first+1 << "\n";
			fflush(stdout);
			return 0;
		}
		else if(first + 2 <= n){
			int sec = search(first + 2, n);
			if(teste(sec)){
				cout << "2 " << first << " " << sec << "\n";
			fflush(stdout);
			return 0;
			}
		}


	}
	if(teste(first-1)){
		cout << "2 " << first << " " << first-1 << "\n";
		fflush(stdout);
		return 0;
	}
	int sec = search(1, first-2);
	cout << "2 " << first << " " << sec << "\n";
	fflush(stdout);
	return 0;


}