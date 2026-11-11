#include <vector>
using namespace std;

// 找到有序数组中 <= num 的最后一个元素下标（即 num 的右边界）
int findRight(vector<int>& arr, int num) {
    int l = 0, r = (int)arr.size() - 1, m = 0;
    int ans = -1;
    while (l <= r) {
        m = l + ((r - l) >> 1);
        if (arr[m] <= num) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}