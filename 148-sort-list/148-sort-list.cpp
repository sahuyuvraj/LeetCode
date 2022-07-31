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
ListNode* mergeList(ListNode* head1, ListNode* head2){
    
    if(head1 == NULL and head2 == NULL) return NULL;
    
    else if(head1 == NULL) return head2;
    
    else if(head2 == NULL) return head1;
    
    ListNode* temp;
    ListNode* head;
    
    if(head1->val < head2->val){
        temp = head1;
        head1 = head1->next;
    }
    else{
        temp = head2;
        head2 = head2->next;
    }
    
    head = temp;
    
    while(head1 != NULL and head2 != NULL){
        
        if(head1->val < head2->val){
            temp->next = head1;
            temp = temp->next;
            
            head1 = head1->next;
        }
        else{
            
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
        
    }
    
    if(head1 != NULL){
        temp->next = head1;
    }
    else{
        temp->next = head2;
    }
    
    
    return head;
}

ListNode* findMid(ListNode* head){
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast != NULL and fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
    
} 

ListNode* mergeSort(ListNode* head){
    
    if(head == NULL) return NULL;
    
    ListNode* mid = findMid(head);
    
    ListNode* left_list = head;
    ListNode* right_list = mid->next;
    
    mid->next = NULL;
    
    if(right_list == NULL) return head;
    
    ListNode* head1 = mergeSort(left_list);
    ListNode* head2 = mergeSort(right_list);
    
    ListNode* newHead = mergeList(head1, head2);
    
    return newHead;
    
}

ListNode* sortList(ListNode* head) {
    
    return mergeSort(head);
}
};