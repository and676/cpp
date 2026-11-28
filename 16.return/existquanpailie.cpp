#include<bits/stdc++.h>
using namespace std;
int n;
int nums[15],path[15];
void f(int i,int size)
{
    if(i==n)
    {   for(int k=0;k<size;k++)
            cout<<path[k]<<' ';
     cout<<'\n';
    return ;
    }
    int j=i+1;
    while(j<n&&nums[i]==nums[j])j++;
    f(j,size);
    for(int k=i;k<j;k++)
    {  path[size++]=nums[k];
    f(j,size);
    }
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)cin>>nums[i];
    sort(nums,nums+n);
    f(0,0);
    return 0;
}