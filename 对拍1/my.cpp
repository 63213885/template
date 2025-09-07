#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+3;
const int mod=998244353;
int a[N];
int f[N];
int d[N];
void solve()
{   
    int n,p;
    cin>>n>>p;
    for(int i=0;i<=p;i++) d[i]=mod;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]%=p;
        f[a[i]]=1;
        d[a[i]]=1;
    }
    if(f[0]) cout<<"1\n";
    else
    {
        for(int i=1;i<=p;i++)
        {
            if(f[i])
            for(int j=1;j<=p;j++)
            {
                int l=(i+(j-1)*i)%p;
                int r=(i+j*i)%p;
                if(d[l]!=mod)
                {
                    d[r]=min(d[r],d[l]+1);
                }
            }
        }
        for(int i=p;i>=1;i--)
        {
            if(f[i])
            for(int j=1;j<=p;j++)
            {
                int l=(i+(j-1)*i)%p;
                int r=(i+j*i)%p;
                if(d[l]!=mod)
                {
                    d[r]=min(d[r],d[l]+1);
                }
            }
        }
        cout<<d[0]<<"\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}