#include <cstdio>
#include <algorithm>

using namespace std;



int ans(int W, int H, int w, int h ){
	if(W < w || H < h) return 1e9;
	if(W == w){
		if(H == h) return 0;
		if(2*h >= H) return 1;
		else return 1 + ans(w, (H / 2) + (H & 1 == 1), w, h);
	}
	else{
		if(2*w >= W)
			return 1 + ans(w, H, w, h);
		else
			return 1 + ans((W/2) + (W & 1 == 1), H, w, h);
	}
}
int main() {

	int W, H, w, h;
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	scanf("%d %d %d %d", &W, &H, &w, &h);
	int a = min(ans(W, H, w, h), ans(H, W, w, h));
	if(a == 1e9)
		printf("-1\n");
	else printf("%d\n", a);
	return 0;
}