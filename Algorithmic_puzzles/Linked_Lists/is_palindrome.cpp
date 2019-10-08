/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//Complexity- O(n) time and O(1) space
//A solution using O(n) space would be using a stack

ListNode* reverse_list(ListNode* cur)
{
    if(!cur) return NULL;
    ListNode* prev = NULL;
    ListNode* next;
    
    while(cur)
    {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool compareLists(ListNode* A, ListNode* B)
{
    while(A && B)
    {
        if(A->val != B->val) return false;
        A = A-> next;
        B = B-> next;
    }
    return (!A && !B);
}


int Solution::lPalin(ListNode* A) {
    if(!A) return 1;
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev_slow = NULL;
    
    while(fast && fast->next)
    {
        prev_slow = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    if(fast) //odd number of nodes
    {
        slow = slow -> next;
    }
    prev_slow -> next = NULL;
    
    //reverse from here
    
    slow = reverse_list(slow);
    
    return compareLists(slow, A);
    

    
}
