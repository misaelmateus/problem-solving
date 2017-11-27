//   Author : Misael Mateus 
//   Submission date: 2017-04-16 22:23:20
#include<bits/stdc++.h>
using namespace std;
int main(){
	int soma = 0;
	int me = 1000000;
	int num, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		if(num > 0)
			soma += num;
		if(abs(num) % 2 != 0)
			me = min(me, abs(num));
	}
	if(soma % 2 == 0)
		soma -= me;
	printf("%d\n", soma);

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int soma = 0;
	int me = 1000000;
	int num, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		if(num > 0)
			soma += num;
		if(abs(num) % 2 != 0)
			me = min(me, abs(num));
	}
	if(soma % 2 == 0)
		soma -= me;
	printf("%d\n", soma);

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int soma = 0;
	int me = 1000000;
	int num, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		if(num > 0)
			soma += num;
		if(abs(num) % 2 != 0)
			me = min(me, abs(num));
	}
	if(soma % 2 == 0)
		soma -= me;
	printf("%d\n", soma);

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int soma = 0;
	int me = 1000000;
	int num, n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num);
		if(num > 0)
			soma += num;
		if(abs(num) % 2 != 0)
			me = min(me, abs(num));
	}
	if(soma % 2 == 0)
		soma -= me;
	printf("%d\n", soma);

	return 0;
}