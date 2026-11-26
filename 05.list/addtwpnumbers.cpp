class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        ListNode* ans = nullptr, *cur = nullptr;
        int carry = 0;
        for (int sum = 0, val = 0;                 // 初始化
             h1 != nullptr || h2 != nullptr;        // 终止条件
             h1 = (h1 == nullptr) ? nullptr : h1->next,   // 每轮 h1 前进
             h2 = (h2 == nullptr) ? nullptr : h2->next    // 每轮 h2 前进
             ) {
            sum = (h1 == nullptr ? 0 : h1->val)
                + (h2 == nullptr ? 0 : h2->val)
                + carry;
            val = sum % 10;
            carry = sum / 10;
            if (ans == nullptr) {
                ans = new ListNode(val);
                cur = ans;
            } else {
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }
        if (carry == 1) {
            cur->next = new ListNode(1);
        }
        return ans;
    }
};