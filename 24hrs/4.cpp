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

inline ll inv(ll x){
	return mpow(x,mod-2);
}

ll N,M;
const int MAX = 7001;
vector<int> a(MAX);
ll fact[MAX];
ll partial[MAX],min_m;

ll ways(ll n,ll m){
	//if(m<0) return 0;
	if(m==0)return 1;
	int low=m-min_m;
	int high=low+n-1;
	ll num = partial[high]*inv(partial[low])%mod;
	return inv(fact[n-1])*num%mod;
}

int main(){
    ios_base::sync_with_stdio(0);

    //clock_t t1=clock();

    for (int i = fact[0] = 1; i < MAX ; ++i)
    {
    	fact[i]=fact[i-1]*i%mod;
    }

    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin >> N >> M ;
        if (N==1)
        {
        	cout << "Case #"<< tc << ": " << M << "\n";
        	continue;
        }

        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
        	cin >> a[i];
        	sum+=2*a[i];
        }
        min_m = max(M-1-sum,(ll)1);
        partial[0]=min_m; 
        for (int i = 1; i < MAX; ++i)
        {
        	partial[i]=(partial[0]+i)*partial[i-1]%mod;
        }

        ll ans = 0;

        for (int i = 0; i < N; ++i)
        {
        	for (int j = 0; j < i; ++j)
        	{
        		ll m = M - 1 - sum + (a[i]+a[j]);
        		if(m>=0){
        			ans += 2*ways(N+1,m)*fact[N-2]%mod;
        		}
        	}
        }

        cout << "Case #"<< tc << ": " << (ans%mod) << "\n";

    }
    return 0;
}