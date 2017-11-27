//   Author : Misael Mateus 
//   Submission date: 2016-10-07 14:49:26
#include<bits/stdc++.h>
#define TAM 130
#define INF 10000000
#define ii pair<int, int>
int res[TAM][TAM];
using namespace std;
vector<int> p;
int f;

void augment(int v, int min_edge){
    if(v == 0)
       f = min_edge;
    else{
       augment(p[v], min(res[p[v]][v], min_edge));
       res[p[v]][v] -= f;
       res[v][p[v]] += f;
    }

}        

int n;
int a[TAM], l[26] = {0};

int custo(int A, int b){

    if(b != n+27)
        return 0;
    return A - 26; 
}

int main(){
   string s;
   cin >> s;
   cin >> n;
   string m[n];
   
   for(int i = 0; i < n; i++)
       cin >> m[i] >> a[i];
   
   for(int i = 0; i < s.size(); i++)
       l[ s[i] - 'a']++;
   
   for(int i = 0; i < 26; i++)
       res[0][i+1] += l[i];
   
   for(int i = 0; i < 26; i++) {
       for(int j = 0; j < n; j++){
           for(int l = 0; l < m[j].size(); l++)
               if((int)(m[j][l] - 'a' ) == i)
                   res[i+1][j+27] += 1;
       }
   }
   
   for(int i = 0; i < n; i++){
       res[i+27][n+27] = a[i];
   }
   
   
	int mf = 0;
   while(1){
       priority_queue< ii, vector<ii>, greater<ii> > pq;
       vector<int> dist(n+28, INF);
       pq.push( {0, 0});
       p = vector<int>(TAM, -1);
       p[0] = 0;
       dist[0] = 0;
       while(!pq.empty()){
           ii atual = pq.top();
           pq.pop();
           int d = atual.first;
           int u = atual.second;
           for(int i = 0; i <= n+27; i++)
            if(res[u][i] > 0 && dist[i] > dist[u] + custo(u, i))
                dist[i] = dist[u] + custo(u, i), pq.push({dist[i], i}), p[i] = u;
       } 
       if(p[n+27] == -1)
           break;
       augment(n+27, INF);

   }
   int sum = -s.size();
   for(int i = 0; i < n; i++)
        mf += (i+1)*(res[n+27][i+27]), sum += res[n+27][i+27];
   cout << (sum ? -1 : mf )<< endl;
   
}
#include<bits/stdc++.h>
#define TAM 130
#define INF 10000000
#define ii pair<int, int>
int res[TAM][TAM];
using namespace std;
vector<int> p;
int f;

void augment(int v, int min_edge){
    if(v == 0)
       f = min_edge;
    else{
       augment(p[v], min(res[p[v]][v], min_edge));
       res[p[v]][v] -= f;
       res[v][p[v]] += f;
    }

}        

int n;
int a[TAM], l[26] = {0};

int custo(int A, int b){

    if(b != n+27)
        return 0;
    return A - 26; 
}

int main(){
   string s;
   cin >> s;
   cin >> n;
   string m[n];
   
   for(int i = 0; i < n; i++)
       cin >> m[i] >> a[i];
   
   for(int i = 0; i < s.size(); i++)
       l[ s[i] - 'a']++;
   
   for(int i = 0; i < 26; i++)
       res[0][i+1] += l[i];
   
   for(int i = 0; i < 26; i++) {
       for(int j = 0; j < n; j++){
           for(int l = 0; l < m[j].size(); l++)
               if((int)(m[j][l] - 'a' ) == i)
                   res[i+1][j+27] += 1;
       }
   }
   
   for(int i = 0; i < n; i++){
       res[i+27][n+27] = a[i];
   }
   
   
	int mf = 0;
   while(1){
       priority_queue< ii, vector<ii>, greater<ii> > pq;
       vector<int> dist(n+28, INF);
       pq.push( {0, 0});
       p = vector<int>(TAM, -1);
       p[0] = 0;
       dist[0] = 0;
       while(!pq.empty()){
           ii atual = pq.top();
           pq.pop();
           int d = atual.first;
           int u = atual.second;
           for(int i = 0; i <= n+27; i++)
            if(res[u][i] > 0 && dist[i] > dist[u] + custo(u, i))
                dist[i] = dist[u] + custo(u, i), pq.push({dist[i], i}), p[i] = u;
       } 
       if(p[n+27] == -1)
           break;
       augment(n+27, INF);

   }
   int sum = -s.size();
   for(int i = 0; i < n; i++)
        mf += (i+1)*(res[n+27][i+27]), sum += res[n+27][i+27];
   cout << (sum ? -1 : mf )<< endl;
   
}
#include<bits/stdc++.h>
#define TAM 130
#define INF 10000000
#define ii pair<int, int>
int res[TAM][TAM];
using namespace std;
vector<int> p;
int f;

