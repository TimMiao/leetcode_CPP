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
        ListNode *edge = new ListNode(0);
        edge->next = head;
        ListNode *temp_node = head;
        ListNode *pre_node = edge;

        while (temp_node != nullptr && temp_node->next != nullptr) {
            if (temp_node->val == temp_node->next->val) {
                int value = temp_node->val;
                while (temp_node != nullptr && temp_node->val == value) {
                    ListNode *del = temp_node;
                    temp_node = temp_node->next;
                    delete del;
                }
                pre_node->next = temp_node;
            }
            else {
                pre_node = temp_node;
                temp_node = temp_node->next;
            }
        }

        head = edge->next;
        delete edge;
        return head;
    }
};