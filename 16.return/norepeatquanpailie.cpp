#include<bits/stdc++.h>
using namespace std;
int n;int nums[10],path[10];
bool used[10];
void f(int size)
{   if(size==n)
    {
        for(int i=0;i<size;i++)
            cout<<path[i]<<' ';
        cout<<'\n';
        return ;
    }
 for(int k=0;k<n;k++)
 {
     if(used[k])continue;
     if(k>=1&&nums[k]==nums[k-1]&&used[k-1]==0)
         continue;
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
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums,nums+n);
    f(0);
    return 0;
}
/*
核心招：重复排列的死因是"相同值的不同下标被当成不同人"。解法：排序抱团 + nums[k]==nums[k-1] && !used[k-1] 同层剪枝——相同的值必须按先后顺序上场，乱序分支整棵砍掉。*/