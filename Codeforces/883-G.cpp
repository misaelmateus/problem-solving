//   Author : Misael Mateus 
//   Submission date: 2017-11-01 21:54:01
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, s, t[N], u[N], v[N];
char ans[N];
bool seen[N];
vector <int> q;
vector <int> g[N];

int main() {

  while (scanf("%d %d %d", &n, &m, &s) != EOF) {
    s--;
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &t[i], &u[i], &v[i]);
      u[i]--;
      v[i]--;
      g[u[i]].push_back(i);
      g[v[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '-';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          int tmp = u[id] + v[id] - now;
          if (!seen[tmp]) {
            ans[id] = (u[id] == now) ? '+' : '-';
            seen[tmp] = true;
            q.push_back(tmp);
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '?';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          //int tmp = u[id] + v[id] - now;
          if (ans[id] == '?' && u[id] == now) {
            ans[id] = '-';
          } else if (ans[id] == '?' && v[id] == now) {
            ans[id] = '+';
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (ans[i] == '?') {
        ans[i] = '+';
      }
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  return 0;

}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, s, t[N], u[N], v[N];
char ans[N];
bool seen[N];
vector <int> q;
vector <int> g[N];

int main() {

  while (scanf("%d %d %d", &n, &m, &s) != EOF) {
    s--;
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &t[i], &u[i], &v[i]);
      u[i]--;
      v[i]--;
      g[u[i]].push_back(i);
      g[v[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '-';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          int tmp = u[id] + v[id] - now;
          if (!seen[tmp]) {
            ans[id] = (u[id] == now) ? '+' : '-';
            seen[tmp] = true;
            q.push_back(tmp);
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '?';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          //int tmp = u[id] + v[id] - now;
          if (ans[id] == '?' && u[id] == now) {
            ans[id] = '-';
          } else if (ans[id] == '?' && v[id] == now) {
            ans[id] = '+';
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (ans[i] == '?') {
        ans[i] = '+';
      }
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  return 0;

}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, s, t[N], u[N], v[N];
char ans[N];
bool seen[N];
vector <int> q;
vector <int> g[N];

int main() {

  while (scanf("%d %d %d", &n, &m, &s) != EOF) {
    s--;
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &t[i], &u[i], &v[i]);
      u[i]--;
      v[i]--;
      g[u[i]].push_back(i);
      g[v[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '-';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          int tmp = u[id] + v[id] - now;
          if (!seen[tmp]) {
            ans[id] = (u[id] == now) ? '+' : '-';
            seen[tmp] = true;
            q.push_back(tmp);
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '?';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          //int tmp = u[id] + v[id] - now;
          if (ans[id] == '?' && u[id] == now) {
            ans[id] = '-';
          } else if (ans[id] == '?' && v[id] == now) {
            ans[id] = '+';
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (ans[i] == '?') {
        ans[i] = '+';
      }
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  return 0;

}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 400010;

int n, m, s, t[N], u[N], v[N];
char ans[N];
bool seen[N];
vector <int> q;
vector <int> g[N];

int main() {

  while (scanf("%d %d %d", &n, &m, &s) != EOF) {
    s--;
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &t[i], &u[i], &v[i]);
      u[i]--;
      v[i]--;
      g[u[i]].push_back(i);
      g[v[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '-';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          int tmp = u[id] + v[id] - now;
          if (!seen[tmp]) {
            ans[id] = (u[id] == now) ? '+' : '-';
            seen[tmp] = true;
            q.push_back(tmp);
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      seen[i] = false;
    }
    for (int i = 0; i < m; i++) {
      ans[i] = '?';
    }
    seen[s] = true;
    q.push_back(s);
    for (int i = 0; i < (int) q.size(); i++) {
      int now = q[i];
      for (int j = 0; j < (int) g[now].size(); j++) {
        int id = g[now][j];
        if (t[id] == 1 && u[id] == now) {
          int tmp = v[id];
          if (!seen[tmp]) {
            seen[tmp] = true;
            q.push_back(tmp);
          }
        } else if (t[id] == 2) {
          //int tmp = u[id] + v[id] - now;
          if (ans[id] == '?' && u[id] == now) {
            ans[id] = '-';
          } else if (ans[id] == '?' && v[id] == now) {
            ans[id] = '+';
          }
        }
      }
    }
    printf("%d\n", (int) q.size());
    for (int i = 0; i < m; i++) {
      if (ans[i] == '?') {
        ans[i] = '+';
      }
      if (t[i] == 2) {
        printf("%c", ans[i]);
      }
    }
    puts("");
    q.clear();
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
  }

  return 0;

}
