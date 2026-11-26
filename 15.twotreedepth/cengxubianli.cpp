#include<bits/stdc++.h>
using namespace std;
const int N=100003;
int v[N];
int lc[N],rc[N];//leftchild rightchild
int q[N];//队列
int dep[N];//depth深度/层数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>lc[i]>>rc[i];//用下标！！
    }
    int l=0,r=0;
    q[r++]=1;
    dep[1]=0;
    int curlv=0;
    
    while(l<r)
    {
        int cur=q[l++];
        if(dep[cur]!=curlv)
        {
            cout<<'\n';
            curlv=dep[cur];
        }
        cout<<v[cur]<<' ';
        if(lc[cur]!=0)
        {
            q[r++]=lc[cur];
            dep[lc[cur]]=dep[cur]+1;
        }
        if(rc[cur]!=0)
        {
            q[r++]=rc[cur];
            dep[rc[cur]]=dep[cur]+1;
        }
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int maxn=2002;
int v[maxn],lc[maxn],rc[maxn];
int q[maxn];
int n;

int main()
{ios::sync_with_stdio(false);
 cin.tie(nullptr);
cin>>n;
 for(int i=1;i<=n;i++)
     cin>>v[i]>>lc[i]>>rc[i];//lc[i]存的是左孩子的下标，rc[i]存的是右孩子的下标
 int l=0,r=0;
 q[r++]=1;
 while(l<r)
 {
     int size=r-l;
     for(int i=1;i<=size;i++)
     {
         int cur=q[l++];
         cout<<v[cur]<<' ';
         if(lc[cur]!=0)
          q[r++]=lc[cur];
         if(rc[cur]!=0)
            q[r++]=rc[cur];
     }
     cout<<'\n';
 }
 
return 0;
}