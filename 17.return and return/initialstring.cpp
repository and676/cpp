#include<bits/stdc++.h>
using namespace std;
string s;
int where=0;
string get(int cnt,string str)
{
 string t;
    for(int k=0;k<cnt;k++)
        t+=str;
    return t;
}
string f(int i)
{
    int cnt =0;
    string path;
    while(i<s.size()&&s[i]!=']')
    {
        
        if(s[i]>='a'&&s[i]<='z')
            path+=s[i++];
        else if(s[i]!='[')
        {
            cnt=cnt*10+s[i]-'0';
            i++;
        }
        else
        {
            path+=get(cnt,f(i+1));
            cnt=0;
        i=where+1;
        }
    } 
       where=i;
       return path;
}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    string path=f(0);
    cout<<path;
    return 0;
}

/*
path：本层攒、本层返回——不跨层 → 局部 ✓（你已经改对了）
where：子层要上报给父层——跨层 → 全局 ✓
cnt：本层攒、本层用、用完清零——跨层吗？不跨 → 局部*/
