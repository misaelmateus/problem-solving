//   Author : Misael Mateus 
//   Submission date: 2017-06-22 16:08:41
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int g[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	}
	int ans = 100000000;
	vector<int> row_ans(n), col_ans(m);
	for(int i = 0; i <= 500; i++){
		vector<int> row(n, 0), col(m, 0);
		int j, cont = 0;
		
		cont = row[0] = i;

		for(j = 0 ; j < m; j++){
			col[j] = g[0][j] - row[0];
			cont += col[j];
			if(col[j] < 0) break;
		}
		if(j < m) continue;

		for(j = 1; j < n; j++){
			row[j] = g[j][0] - col[0];
			cont += row[j];
			if(row[j] < 0) break;
			int l;
			for(l = 1; l < m; l++)
				if(row[j] != g[j][l] - col[l]) break;
			if(l < m)
				break;
		}
		if(j < n || cont >= ans) continue;

		ans = cont;
		row_ans = row, col_ans = col;

	}

	if(ans == 100000000) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		while(row_ans[i]--)
			cout << "row " << i+1 << endl;
	}
	for(int i = 0; i < m; i++){
		while(col_ans[i]--)
			cout << "col " << i+1 << endl;
	}

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int g[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	}
	int ans = 100000000;
	vector<int> row_ans(n), col_ans(m);
	for(int i = 0; i <= 500; i++){
		vector<int> row(n, 0), col(m, 0);
		int j, cont = 0;
		
		cont = row[0] = i;

		for(j = 0 ; j < m; j++){
			col[j] = g[0][j] - row[0];
			cont += col[j];
			if(col[j] < 0) break;
		}
		if(j < m) continue;

		for(j = 1; j < n; j++){
			row[j] = g[j][0] - col[0];
			cont += row[j];
			if(row[j] < 0) break;
			int l;
			for(l = 1; l < m; l++)
				if(row[j] != g[j][l] - col[l]) break;
			if(l < m)
				break;
		}
		if(j < n || cont >= ans) continue;

		ans = cont;
		row_ans = row, col_ans = col;

	}

	if(ans == 100000000) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		while(row_ans[i]--)
			cout << "row " << i+1 << endl;
	}
	for(int i = 0; i < m; i++){
		while(col_ans[i]--)
			cout << "col " << i+1 << endl;
	}

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int g[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	}
	int ans = 100000000;
	vector<int> row_ans(n), col_ans(m);
	for(int i = 0; i <= 500; i++){
		vector<int> row(n, 0), col(m, 0);
		int j, cont = 0;
		
		cont = row[0] = i;

		for(j = 0 ; j < m; j++){
			col[j] = g[0][j] - row[0];
			cont += col[j];
			if(col[j] < 0) break;
		}
		if(j < m) continue;

		for(j = 1; j < n; j++){
			row[j] = g[j][0] - col[0];
			cont += row[j];
			if(row[j] < 0) break;
			int l;
			for(l = 1; l < m; l++)
				if(row[j] != g[j][l] - col[l]) break;
			if(l < m)
				break;
		}
		if(j < n || cont >= ans) continue;

		ans = cont;
		row_ans = row, col_ans = col;

	}

	if(ans == 100000000) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		while(row_ans[i]--)
			cout << "row " << i+1 << endl;
	}
	for(int i = 0; i < m; i++){
		while(col_ans[i]--)
			cout << "col " << i+1 << endl;
	}

	return 0;
}#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	int g[n][m];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	}
	int ans = 100000000;
	vector<int> row_ans(n), col_ans(m);
	for(int i = 0; i <= 500; i++){
		vector<int> row(n, 0), col(m, 0);
		int j, cont = 0;
		
		cont = row[0] = i;

		for(j = 0 ; j < m; j++){
			col[j] = g[0][j] - row[0];
			cont += col[j];
			if(col[j] < 0) break;
		}
		if(j < m) continue;

		for(j = 1; j < n; j++){
			row[j] = g[j][0] - col[0];
			cont += row[j];
			if(row[j] < 0) break;
			int l;
			for(l = 1; l < m; l++)
				if(row[j] != g[j][l] - col[l]) break;
			if(l < m)
				break;
		}
		if(j < n || cont >= ans) continue;

		ans = cont;
		row_ans = row, col_ans = col;

	}

	if(ans == 100000000) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		while(row_ans[i]--)
			cout << "row " << i+1 << endl;
	}
	for(int i = 0; i < m; i++){
		while(col_ans[i]--)
			cout << "col " << i+1 << endl;
	}

	return 0;
}