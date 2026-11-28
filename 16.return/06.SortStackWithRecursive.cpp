#include<bits/stdc++.h>
using namespace std;
int deep()
{
    if(top==0)return 0;
    int num=stk[--top];
    int d=deep()+1;
    stk[top++]=num;
    return d;
}
int getmax(int dep)
{
    if(dep==0)return INT_MIN;
    int num=stk[--top];
    int rest=getmax(dep-1);
    stk[top++]=num;
    return max(num,rest);
}
int times(int deep,int max)
{
    if(deep==0)return 0;
    int num=stk[--top];
    int rest=times(deep-1,max);
    stk[top++]=num;
    int count=(num==max)?1:0;
        return rest+count;
}
void down(int deep,int max,int k)
{
    if(deep==0)
    {
        for(int i=0;i<k;i++)
            stk[top++]=max;
        return;
    }
    int num=stk[--top];
    down(deep-1,max,k);
    if(num!=max)
        stk[top++]=num;
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[]={1,5,4,5,3,2,3,1,4,2};
    int n=10;
    for(int i=0;i<n;i++)
        stk[top++]=arr[i];
    int dep=deep();
        while(dep)
        {
           int max_=getmax(dep);
            int tm=times(dep,max_);
            down(dep,max_,tm);
            dep-=tm;
        }
    while(top)cout<<stk[--top]<<' ';
    
    return 0;
}