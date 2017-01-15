#include <bits/stdc++.h>


#define mp make_pair
#define pb push_back
#define F first
#define S second
#define N 100010
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbg2(x,y) {cerr << #x << "," << #y << " = " << x << " " << y << endl;}
#define dbg3(x,y,z) {cerr << #x << "," << #y << "," << #z << " = " << x << " " << y << " " << z << endl;}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
using namespace std;
ll mod = 1000000007;
const double eps = 0.0000001;

ll n;
int a[100]; 

int main(){
    // clock_t t1=clock();
    ios_base::sync_with_stdio(0);
    // cin.tie(NULL);

    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin >> n  ;
        for (int i = 0; i < n; ++i)
        {
        	cin >> a[i];
        }
        sort(a, a+n);

        int trips=0,used=0;
        for (int i = n-1; i>=0; --i)
        {
        	int needed = (50/a[i])+(50%a[i]!=0);
        	if (used+needed>n)
        	{
        		break;
        	}else{
        		trips++;
        		used+=needed;
        	}
        }
        cout << "Case #"<< tc << ": " << trips << "\n";
    }

    // cerr << double(clock()-t1)/CLOCKS_PER_SEC << endl; 

    return 0;
}