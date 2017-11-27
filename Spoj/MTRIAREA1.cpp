#include<bits/stdc++.h>
#define MAXN 50010

using namespace std;
 
inline int readInt()
{
    bool minus = false;
    register int result = 0;
    register char ch = getchar_unlocked();
    while (true)
    {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break ;
        ch = getchar_unlocked();
    }
    if (ch == '-') minus = true; 
    else result = ch-'0';
    while (true)
    {
        ch = getchar_unlocked();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus) return -result;
    else return result;
}
 

const int INF = 1e9;
 
struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;

//funcao de comparacao
int cmp(int a, int b = 0){
    if(a == b) return 0;
    return a > b ? 1 : -1;
}

struct pt{
    int x, y;
    int id;
    pt(int x = 0, int y = 0) : x(x), y(y) {}
     
    double length() { return sqrt(x*x + y*y); }
    int length2() { return x*x + y*y; }
     
    pt normalize(){
        return (*this)/length();
    }
     
    pt operator - (pt p){ return pt(x - p.x, y - p.y); }
    pt operator + (pt p){ return pt(x + p.x, y + p.y); }
    pt operator * (int k){ return pt(x * k, y * k); }
    pt operator / (int k){ return pt(x / k, y / k); }
    bool operator < (const pt& p) const{
        if(x == p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p){
        return ( x == p.x && y == p.y);
    }
};
 

int dist(pt a, pt b){ return (a - b).length(); }
int dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
int cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
int signed_area_plus_2(pt a, pt b, pt c){ return cross((a-c),(b-c)); }

int side_sign(pt a, pt b, pt c){ return cmp(signed_area_plus_2(a, b, c)); }

void convex_hull_2(polygon P, polygon& hull) {
    hull.clear();
     
    // Sort points lexicographically

    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());
     
    // Buiint lower hull
    for (int i = 0; i < P.size(); i ++) {
        while (hull.size() >= 2 && side_sign(hull[hull.size() - 2], hull[hull.size() - 1], P[i]) <= 0)
            hull.pop_back();
        hull.push_back(P[i]);
    };
  
    // Buiint upper hull
    for (int i = P.size()-2, t = hull.size() + 1; i >= 0; i --) {
        while (hull.size() >= t && side_sign(hull[hull.size()-2], hull[hull.size()-1], P[i]) <= 0)
            hull.pop_back();
        hull.push_back(P[i]);
    };
}

polygon hull;

int calc_area(int a, int b){
	int i = a, j = b;
	while(j - i > 2){
		int i1 = i + (j - i)/3;
		int j1 = j - (j - i)/3;
		int area1 = abs(signed_area_plus_2(hull[a], hull[b], hull[i1]));
		int area2 = abs(signed_area_plus_2(hull[a], hull[b], hull[j1]));
		if(area1 > area2)
			j = j1;
		else i = i1;
	}
	int area = 0;
	for(int l = i; l <= j; l++){
		area = max(abs(signed_area_plus_2(hull[a], hull[b], hull[l])), area);
	}
	return area;
}

int main(){
	int n;
	while((n = readInt()) && n+1){
		polygon p(n);
		for(int i = 0; i < n; i++){
			p[i].x = readInt();
			p[i].y = readInt();
		}

		convex_hull_2(p, hull);
		int t = hull.size();
		for(int i = 0; i < t; i++)
			hull.push_back(hull[i]);
		int ans = 0;
		int a = 0, b = 1, c = 2;
        int ba = 0, bb = 1, bc = 2;
        for(; a < t; a++){
            if(a == b) b++;
            if(b == c) c++;
            while(true){
                while(c < 2*t -1 && abs(signed_area_plus_2(hull[a], hull[b], hull[c])) <= abs(signed_area_plus_2(hull[a], hull[b], hull[c+1])) )
                    c++;
                if(b < 2*t-1 && abs(signed_area_plus_2(hull[a], hull[b], hull[c])) <= abs(signed_area_plus_2(hull[a], hull[b+1], hull[c])))
                    b++;
                else break;
            }
            if(abs(signed_area_plus_2(hull[a], hull[b], hull[c])) > abs(signed_area_plus_2(hull[ba], hull[bb], hull[bc])))
                ba = a, bb = b, bc = c;
        }
        ans = abs(signed_area_plus_2(hull[ba], hull[bb], hull[bc]));
        a = ans/2;
        b = (ans % 2)*50;
        printf("%d.%02d\n", a, b);
	}

}