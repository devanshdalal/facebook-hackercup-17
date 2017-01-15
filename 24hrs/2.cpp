#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbg2(x,y) {cerr << #x << "," << #y << " = " << x << " " << y << endl;}
#define dbg3(x,y,z) {cerr << #x << "," << #y << "," << #z << " = " << x << " " << y << " " << z << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;

inline ll mpow(ll b, ll ex){
	if (b==1)return 1;
    ll r = 1;
    while (ex ){
        if (ex&1)r=(r * b)%mod;
        ex = ex >> 1;
        b = (b * b)%mod;}
    return r;
}

int n,r;
const int V = 51;
ll x[V],y[V];

int main(){
    ios_base::sync_with_stdio(0);

    //clock_t t1=clock();

    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin >> n >> r;
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i] >> y[i];   
        }





        cout << "Case #"<< tc << ": " <<  << "\n";

    }
    return 0;
}