#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int v[maxn],lc[maxn],rc[maxn];
int cnt;
string vals[maxn];int pos;
int n;
void serialize(int u,string&s)
{   
    if(u==0)s+='#,';
 else 
 {s+=to_string(v[u])+',';
 serialize(lc[u],string &s);
   serialize(rc[u],string&s);
 }  
}
int deserialize()
{
    string cur=vals[pos++];
    if(cur=="#")
        return 0;
    int u=++cnt;
    v[u]=stoi(cur);
    lc[u]=deserialize();
    rc[u]=deserialize();
    return u;
    
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>v[i]>>lc[i]>>rc[i];
    string s;
    serialize(1,s);
    cout<<s<<'\n';
    stringstream ss(s);
    string item;
    int m=0;
    while(getline(ss,item,','))
    vals[m++]=item;
    cnt=0;pos=0;
    int root2=deserialize();

    
        return 0;
}