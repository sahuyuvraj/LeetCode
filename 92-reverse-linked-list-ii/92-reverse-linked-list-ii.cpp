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
        if(head->next == NULL || left == right) return head;
        ListNode* temp = head, *ptr1 = NULL, *ptr2 = NULL, *prev, *curr, *nextnode, *tmp;
        int cnt = 0;
        while(temp)
        {
            cnt++;
            if(cnt == left-1) ptr1 = temp;
            else if(cnt == right+1) ptr2 = temp;
            temp = temp->next;
        }
        prev = NULL;
        if(ptr1) curr = ptr1->next;
        else curr = head;
        tmp = curr;
        while(curr != ptr2)
        {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        if(!ptr1 && !ptr2) return prev;
        else if(!ptr1 && ptr2) { tmp->next = ptr2; return prev;}
        ptr1->next = prev; 
        tmp->next = ptr2;
        return head;
    }
};