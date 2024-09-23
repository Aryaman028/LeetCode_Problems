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
        map<ListNode*,int>m;
        ListNode* cur = head;
        if(cur==NULL || cur->next==NULL)return NULL;
        int index = 0;
        while(cur!=NULL){
            if(m.find(cur)==m.end()){
                m[cur]=index++;
            }else{
                return cur;
            }
            cur=cur->next;
        }
        return NULL;
        
    }
};