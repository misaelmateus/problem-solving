#include<bits/stdc++.h>
#define ld long double
using namespace std;
vector<ld> v;
ld ar(ld a, ld b, ld c){
	ld p = (a + b + c) / 2;
	return p * (p - a) * (p - b) * (p - c);
}

bool test(int x, int y, int z){
	if(v[x] + v[y] - v[z] > 0.00000000001)
		return true;
	return false;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		v = vector<ld>(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		ld area = (ld) (1LL << 60);
		for(int i = 0; i < n-2; i++)
			for(int j = i+1; j < n-1; j++){
				if(!test(i, j, j+1)) continue;
				ld a = ar(v[i], v[j], v[j+1]);
				int x = j+1, y = v.size();
				while(y - x > 1){
					int middle = (x + y) >> 1;
					if(test(i, j, middle))
						x = middle;
					else y = middle;
				}
				ld b = ar(v[i], v[j], v[x]);
				area = min(area, b);
				area = min(area, a);
			}
		if(area > (ld) (1LL << 57))
			cout << -1 << endl;
		else cout << fixed << setprecision(8) << sqrt(area) << endl;
	}
}	