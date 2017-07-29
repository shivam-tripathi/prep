/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode *less = NULL, *more = NULL, *mid = NULL, *iter = head;
        ListNode *headless = NULL, *headmore = NULL, *headmid = NULL;

        while(iter!=NULL) {

            if (iter->val < x) {
                if (headless == NULL) {
                    less = headless = iter;
                }
                else {
                    less->next = iter;
                    less = iter;
                }
            }

            else if (iter->val >= x) {
                if (headmore == NULL) {
                    more = headmore = iter;
                }
                else {
                    more->next = iter;
                    more = iter;
                }
            }

            // else if (iter->val == x) {
            //     if (headmid == NULL) {
            //         mid = headmid = iter;
            //     }
            //     else {
            //         mid->next = iter;
            //         mid = iter;
            //     }
            // }

            iter = iter->next;
        }

        // less->next = NULL;
        // return headless;

        if (headless != NULL) {
            // Add the mid sublist
            // if (headmid != NULL) {
            //     less->next = headmid;
            //     less = mid;
            // }

            less->next = NULL;
            // Add the more sublist
            if (headmore != NULL) {
                less->next = headmore;
                more->next = NULL;
            }
            return headless;
        }

        // else if (headmid != NULL) {
        //     if (headmore != NULL) {
        //         mid->next = headmore;
        //         more->next = NULL;
        //     }
        //     else {
        //         mid->next = NULL;
        //     }
        //     return headmid;
        // }

        else if (headmore != NULL) {
            more->next = NULL;
            return headmore;
        }

        return NULL;
    }
};