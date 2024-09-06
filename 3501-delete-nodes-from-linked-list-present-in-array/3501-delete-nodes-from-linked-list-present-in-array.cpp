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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        if(head==NULL){
            return NULL;
        }
        while(s.find(head->val)!=s.end()){
            head=head->next;
        }
        ListNode* cur = head;
        while(cur->next!=NULL && cur->next->next!=NULL){
            int v=cur->next->val;
            if(s.find(v)!=s.end()){
                cur->next=cur->next->next;
                continue;
            }
            cur=cur->next;
        }
        if(cur->next!=NULL && s.find(cur->next->val)!=s.end()){
            cur->next=NULL;
        }
        return head;
    }
};