void augment(int v, int min_edge){
    if(v == 0)
       f = min_edge;
    else{
       augment(p[v], min(res[p[v]][v], min_edge));
       res[p[v]][v] -= f;
       res[v][p[v]] += f;
    }

}        

int n;
int a[TAM], l[26] = {0};

int custo(int A, int b){

    if(b != n+27)
        return 0;
    return A - 26; 
}

int main(){
   string s;
   cin >> s;
   cin >> n;
   string m[n];
   
   for(int i = 0; i < n; i++)
       cin >> m[i] >> a[i];
   
   for(int i = 0; i < s.size(); i++)
       l[ s[i] - 'a']++;
   
   for(int i = 0; i < 26; i++)
       res[0][i+1] += l[i];
   
   for(int i = 0; i < 26; i++) {
       for(int j = 0; j < n; j++){
           for(int l = 0; l < m[j].size(); l++)
               if((int)(m[j][l] - 'a' ) == i)
                   res[i+1][j+27] += 1;
       }
   }
   
   for(int i = 0; i < n; i++){
       res[i+27][n+27] = a[i];
   }
   
   
	int mf = 0;
   while(1){
       priority_queue< ii, vector<ii>, greater<ii> > pq;
       vector<int> dist(n+28, INF);
       pq.push( {0, 0});
       p = vector<int>(TAM, -1);
       p[0] = 0;
       dist[0] = 0;
       while(!pq.empty()){
           ii atual = pq.top();
           pq.pop();
           int d = atual.first;
           int u = atual.second;
           for(int i = 0; i <= n+27; i++)
            if(res[u][i] > 0 && dist[i] > dist[u] + custo(u, i))
                dist[i] = dist[u] + custo(u, i), pq.push({dist[i], i}), p[i] = u;
       } 
       if(p[n+27] == -1)
           break;
       augment(n+27, INF);

   }
   int sum = -s.size();
   for(int i = 0; i < n; i++)
        mf += (i+1)*(res[n+27][i+27]), sum += res[n+27][i+27];
   cout << (sum ? -1 : mf )<< endl;
   
}
#include<bits/stdc++.h>
#define TAM 130
#define INF 10000000
#define ii pair<int, int>
int res[TAM][TAM];
using namespace std;
vector<int> p;
int f;

void augment(int v, int min_edge){
    if(v == 0)
       f = min_edge;
    else{
       augment(p[v], min(res[p[v]][v], min_edge));
       res[p[v]][v] -= f;
       res[v][p[v]] += f;
    }

}        

int n;
int a[TAM], l[26] = {0};

int custo(int A, int b){

    if(b != n+27)
        return 0;
    return A - 26; 
}

int main(){
   string s;
   cin >> s;
   cin >> n;
   string m[n];
   
   for(int i = 0; i < n; i++)
       cin >> m[i] >> a[i];
   
   for(int i = 0; i < s.size(); i++)
       l[ s[i] - 'a']++;
   
   for(int i = 0; i < 26; i++)
       res[0][i+1] += l[i];
   
   for(int i = 0; i < 26; i++) {
       for(int j = 0; j < n; j++){
           for(int l = 0; l < m[j].size(); l++)
               if((int)(m[j][l] - 'a' ) == i)
                   res[i+1][j+27] += 1;
       }
   }
   
   for(int i = 0; i < n; i++){
       res[i+27][n+27] = a[i];
   }
   
   
	int mf = 0;
   while(1){
       priority_queue< ii, vector<ii>, greater<ii> > pq;
       vector<int> dist(n+28, INF);
       pq.push( {0, 0});
       p = vector<int>(TAM, -1);
       p[0] = 0;
       dist[0] = 0;
       while(!pq.empty()){
           ii atual = pq.top();
           pq.pop();
           int d = atual.first;
           int u = atual.second;
           for(int i = 0; i <= n+27; i++)
            if(res[u][i] > 0 && dist[i] > dist[u] + custo(u, i))
                dist[i] = dist[u] + custo(u, i), pq.push({dist[i], i}), p[i] = u;
       } 
       if(p[n+27] == -1)
           break;
       augment(n+27, INF);

   }
   int sum = -s.size();
   for(int i = 0; i < n; i++)
        mf += (i+1)*(res[n+27][i+27]), sum += res[n+27][i+27];
   cout << (sum ? -1 : mf )<< endl;
   
}
