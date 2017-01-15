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
#define gc getchar_unlocked
using namespace std;
ll mod = 1000000007;
const double eps = 0.0000001;

int h,n;
int a[100]; 

char c;

int read(int& ret) {
    c = gc();
    while(c<'0' || c>'9') c = gc();
    ret = 0;
    while(c>='0' && c<='9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return ret;
}

const int types[] = {4, 6, 8, 10, 12, 20};
const int rolls = 20; 

int main(){
    // clock_t t1=clock();
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout << std::fixed;
    vector< vector<double> > v[21];
    vector< vector<double> > cum[21];
    for (int i = 0; i < 6; ++i)
    {
        int dice = types[i];
        int outcomes = rolls*dice;
        v[dice]=vector<vector<double> >(rolls+1,vector<double>(outcomes+1,0));
        v[dice][0][0]=1;
        cum[dice]=vector<vector<double> >(rolls+1,vector<double>(outcomes+1,0));
        for (int k = 1; k <=rolls ; ++k)
        {
            for (int j = 1; j<=outcomes ; ++j)
            {
                for (int l = 1; l <=dice and j-l>=0 ; ++l)
                {
                    v[dice][k][j]+=v[dice][k-1][j-l]*1.0/double(dice);
                }
                // cerr << "v["<<k<<"]["<<j<<"]=" << v[dice][k][j] << " ";
            }
            // cerr << "\n";

            for (int j = outcomes-1; j>=0; --j)
            {
                cum[dice][k][j]=cum[dice][k][j+1]+v[dice][k][j];
            }
            // cerr << "c="<< cum[dice][k][0] << "\n";

        }
    }

    int t;
    read(t);
    for(int tc=1;tc<=t;tc++){
        read(h); read(n); 
        double optimal = 0;
        for (int i = 0; i < n; ++i)
        {
            int times,dice,extra=0;
            read(times);
            read(dice);
            if (c=='-')
            {
                read(extra);
                extra=-extra;
            }else if(c=='+'){
                read(extra);
            } 
            // cerr << times << " " << dice << " " << extra << "\n";
            int l=times,r=times*dice;
            int hh = h - extra;
            // cerr << l << "><" <<r<< "\n";
            if (hh<=r)
            {
                optimal = max(optimal, cum[dice][times][max(hh,0)] );
            }
        }
        
        cout << "Case #"<< tc << ": " << setprecision(6) << optimal << "\n";
    }

    // cerr << double(clock()-t1)/CLOCKS_PER_SEC << endl; 

    return 0;
}