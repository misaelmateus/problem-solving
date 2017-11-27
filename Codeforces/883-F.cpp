//   Author : Misael Mateus 
//   Submission date: 2017-11-01 19:48:00
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> strs;
    while( n-- ) {
        string str, strf;
        cin >> str;

        for( int i = 0; str[i]; i++ ) {
            int qt = 0;
            switch( str[i] ) {
            case 'k':
                while( str[i+qt] == 'k' ) qt++;
                if( str[i+=qt] == 'h' ) strf += 'h';
                else {
                    i--;
                    while( qt-- ) strf += 'k';
                }
                break;
            case 'u':
                strf += "oo";
                break;
            default:
                strf += str[i];
            }
        }
        strs.insert(strf);
    }
    cout << strs.size() << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> strs;
    while( n-- ) {
        string str, strf;
        cin >> str;

        for( int i = 0; str[i]; i++ ) {
            int qt = 0;
            switch( str[i] ) {
            case 'k':
                while( str[i+qt] == 'k' ) qt++;
                if( str[i+=qt] == 'h' ) strf += 'h';
                else {
                    i--;
                    while( qt-- ) strf += 'k';
                }
                break;
            case 'u':
                strf += "oo";
                break;
            default:
                strf += str[i];
            }
        }
        strs.insert(strf);
    }
    cout << strs.size() << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> strs;
    while( n-- ) {
        string str, strf;
        cin >> str;

        for( int i = 0; str[i]; i++ ) {
            int qt = 0;
            switch( str[i] ) {
            case 'k':
                while( str[i+qt] == 'k' ) qt++;
                if( str[i+=qt] == 'h' ) strf += 'h';
                else {
                    i--;
                    while( qt-- ) strf += 'k';
                }
                break;
            case 'u':
                strf += "oo";
                break;
            default:
                strf += str[i];
            }
        }
        strs.insert(strf);
    }
    cout << strs.size() << endl;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> strs;
    while( n-- ) {
        string str, strf;
        cin >> str;

        for( int i = 0; str[i]; i++ ) {
            int qt = 0;
            switch( str[i] ) {
            case 'k':
                while( str[i+qt] == 'k' ) qt++;
                if( str[i+=qt] == 'h' ) strf += 'h';
                else {
                    i--;
                    while( qt-- ) strf += 'k';
                }
                break;
            case 'u':
                strf += "oo";
                break;
            default:
                strf += str[i];
            }
        }
        strs.insert(strf);
    }
    cout << strs.size() << endl;
}
