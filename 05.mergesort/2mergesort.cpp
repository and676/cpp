#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int arr[MAXN];
int help_[MAXN];   // 避免和系统函数名/关键字冲突，换个名字
int n;

// 归并：把 arr[l..m] 和 arr[m+1..r] 合并成有序
void merge(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        help_[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= m) help_[k++] = arr[i++];
    while (j <= r) help_[k++] = arr[j++];
    for (int p = l; p <= r; p++) arr[p] = help_[p];
}

// 归并排序递归版
// T(n) = 2 * T(n/2) + O(n)，master 公式得 O(n log n)，空间 O(n)
void mergeSort1(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    mergeSort1(l, m);
    mergeSort1(m + 1, r);
    merge(l, m, r);
}

// 归并排序迭代版：step 从 1 开始倍增
void mergeSort2() {
    for (int step = 1; step < n; step <<= 1) {
        for (int l = 0; l < n; l += 2 * step) {
            int m = l + step - 1;
            if (m >= n - 1) break;
            int r = min(l + 2 * step - 1, n - 1);
            merge(l, m, r);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);          // 对应 Java 的 StreamTokenizer + PrintWriter 高速 IO

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // mergeSort1(0, n - 1);
    mergeSort2();

    for (int i = 0; i < n - 1; i++) cout << arr[i] << ' ';
    cout << arr[n - 1] << '\n';   // 对应 out.println + flush，'\n' 不强制刷新
    return 0;
}