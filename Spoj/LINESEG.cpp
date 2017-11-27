#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int a1, b1, c1, d1;
		int a2, b2, c2, d2;
		scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
		scanf("%d %d %d %d", &a2, &b2, &c2, &d2);
		if(a1 == c1 && b1 > d1) swap(b1, d1);
		if(b1 == d1 && a1 > c1) swap(a1, c1);

		if(a2 == c2 && b2 > d2) swap(b2, d2);
		if(b2 == d2 && a2 > c2) swap(a2, c2);
		int flag;
		if(a1 == c1 && a2 == c2){
			if(a1 != b1 || (b1 < a2 || b2 < a1))
				flag = 0;
			else if(b1 == a2 || b2 == a1)
				flag = 1;
			else flag = 2;
		}
		if(b1 == d1 && b2 == d2){
			if(a1 != b1 || (b1 < a2 || b2 < a1))
				flag = 0;
			else if(b1 == a2 || b2 == a1)
				flag = 1;
			else flag = 2;
		}
	}	
}