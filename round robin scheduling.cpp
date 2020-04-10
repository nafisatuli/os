/*Round Robin Scheduling*/
#include<bits/stdc++.h>
using namespace std;
struct st
{
    string s;
    double b;
};
int main()
{
    st aa[1000];
    int n,j;
    double rem_bt[100],wt[1000],tq,t=0,temp=0;
    vector<pair<double,string> >sum;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> aa[i].s >> aa[i].b;
    }
    for(int i=0; i<n; i++)
    {
        rem_bt[i]=aa[i].b;
    }
    cin >> tq;
    while(1)
    {
        bool done=true;
        for(int i=0; i<n; i++)
        {
            if(rem_bt[i]>0)
            {
                done=false;
                if(rem_bt[i]>tq)
                {
                    temp+=tq;
                    t+=tq;
                    rem_bt[i]-=tq;
                    sum.push_back(make_pair(temp,aa[i].s));
                }
                else
                {
                    temp+=rem_bt[i];
                    t+=rem_bt[i];
                    wt[i]=t-aa[i].b;
                    sum.push_back(make_pair(temp,aa[i].s));
                    rem_bt[i]=0;
                }
            }
        }
        if(done==true)
            break;
    }
    cout << "0 ";
    for(int i=0; i<sum.size(); i++)
    {
       cout << sum[i].second << " " << sum[i].first << " ";
    }
    double w=0;
    for(int i=0;i<n;i++)
    {
        w+=wt[i];
    }
    cout << w/n << endl;
    double tt=0;
    for(int i=0;i<n;i++)
    {
        tt+=wt[i]+aa[i].b;
    }
    cout << tt/n << endl;
}
