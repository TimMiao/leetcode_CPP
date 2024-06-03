struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int temp_value = (head->next)->val;
        // ListNode *temp_head = head->next;
        ListNode *pre_val = head;

        while(pre_val->next != nullptr) {
            if (pre_val->val != temp_value) {
                temp_value = pre_val->val;
                pre_val = pre_val->next;
                // temp_head = temp_head->next;
            }
            else {
                pre_val->next = pre_val;
                pre_val = pre_val->next;
            }
        }

        return head;
    }
};