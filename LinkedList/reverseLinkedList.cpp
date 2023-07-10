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
    ListNode* reverseList(ListNode* head) {
      ListNode* ret = NULL;
      auto F = [&] (ListNode* cur, ListNode* new_par, auto& F) -> void {
        if (cur == NULL) {
          return;
        }
        ret = cur;
        ListNode* next_ = cur -> next;
        cur -> next = new_par;
        F (next_, cur, F);
      };
      F (head, NULL, F);
      return ret;
    }
};
