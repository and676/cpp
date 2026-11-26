class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return head1 == nullptr ? head2 : head1;
        }
        ListNode* head = head1->val <= head2->val ? head1 : head2;
        ListNode* cur1 = head->next;
        ListNode* cur2 = (head == head1) ? head2 : head1;
        ListNode* pre = head;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                pre->next = cur1;
                cur1 = cur1->next;
            } else {
                pre->next = cur2;
                cur2 = cur2->next;
            }
            pre = pre->next;
        }
        pre->next = (cur1 != nullptr) ? cur1 : cur2;
        return head;
    }
};