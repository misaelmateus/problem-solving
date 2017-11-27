#include<bits/stdc++.h>
using namespace std;


const int N = 100100;
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
int main(){
	scanf("%s", x);
    int t = strlen(x);
    while(n < 2*t)
        n*= 2;
    f = vector <int> (t, 0);

    for(char c = 'a'; c <= 'c'; c++){
        
        a = vector <comp>(n, comp(0.0, 0.0));
        b = vector <comp>(n, comp(0.0, 0.0));
        for(int i = 0; i < t; i++)
            a[i].r = (int)(x[i] == c), b[t - i].r = (int)(x[i] == c);
        fft(a, false);
        fft(b, false);
        for(int i = 0; i < n; i++)
            a[i] = a[i] * b[i];
        fft(a, true);
        for(int i = t+1; i < 2*t; i++){
            f[i-t] += (int)(a[i].r + 0.5);
        }
    }
    int ma = 0;
    for(int i = 1; i < t; i++)
        ma = max(ma, f[i]);
    printf("%d\n", ma);
    int flag = 0;
    for(int i = 1; i < t; i++){
        if(f[i] != ma) continue;
        if(flag) printf(" ");
        printf("%d", i);
        flag = 1;
    }
    if(ma == 0)
        printf(" %d", t);
    printf("\n");
    return 0;
}