#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = head, *cur = NULL, *next = NULL, *past = NULL;

        if (prev == NULL)
            return NULL;

        while(prev!=NULL) {
            cur = prev->next;
            if (cur == NULL)
                break;

            next = cur->next;

            prev->next = next;
            cur->next = prev;

            if (head == prev)
                head = cur;

            if (past != NULL)
                past->next = cur;

            past = prev;
            prev = next;
        }

        return head;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}

// The essence of linked list swap based questions is that the original logic is no more
// than a couple of lines - but it takes a lot more thinking.

// Remember here to reset the head!