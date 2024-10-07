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
    ListNode* reverseknodes(ListNode* head,int k){
        if(head==NULL)return NULL;
        ListNode* cur = head;
        ListNode* prev = NULL;
        int c=0;
        while(cur!=NULL && c!=k){
            ListNode* sec = cur->next;
            cur->next=prev;
            prev = cur;
            cur = sec;
            c++;
        }
        if(cur!=NULL){
            ListNode* new_head = reverseknodes(cur,2);
            head->next=new_head;
        }
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* newhead = reverseknodes(head,2);
        return newhead;
        
    }
};