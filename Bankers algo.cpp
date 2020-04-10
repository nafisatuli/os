#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int alloc[n+1][m+1],mx[n+1][m+1],need[n+1][m+1],avail[n+1],ans[n+1],f[n],in=0;
    memset(f,0,sizeof(f));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> alloc[i][j];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin >> mx[i][j];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            need[i][j]=mx[i][j]-alloc[i][j];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << need[i][j] << " ";
        cout << endl;
    }
    for(int i=0; i<m; i++)
        cin >> avail[i];
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            if(f[i]==0)
            {
                bool flag=true;
                for(int j=0;j<m;i++)
                {
                    if(need[i][j]>avail[j])
                        flag=false;
                    break;
                }
                if(flag)
                {
                    ans[in]=i;
                    in++;
                    for(int j=0;j<m;j++)
                        avail[j]+=alloc[i][j];
                    f[i]=1;
                }
            }
        }
    }
    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << ans[i] << " ";
    }
}
