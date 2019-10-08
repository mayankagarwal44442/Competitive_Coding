/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

    ListNode* head = A;
    if(!head) return NULL;

    while(head -> next)
    {
        if(head -> next -> val == head -> val)
        {
            ListNode* to_free = head -> next;
            head -> next = head -> next -> next;
            free(to_free);
        }
        else
        {
            head = head -> next;
        }
    }
    return A;
    
}
