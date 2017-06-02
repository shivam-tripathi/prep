#include <bits/stdc++.h> 
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        int done = 0;
        ListNode *root = NULL;
        ListNode *prev = root;
        while(done < lists.size()) {
            int sval = INT_MAX, sindex = -1;
            for(int i=0; i<size; i++) {
                if (lists[i] != NULL && lists[i]->val < sval) {
                    sval = lists[i]->val;
                    sindex = i;
                }
            }
            if (sindex != -1 && sval != INT_MAX) {
                ListNode *cur = new ListNode(sval);
                if (prev == NULL) {
                    root = cur;
                    prev = root;
                }
                else {
                    prev->next = cur;
                    prev = cur;
                }
                lists[sindex] = lists[sindex]->next;
                if (lists[sindex] == NULL)
                    done++;

                ListNode *temp = root;
                if (root == NULL)
                    printf("NULL\n");
                while(temp != NULL) {
                    printf("%d\n", temp->val);
                    temp = temp->next;
                } 
            }
            else {
                cout << sindex << " " << sval << endl;
                break;
            }
        }
        return root;
    }
};

int main() {
    int number;
    vector <ListNode*> lists;
    ListNode *temp1 = new ListNode(1);
    temp1->next = new ListNode(5);
    temp1->next->next = new ListNode(6);

    ListNode *temp2 = new ListNode(2);
    temp2->next = new ListNode(7);


    ListNode *temp3 = new ListNode(0);
    temp3->next = new ListNode(3);
    temp3->next->next = new ListNode(5);

    lists.push_back(temp1);
    lists.push_back(temp2);
    lists.push_back(temp3);

    Solution sol;
    ListNode *root = sol.mergeKLists(lists);
    ListNode *temp = root;
    if (root == NULL)
        printf("NULL\n");
    while(temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    } 
}

// [[1, 5, 6], [2, 7], [0, 3, 5]]