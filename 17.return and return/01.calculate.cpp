#include<bits/stdc++.h>
using namespace std;
string s;
int where;
void push(vector<int>&nums,vector<char>&ops,int cur,char op)
{
    int n=nums.size();
    if(n==0||ops[n-1]=='+'||ops[n-1]=='-')
    {
        nums.push_back(cur);
        ops.push_back(op);
    }
    else{
        if(ops[n-1]=='*')nums[n-1]*=cur;
        else nums[n-1]/=cur;
        ops[n-1]=op;
    }
}
int compute(vector<int>&nums,vector<char>&ops)
{
    int ans=nums[0];
    for(int i=1;i<nums.size();i++)
        ans+=(ops[i-1]=='+')?nums[i]:-nums[i];
    return ans;
}
int f(int i)
{
    int cur=0;
    vector<int>nums;vector<char>ops;
    while(i<s.size()&&s[i]!=')')
    {
        if(s[i]>='0'&&s[i]<='9')
        {    cur=cur*10+s[i]-'0';
        i++;
        }
        else if(s[i]!='(')
        {
            push(nums,ops,cur,s[i]);
                i++;
            cur=0;
        }
        else
        {
            cur=f(i+1);
            i=where+1;
        }
    }
    push(nums,ops,cur,'+');
    where=i;
    return compute(nums,ops);
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>s;
    where=0;
    cout<<f(0)<<'\n';
    return 0;
}

/*
嵌套类问题的解题套路
大概过程: 
定义全局变量 int where
递归函数f(i) : s[i..]，从i位置出发开始解析，遇到 字符串终止 或 嵌套条件终止 就返回
返回值是f(i)负责这一段的结果
f(i)在返回前更新全局变量where，让上级函数通过where知道解析到了什么位置，进而继续
*/