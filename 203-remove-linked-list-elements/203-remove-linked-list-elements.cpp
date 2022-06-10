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
    ListNode* removeElements(ListNode* head, int val) {
        while(head and head->val==val)head=head->next;
        ListNode*curr=head;
        while(curr){
            while(curr->next and curr->next->val==val)curr->next=curr->next->next;
            curr=curr->next;
        }
        return head;
    }
};