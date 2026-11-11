class Code01_FindNumber {
public:
    // 保证arr有序，才能用这个方法
    static bool exist(const std::vector<int>& arr, int num) {
        if (arr.empty()) {
            return false;
        }
        int l = 0, r = (int)arr.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (arr[m] == num) {
                return true;
            } else if (arr[m] > num) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }