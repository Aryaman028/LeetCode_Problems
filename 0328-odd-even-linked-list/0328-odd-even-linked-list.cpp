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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)return head;
        ListNode *oddHead = new ListNode(-1), *oddTail = oddHead;
        ListNode *evenHead = new ListNode(-1), *evenTail = evenHead;
        ListNode *curr = head, *temp;
        int i=0;
        while (curr)
        {
            if(i%2==0){
                oddTail->next = curr;
                oddTail = oddTail->next;
            }else{
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
            i++;
            curr=curr->next;
        }
        //at the end it got connected to the main list thus mark it NULL
        oddTail ->next = NULL;
        evenTail->next = NULL;
        oddTail->next = evenHead->next;
        return oddHead->next;
    } 
        
};