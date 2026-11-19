#include<bits/stdc++.h>
using namespace std;
struct listnode{
	int val;
	listnode*next;
	listnode(int x):val(x),next(nullptr){
	}
	
};
listnode*mergeklists(vector<listnode*>&arr)
{
        // 小根堆：val 越小，优先级越高
	auto cmp=[](listnode*a,listnode*b)
	{
		return a->val>b->val;
	};
	priority_queue<listnode*,vector<listnode*>,decltype(cmp)>heap(cmp);
  // 所有非空链表的头节点入堆
	for(listnode* head:arr)
	{
		if(head!=nullptr)
		heap.push(head);
	}
	if(heap.empty())
	return nullptr;
// 最小的头节点作为合并后的总头部
	listnode*head=heap.top();
	heap.pop();
	listnode*pre=head;
	if(pre->next!=nullptr)
	heap.push(pre->next);
	while(!heap.empty())
	{
		listnode*cur=heap.top();
		heap.pop();
		pre->next=cur;	
		pre=cur;
		if(cur->next!=nullptr)
		heap.push(cur->next);
	}
	return head;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 // 读入并建立 k 条链表
int k;
cin>>k;
vector<listnode*>lists(k,nullptr);
for(int i=0;i<k;i++)
{
	int n;
	cin>>n;
	listnode*head=nullptr;
	listnode*tail=nullptr;
	for(int j=0;j<n;j++)
	{
		int val;
		cin>>val;
		listnode*node=new listnode(val);
		if(head==nullptr)
    	{
		head=node;
		tail=node;
		}
		else
		{
			tail->next=node;
			tail=tail->next;
		}
		
	}
	lists[i]=head;
}
listnode*ans=mergeklists(lists);

    // 输出合并后的链表   //可以优化cout<<cur->val<<' ';
bool first =true;

for(listnode*cur=ans;cur!=nullptr;cur=cur->next)
{

if(!first)
{
	cout<<" ";
}
cout <<cur->val;
first=false;
}
cout<<'\n';
	return 0;
 } 
