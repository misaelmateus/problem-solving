#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;	
	while(t--) {
		int x, y,
			s, t;
		set<pair<int,int>> points;
		cin >> x >> y >> s >> t;
		vector<pair<int,int>> stamp;
		for( int i = 0; i < x; i++ )
			for( int j = 0; j < y; j++ ) {
				char q;
				scanf(" %c", &q);
				if( q == 'x' ) points.insert({i,j});
			}
		bool first = true;
		for( int i = 0; i < s; i++ )
			for( int j = 0; j < t; j++ ) {
				char q;
				cin >> q;
				if( q == 'x' ) 
					if( !first ) stamp.push_back({i - stamp.back().first, j - stamp.back().second}); 
					else { stamp.push_back({i,j}); first = false; }
			}
		bool notOkay = false;
		while( !points.empty() ) {
			pair<int, int> a = *points.begin();
			points.erase(a);
			for( int i = 1; i < stamp.size(); i++ ) {
				a.first += stamp[i].first;
				a.second += stamp[i].second;
				//cout << a.first << " " << a.second << endl;
				if( !points.count(a) ) { cout << "NIE\n"; notOkay = true; break; }
				points.erase(a);
			}
			if( notOkay ) break;
		}
		if( !notOkay )
			cout << "ANO\n";
	}
}