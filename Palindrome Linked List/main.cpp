#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class palindromeLinkedList {
public:
    bool isValidPalindrome(ListNode* head) {
        vector<int> numVec;
        while(head) {
            numVec.push_back(head->val);
            head = head->next;
        }

        int leftIdx = 0;
        int rightIdx = numVec.size() - 1;

        while (leftIdx < rightIdx) {
            if (numVec[leftIdx] != numVec[rightIdx]) return false;

            leftIdx++;
            rightIdx--;
        }

        return true;
    }
};

void deleteLinkedList(ListNode* head) {
    if (!head) return;
    deleteLinkedList(head->next);
    delete head;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    palindromeLinkedList pLinkedList;
    bool isPalindrome = pLinkedList.isValidPalindrome(head);

    cout << isPalindrome << endl;

    deleteLinkedList(head);

    return 0;
}

