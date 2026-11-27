#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
int pre[maxn],in[maxn],pos[maxn];
int v[maxn],lc[maxn],rc[maxn],cnt,n;
void postorder(int u)
{
    if(u==0)return;
    postorder(lc[u]);
    postorder(rc[u]);
    cout<<v[u]<<' ';
}
int build(int l1,int r1,int l2,int r2)
{
    if(l1>r1)return 0;
    int u=++cnt;
    v[u]=pre[l1];
    if(l1==r1)return u;
    int k=pos[pre[l1]];
   int leftsize=k-l2;
    lc[u]=build(l1+1,l1+leftsize,l2,k-1);
    rc[u]=build(l1+leftsize+1,r1,k+1,r2);
    return u;
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>pre[i];
    for(int i=1;i<=n;i++)cin>>in[i];
    for(int i=1;i<=n;i++)pos[in[i]]=i;
    int root=build(1,n,1,n);
    postorder(root);
    return 0;
}