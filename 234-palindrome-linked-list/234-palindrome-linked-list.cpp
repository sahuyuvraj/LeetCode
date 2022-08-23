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
    
    ListNode*reverse(ListNode*head){
        ListNode*curr=head,*next=NULL,*prev=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        int n=0;
        ListNode*temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(n&1)slow=slow->next;
        ListNode*curr2=reverse(slow);
        ListNode*curr1=head;
        while(curr2 and curr1){
            if(curr1->val!=curr2->val)return false;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return true;
    }
};