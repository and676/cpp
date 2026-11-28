#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=100002;
int nq[maxn];
long long iq[maxn];
int v[maxn],lc[maxn],rc[maxn];

int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>lc[i]>>rc[i];
    int l=0,r=0;
    nq[r]=1;iq[r++]=1;
    int ans=0;
while(l<r)
{
    int size=r-l;
    int m=iq[r-1]-iq[l]+1;
    if(m>ans)
        ans=m;
    for(int i=0;i<size;i++)
    {
        int cur=nq[l];
        long long id=iq[l++];
        if(lc[cur]!=0){nq[r]=lc[cur];iq[r++]=id*2;}
        if(rc[cur]!=0)
        {
            nq[r]=rc[cur];iq[r++]=id*2+1;
        }
    }
}
    cout<<ans;
    return 0;
}