/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head;
        ListNode* first = NULL;
        ListNode* second = head;
        int count = 1;
        while(cur!=NULL){
            if(count==k){
                first=cur;
            }
            if(count>k){
                second=second->next;
            }
            count++;
            cur=cur->next;
        }
        swap(first->val,second->val);
        return head;
    }
};