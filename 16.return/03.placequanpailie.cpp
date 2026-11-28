#include<bits/stdc++.h>
using namespace std;
int n;
int nums[10],path[10];
bool used[10];

void f(int size)
{
    if(size==n)
    {
        for(int i=0;i<n;i++)
            cout<<path[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int k=0;k<n;k++)
    {
        if(used[k]==1)continue;
        path[size]=nums[k];
        used[k]=1;
        f(size+1);
        used[k]=0;
    }
}


int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i =0;i<n;i++)cin>>nums[i];
    f(0);
    return 0;
}