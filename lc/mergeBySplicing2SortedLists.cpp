/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        
        if (l1->val > l2->val) swap(l1, l2);
        
        ListNode *temp1 = l1, *temp2 = l2;
        ListNode *root = l1, *prev = l1;
        
        while(temp1 != NULL && temp2 != NULL) {
            if (temp1->val <= temp2->val) {
                prev = temp1;
                temp1 = temp1->next;
            }
            else if (temp1->val > temp2->val) {
                prev->next = temp2;
                temp2 = temp2->next;
                prev = prev->next;
                prev->next = temp1;
            }
        }
        
        if (temp2 != NULL) {
            prev->next = temp2;
            temp2 = temp2->next;
            prev = prev->next;
        }
        return root;
    }
};