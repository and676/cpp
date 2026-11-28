#include <vector>
using namespace std;

class Code02_FindLeft {
public:
    // 保证arr有序，才能用这个方法
    // 返回>=num的最左位置，不存在返回-1
    static int findLeft(const vector<int>& arr, int num) {
        int l = 0, r = (int)arr.size() - 1, m = 0;
        int ans = -1;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (arr[m] >= num) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};