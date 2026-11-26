#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int arr[MAXN];
int n;
int first, last;  //全局变量！
// 荷兰国旗划分：arr[l..r] 上 <x 放左边，==x 放中间，>x 放右边
// 执行完后，first..last 就是 ==x 的区间
void partition2(int l, int r, int x) 
{
    first = l;
    last = r;
    int i = l;
    while (i <= last)   //注意！
      {
        if (arr[i] == x)  i++;
        else if (arr[i] < x)  swap(arr[first++], arr[i++]);
        else  swap(arr[i], arr[last--]);
        }
}

// 随机快排改进版
void quickSort2(int l, int r) {
    if (l >= r) return;
    int x = arr[l + (rand() % (r - l + 1))];  // 随机选划分值，最好不要在partition中选随机值
    partition2(l, r, x);
    int left = first;
    int right = last;
    quickSort2(l, left - 1);   //注意！
    quickSort2(right + 1, r);
}




// 经典版（不推荐，重复元素多时会爆栈）
int partition1(int l, int r, int x) {
    int a = l, xi = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] <= x) {
            swap(arr[a], arr[i]);
            if (arr[a] == x) xi = a;
            a++;
        }
    }
    swap(arr[xi], arr[a - 1]);
    return a - 1;
}

void quickSort1(int l, int r) {
    if (l >= r) return;
    int x = arr[l + (rand() % (r - l + 1))];
    int mid = partition1(l, r, x);
    quickSort1(l, mid - 1);
    quickSort1(mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    quickSort2(0, n - 1);

    for (int i = 0; i < n - 1; i++) cout << arr[i] << ' ';
    cout << arr[n - 1] << '\n';
    return 0;
}


/*
swap()有库函数

// ❌ 错误：值传递，拷贝了一份，修改不影响原数组
void partition2(vector<int> arr, int l, int r, int x) { ... }

// ✓ 正确：引用传递，直接操作原数组
void partition2(vector<int>& arr, int l, int r, int x) { ... }

// ✓ 只读场景：const 引用，不拷贝也不能改
void print(const vector<int>& arr) { ... }

*/


