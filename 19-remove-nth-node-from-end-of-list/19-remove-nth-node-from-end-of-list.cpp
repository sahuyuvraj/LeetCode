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
        if(!head)return head;
        int num=0;
        ListNode*curr=head;
        while(curr){
            num++;
            curr=curr->next;
        }
        if(n>num)return head;
        if(n==num)return head->next;
        num=num-n;
        curr=head;
        while(--num and curr){
            curr=curr->next;
        }
        if(curr and curr->next){
            curr->next=curr->next->next;
        }
        return head;
    }
};