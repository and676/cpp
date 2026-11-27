#include<bits/stdc++.h>
using namespace std;
const int maxn=100002;
int v[maxn],lc[maxn],rc[maxn];
int q[maxn];
int  n;
int maxdepth(int root)
{
    if(root==0)return 0;
    return max(maxdepth(lc[root]),maxdepth(rc[root]))+1;
}
int nodenum(int root)
{
    if(root==0)
        return 0;
    if(maxdepth(lc[root])==maxdepth(rc[root]))
        return (1<<(maxdepth(lc[root])))+nodenum(rc[root]);
    else
        return (1<<(maxdepth(rc[root])))+nodenum(lc[root]);
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>lc[i]>>rc[i];
    int num=nodenum(1);
    cout<<num;
    return 0;
    
}