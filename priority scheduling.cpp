/*Priority Scheduling*/
#include<bits/stdc++.h>
using namespace std;
struct st
{
    string s;
    double b,p;
};
bool compare(st x,st y)
{
    return x.p<y.p;
}
int main()
{
    int n;
    st aa[1000];
    double w=0,t=0,sum[1000];
    cout << "Number of input: ";
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cout << "Name of the process: ";
        cin >> aa[i].s;
        cout << "Priority: ";
        cin >> aa[i].p;
        cout << "Bursting time: ";
        cin >> aa[i].b;
    }
    sort(aa+1,aa+n+1,compare);
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        sum[i]=sum[i-1]+aa[i].b;
    }
    cout <<endl << "Gantt Chart:: " << "0 ";
    for(int i=1; i<=n; i++)
    {
        cout << aa[i].s << " " << sum[i] << " ";
    }
    cout << endl;

    for(int i=0; i<=n; i++)
    {
        if(i!=0)
            t+=sum[i];
        if(i!=n)
            w+=sum[i];
    }

    cout << "Average waiting time:: ";
    cout << w/n << endl;

    cout << "Average turnaround time:: ";
    cout << t/n << endl;
}
