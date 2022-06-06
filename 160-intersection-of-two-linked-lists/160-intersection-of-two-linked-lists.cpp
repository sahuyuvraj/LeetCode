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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int an=0,bn=0;
        ListNode*temp1=headA,*temp2=headB;
        while(temp1 or temp2){
            if(temp1){
                an++;
                temp1=temp1->next;
            }
            if(temp2){
                bn++;
                temp2=temp2->next;
            }
        }
        
        temp1=headA;
        temp2=headB;
        
        int n=abs(an-bn);
        
        if(bn>an){
            while(n--)temp2=temp2->next;
        }else if(an>bn){
            while(n--)temp1=temp1->next;
        }
        
        while(temp1){
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};