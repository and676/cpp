#include<bits/stdc++.h>
using namespace std;
    int n;
struct listnode{
int val;
    listnode*next;
    listnode(int v):val(v),next(nullptr){}
    listnode(int v,listnode*next):val(v),next(next){}
};
listnode* reverselist(listnode*head)
{
    listnode*pre=nullptr;
    listnode*next=nullptr;
    while(head!=nullptr)
    {
        next=head->next;
        head->next=pre;
        pre=head;
        head=next;
    }
    return pre;
}
listnode*buildlist(int n)
{
    listnode*head=new listnode(0);
    listnode*tail=head;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
     listnode*h=new listnode(x);
        tail->next=h;
        tail=h;
    }
    return head->next;
}
void printlist(listnode*head)
{
    while(head!=nullptr)
    {
        cout<<head->val<<' ';
        head=head->next;
    }
}
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    listnode*head=buildlist(n);
    listnode*pre=reverselist(head);
    printlist(pre);
    return 0;
}




#include<bits/stdc++.h>
using namespace std;
int n;
int e[100001];
int ne[100001];
int main()
{
ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>e[i];
        ne[i]=i+1;
    }
    ne[n]=0;
    int pre=0,cur=1,nxt;
    while(cur!=0)
    {
        nxt=ne[cur];
        ne[cur]=pre;
        pre=cur;
        cur=nxt;
    }
    for(int c=pre;c!=0;c=ne[c])
        cout<<e[c]<<' ';
    cout<<'\n';
    return 0;
}