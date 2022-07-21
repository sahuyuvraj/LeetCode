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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode*dummy=new ListNode(0),*curr=dummy;
        dummy->next=head;
        for(int i=0;i<left-1;i++){
            curr=curr->next;
        }
        ListNode*temp=curr->next,*prev=NULL,*next=NULL;
        for(int i=0;i<=right-left;i++){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        curr->next=prev;
        while(curr->next)curr=curr->next;
        curr->next=temp;
        return dummy->next;
    }
};