/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        if (lists.empty()) 
            return nullptr; 
        return mergeSort(lists, 0, lists.size() - 1); 
    }

   private:
    ListNode* mergeSort(vector<ListNode*>& lists, int l, int r) {
        // merges lists[l...r] and returns the merged list
        if (l > r) return nullptr;
        if (l == r) return lists[l];
        int mid = (l + r) / 2;
        auto left = mergeSort(lists, l, mid);
        auto right = mergeSort(lists, mid + 1, r);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* node = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                node->next = left;
                node = node->next;
                left = left->next;
            } else {
                node->next = right;
                node = node->next;
                right = right->next;
            }
        }
        while (left) {
            node->next = left;
            node = node->next;
            left = left->next;
        }
        while (right) {
            node->next = right;
            node = node->next;
            right = right->next;
        }
        return dummy.next;
    }
};
