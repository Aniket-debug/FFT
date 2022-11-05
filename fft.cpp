#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define vi vector<int>
#define vvi vector<vector<int>> 
#define vll vector<ll>
#define vs vector<string>
#define vii vector<pair<int,int>>
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define F first
#define S second
#define bits __builtin_popcount
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert){
    int n = a.size();
    if (n == 1) return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

void solve(){
    int n;cin>>n;
    vi a(n);for (int i=0;i<n;i++)cin>>a[i];
    vector<cd> f(all(a));
    fft(f,false);
    for (cd i:f)cout<<i<<' ';
    cout<<'\n';
    fft(f,true);
    for (cd i:f)cout<<i.real()<<' ';
    cout<<'\n';
}

int main() {
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}
