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
    bool has_duplicates = false;
    ListNode* prev = NULL;
    while(head -> next)
    {
        if(head -> next -> val == head -> val)
        {
            has_duplicates = true;
            ListNode* to_free = head -> next;
            head -> next = head -> next -> next;
            free(to_free);
        }
        else
        {
            if(has_duplicates)
            {
                if(prev)
                {
                    prev->next = prev ->next->next;
                    free(head);
                    head = prev->next;
                }
                else    //first element deletion
                {
                    A = head->next;
                    free(head);
                    head = A;
                }
                has_duplicates = false;
            }
            else 
            {
                prev = head;
                head = head -> next;
            }
           
        }
    }
    if(has_duplicates)
    {
        if(prev)
        {
            prev->next = NULL;
            free(head);
        }
        else //result has no element
        {
            free(head);
            A = NULL;
        }
    }
    return A;    
}
