#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;
 
struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;
 
//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
struct pt{
    ll x, y;
     
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
     
     
    pt operator - (pt p){ return pt(x - p.x, y - p.y); }
    pt operator + (pt p){ return pt(x + p.x, y + p.y); }
    pt operator * (double k){ return pt(x * k, y * k); }
    pt operator / (double k){ return pt(x / k, y / k); }
    bool operator < (const pt& p) const{
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p){
        return (x == p.x && y == p.y);
    }
};

ll cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
ll signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c)); }

int main(){
	ios::sync_with_stdio(false);	
	int N;
	while(cin >> N){
		vector<pt> p(N);
		for(int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
		ll area_total = 0;
		for(int i = 2; i < N; i++)
			area_total += abs(signed_area(p[0], p[i], p[i-1]));
		int j = 1;
		ll area = 0LL;
		pair<ll, ll> ans = {0LL, 0LL};
		for(int i = 0; i < N; i++){
			while(area < area_total - area){
				j = (j + 1) % N;
				area += abs(signed_area(p[i], p[j], p[(j + N - 1)  % N]));
			}
			if(area_total - area < area - abs(signed_area(p[i], p[j], p[(j + N - 1)  % N])) ){
				area -= abs(signed_area(p[i], p[j], p[(j + N - 1)  % N]));
				j = (j - 1 + N) % N;
				ans = max(ans, {area_total - area, area});
			}
			else ans = max(ans, {area, area_total - area});
			area -= abs(signed_area(p[i], p[(i+1) % N], p[j]));
		}
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}