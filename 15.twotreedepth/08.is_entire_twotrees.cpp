#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=10002;
int v[maxn],lc[maxn],rc[maxn];
int q[maxn];
bool ans=true,leaf=false;

int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l=0,r=0;
    q[r++]=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>lc[i]>>rc[i];
    while(l<r)
    {
        int size=r-l;
        
        for(int i=0;i<size;i++)
        {
            int cur=q[l++];
            if(lc[cur]!=0)q[r++]=lc[cur];
            if(rc[cur]!=0)q[r++]=rc[cur];
        if(lc[cur]==0&&rc[cur]!=0) ans=false;
            else if(leaf&&(lc[cur]!=0||rc[cur]!=0))
                ans=false;
            if(lc[cur]==0||rc[cur]==0)
                leaf=true;
        }
    }
    cout<<(ans?"true":"false")<<'\n';
    return 0;
}