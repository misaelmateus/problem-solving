#include<bits/stdc++.h>
using namespace std;

const int N = 300100;
const double PI = acos(-1.0);

struct comp {
    double r;
    double i;
    comp(double x, double y) {
        r = x;
        i = y;
    }
    comp operator + (const comp &q) {
        return comp(r + q.r, i + q.i);
    }
    comp operator - (const comp &q) {
        return comp(r - q.r, i - q.i);
    }
    comp operator * (const comp &q) {
        return comp(r * q.r - i * q.i, r * q.i + i * q.r);
    }
};

int T, l, r, n = 1;
vector <int> f;
vector <comp> a, b;

void fft(vector <comp> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int k = n / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        j += k;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    for (int len = 2; len <= n; len *= 2) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        comp wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            comp w(1.0, 0.0);
            for (int j = 0; j < len / 2; j++) {
                comp u = a[i + j];
                comp v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w = w * wlen;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i].r /= n;
        }
    }
}
char x[N];
char y[N];
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
        int t;
		scanf("%d", &t);
        t++;
		n = 1;

		while(n < 2*t)
			n *= 2;
		a = vector <comp> (n, comp(0.0, 0.0));
		b = vector <comp> (n, comp(0.0, 0.0));
        int aux;
		for(int i = 0; i < t; i++){
            scanf("%d", &aux);
			a[i].r = aux;
		}
		for(int i = 0; i < t; i++){
            scanf("%d", &aux);
            b[i].r = aux;
        }

		fft(a, false);
		fft(b, false);
		for(int i = 0; i < a.size(); i++)
			a[i] = a[i]*b[i];
		fft(a, true);

		for(int i = 0; i < 2*t-1; i++){
            if(i) printf(" ");
			printf("%lld", (long long)(a[i].r + 0.5));
		}
		printf("\n");
	}
}