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
    ListNode* reverse(ListNode* head){
        ListNode* prev =NULL;
        ListNode* cur = head;
        while(cur!=NULL){
            ListNode* sec = cur->next;
            cur->next = prev;
            prev =cur;
            cur = sec;
        }
        return prev;
    }
    ListNode* middleElement(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        //Find the middle node and then reverse from that node and start comparing from the head and the middle element

        //middle node
        ListNode* middle = middleElement(head);
        middle->next = reverse(middle->next);
        middle = middle ->next;
        while(middle!=NULL){
            if(head->val!=middle->val)return false;
            head=head->next;
            middle = middle->next;
        }
        return true;

        
    }
};