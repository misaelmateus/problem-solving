#include<bits/stdc++.h>

typedef double T;
struct pt {
	T x,y;
	pt operator+(pt p) {return {x+p.x, y+p.y};}
	pt operator-(pt p) {return {x-p.x, y-p.y};}
	pt operator*(T d) {return {x*d, y*d};}
	pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
	
	bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
	bool operator!=(pt a, pt b) {return !(a == b);}

	T sq(pt p) {return p.x*p.x + p.y*p.y;}
	double abs(pt p) {return sqrt(sq(p));}

	ostream& operator<<(ostream& os, pt p) {
		return os << "("<< p.x << "," << p.y << ")";
	}
};

// rotate 90º
pt perp(pt p) {return {-p.y, p.x};}

pt rot(pt p, double a) {
	return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}

// anti-horario: > 0
// horario : < 0
// colinear: = 0
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}

pt scale(pt c, double factor, pt p) {
	return c + (p-c)*factor;
}

// angle in [0, PI]
double angle(pt v, pt w) {
	double cosTheta = dot(v,w) / abs(v) / abs(w);
	return acos(max(-1.0, min(1.0, cosTheta)));
}

bool isConvex(vector<pt> p) {
	bool hasPos=false, hasNeg=false;
	for (int i=0, n=p.size(); i<n; i++) {
		int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
		if (o > 0) hasPos = true;
		if (o < 0) hasNeg = true;
	}
	return !(hasPos && hasNeg);
}

bool half(pt p) { // true if in blue half
	assert(p.x != 0 || p.y != 0); // the argument of (0,0) is undefined
	return p.y > 0 || (p.y == 0 && p.x < 0);
}

// use when want to do polar starting in point v, v is the first in the polar sort
bool half(pt p, pt v){
	return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);

}
void polarSort(vector<pt> &v) {
	sort(v.begin(), v.end(), [](pt v, pt w) {
		return make_tuple(half(v), 0, sq(v)) <
	    	   make_tuple(half(w), cross(v,w), sq(w)); 
	});

	/* if want to do polar around point O do 
		return make_tuple(half(v-o), 0)) <
			   make_tuple(half(w-o), cross(v-o, w-o));
	*/
}


// Line
struct line {
	pt v; T c;
	// From direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// From equation ax+by=c
	line(T a, T b, T c) : v({b,-a}), c(c) {}
	// From points P and Q
	line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
	
	// - these work with T = int
	
	// positive if in the left side and negative if in the right side
	T side(pt p) {return cross(v,p)-c;}
	double dist(pt p) {return abs(side(p)) / abs(v);}
	double sqDist(pt p) {return side(p)*side(p) / (double)sq(v);}
	// line perpendicular to this line passes in point P
	line perpThrough(pt p) {return {p, p + perp(v)};}
	// compare two projections on a line, what comes before in direction v
	bool cmpProj(pt p, pt q) {
		return dot(v,p) < dot(v,q);
	}
	line translate(pt t) {return {v, c + cross(v,t)};}
	
	// - these require T = double
	line shiftLeft(double dist) {return {v, c + dist*abs(v)};}
	pt proj(pt p);
	pt refl(pt p);
};

bool inter(line l1, line l2, pt &out) {
	T d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating-point coordinates
	return true;
}






int main(){


	return 0;
}