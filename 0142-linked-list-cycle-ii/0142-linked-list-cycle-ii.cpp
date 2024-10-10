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
    ListNode *detectCycle(ListNode *head) {
        //OPTIMAL APPROACH 
        //TC->O(N)  SC->O(1)
        if(head==NULL)return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        //Is cycle present or not
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        //now fast points to head and move both slow and fast with the same speed
        //now the point the meet that will be the head of the cycle
        if(fast==NULL || fast->next==NULL)return NULL;
        fast=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
        
    }
};