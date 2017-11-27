#include<bits/stdc++.h>

using namespace std;
 
const int pi = acos(-1.0);

const int INF = 1e9;
 
struct pt;
typedef pair<pt, pt> line;
typedef vector<pt> polygon;
 
int cmp(int a, int b = 0){
    if(a == b) return 0;
    return a > b ? 1 : -1;
}
 
//estrutura que representa um ponto
// ou um vetor dependendo da necessidade
struct pt{
    int x, y;
    int i;     
    pt(int x = 0, int y = 0) : x(x), y(y) {}
     
    int length() { return sqrt(x*x + y*y); }
    int length2() { return x*x + y*y; }
     
    pt normalize(){
        return (*this)/length();
    }
     
    pt operator - (pt p){ return pt(x - p.x, y - p.y); }
    pt operator + (pt p){ return pt(x + p.x, y + p.y); }
    pt operator * (int k){ return pt(x * k, y * k); }
    pt operator / (int k){ return pt(x / k, y / k); }
    bool operator < (const pt& p) const{
        if(x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator == (const pt p){
        return ( x == p.x && y == p.y );
    }
    bool operator != (const pt p){
        return ( x != p.x || y != p.y );
    }
};
 
////////////////////
// Funcoes basicas
 
int dist(pt a, pt b){ return (a - b).length2(); }
int dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
int cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
int signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c)); }
int side_sign(pt a, pt b, pt c){ return cmp(signed_area(a, b, c)); }
pt refer;
bool cmp_angle(pt p1, pt p2){
    int det = signed_area(refer, p1, p2); 
    if(det == 0){
        return (dist(refer, p1) >= dist(refer, p2));
    }
    return (det > 0);
}

void convex_hull(polygon in, polygon& hull){
    hull.clear();
     
    if(in.size() < 3){ hull = in; return; }
     
    int pos = 0;
    for(int i = 1; i < in.size(); i++) if(in[i] < in[pos]) pos = i;
    swap(in[0], in[pos]);
    refer = in[0];
     
    sort(in.begin() + 1, in.end(), cmp_angle);
    in.resize(unique(in.begin(), in.end()) - in.begin());
     
    hull.push_back(in[0]); hull.push_back(in[1]);
     
    in.push_back(in[0]); //isto evita pontos colineares no final do poligono
    for(int i = 2; i < in.size(); ){
        //cout << in[i].i << endl;
        if(hull.size() > 2 && side_sign(hull[hull.size() - 2], hull[hull.size() - 1], in[i]) <= 0){
            hull.pop_back();
        }
        else hull.push_back(in[i++]);
    }
    hull.pop_back();
}
 
int main(){
    int n;
    cin >> n;
    polygon p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].i = i+1;
    }

    string s;
    cin >> s;
    polygon hull;
    convex_hull(p, hull);
    pt a = hull[0];
    cout << a.i << " ";
    int flag1;
    for(int i = 0; i < s.size(); i++){
        pt next_point;
        if(s[i] == 'R')
            flag1 =0;
        else flag1 = 1;
        int j;
        for(j = 0; hull[j] != a; j++);
        if(flag1)
            next_point = hull[(j + 1) % hull.size()];
        else{
            next_point = hull[(j-1 + hull.size()) % hull.size()];
        }

        cout << next_point.i << " ";
        for(j = 0; p[j] != a; j++);
        p.erase(p.begin() + j);
        if(p.size())
            convex_hull(p, hull);
        a = next_point;
    }
    if(p[0] != a)
        cout << p[0].i << " ";
    else cout << p[1].i << " "; 
}