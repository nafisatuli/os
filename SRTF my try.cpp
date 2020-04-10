#include<bits/stdc++.h>
using namespace std;
struct st
{
    string s;
    double a,bt;
};
int main()
{
     vector<pair<string,double> >v;
     int n,cont=0,pos,endd=0;
     double rem[10000],temp[1000],wt=0,tt=0;
     st arr[10000];
     cin >> n;
     for(int i=0;i<n;i++)
     {
         cin >> arr[i].s >> arr[i].a >> arr[i].bt;
         rem[i]=arr[i].bt;
     }
     for(int i=0;i<n;i++)temp[i]=rem[i];
     rem[100]=99999;
     for(int i=0;cont!=n;i++)
     {
         pos=100;
         for(int i=0;i<n;i++)
         {
             if(arr[i].a<=i && rem[i]<rem[pos] && rem[i]>0)
             {
                 pos=i;
             }
         }
         rem[pos]--;
         if(rem[pos]==0)
         {
             cont++;
             endd=i++;
             wt+=endd-arr[pos].a-temp[pos];
             tt+=endd-arr[pos].a;
         }
     }
     cout << wt/n << endl;
     cout << tt/n << endl;
     cout << "0 ";
     for(int i=0;i<v.size();i++)cout << v[i].first << " " << v[i].second << " ";
}

