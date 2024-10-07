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
    int length(ListNode* head){
        ListNode* cur = head;
        int c = 0;
        while(cur!=NULL){
            cur=cur->next;
            c++;
        }
        return c;
    }
    ListNode* kthnode(ListNode* head,int k){
        ListNode* cur = head;
        int c=0;
        while(c!=k-1){
            cur=cur->next;
            c++;
        }
        return cur;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int l = length(head);
        ListNode* firstkthnode = kthnode(head,k);
        ListNode* lastkthnode  = kthnode(head,l-k+1);
        swap(firstkthnode->val,lastkthnode->val);
        return head;
        
    }
};