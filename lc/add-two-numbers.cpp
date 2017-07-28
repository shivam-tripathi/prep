#include <bits/stdc++.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *ans = NULL, *temp = NULL;
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        int carry = 0, sum;

        while(l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;

            carry = sum/10;
            sum = sum%10;

            l1 = l1->next;
            l2 = l2->next;
            if (ans == NULL) {
                ans = new ListNode(sum);
                temp = ans;
                continue;
            }
            assert(temp != NULL);
            temp->next = new ListNode(sum);
            temp = temp->next;
        }

        while(l1 != NULL) {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l1 = l1->next;
        }

        while(l2 != NULL) {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new ListNode(sum);
            temp = temp->next;
            l2 = l2->next;

            carry = 0;
        }

        if (carry != 0)
            temp->next = new ListNode(carry);

        temp = ans;
        while(temp != NULL) {
            printf("%d", temp->val);
            temp = temp->next;
        }
        printf("\n");

        return ans;
    }

    void print(ListNode *ans) {
        ListNode *temp = ans;
        while(temp != NULL) {
            printf(" %d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
};

int main(int argc, char const *argv[])
{
    ListNode *root1 = new ListNode(2);
    root1->next = new ListNode(4);
    root1->next->next = new ListNode(3);

    ListNode *root2 = new ListNode(5);
    root2->next = new ListNode(6);
    root2->next->next = new ListNode(4);

    Solution sol;
    sol.addTwoNumbers(root1, root2);

    return 0;
}


// Don't forget to initialize the iterators as NULLs in the beginning
// Don't forget to add the last remaining carry if it's not zero
// Don't forget to repeat the add - carry - sum procedure for not just l1+l2+carry but also l1+carry and l2+carry
// Don't forget carry = add/10 and sum = add%10