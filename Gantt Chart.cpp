#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin >> n;
        double aa[n+5],cum[n+5];
        memset(aa,0,sizeof(aa));
        memset(cum,0,sizeof(aa));
        cum[0]=0;
        for(int i=1; i<=n; i++)
        {
            cin >> aa[i];
            cum[i]=aa[i]+cum[i-1];
        }
        cout << "Gantt Chart:" << endl;
        cout << "0 ";
        for(int i=1; i<=n; i++)
        {
            cout <<"P" << i << " "<< cum[i] << " ";
        }
        cout << endl;

        cout << "Avg Turnaround time:" << endl;
        double sum=0;
        for(int i=1; i<=n; i++)sum+=cum[i];
        cout << sum/n << endl;

        cout << "Avg Waiting time:" << endl;
        double sum2=0;
        for(int i=0; i<n; i++)sum2+=cum[i];
        cout << sum2/n << endl;
    }
}
/*
Input:
4
2 3 4 5

Output:

Gantt Chart:
0 P1 2 P2 5 P3 9 P4 14
Avg Turnaround time:
7.5
Avg Waiting time:
4
*/
