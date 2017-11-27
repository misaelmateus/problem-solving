//   Author : Misael Mateus 
//   Submission date: 2017-11-01 20:20:57
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000;

int n, m, w = 0, c[26];
bool mark[N][26], valid[N];
char str[N];
string a[N];

string read() {
    scanf("%s", str);
    return str;
}

int main() {

    scanf("%d", &n);

    string s = read();

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        a[i] = read();
        valid[i] = true;
        memset(mark[i], false, sizeof mark[i]);
        for (int j = 0; j < n; j++) {
            if (s[j] != '*' && a[i][j] != s[j]) {
                valid[i] = false;
                break;
            }
            if (s[j] != '*') {
                mark[i][s[j] - 'a'] = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (s[j] == '*' && mark[i][a[i][j] - 'a']) {
                valid[i] = false;
                break;
            }
        }
        if (!valid[i]) {
            continue;
        }
        memset(mark[i], false, sizeof mark[i]);
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') {
                mark[i][a[i][j] - 'a'] = true;
            }
        }
        w++;
        for (int j = 0; j < 26; j++) {
            if (mark[i][j]) {
                c[j]++;
            }
        }
    }

    int res = 0;

    for (int i = 0; i < 26; i++) {
        //printf("dbg %d %d\n", w, c[i]);
        if (c[i] == w) {
            res++;
        }
    }

    printf("%d\n", res);

    return 0;

}
