#include <bits/stdc++.h>
using namespace std;

const int maxn = 50001;
int arr[maxn];
int help_[maxn];
int n;

long long merge(int l, int m, int r) {
    long long ans = 0;
    // 统计：左半每个元素对右半的贡献
    for (int i = l, j = m + 1; i <= m; i++) {
        while (j <= r && (long long)arr[i] > (long long)arr[j] * 2) //可能会溢出
            j++;
        ans += j - m - 1;
    }
    // 归并
    int i = l, j = m+1,  k=l;
    while (i<= m && j <= r) help_[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while (i<= m) help_[k++] = arr[i++];
    while (j<= r) help_[k++] = arr[j++];
    for (int p = l; p <= r; p++) arr[p] = help_[p];
    return ans;
}

// 统计 l..r 范围上翻转对的数量，同时让 arr[l..r] 变有序
long long counts(int l, int r) {
    if (l == r) return 0;
    int m = l+((r-l)>>1);//要传给arr数组要是int类型；
    return counts(l, m) + counts(m + 1, r) + merge(l, m, r);
}

//注意两个函数的先后顺序

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << counts(0, n - 1) << '\n';
    }
    return 0;
}
//小和问题和反转对问题的差异
/*	                    小和问题                              	        翻转对问题
定义	              找每个数左边比它小的数的和	        找每个数左边比它两倍还大的数的个数
谁是"被找"的	右半部分的每个 arr[j]	                 左半部分的每个 arr[i]
指针方向	      固定 j 在右半，移动 i 扫左半	        固定 i 在左半，移动 j 扫右半
外层循环	          j 从 m+1 走到 r	                    i 从 l 走到 m*/


//外层循环遍历的是"主动发起比较"的那一边；内层 while 移动的是"被筛选"的那一边。
//谁的值在变化时会单调地扩大/缩小筛选范围，谁就能用双指针只走一趟。小和是"右边每个数看左边"，翻转对是"左边每个数看右边"，所以 for 和 while 的主次对调了。




//对于long long
写法           	 					实际运算过程 													结果 
arr[i] > arr[j]*2						int * int = int，	可能溢出，再比较									❌ 错误
(long long)arr[i] > arr[j]*2				右边 arr[j]*2 仍是 int 运算，溢出后才转成 long long 去跟左边比				❌ 还是错，右边已经炸了
(long long)arr[i] > (long long)arr[j] * 2	arr[j] 先转 long long，再乘 2（2 被提升为 long long），全程 long long 运算		✓ 正确
arr[i] > (long long)arr[j] * 2			同上，右边是 long long 运算，左边 int 自动提升							✓ 正确
(long long)(arr[j] * 2)					先算 arr[j]*2（int 乘法），溢出后再强转								❌ 括号包住了，死得更快
