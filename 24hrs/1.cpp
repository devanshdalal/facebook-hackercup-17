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

int n,m;
vector< ll  > cost_prev(301, INT_MAX );
vector< ll  > cost(301, INT_MAX );
int table[301];

int main(){
    ios_base::sync_with_stdio(0);

    //clock_t t1=clock();

    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin >> n >> m ;
        // cost(i,k)= min. cost paid till ith day so that k candies are bought. 
        // n*m + n*log(n) algo exists actually.
        fill(cost_prev.begin()+1, cost_prev.begin()+n+1,INT_MAX);
        cost_prev[0]=0;
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 1; j <=m; ++j)
			{
				cin >> table[j];
			}
			sort(table+1,table+m+1);
			for (int k = 0; k <=n; ++k)
			{
				cost[k]=cost_prev[k];
				ll expenditure = 0;
				for (int j = 1; j <=min(k,m); ++j)
				{
					expenditure+=table[j];
					cost[k]=min(cost[k],j*j+expenditure+cost_prev[k-j]);
				}
				// cerr << cost[k] << " ";
			}
			// cerr << "\n";
			swap(cost_prev,cost);
		}

        cout << "Case #"<< tc << ": " << cost_prev[n] << "\n";
    }

    // cerr << double(clock()-t1)/CLOCKS_PER_SEC << endl; 

    return 0;
}