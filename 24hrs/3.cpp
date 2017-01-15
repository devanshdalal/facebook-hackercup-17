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

const int V = 100;
const int M = 10000;
ll graph[V][V];
ll dist[V][V];
int s[M],d[M];
ll dp[M][2];

void floydWarshall (int n)
{
    int i,j,l;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
    for (l = 0; l < n; l++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (dist[i][l] + dist[l][j] < dist[i][j])
                    dist[i][j] = dist[i][l] + dist[l][j];
            }
        }
    }
}
int n,m,k;

int main(){
    ios_base::sync_with_stdio(0);

    //clock_t t1=clock();

    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(i==j){
                    graph[i][j]=0;
                }else{
                    graph[i][j]=INT_MAX;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            int x,y;
            ll cost;
        	cin >> x >> y >> cost;
            x--;
            y--;
            graph[x][y]=min(cost,graph[x][y]);
            graph[y][x]=graph[x][y];
        }
        floydWarshall(n);
        // for (int i = 0; i < n; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         cerr << dist[i][j] << " ";
        //     }
        //     cerr << "\n";
        // }
        for (int i = 1; i <=k; ++i)
        {
            cin >> s[i] >> d[i]; 
            s[i]--;
            d[i]--;
        }
        // s[0]=0;
        d[0]=0;
        // dp(i,0): min gas used such that ith cargo is just delivered at di & trunk is empty. 
        // dp(i,i): min gas used such that ith cargo is just delivered at di & trunk has (i+1)th cargo. 
        dp[0][0]=0;
        dp[0][1]=INT_MAX;
        for (int i = 1; i <=k; ++i)
        {
            dp[i][0]=min(dp[i-1][1]+dist[d[i-1]][d[i]],dp[i-1][0]+dist[d[i-1]][s[i]]+dist[s[i]][d[i]]); 
            dp[i][0]=min(dp[i][0],(ll)INT_MAX); 
            if (i<k)
            {
                dp[i][1]=min(dp[i-1][1]+dist[d[i-1]][s[i+1]]+dist[s[i+1]][d[i]],
                    dp[i-1][0]+dist[d[i-1]][s[i]]+dist[s[i]][s[i+1]]+dist[s[i+1]][d[i]]); 
            }
            dp[i][1]=min((ll)INT_MAX,dp[i][1]);
        }

        cout << "Case #"<< tc << ": " << (dp[k][0]>=INT_MAX?-1:dp[k][0]) << "\n";

    }
    return 0;
}