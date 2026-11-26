#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1000004;
int v[maxn],lc[maxn],rc[maxn];
int maxdepth(int u)
{
    if(u==0)return 0;
    return max(maxdepth(lc[u]),maxdepth(rc[u]))+1;
}
    
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>lc[i]>>rc[i];
    cout<<maxdepth(1);
    return 0;
}
//递归求max，也可以层序遍历，记层数，不容易超时
//递归求mindepth
int mindepth(int u)
{
    if(u==0)return 0;
    if(lc[u]==0&&rc[u]==0)return 1;
    int ldeep=INT_MAX,rdeep=INT_MAX;
    if(lc[u]!=0) ldeep=mindepth(lc[u]);
    if(rc[u]!=0)rdeep=mindepth(rc[u]);
    return min(ldeep,rdeep)+1;//+1别忘了
}