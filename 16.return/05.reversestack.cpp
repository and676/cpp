#include<bits/stdc++.h>
using namespace std;
const int maxn=100004;
int stk[maxn],top=0;
int bottomout()
{
    int ans=stk[--top];
    if(top==0)return ans;
    int last =bottomout();
    stk[top++]=ans;
    return last;
}
void reversestk()
{
    if(top==0)return;
    int num=bottomout();
    reversestk();
    stk[top++]=num;
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;stk[top++]=x;
    }
    reversestk();
    while(top)
        cout<<stk[--top]<<"\n"[top==0];
    return 0;
}
//入栈出栈的方式是配对的