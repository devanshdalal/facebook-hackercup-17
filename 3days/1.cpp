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

const double PI = acos(-1);
struct point
{
	double x,y;
	point(){}
	point(double a,double b){
		x=a;
		y=b;
	}
};

point operator -( const point& lhs, const point& rhs ){
	return point(lhs.x-rhs.x,lhs.y-rhs.y);
}

inline double len(const point& p1){
	return sqrt(p1.x*p1.x + p1.y*p1.y);
}

point operator *(const point p1,double val){
	return point(p1.x*val,p1.y*val);
}

double angle(const point& p1,const point& p2,const point& p3){
	point t1=(p2-p1)*(1.0/len(p2-p1));
	point t2=(p3-p1)*(1.0/len(p3-p1));
	dbl costh= (t1.x*t2.x + t1.y*t2.y) ;
	dbl sinth= (t1.x*t2.y - t1.y*t2.x) ;
	if (costh>=0 and sinth>=0)
	{
		return abs(sinth-1.0)<eps?90.0:180.0*atan(sinth/costh)/PI;
	}else if (costh<0 and sinth>=0)
	{
		return abs(sinth-1.0)<eps?90.0 : 180.0 + 180.0*atan(sinth/costh)/PI;
	}else if (costh<0 and sinth<0)
	{
		return abs(sinth+1.0)<eps?270.0 : 180.0 + 180.0*atan(sinth/costh)/PI;
	}else
	{
		return abs(sinth+1.0)<eps?270.0 : 360.0 + 180.0*atan(sinth/costh)/PI;
	}
}

ll p,x,y;

int main(){
    ios_base::sync_with_stdio(0);

    clock_t t1=clock();

    int t;
    cin >> t;
    const point center(50,50); 
    const point top(50,100); 
    for(int i=1;i<=t;i++){
        cin >> p >> x >> y ;

        point cur(x,y);

        cout << "Case #"<< i << ": ";
        if ( len(center-cur)<=50.0 and angle(center,cur,top)/360.0<=double(p)/100.0 )
        {
        	cout << "black\n";
        } else{
        	cout << "white\n";
        }
    }

    cerr << double(clock()-t1)/CLOCKS_PER_SEC << endl; 

    return 0;
}