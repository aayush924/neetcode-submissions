class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while (temp1 || temp2) {
            // Fix: Extract values safely using ternary operators
            int val1 = temp1 ? temp1->val : 0;
            int val2 = temp2 ? temp2->val : 0;
            
            int sum = val1 + val2 + carry;
            carry = sum / 10; // Shorthand for updating carry

            ListNode* temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = curr->next;

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        if (carry) {
            ListNode* temp = new ListNode(1);
            curr->next = temp;
        }

        return head->next;
    }
};
