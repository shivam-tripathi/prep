#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = head, *cur;

        while(prev != NULL) {
            cur = prev->next;
            while(cur != NULL && cur->val == prev->val) {
                cur = cur->next;
            }
            prev->next = cur;
            prev = cur;
        }

        return head;
    }
};

int main() {
}

// Simple