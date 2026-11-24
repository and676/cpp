#include<bits/stdc++.h>
using namespace std;
int add(int x,int y)
{
    int ans=x;
    while(y!=0)
    {
        ans=x^y;
        y=(x&y)<<1;
        x=ans;
    }
    return ans;
}
int sub(int x,int y)
{
    return add(x,add(~y,1));
}
int multiply(int x,int y)
{
    int neg=0;
    if(y<0)
    {
        neg=-1;
        y=add(~y,1);
        
    }
    int ans =0;
    while(y!=0)
    {
        if(y&1)
        ans=add(x,ans);
       x= x<<1;
        y=y>>1;
    }
    if(neg==-1)
        ans=add(~ans,1);
    return ans;
}