#include <bits/stdc++.h>
using namespace std;
const int maxn =100001;
int arr[maxn];
int n;

// i位置的数，向上调整大根堆
// arr[i] = x，x是新来的！往上看，直到不比父亲大，或者来到0位置(顶)

void heapinsert(int i)
{
	while(arr[i]>arr[(i-1)/2])
	{
		swap(arr[i],arr[(i-1)/2]);
		i=(i-1)/2;
	}
 } 

 // i位置的数，变小了，又想维持大根堆结构
// 向下调整大根堆
// 当前堆的大小为size

void heapify(int i,int size)
{
	int l=i*2+1;
	while(l<size)
	{
                 // 有左孩子，l
       		// 右孩子，l+1
		// 评选，最强的孩子，是哪个下标的孩子
		int best=l+1<size&&arr[l+1]>arr[l]?l+1:l;
	// 上面已经评选了最强的孩子，接下来，当前的数和最强的孩子之前，最强下标是谁
		best=arr[best]>arr[i]?best:i;
		if(best==i)break;
		swap(arr[best],arr[i]);
		i=best;
		l=i*2+1;
	}
}
	// 从顶到底建立大根堆，O(n * logn)
	// 依次弹出堆内最大值并排好序，O(n * logn)
	// 整体时间复杂度O(n * logn)
void heapsort1()
{
	for(int i=0;i<n;i++)
	heapinsert(i);
	int size=n;
	wihle(size>1)
	{
		swap(arr[0],arr[size--]);
		heapify(0,size);
	}
}

	// 从底到顶建立大根堆，O(n)
	// 依次弹出堆内最大值并排好序，O(n * logn)
	// 整体时间复杂度O(n * logn)
void heapsort2()
{
	for(int i=n-1;i>=0;i--)
	heapify(i,n);
	int size =n;
	while(size>1)
	{
		swap(arr[0],arr[--size]);
		heapify(0,size);
		
	}
 } 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i =0;i<n;i++)cin>>arr[i];
	heapsort1();
	for(int i =0;i<n;i++)
	if(i)cout<<" ";
	cout<<arr[i];
	cout<<'\n';
	return 0;
 } 


 
