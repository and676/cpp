#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int arr[maxn];
int help_[maxn];
int n;

long long merge(int l, int m, int r) {
    long long ans = 0; 
    for (int  i = l，j = m+1; j <= r; j++) {
        long long sum = 0;
        while (i <= m && arr[i] <= arr[j]) {
            sum += arr[i++];
        }
        ans += sum;
    }
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {  
        help_[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    }
    while (i <= m) help_[k++] = arr[i++];
    while (j <= r) help_[k++] = arr[j++];
    for (int p = l; p <= r; p++) arr[p] = help_[p];
    return ans;
}

long long smallsum(int l, int r) {
    if (l == r) return 0;
    int m = l + ((r - l) >> 1);
    return smallsum(l, m) + smallsum(m + 1, r) + merge(l, m, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << smallsum(0, n - 1) << '\n';
    }
    return 0;
}
//全局变量 = 所有递归层共用同一个账本，A 层记了账，B 层接着往上写，越加越乱。
//局部变量 = 每层调用有自己的独立账本，算完把数字报给上级，自己的账本撕掉，互不干扰。
//在归并排序这种"分治 → 递归 → 合并结果"的结构里，每一层 merge 只应该返回它自己这一层产生的小和，绝不能让它能看到或修改其他层的结果。所以 ans 必须是局部变量。