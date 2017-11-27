//   Author : Misael Mateus 
//   Submission date: 2016-11-19 01:51:41
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ld l, v1, v2, C;
    int n, k;
    cin >> n >> l >> v1 >> v2 >> k;
    C = (ld)((int)(n/k) + (int)(n % k != 0));
    ld aux = ((C-1.)*v1)/v2 + ((C-1.)*(v2 - v1)*v1)/(v2*(v2+v1)) + 1.;
    ld x = l/aux;
    
    ld t = (x/v2) + (l-x)/v1;
    cout << fixed << setprecision(10) << t << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ld l, v1, v2, C;
    int n, k;
    cin >> n >> l >> v1 >> v2 >> k;
    C = (ld)((int)(n/k) + (int)(n % k != 0));
    ld aux = ((C-1.)*v1)/v2 + ((C-1.)*(v2 - v1)*v1)/(v2*(v2+v1)) + 1.;
    ld x = l/aux;
    
    ld t = (x/v2) + (l-x)/v1;
    cout << fixed << setprecision(10) << t << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ld l, v1, v2, C;
    int n, k;
    cin >> n >> l >> v1 >> v2 >> k;
    C = (ld)((int)(n/k) + (int)(n % k != 0));
    ld aux = ((C-1.)*v1)/v2 + ((C-1.)*(v2 - v1)*v1)/(v2*(v2+v1)) + 1.;
    ld x = l/aux;
    
    ld t = (x/v2) + (l-x)/v1;
    cout << fixed << setprecision(10) << t << endl;
}#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;
int main(){
    ios::sync_with_stdio( false );
    ld l, v1, v2, C;
    int n, k;
    cin >> n >> l >> v1 >> v2 >> k;
    C = (ld)((int)(n/k) + (int)(n % k != 0));
    ld aux = ((C-1.)*v1)/v2 + ((C-1.)*(v2 - v1)*v1)/(v2*(v2+v1)) + 1.;
    ld x = l/aux;
    
    ld t = (x/v2) + (l-x)/v1;
    cout << fixed << setprecision(10) << t << endl;
}