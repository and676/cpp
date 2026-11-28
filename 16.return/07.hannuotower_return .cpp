#include<bits/stdc++.h>
using namespace std;
void f(int i,string from,string to,string other)
{
    if(i==1)
    {
        cout<<"移动圆盘1从"<<from<<"到"<<to<<'\n';
    return ;
    }
    f(i-1,from,other,to);
    cout<<"移动圆盘"<<i<<"从"<<from<<"到"<<to<<'\n';
    f(i-1,other,to,from);
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n>0)f(n,"左","右","中");
    return 0;
}