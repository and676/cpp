class Solution {
public:
    static ListNode* partition(ListNode* head, int x) {
        ListNode* leftHead = nullptr, *leftTail = nullptr;   // < x 的区域
        ListNode* rightHead = nullptr, *rightTail = nullptr; // >= x 的区域
        ListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = nullptr;
            if (head->val < x) {
                if (leftHead == nullptr) {
                    leftHead = head;
                } else {
                    leftTail->next = head;
                }
                leftTail = head;
            } else {
                if (rightHead == nullptr) {
                    rightHead = head;
                } else {
                    rightTail->next = head;
                }
                rightTail = head;
            }
            head = next;
        }
        if (leftHead == nullptr) {
            return rightHead;
        }
        // < x 的区域有内容，把右区接上
        leftTail->next = rightHead;
        return leftHead;
    }
};