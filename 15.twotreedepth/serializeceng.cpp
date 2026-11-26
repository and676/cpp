#include<bits/stdc++.h>
using namespace std;
const int maxn=100002;
int v[maxn],lc[maxn],rc[maxn];
int q[maxn];
string vals[maxn];
int cnt,pos;
int generate(string&str)
{
    if(str=="#")return 0;
    else int u=++cnt;v[u]=stoi(str);return u;
}
string serialize(int root)
{
    string s;
    int l=0,r=0;
    q[r++]=root;
    s+=to_string(v[root])+",";
    while(l<r)
    {
        int cur=q[l++];
        if(lc[cur]!=0) {
            q[r++]=lc[cur];
         s+=to_string(v[lc[cur]])+',';
        }
        else s+="#,";
        //就差一步，但这一步卡在编译上：s += "#" + "," 编译不过。
//原因：+ 做字符串拼接的前提是至少有一边是 string 类型。"#" 和 "," 都是字符串字面量（const char*），两个 const char* 相加，编译器不认识这个操作——直接报错。
        if(rc[cur]!=0) 
        {q[r++]=rc[cur];
            s+=to_string(v[rc[cur]])+',';}
        else s+="#,";

    }
    return s;
}
int deserialize(int m)
{
    int l=0,r=0;
    int root=generate(vals[pos]);
    q[r++]=root;
    pos=1;
    while(l<r)
    {
        int cur=q[l++];
        lc[cur]=generate(vals[pos++]);
        rc[cur]=generate(vals[pos++]);
        if(lc[cur]!=0)q[r++]=lc[cur];
        if(rc[cur]!=0)q[r++]=rc[cur];
    }
      return root;  
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>v[i]>>lc[i]>>rc[i];
 
   string s= serialize(1);
    cout<<s<<'\n';
    stringstream ss(s);
    string item;
    int m=0;
    while(getline(ss,item,','))
    vals[m++]=item;
    cnt=0;pos=0;
    int root2=deserialize(m);
string s2 = serialize(root2);
cout << s2 << '\n';
cout << (s == s2 ? "SAME" : "DIFF") << '\n';

    return 0;
}