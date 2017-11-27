#include <bits/stdc++.h>

using namespace std;

int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

	ifstream in("king.in");
    cin.rdbuf(in.rdbuf());

    ofstream out("king.out");
    cout.rdbuf(out.rdbuf());

	vector< pair< long long, int > > dates;
	int year, month, day;
	cin >> day >> month >> year;
	for( int i = 1; i < 12; i++ )
		daysMonth[i] += daysMonth[i-1];
	long long days = year*365 + daysMonth[month-1] + day;
	int n;
	cin >> n;
	for( int i = 0; i < n; i++ ) {
		int a, b, c;
		cin >> a >> b >> c;
		dates.push_back({c*365 + daysMonth[b-1] + a, i});
	}
	sort(dates.begin(), dates.end());

	while( !dates.empty() && days - dates.back().first < 18*365 ) {
		//cout << dates.back().second << " " << days - 18*365 - dates.back().first << endl;
		dates.pop_back();
	}

	if( dates.empty() ) cout << -1 << endl;
	else cout << dates.back().second + 1 << endl;

}