#include<bits/stdc++.h>
using namespace std;
string s,path;
set<string>st;
void f(int i)
{
    if(i==s.size())
    {st.insert(path);
    return;}
    path.push_back(s[i]);
    f(i+1);
    path.pop_back();
    f(i+1);
}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
   cin>>s;
    f(0);
    for(auto&x:st)cout<<x<<'\n';
    return 0;
}



#include<bits/stdc++.h>
using namespace std;
const int maxn=100002;
string s;
char path[maxn];
set<string>st;

void f(int i,int size)
{
    if(i==s.size())
    {
        st.insert(string(path，size));
        return;
    }
   path[size]=s[i];
    f(i+1,size+1);
    f(i+1,size);
}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    f(0,0);
    for(auto&x:st)cout<<x<<'\n';
    return 0;
}