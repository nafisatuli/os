/*Shortest Job First*/
#include<bits/stdc++.h>
using namespace std;
struct st
{
    string s;
    double v;
};
bool compare(st a,st b)
{
    return a.v<b.v;
}
int main()
{
    int n;
    cin >> n;
    st aa[n+10];
    for(int i=1;i<=n;i++)
    {
        cin >> aa[i].s >> aa[i].v;
    }
    sort(aa+1,aa+n+1,compare);
    int csum[n+10];
    csum[0]=0;
    for(int i=1;i<=n;i++)
    {
        csum[i]=csum[i-1]+aa[i].v;
    }
    cout << "0 ";
    for(int i=1;i<=n;i++)
    {
       cout << aa[i].s << " " << csum[i]<< " ";
    }
    int s=0;
    for(int i=0;i<n;i++)s+=csum[i];
    cout << endl << s/n << endl;
    s=0;
    for(int i=1;i<=n;i++)s+=csum[i];
    cout << s/n << endl;

}
