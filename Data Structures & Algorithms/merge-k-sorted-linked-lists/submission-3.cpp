class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Compare {
            bool operator()(const ListNode* a, const ListNode* b) const {
                return a->val > b->val; // Min-heap
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push initial valid list heads
        for (auto list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            curr->next = node;
            curr = curr->next;

            // Only push if a valid next node exists
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }

        return dummy.next;
    }
};