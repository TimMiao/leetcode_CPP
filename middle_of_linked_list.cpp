#include <iostream>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        ListNode *finalNode = head;
        int counter = 0;
        while (temp != nullptr) {
            temp = temp->next;
            counter++;
        }
        int mid_pos = 0;
        mid_pos = counter / 2;
        int mid_counter = 0;
        while (finalNode != nullptr) {
            if (mid_counter != mid_pos) {
                finalNode = finalNode->next;
            }
            else {
                break;
            }
            mid_counter++;
        }
        return finalNode;
    }
};