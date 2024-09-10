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
    int gcd(int a,int b){
        if(b>a)return gcd(b,a);
        if(a%b==0)return b;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL)return NULL;
        ListNode* cur = head;
        while(cur->next!=NULL){
            // ListNode* sec = cur->next;
            int v = gcd(cur->val,cur->next->val);
            ListNode* new_node = new ListNode(v);
            new_node->next=cur->next;
            cur->next=new_node;
            cur=cur->next->next;
        }
        return head;
    }
};