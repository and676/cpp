#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int arr[maxn];
int first, last;
int n, k;

void partition(int l, int r, int x) {
    first = l;
    last = r;
    int i = l;
    while (i <= last) {  // ← 修正
        if (arr[i] == x) 
            i++;
        else if (arr[i] < x) 
            swap(arr[i++], arr[first++]);
        else 
            swap(arr[i], arr[last--]);
        
    }
}

// 返回排序后下标 i 位置上的值
int randomizedSelect(int i) {
    int ans = 0;
    for(int l = 0,r=n-1;l<=r;) {  // ← 修正
        int x = arr[l + rand() % (r - l + 1)];
        partition(l, r, x);
        int left = first;
        int right = last;
        if (i < left) {
            r = left - 1;
        } else if (i > right) {
            l = right + 1;
        } else {
            ans = arr[i];  // ← 修正：返回下标 i的值
            break;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    // 第 k 小 = 排序后下标 k-1 的元素
    cout << randomizedSelect( k - 1) << '\n';
//cout<<randomizedSelsect(n-k)<<'\n';
    return 0;
}