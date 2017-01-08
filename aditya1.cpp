#include <iostream>
#include<math.h>
using namespace std;

double corrected_value(double theta, int X, int Y)  {

if(X >= 50 && Y >= 50)  {
    return theta;
} else if(X >= 50 && Y < 50)  {
    return 180 - theta;
} else if( X < 50 && Y <= 50)  {
    return 180 + theta;
} else if( X < 50 && Y > 50)  {
    return 360 - theta;
}
}

bool is_in_black(int P,int X, int Y)  {
    double theta1, theta2;
    if( Y == 50)  {
        theta1 = corrected_value(90.0, X, Y);
    }  else {
        theta1 = (double)(atan((double)(50-X)/(double)(50-Y))*(double)(180))/((double)(4)*atan(1));
        theta1 = corrected_value(fabs(theta1), X, Y);
    }
    theta2 = ((double)18*(double)P)/((double)5);
    if((theta1-theta2) >= 1e-9)  {
        return false;
    }  else  {
        return true;
    }
}

bool is_in_sector(int X, int Y)  {

    double dist;
    dist = sqrt((X-50)*(X-50)+(Y-50)*(Y-50));
    if(dist - 50 < 1e-9)  {
        return true;
    }  else {
        return false;
    }
}

int main()
{
    clock_t t1=clock();
    ios_base::sync_with_stdio(0);
    
    int T;
    int k = 0;
    cin>>T;
    while(T--)  {
        k++;
        int P,X,Y;
        cin>>P>>X>>Y;
        std::cout<<"Case #"<<k<<": ";
        if(is_in_sector(X,Y))  {
            if(is_in_black(P,X,Y))  {
                std::cout<<"black";
            } else {
                std::cout<<"white";
            }
        } else {
            std::cout<<"white";
        }
        std::cout<<std::endl;
    }

    cerr << double(clock()-t1)/CLOCKS_PER_SEC << endl; 

    return 0;
}

