#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *previous = head, *prev = head, *cur;
        bool flag = false;

        while(prev != NULL && prev->next != NULL) {
            cur = prev->next;
            while (cur != NULL && prev->val == cur->val) {
                cur = cur->next;
            }
            if (cur == prev->next) {
                previous = prev;
                prev = cur;
                continue;
            }
            if (previous == prev) {
                prev = previous = head = cur;
            }
            else {
                previous->next = cur;
                prev = cur;
            }
        }
        return head;
    }
};


// God knows how this worked