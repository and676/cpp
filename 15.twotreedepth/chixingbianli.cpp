#include<bits/stdc++.h>
using namespace std;
const int maxn=100002;
int v[maxn],lc[maxn],rc[maxn],q[maxn];
int n;
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i]>>lc[i]>>rc[i];
//因为一棵树要输入，必须交代两类信息：每个节点是谁 + 谁和谁连着。这套格式用"行号"承担了第一类信息（省得输入里再写一遍编号），用行内的两个数字承担第二类
    int l=0,r=0;
    q[r++]=1;
    bool reverse =false;
    while(l<r)
    {
        int size=r-l;
        if(!reverse)
            for(int i=l;i<r;i++)cout<<v[q[i]]<<' ';
        else 
            for(int i=r-1;i>=l;i--)
                cout<<v[q[i]]<<' ';
        for(int i=1;i<=size;i++)
        {
            int cur=q[l++];
            if(lc[cur]!=0)q[r++]=lc[cur];
            if(rc[cur]!=0)q[r++]=rc[cur]; 
        }
        cout<<'\n';
        reverse=!reverse;
    }
    return 0;
}