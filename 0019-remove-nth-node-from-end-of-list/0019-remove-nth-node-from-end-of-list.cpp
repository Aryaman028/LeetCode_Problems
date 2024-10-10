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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //1st - Using vector for storing all the ele and then deleting and initializing LL
        //TC->O(N)  SC->O(N)
        //2ND - REVERSING THE LL 
        //TC->O(N)  SC->O(1)
        //3RD - Finding the length and then traversing n-k+1
        //TC->O(N)  SC->O(1)
        //4th - OPTIMAL 2 POINTER FAST AND SLOW
        //TC->O(N)  SC->O(1)

        ListNode* dummy = new ListNode(-1);
        //using dummy as if the length is 5 and it asks to delete the  5th node from end then fast pointer will be at the null 
        dummy->next=head;
        ListNode* slow =dummy;
        ListNode* fast = dummy;
        //maintaining n node distance between fast and slow when the fast becomes null slow gets to the node prior to the deleting node
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy->next;


        

        
    }
};