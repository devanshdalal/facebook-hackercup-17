#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;
int wt[105];
int main()
{
    int T;
    int k = 0;
    cin >> T;
    while(T--)  {
        k++;
        int N;
        cin>>N;
        for(int i = 0; i < N; i++)  {
            cin>>wt[i];
        }
        sort(wt, wt+N);
        int count = 0;
        int end = N-1;
        int begin = 0;
        while(begin <= end)  {
            begin += (int)(49/wt[end]);
            if(end >= begin)  {
                count++;
            }
            end--;
        }
        cout<<"Case #"<<k<<": "<<count<<endl;
    }
    return 0;
}

