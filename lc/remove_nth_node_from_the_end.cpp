#include<bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node = head, *prev = NULL, *cur = head;

        int cp = n;
        while(cp-- && cur != NULL) {
            cur = cur->next;
        }

        while(cur != NULL) {
            assert(cur != NULL);
            prev = node;
            node = node->next;
            cur = cur->next;
        }

        if(prev == NULL)
            return node->next;

        assert(prev != NULL && node != NULL);
        prev->next = node->next;
        delete node;

        ListNode *temp = head;
        printf("Printing..\n");
        while(temp != NULL) {
            printf("%d\n", temp->val);
            temp = temp->next;
        }

        assert(head != NULL);
        return head;
    }
};


int main(int argc, char const *argv[])
{
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    Solution sol;
    sol.removeNthFromEnd(root, 1);
    return 0;
}


// Always handle base cases very very cautiously, like here n==1; if it gets handled in a regular manner
// then don't unnecessarily add extra code
// The more you write, the greater are the chances that there is an error and difficult to debug