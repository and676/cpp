#include<bits/stdc++.h>
using namespace std;
static int maxn=100001;
int e[maxn];
int en[maxn];
int head;
int idx;

void init()
{
	head=-1;
	idx=0;
}
void insert_first(int x)
{
	e[idx]=x;
	en[idx]=head;
	head=idx;
	idx++;
}
void insert_k(int k,int x)
{ 
	e[idx]=x;
	en[idx]=en[k];
	en[k]=idx;
	idx++;
}
//x后面的点删除 
void delete (int x)
{
	en[x]=en[en[x]];
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	return 0;
 } 
